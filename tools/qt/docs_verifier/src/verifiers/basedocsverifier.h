#ifndef DOCS_VERIFIER_SRC_VERIFIERS_BASEDOCSVERIFIER_H
#define DOCS_VERIFIER_SRC_VERIFIERS_BASEDOCSVERIFIER_H



#include <QList>

#include "src/other/docsfileinfo.h"
#include "src/threads/docsworkerthread.h"



class BaseDocsVerifier
{
public:
    BaseDocsVerifier(VerificationFileType verification); // TEST: NO
    BaseDocsVerifier(quint64 verification); // TEST: NO

    static void verifyAll(DocsWorkerThread *worker, DocsFileInfo *fileInfo, const QString &content, const QStringList &lines); // TEST: NO

    static quint64 getAmountOfVerifications(); // TEST: NO

protected:
    virtual void verify(DocsWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines); // TEST: NO

private:
    static QList<BaseDocsVerifier *> sVerifiers;
    static quint64                   sAmountOfVerifications;

    quint64 mVerification;
};



#endif // DOCS_VERIFIER_SRC_VERIFIERS_BASEDOCSVERIFIER_H
