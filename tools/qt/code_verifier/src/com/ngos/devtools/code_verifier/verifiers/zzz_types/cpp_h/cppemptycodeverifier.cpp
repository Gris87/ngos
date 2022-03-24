#include "cppemptycodeverifier.h"                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/devtools/code_verifier/other/codeverificationfiletype.h>                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
CppEmptyCodeVerifier::CppEmptyCodeVerifier()                                                                                                                                                             // Colorize: green
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)                                                                                                                                                          // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // Nothing                                                                                                                                                                                           // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
void CppEmptyCodeVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)                                                                   // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    for (qint64 i = 0; i < lines.size(); ++i)                                                                                                                                                            // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        QString line = lines.at(i);                                                                                                                                                                      // Colorize: green
        VERIFIER_IGNORE(line, "// Ignore CppEmptyCodeVerifier");                                                                                                                                         // Colorize: green
        removeComments(line);                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        QString lineTrimmed = line.trimmed();                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (lineTrimmed == '}')                                                                                                                                                                          // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            if (i > 0)                                                                                                                                                                                   // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                QString anotherLineTrimmed = lines.at(i - 1).trimmed();                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                if (anotherLineTrimmed == '{' || anotherLineTrimmed == "")                                                                                                                               // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    worker->addWarning(path, i, "Empty code");                                                                                                                                           // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            qint64 index = lineTrimmed.indexOf('{');                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (index >= 0)                                                                                                                                                                              // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                qint64 index2 = lineTrimmed.indexOf('}', index + 1);                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                if (index2 >= 0)                                                                                                                                                                         // Colorize: green
                {                                                                                                                                                                                        // Colorize: green
                    if (lineTrimmed.mid(index + 1, index2 - index - 1).trimmed() == "")                                                                                                                  // Colorize: green
                    {                                                                                                                                                                                    // Colorize: green
                        worker->addWarning(path, i, "Empty code");                                                                                                                                       // Colorize: green
                    }                                                                                                                                                                                    // Colorize: green
                }                                                                                                                                                                                        // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
CppEmptyCodeVerifier cppEmptyCodeVerifierInstance;                                                                                                                                                       // Colorize: green
