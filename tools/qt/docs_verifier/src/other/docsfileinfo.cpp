#include "docsfileinfo.h"



DocsFileInfo::DocsFileInfo(const QString &path, VerificationFileType verificationFileType)
    : mPath(path)
    , mVerificationFileType(verificationFileType)
{
    // Nothing
}

QString DocsFileInfo::getPath() const
{
    return mPath;
}

VerificationFileType DocsFileInfo::getVerificationFileType() const
{
    return mVerificationFileType;
}
