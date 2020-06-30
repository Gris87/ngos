#include "testmessageinfo.h"



TestMessageInfo::TestMessageInfo(const QString &path, const QString &message)
    : mPath(path)
    , mMessage(message)
{
    // Nothing
}

bool TestMessageInfo::operator<(const TestMessageInfo &another) const
{
    if (mPath < another.mPath)
    {
        return true;
    }
    else
    if (mPath > another.mPath)
    {
        return false;
    }



    return mMessage < another.mMessage;
}

QString TestMessageInfo::toString() const
{
    return QString("%1 | %2").arg(mPath).arg(mMessage);
}
