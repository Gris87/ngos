#include "git.h"                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <QProcess>                                                                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
bool GIT::isIgnored(const QString &workingDirectory, const QString &path)                                                                                                                                // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    QProcess git;                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    git.setWorkingDirectory(workingDirectory);                                                                                                                                                           // Colorize: green
    git.start("git", QStringList() << "check-ignore" << path);                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    if (!git.waitForFinished(-1))                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        return false;                                                                                                                                                                                    // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return !git.readAll().isEmpty();                                                                                                                                                                     // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
GIT::GIT()                                                                                                                                                                                               // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // Nothing                                                                                                                                                                                           // Colorize: green
}                                                                                                                                                                                                        // Colorize: green