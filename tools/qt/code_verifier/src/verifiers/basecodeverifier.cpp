#include "basecodeverifier.h"



QList<BaseCodeVerifier *> BaseCodeVerifier::sVerifiers;
quint64                   BaseCodeVerifier::sAmountOfVerifications = 0;



BaseCodeVerifier::BaseCodeVerifier(CodeVerificationFileType verification)
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

void BaseCodeVerifier::removeComments(QString &line) // TEST: NO
{
    for (qint64 i = 0; i < line.length(); ++i)
    {
        if (line.at(i) == '\\')
        {
            ++i;

            continue;
        }

        if (line.at(i) == '\"')
        {
            ++i;

            while (i < line.length())
            {
                if (line.at(i) == '\\')
                {
                    i += 2;

                    continue;
                }

                if (line.at(i) == '\"')
                {
                    break;
                }

                ++i;
            }

            continue;
        }

        if (
            i > 0
            &&
            line.at(i - 1) == '/'
            &&
            line.at(i) == '/'
           )
        {
            line = line.left(i - 1);

            break;
        }
    }
}

void BaseCodeVerifier::removeStrings(QString &line) // TEST: NO
{
    for (qint64 i = 0; i < line.length(); ++i)
    {
        if (line.at(i) == '\\')
        {
            ++i;

            continue;
        }

        if (line.at(i) == '\"')
        {
            qint64 startIndex = i;



            ++i;

            while (i < line.length())
            {
                if (line.at(i) == '\\')
                {
                    i += 2;

                    continue;
                }

                if (line.at(i) == '\"')
                {
                    break;
                }

                ++i;
            }



            line.remove(startIndex, i - startIndex + 1);

            i = startIndex - 1;
        }
    }
}

QString BaseCodeVerifier::traceCommandFromPath(const QString &path)
{
    if (path.contains("/src/os/bootloader/"))
    {
        return "UEFI_LT";
    }
    else
    if (path.contains("/src/os/configure/"))
    {
        if (path.contains("uefi/"))
        {
            return "UEFI_LT";
        }
        else
        if (path.contains("early/"))
        {
            return "EARLY_LT";
        }
    }
    else
    if (path.contains("/src/os/kernel/"))
    {
        if (path.contains("early/"))
        {
            return "EARLY_LT";
        }
    }
    else
    if (path.contains("/src/os/installer/"))
    {
        if (path.contains("early/"))
        {
            return "EARLY_LT";
        }
    }
    else
    if (path.contains("/src/os/shared/kernelbase/"))
    {
        if (path.contains("early/"))
        {
            return "EARLY_LT";
        }
        else
        {
            return "COMMON_LT";
        }
    }
    else
    if (path.contains("/src/os/shared/uefibase/"))
    {
        return "UEFI_LT";
    }
    else
    if (path.contains("/src/os/shared/common/"))
    {
        return "COMMON_LT";
    }

    return "";
}
