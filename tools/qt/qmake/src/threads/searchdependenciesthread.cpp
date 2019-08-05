#include "searchdependenciesthread.h"

#include <QFile>
#include <QIODevice>



#define WAIT_FOR_SOURCE_DELAY 200



QStringList                SearchDependenciesThread::sSources;
qint64                     SearchDependenciesThread::sTotalSources;
QMap<QString, QStringList> SearchDependenciesThread::sDependencies;
QMutex                     SearchDependenciesThread::sSourcesMutex;



SearchDependenciesThread::SearchDependenciesThread(const QString &workingDirectory)
    : mWorkingDirectory(workingDirectory)
    , mErrors()
{
    // Nothing
}

void SearchDependenciesThread::putSources(const QStringList &sources)
{
    sSources      = sources;
    sTotalSources = sSources.length();
}

void SearchDependenciesThread::addSourcesForDependencies(const QStringList &sources)
{
    QMutexLocker lock(&sSourcesMutex);



    for (qint64 i = 0; i < sources.length(); ++i)
    {
        const QString &source = sources.at(i);

        if (
            !sSources.contains(source)
            &&
            !sDependencies.contains(source)
           )
        {
            sSources.append(source);
            ++sTotalSources;
        }
    }
}

QString SearchDependenciesThread::takeSource()
{
    do
    {
        {
            QMutexLocker lock(&sSourcesMutex);

            if (sSources.length() > 0)
            {
                return sSources.takeFirst();
            }

            if (sDependencies.size() >= sTotalSources)
            {
                return "";
            }
        }

        msleep(WAIT_FOR_SOURCE_DELAY);
    } while(true);
}

void SearchDependenciesThread::addDependencies(const QString &source, const QStringList &dependencies)
{
    QMutexLocker lock(&sSourcesMutex);

    sDependencies.insert(source, dependencies);
}

QMap<QString, QStringList> SearchDependenciesThread::buildDependenciesMap()
{
    return sDependencies;
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

                dependencies.append(includedFile);
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
