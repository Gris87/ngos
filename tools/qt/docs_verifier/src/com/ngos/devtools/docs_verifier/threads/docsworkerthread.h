#ifndef DOCS_VERIFIER_SRC_COM_NGOS_DEVTOOLS_DOCS_VERIFIER_THREADS_DOCSWORKERTHREAD_H
#define DOCS_VERIFIER_SRC_COM_NGOS_DEVTOOLS_DOCS_VERIFIER_THREADS_DOCSWORKERTHREAD_H



#include <QThread>

#include <QMutex>
#include <QSemaphore>

#include <com/ngos/devtools/docs_verifier/other/docsfileinfo.h>
#include <com/ngos/devtools/docs_verifier/other/docsmessageinfo.h>



class DocsWorkerThread: public QThread
{
public:
    DocsWorkerThread(); // TEST: NO

    static quint64 getAmountOfFiles(); // TEST: NO
    static void pushFile(const QString &path, DocsVerificationFileType verifications); // TEST: NO
    static void pushFile(DocsFileInfo *fileInfo); // TEST: NO
    static DocsFileInfo* popFile(); // TEST: NO
    static void noMoreFiles(); // TEST: NO

    void addWarning(const QString &path, qint64 line, const QString &warning); // TEST: NO
    void addError(const QString &path, qint64 line, const QString &error); // TEST: NO

    const QList<DocsMessageInfo>& getWarnings() const; // TEST: NO
    const QList<DocsMessageInfo>& getErrors() const; // TEST: NO

protected:
    void run() override; // TEST: NO

private:
    void processFile(DocsFileInfo *fileInfo); // TEST: NO

    static quint64               sAmountOfFiles;
    static QList<DocsFileInfo *> sFiles;
    static QMutex                sFilesMutex;
    static QSemaphore            sFilesSemaphore;

    QList<DocsMessageInfo> mWarnings;
    QList<DocsMessageInfo> mErrors;
};



#endif // DOCS_VERIFIER_SRC_COM_NGOS_DEVTOOLS_DOCS_VERIFIER_THREADS_DOCSWORKERTHREAD_H
