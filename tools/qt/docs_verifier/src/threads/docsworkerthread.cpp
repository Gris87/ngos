#include "docsworkerthread.h"

#include <QFile>

#include "src/verifiers/basedocsverifier.h"



quint64               DocsWorkerThread::sAmountOfFiles = 0;
QList<DocsFileInfo *> DocsWorkerThread::sFiles;
QMutex                DocsWorkerThread::sFilesMutex;
QSemaphore            DocsWorkerThread::sFilesSemaphore;



DocsWorkerThread::DocsWorkerThread()
    : QThread()
    , mWarnings()
    , mErrors()
{
    // Nothing
}

quint64 DocsWorkerThread::getAmountOfFiles()
{
    return sAmountOfFiles;
}

void DocsWorkerThread::pushFile(const QString &path, DocsVerificationFileType verifications)
{
    pushFile(new DocsFileInfo(path, verifications));
}

void DocsWorkerThread::pushFile(DocsFileInfo *fileInfo)
{
    QMutexLocker lock(&sFilesMutex);

    ++sAmountOfFiles;
    sFiles.append(fileInfo);
    sFilesSemaphore.release();
}

DocsFileInfo* DocsWorkerThread::popFile()
{
    sFilesSemaphore.acquire();

    {
        QMutexLocker lock(&sFilesMutex);



        DocsFileInfo *res = sFiles.constFirst();

        if (!res) // res == 0
        {
            sFilesSemaphore.release();
        }
        else
        {
            sFiles.removeFirst();
        }

        return res;
    }
}

void DocsWorkerThread::noMoreFiles()
{
    pushFile(0);
}

void DocsWorkerThread::addWarning(const QString &path, qint64 line, const QString &warning)
{
    mWarnings.append(DocsMessageInfo(path, line, warning));
}

void DocsWorkerThread::addError(const QString &path, qint64 line, const QString &error)
{
    mErrors.append(DocsMessageInfo(path, line, error));
}

const QList<DocsMessageInfo>& DocsWorkerThread::getWarnings() const
{
    return mWarnings;
}

const QList<DocsMessageInfo>& DocsWorkerThread::getErrors() const
{
    return mErrors;
}

void DocsWorkerThread::run()
{
    do
    {
        DocsFileInfo *fileInfo = popFile();

        if (!fileInfo) // fileInfo == 0
        {
            break;
        }

        processFile(fileInfo);

        delete fileInfo;
    } while(true);
}

void DocsWorkerThread::processFile(DocsFileInfo *fileInfo)
{
    QFile file(fileInfo->getPath());

    if (!file.open(QIODevice::ReadOnly))
    {
        return;
    }

    QString content = QString::fromUtf8(file.readAll());
    file.close();



    QStringList lines = content.split('\n');

    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString &line = lines[i];

        if (line.endsWith('\r'))
        {
            line.remove(line.length() - 1, 1);
        }
    }



    BaseDocsVerifier::verifyAll(this, fileInfo, content, lines);
}
