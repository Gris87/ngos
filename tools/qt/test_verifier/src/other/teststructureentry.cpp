#include "teststructureentry.h"



TestStructureEntry::TestStructureEntry(const QString &path, qint64 line, const QString &name)
    : mPath(path)
    , mLine(line)
    , mName(name)
{
    // Nothing
}

bool TestStructureEntry::operator<(const TestStructureEntry &another) const
{
    if (mPath < another.mPath)
    {
        return true;
    }

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



    return mName < another.mName;
}

QString TestStructureEntry::getPath() const
{
    return mPath;
}

QString TestStructureEntry::getName() const
{
    return mName;
}

QString TestStructureEntry::toString() const
{
    return QString("%1 | %2")
            .arg(mPath + ':' + QString::number(mLine + 1), -130, QChar(' '))
            .arg(mName, 50, QChar(' '));
}
