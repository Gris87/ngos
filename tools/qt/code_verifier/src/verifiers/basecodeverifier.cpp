#include "basecodeverifier.h"



QList<BaseCodeVerifier *> BaseCodeVerifier::sVerifiers;
quint64                   BaseCodeVerifier::sAmountOfVerifications = 0;



BaseCodeVerifier::BaseCodeVerifier(VerificationFileType verification)
    : BaseCodeVerifier((quint64)verification)
{
    // Nothing
}

BaseCodeVerifier::BaseCodeVerifier(quint64 verification)
    : mVerification(verification)
{
    sVerifiers.append(this);
}

void BaseCodeVerifier::verifyAll(CodeWorkerThread *worker, CodeFileInfo *fileInfo, const QString &content, const QStringList &lines)
{
    for (qint64 i = 0; i < sVerifiers.length(); ++i)
    {
        BaseCodeVerifier *verifier = sVerifiers.at(i);

        if ((quint64)fileInfo->getVerificationFileType() & verifier->mVerification)
        {
            verifier->verify(worker, fileInfo->getPath(), content, lines);

            ++sAmountOfVerifications;
        }
    }
}

quint64 BaseCodeVerifier::getAmountOfVerifications()
{
    return sAmountOfVerifications;
}

void BaseCodeVerifier::verify(CodeWorkerThread */*worker*/, const QString &/*path*/, const QString &/*content*/, const QStringList &/*lines*/)
{
    // Nothing
}
