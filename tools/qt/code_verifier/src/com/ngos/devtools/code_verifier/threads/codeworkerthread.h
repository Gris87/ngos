#ifndef COM_NGOS_DEVTOOLS_CODE_VERIFIER_THREADS_CODEWORKERTHREAD_H
#define COM_NGOS_DEVTOOLS_CODE_VERIFIER_THREADS_CODEWORKERTHREAD_H



#include <QThread>

#include <QMutex>
#include <QSemaphore>

#include <com/ngos/devtools/code_verifier/other/codefileinfo.h>
#include <com/ngos/devtools/code_verifier/other/codemessageinfo.h>



class CodeWorkerThread: public QThread
{
public:
    CodeWorkerThread(); // TEST: NO

    static quint64 getAmountOfFiles(); // TEST: NO
    static void pushFile(const QString &path, CodeVerificationFileType verificationFileType); // TEST: NO
    static void pushFile(CodeFileInfo *fileInfo); // TEST: NO
    static CodeFileInfo* popFile(); // TEST: NO
    static void noMoreFiles(); // TEST: NO

    void addWarning(const QString &path, qint64 line, const QString &warning); // TEST: NO
    void addError(const QString &path, qint64 line, const QString &error); // TEST: NO

    const QList<CodeMessageInfo>& getWarnings() const; // TEST: NO
    const QList<CodeMessageInfo>& getErrors() const; // TEST: NO

protected:
    void run() override; // TEST: NO

private:
    void processFile(CodeFileInfo *fileInfo); // TEST: NO

    static quint64               sAmountOfFiles;
    static QList<CodeFileInfo *> sFiles;
    static QMutex                sFilesMutex;
    static QSemaphore            sFilesSemaphore;

    QList<CodeMessageInfo> mWarnings;
    QList<CodeMessageInfo> mErrors;
};



#endif // COM_NGOS_DEVTOOLS_CODE_VERIFIER_THREADS_CODEWORKERTHREAD_H
