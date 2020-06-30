#include "codefileinfo.h"



CodeFileInfo::CodeFileInfo(const QString &path, CodeVerificationFileType verificationFileType)
    : mPath(path)
    , mVerificationFileType(verificationFileType)
{
    // Nothing
}

QString CodeFileInfo::getPath() const
{
    return mPath;
}

CodeVerificationFileType CodeFileInfo::getVerificationFileType() const
{
    return mVerificationFileType;
}
