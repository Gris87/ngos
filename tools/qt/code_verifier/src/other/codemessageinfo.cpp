#include "codemessageinfo.h"



CodeMessageInfo::CodeMessageInfo(const QString &path, qint64 line, const QString &message)
    : mPath(path)
    , mLine(line)
    , mMessage(message)
{
    // Nothing
}

bool CodeMessageInfo::operator<(const CodeMessageInfo &another) const
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



    if (mLine < another.mLine)
    {
        return true;
    }
    else
    if (mLine > another.mLine)
    {
        return false;
    }



    return mMessage < another.mMessage;
}

bool CodeMessageInfo::operator==(const CodeMessageInfo &another) const
{
    if (mLine != another.mLine)
    {
        return false;
    }

    if (mPath != another.mPath)
    {
        return false;
    }

    if (mMessage != another.mMessage)
    {
        return false;
    }

    return true;
}

QString CodeMessageInfo::toString() const
{
    if (mLine >= 0)
    {
        return QString("%1:%2 | %3").arg(mPath).arg(mLine + 1).arg(mMessage);
    }
    else
    {
        return QString("%1 | %2").arg(mPath).arg(mMessage);
    }
}
