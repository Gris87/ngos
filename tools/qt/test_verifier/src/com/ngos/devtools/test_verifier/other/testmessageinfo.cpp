#include "testmessageinfo.h"                                                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
TestMessageInfo::TestMessageInfo(const QString &path, const QString &message)                                                                                                                            // Colorize: green
    : mPath(path)                                                                                                                                                                                        // Colorize: green
    , mMessage(message)                                                                                                                                                                                  // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // Nothing                                                                                                                                                                                           // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
bool TestMessageInfo::operator<(const TestMessageInfo &another) const                                                                                                                                    // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // Compare mPath                                                                                                                                                                                     // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (mPath < another.mPath)                                                                                                                                                                       // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            return true;                                                                                                                                                                                 // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        if (mPath > another.mPath)                                                                                                                                                                       // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            return false;                                                                                                                                                                                // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return mMessage < another.mMessage;                                                                                                                                                                  // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
QString TestMessageInfo::toString() const                                                                                                                                                                // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    return QString("%1 | %2")                                                                                                                                                                            // Colorize: green
            .arg(mPath)                                                                                                                                                                                  // Colorize: green
            .arg(mMessage);                                                                                                                                                                              // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
