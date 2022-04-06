#include "docsworkerthread.h"                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <QFile>                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/devtools/docs_verifier/verifiers/basedocsverifier.h>                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
quint64               DocsWorkerThread::sAmountOfFiles = 0;                                                                                                                                              // Colorize: green
QList<DocsFileInfo *> DocsWorkerThread::sFiles;                                                                                                                                                          // Colorize: green
QMutex                DocsWorkerThread::sFilesMutex;                                                                                                                                                     // Colorize: green
QSemaphore            DocsWorkerThread::sFilesSemaphore;                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
DocsWorkerThread::DocsWorkerThread()                                                                                                                                                                     // Colorize: green
    : QThread()                                                                                                                                                                                          // Colorize: green
    , mWarnings()                                                                                                                                                                                        // Colorize: green
    , mErrors()                                                                                                                                                                                          // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // Nothing                                                                                                                                                                                           // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
quint64 DocsWorkerThread::getAmountOfFiles()                                                                                                                                                              // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    return sAmountOfFiles - 1;                                                                                                                                                                           // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
void DocsWorkerThread::pushFile(const QString &path, DocsVerificationFileType verificationFileType)                                                                                                      // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    pushFile(new DocsFileInfo(path, verificationFileType));                                                                                                                                              // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
void DocsWorkerThread::pushFile(DocsFileInfo *fileInfo)                                                                                                                                                  // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    QMutexLocker lock(&sFilesMutex);                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    ++sAmountOfFiles;                                                                                                                                                                                    // Colorize: green
    sFiles.append(fileInfo);                                                                                                                                                                             // Colorize: green
    sFilesSemaphore.release();                                                                                                                                                                           // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
DocsFileInfo* DocsWorkerThread::popFile()                                                                                                                                                                // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    sFilesSemaphore.acquire();                                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        QMutexLocker lock(&sFilesMutex);                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        DocsFileInfo *res = sFiles.constFirst();                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (res == nullptr)                                                                                                                                                                              // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            sFilesSemaphore.release();                                                                                                                                                                   // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            sFiles.removeFirst();                                                                                                                                                                        // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        return res;                                                                                                                                                                                      // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
void DocsWorkerThread::noMoreFiles()                                                                                                                                                                     // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    pushFile(nullptr);                                                                                                                                                                                   // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
void DocsWorkerThread::addWarning(const QString &path, qint64 line, const QString &warning)                                                                                                              // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    mWarnings.append(DocsMessageInfo(path, line, warning));                                                                                                                                              // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
void DocsWorkerThread::addError(const QString &path, qint64 line, const QString &error)                                                                                                                  // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    mErrors.append(DocsMessageInfo(path, line, error));                                                                                                                                                  // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
const QList<DocsMessageInfo>& DocsWorkerThread::getWarnings() const                                                                                                                                      // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    return mWarnings;                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
const QList<DocsMessageInfo>& DocsWorkerThread::getErrors() const                                                                                                                                        // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    return mErrors;                                                                                                                                                                                      // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
void DocsWorkerThread::run()                                                                                                                                                                             // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    do                                                                                                                                                                                                   // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        DocsFileInfo *fileInfo = popFile();                                                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (fileInfo == nullptr)                                                                                                                                                                         // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            break;                                                                                                                                                                                       // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        processFile(fileInfo);                                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        delete fileInfo;                                                                                                                                                                                 // Colorize: green
    } while(true);                                                                                                                                                                                       // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
void DocsWorkerThread::processFile(DocsFileInfo *fileInfo)                                                                                                                                               // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    QString content;                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Read file content                                                                                                                                                                                 // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        QFile file(fileInfo->getPath());                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (!file.open(QIODevice::ReadOnly))                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            return;                                                                                                                                                                                      // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        content = QString::fromUtf8(file.readAll());                                                                                                                                                     // Colorize: green
        file.close();                                                                                                                                                                                    // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QStringList lines;                                                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Split content to lines                                                                                                                                                                            // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        lines = content.split('\n');                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        for (qint64 i = 0; i < lines.size(); ++i)                                                                                                                                                        // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            QString &line = lines[i];                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (line.endsWith('\r'))                                                                                                                                                                     // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                line.remove(line.length() - 1, 1);                                                                                                                                                       // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    BaseDocsVerifier::verifyAll(this, fileInfo, content, lines);                                                                                                                                         // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
