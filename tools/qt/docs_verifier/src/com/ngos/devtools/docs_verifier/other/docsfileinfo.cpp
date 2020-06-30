#include "docsfileinfo.h"



DocsFileInfo::DocsFileInfo(const QString &path, DocsVerificationFileType verificationFileType)
    : mPath(path)
    , mVerificationFileType(verificationFileType)
{
    // Nothing
}

QString DocsFileInfo::getPath() const
{
    return mPath;
}

DocsVerificationFileType DocsFileInfo::getVerificationFileType() const
{
    return mVerificationFileType;
}
