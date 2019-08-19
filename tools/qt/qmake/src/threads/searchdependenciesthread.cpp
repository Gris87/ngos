#include "searchdependenciesthread.h"

#include <QFile>
#include <QFileInfo>
#include <QIODevice>



QStringList                 SearchDependenciesThread::sIncludes;
QStringList                 SearchDependenciesThread::sSources;
qint64                      SearchDependenciesThread::sNumberOfThreads;
qint64                      SearchDependenciesThread::sNumberOfBlockedThreads;
QHash<QString, QStringList> SearchDependenciesThread::sDependencies;
QMutex                      SearchDependenciesThread::sSourcesMutex;
QSemaphore                  SearchDependenciesThread::sSourcesSemaphore;



SearchDependenciesThread::SearchDependenciesThread(const QString &workingDirectory)
    : mWorkingDirectory(workingDirectory)
    , mErrors()
{
    // Nothing
}

void SearchDependenciesThread::init(const QStringList &includes, const QStringList &sources, qint64 numberOfThreads)
{
    sIncludes               = includes;
    sSources                = sources;
    sNumberOfThreads        = numberOfThreads;
    sNumberOfBlockedThreads = 0;

    sSourcesSemaphore.release(sSources.length());
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
            !sSources.length() // sSources.length() == 0
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

        if (sSources.length()) // sSources.length() > 0
        {
            --sNumberOfBlockedThreads;

            return sSources.takeFirst();
        }

        sSourcesSemaphore.release();

        return "";
    }
}

void SearchDependenciesThread::addDependencies(const QString &source, const QStringList &dependencies)
{
    QMutexLocker lock(&sSourcesMutex);

    sDependencies.insert(source, dependencies);

    for (qint64 i = 0; i < dependencies.length(); ++i)
    {
        const QString &dependency = dependencies.at(i);

        if (
            !sSources.contains(dependency)
            &&
            !sDependencies.contains(dependency)
           )
        {
            sSources.append(dependency);
            sSourcesSemaphore.release();
        }
    }
}

QHash<QString, QStringList> SearchDependenciesThread::buildDependenciesMap()
{
    QHash<QString, QStringList> res;

    for (QHash<QString, QStringList>::Iterator i = sDependencies.begin(); i != sDependencies.end(); ++i)
    {
        buildDependenciesForSource(i.key(), res);
    }

    return res;
}

QStringList SearchDependenciesThread::buildDependenciesForSource(const QString &source, QHash<QString, QStringList> &dependenciesMap)
{
    if (dependenciesMap.contains(source))
    {
        return dependenciesMap.value(source);
    }



    QStringList res = sDependencies.value(source);

    dependenciesMap.insert(source, res); // Insert here to avoid infinite loops

    for (qint64 i = 0; i < res.length(); ++i)
    {
        QStringList nextDependencies = buildDependenciesForSource(res.at(i), dependenciesMap);



        for (qint64 j = 0; j < nextDependencies.length(); ++j)
        {
            QString nextDependency = nextDependencies.at(j);

            if (!res.contains(nextDependency))
            {
                res.append(nextDependency);
            }
        }
    }



    res.sort();
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
    QString filename = source.startsWith('/') ? source : (mWorkingDirectory + '/' + source);



    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly))
    {
        addError(QString("Failed to read file \"%1\"").arg(filename));

        return false;
    }

    QString content = QString::fromUtf8(file.readAll());
    file.close();



    QStringList dependencies;



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



                QString parentFolder = filename.left(filename.lastIndexOf('/') + 1);

                if (QFile::exists(parentFolder + includedFile))
                {
                    dependencies.append(QFileInfo(parentFolder + includedFile).absoluteFilePath());
                }
                else
                {
                    if (QFile::exists(mWorkingDirectory + '/' + includedFile))
                    {
                        dependencies.append(QFileInfo(mWorkingDirectory + '/' + includedFile).absoluteFilePath());
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

                                dependencies.append(QFileInfo(path).absoluteFilePath());

                                break;
                            }
                        }

                        if (!found)
                        {
                            addError(QString("Failed to find included file \"%1\"").arg(includedFile));

                            return false;
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
            addDependencies(source, QStringList());

            break;
        }
    } while(true);
}
