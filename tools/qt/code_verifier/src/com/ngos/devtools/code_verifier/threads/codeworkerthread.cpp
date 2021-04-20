#include "codeworkerthread.h"

#include <QFile>

#include <com/ngos/devtools/code_verifier/verifiers/basecodeverifier.h>



quint64               CodeWorkerThread::sAmountOfFiles = 0;
QList<CodeFileInfo *> CodeWorkerThread::sFiles;
QMutex                CodeWorkerThread::sFilesMutex;
QSemaphore            CodeWorkerThread::sFilesSemaphore;



CodeWorkerThread::CodeWorkerThread()
    : QThread()
    , mWarnings()
    , mErrors()
{
    // Nothing
}

quint64 CodeWorkerThread::getAmountOfFiles()
{
    return sAmountOfFiles - 1;
}

void CodeWorkerThread::pushFile(const QString &path, CodeVerificationFileType verifications)
{
    pushFile(new CodeFileInfo(path, verifications));
}

void CodeWorkerThread::pushFile(CodeFileInfo *fileInfo)
{
    QMutexLocker lock(&sFilesMutex);

    ++sAmountOfFiles;
    sFiles.append(fileInfo);
    sFilesSemaphore.release();
}

CodeFileInfo* CodeWorkerThread::popFile()
{
    sFilesSemaphore.acquire();

    {
        QMutexLocker lock(&sFilesMutex);



        CodeFileInfo *res = sFiles.constFirst();

        if (res == nullptr)
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

void CodeWorkerThread::noMoreFiles()
{
    pushFile(nullptr);
}

void CodeWorkerThread::addWarning(const QString &path, qint64 line, const QString &warning)
{
    mWarnings.append(CodeMessageInfo(path, line, warning));
}

void CodeWorkerThread::addError(const QString &path, qint64 line, const QString &error)
{
    mErrors.append(CodeMessageInfo(path, line, error));
}

const QList<CodeMessageInfo>& CodeWorkerThread::getWarnings() const
{
    return mWarnings;
}

const QList<CodeMessageInfo>& CodeWorkerThread::getErrors() const
{
    return mErrors;
}

void CodeWorkerThread::run()
{
    do
    {
        CodeFileInfo *fileInfo = popFile();

        if (fileInfo == nullptr)
        {
            break;
        }

        processFile(fileInfo);

        delete fileInfo;
    } while(true);
}

void CodeWorkerThread::processFile(CodeFileInfo *fileInfo)
{
    QFile file(fileInfo->getPath());

    if (!file.open(QIODevice::ReadOnly))
    {
        return;
    }

    QString content = QString::fromUtf8(file.readAll());
    file.close();



    QStringList lines = content.split('\n');

    for (qint64 i = 0; i < lines.size(); ++i)
    {
        QString &line = lines[i];

        if (line.endsWith('\r'))
        {
            line.remove(line.size() - 1, 1);
        }
    }



    BaseCodeVerifier::verifyAll(this, fileInfo, content, lines);
}
