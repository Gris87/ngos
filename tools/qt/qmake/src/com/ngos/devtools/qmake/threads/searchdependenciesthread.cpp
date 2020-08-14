#include "searchdependenciesthread.h"

#include <QFile>
#include <QFileInfo>
#include <QIODevice>



QStringList                   SearchDependenciesThread::sIncludes;
QSet<QString>                 SearchDependenciesThread::sSources;
qint64                        SearchDependenciesThread::sNumberOfThreads;
qint64                        SearchDependenciesThread::sNumberOfBlockedThreads;
QHash<QString, QSet<QString>> SearchDependenciesThread::sDependencies;
QMutex                        SearchDependenciesThread::sSourcesMutex;
QSemaphore                    SearchDependenciesThread::sSourcesSemaphore;



SearchDependenciesThread::SearchDependenciesThread(const QString &workingDirectory)
    : mWorkingDirectory(workingDirectory)
    , mErrors()
{
    // Nothing
}

void SearchDependenciesThread::init(const QStringList &includes, const QStringList &sources, qint64 numberOfThreads)
{
    sIncludes               = includes;
    sSources                = QSet<QString>(sources.begin(), sources.end());
    sNumberOfThreads        = numberOfThreads;
    sNumberOfBlockedThreads = 0;

    sSourcesSemaphore.release(sSources.size());
}

QString SearchDependenciesThread::takeSource()
{
    bool skipSemaphore = false;

    {
        QMutexLocker lock(&sSourcesMutex);

        ++sNumberOfBlockedThreads;

        if (
            sNumberOfBlockedThreads >= sNumberOfThreads
            &&
            sSources.size() <= 0
           )
        {
            skipSemaphore = true;
        }
    }

    if (!skipSemaphore)
    {
        sSourcesSemaphore.acquire();
    }



    {
        QMutexLocker lock(&sSourcesMutex);

        if (sSources.size() > 0)
        {
            --sNumberOfBlockedThreads;

            QString res = *sSources.constBegin();

            sSources.erase(sSources.constBegin());

            return res;
        }

        sSourcesSemaphore.release();

        return "";
    }
}

void SearchDependenciesThread::addDependencies(const QString &source, const QSet<QString> &dependencies)
{
    QMutexLocker lock(&sSourcesMutex);

    sDependencies.insert(source, dependencies);

    QSetIterator<QString> it(dependencies);

    while (it.hasNext())
    {
        const QString &dependency = it.next();

        if (
            !sSources.contains(dependency)
            &&
            !sDependencies.contains(dependency)
           )
        {
            sSources.insert(dependency);
            sSourcesSemaphore.release();
        }
    }
}

QHash<QString, QSet<QString>> SearchDependenciesThread::buildDependenciesMap()
{
    QHash<QString, QSet<QString>> res;

    QHashIterator<QString, QSet<QString>> it(sDependencies);

    while (it.hasNext())
    {
        it.next();

        buildDependenciesForSource(it.key(), res);
    }

    return res;
}

QSet<QString> SearchDependenciesThread::buildDependenciesForSource(const QString &source, QHash<QString, QSet<QString>> &dependenciesMap)
{
    if (dependenciesMap.contains(source))
    {
        return dependenciesMap.value(source);
    }



    QSet<QString> res = sDependencies.value(source);

    dependenciesMap.insert(source, res); // Insert here to avoid infinite loops



    QSet<QString> newDependencies;



    QSetIterator<QString> it(res);

    while (it.hasNext())
    {
        newDependencies.unite(buildDependenciesForSource(it.next(), dependenciesMap));
    }



    res.unite(newDependencies);
    dependenciesMap.insert(source, res);



    return res;
}

void SearchDependenciesThread::addError(const QString &error)
{
    mErrors.append(error);
}

const QStringList& SearchDependenciesThread::getErrors() const
{
    return mErrors;
}

bool SearchDependenciesThread::handleSource(const QString &source)
{
    QString fileName = source.startsWith('/') ? source : (mWorkingDirectory + '/' + source);



    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly))
    {
        addError(QString("Failed to read file \"%1\"").arg(fileName));

        return false;
    }

    QString content = QString::fromUtf8(file.readAll());
    file.close();



    QSet<QString> dependencies;



    QStringList lines = content.split('\n');

    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i).trimmed();

        if (line.startsWith("#include "))
        {
            line = line.mid(9).trimmed();

            if (
                line.length() > 2
                &&
                (
                 (
                  line.startsWith('\"')
                  &&
                  line.endsWith('\"')
                 )
                 ||
                 (
                  line.startsWith('<')
                  &&
                  line.endsWith('>')
                 )
                )
               )
            {
                QString includedFile = line.mid(1, line.length() - 2);



                QString parentFolder = fileName.left(fileName.lastIndexOf('/') + 1);

                if (QFile::exists(parentFolder + includedFile))
                {
                    dependencies.insert(QFileInfo(parentFolder + includedFile).absoluteFilePath());
                }
                else
                {
                    if (QFile::exists(mWorkingDirectory + '/' + includedFile))
                    {
                        dependencies.insert(QFileInfo(mWorkingDirectory + '/' + includedFile).absoluteFilePath());
                    }
                    else
                    {
                        bool found = false;

                        for (qint64 j = 0; j < sIncludes.length(); ++j)
                        {
                            QString path = mWorkingDirectory + '/' + sIncludes.at(j) + '/' + includedFile;

                            if (QFile::exists(path))
                            {
                                found = true;

                                dependencies.insert(QFileInfo(path).absoluteFilePath());

                                break;
                            }
                        }

                        if (
                            !found
                            &&
                            includedFile != "com/ngos/kernel/other/brk/brk.h"
                            &&
                            includedFile != "com/ngos/kernel/other/ioremap/ioremap.h"
                            &&
                            includedFile != "com/ngos/kernel/other/uefi/uefi.h"
                           )
                        {
                            addError(QString("Failed to find included file \"%1\"").arg(includedFile));
                        }
                    }
                }
            }
        }
    }



    addDependencies(source, dependencies);



    return true;
}

void SearchDependenciesThread::run()
{
    do
    {
        QString source = takeSource();

        if (source == "")
        {
            break;
        }

        if (!handleSource(source))
        {
            addDependencies(source, QSet<QString>());
        }
    } while(true);
}
