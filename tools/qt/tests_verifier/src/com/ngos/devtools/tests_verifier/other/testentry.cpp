#include "testentry.h"                                                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/devtools/shared/console/console.h>                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
TestEntry::TestEntry(TestEntryType type, const QString &path, qint64 line, const QString &name, const QString &testModule)                                                                               // Colorize: green
    : mType(type)                                                                                                                                                                                        // Colorize: green
    , mPath(path)                                                                                                                                                                                        // Colorize: green
    , mLine(line)                                                                                                                                                                                        // Colorize: green
    , mName(name)                                                                                                                                                                                        // Colorize: green
    , mTestModule(testModule)                                                                                                                                                                            // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // Nothing                                                                                                                                                                                           // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
bool TestEntry::operator<(const TestEntry &another) const                                                                                                                                                // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // Compare mType                                                                                                                                                                                     // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (mType < another.mType)                                                                                                                                                                       // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            return true;                                                                                                                                                                                 // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (mType > another.mType)                                                                                                                                                                       // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            return false;                                                                                                                                                                                // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Compare mPath                                                                                                                                                                                     // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (mPath < another.mPath)                                                                                                                                                                       // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            return true;                                                                                                                                                                                 // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (mPath > another.mPath)                                                                                                                                                                       // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            return false;                                                                                                                                                                                // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Compare mLine                                                                                                                                                                                     // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (mLine < another.mLine)                                                                                                                                                                       // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            return true;                                                                                                                                                                                 // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        if (mLine > another.mLine)                                                                                                                                                                       // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            return false;                                                                                                                                                                                // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Compare mName                                                                                                                                                                                     // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (mName < another.mName)                                                                                                                                                                       // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            return true;                                                                                                                                                                                 // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (mName > another.mName)                                                                                                                                                                       // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            return false;                                                                                                                                                                                // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return mTestModule < another.mTestModule;                                                                                                                                                            // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
QString TestEntry::getFunctionOrMacro() const                                                                                                                                                            // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    if (mType == TestEntryType::DEFINE)                                                                                                                                                                  // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        return "macro";                                                                                                                                                                                  // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
    else                                                                                                                                                                                                 // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        return "function";                                                                                                                                                                               // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
TestEntryType TestEntry::getType() const                                                                                                                                                                 // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    return mType;                                                                                                                                                                                        // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
QString TestEntry::getPath() const                                                                                                                                                                       // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    return mPath;                                                                                                                                                                                        // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
QString TestEntry::getName() const                                                                                                                                                                       // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    return mName;                                                                                                                                                                                        // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
QString TestEntry::getTestModule() const                                                                                                                                                                 // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    return mTestModule;                                                                                                                                                                                  // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
QString TestEntry::toString() const                                                                                                                                                                      // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    return QString("%1 | %2 | %3 | %4")                                                                                                                                                                  // Colorize: green
            .arg(enumToHumanString(mType), 17, QChar(' '))                                                                                                                                               // Colorize: green
            .arg(mPath + ':' + QString::number(mLine + 1), -120, QChar(' '))                                                                                                                             // Colorize: green
            .arg(mName, 35, QChar(' '))                                                                                                                                                                  // Colorize: green
            .arg(mTestModule);                                                                                                                                                                           // Colorize: green
}                                                                                                                                                                                                        // Colorize: green