#include "codefileinfo.h"



CodeFileInfo::CodeFileInfo(const QString &path, VerificationFileType verificationFileType)
    : mPath(path)
    , mVerificationFileType(verificationFileType)
{
    // Nothing
}

QString CodeFileInfo::getPath() const
{
    return mPath;
}

VerificationFileType CodeFileInfo::getVerificationFileType() const
{
    return mVerificationFileType;
}
