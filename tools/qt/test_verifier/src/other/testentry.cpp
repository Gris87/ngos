#include "testentry.h"

#include <console/console.h>



TestEntry::TestEntry(TestEntryType type, const QString &path, qint64 line, const QString &name, const QString &testModule)
    : mType(type)
    , mPath(path)
    , mLine(line)
    , mName(name)
    , mTestModule(testModule)
{
    // Nothing
}

bool TestEntry::operator<(const TestEntry &another) const
{
    if (mType < another.mType)
    {
        return true;
    }

    if (mType > another.mType)
    {
        return false;
    }



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



    if (mName < another.mName)
    {
        return true;
    }

    if (mName > another.mName)
    {
        return false;
    }



    return mTestModule < another.mTestModule;
}

QString TestEntry::getFunctionOrMacro() const
{
    if (mType == TestEntryType::DEFINE)
    {
        return "macro";
    }
    else
    {
        return "function";
    }
}

TestEntryType TestEntry::getType() const
{
    return mType;
}

QString TestEntry::getPath() const
{
    return mPath;
}

QString TestEntry::getName() const
{
    return mName;
}

QString TestEntry::getTestModule() const
{
    return mTestModule;
}

QString TestEntry::toString() const
{
    return QString("%1 | %2 | %3 | %4")
            .arg(enumToHumanString(mType), 17, QChar(' '))
            .arg(mPath + ':' + QString::number(mLine + 1), -120, QChar(' '))
            .arg(mName, 35, QChar(' '))
            .arg(mTestModule);
}
