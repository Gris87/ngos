#include "indenttabsverifier.h"                                                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/devtools/code_verifier/other/codeverificationfiletype.h>                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
IndentTabsVerifier::IndentTabsVerifier()                                                                                                                                                                 // Colorize: green
    : BaseCodeVerifier(VERIFICATION_INDENT_TABS)                                                                                                                                                         // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // Nothing                                                                                                                                                                                           // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
void IndentTabsVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)                                                                     // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    for (qint64 i = 0; i < lines.size(); ++i)                                                                                                                                                            // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        QString line = lines.at(i);                                                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        for (qint64 j = 0; j < line.length(); ++j)                                                                                                                                                       // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            QChar ch = line.at(j);                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (ch != '\t')                                                                                                                                                                              // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                if (ch == ' ')                                                                                                                                                                           // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    worker->addError(path, i, "Combination of tabs and spaces in indent");                                                                                                               // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                break;                                                                                                                                                                                   // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
IndentTabsVerifier indentTabsVerifierInstance;                                                                                                                                                           // Colorize: green
