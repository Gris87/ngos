#include "basedocsverifier.h"



QList<BaseDocsVerifier *> BaseDocsVerifier::sVerifiers;
quint64                   BaseDocsVerifier::sAmountOfVerifications = 0;



BaseDocsVerifier::BaseDocsVerifier(DocsVerificationFileType verification)
    : BaseDocsVerifier((quint64)verification)
{
    // Nothing
}

BaseDocsVerifier::BaseDocsVerifier(quint64 verification)
    : mVerification(verification)
{
    sVerifiers.append(this);
}

void BaseDocsVerifier::verifyAll(DocsWorkerThread *worker, DocsFileInfo *fileInfo, const QString &content, const QStringList &lines)
{
    for (qint64 i = 0; i < sVerifiers.size(); ++i)
    {
        BaseDocsVerifier *verifier = sVerifiers.at(i);

        if ((quint64)fileInfo->getVerificationFileType() & verifier->mVerification)
        {
            verifier->verify(worker, fileInfo->getPath(), content, lines);

            ++sAmountOfVerifications;
        }
    }
}

quint64 BaseDocsVerifier::getAmountOfVerifications()
{
    return sAmountOfVerifications;
}

void BaseDocsVerifier::verify(DocsWorkerThread */*worker*/, const QString &/*path*/, const QString &/*content*/, const QStringList &/*lines*/)
{
    // Nothing
}
