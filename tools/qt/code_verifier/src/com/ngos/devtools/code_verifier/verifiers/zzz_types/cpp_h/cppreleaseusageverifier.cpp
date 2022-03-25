﻿#include "cppreleaseusageverifier.h"                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/devtools/code_verifier/other/codeverificationfiletype.h>                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
CppReleaseUsageVerifier::CppReleaseUsageVerifier()                                                                                                                                                       // Colorize: green
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)                                                                                                                                                          // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // Nothing                                                                                                                                                                                           // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
void CppReleaseUsageVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)                                                                // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // Do not check specific files                                                                                                                                                                       // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (                                                                                                                                                                                             // Colorize: green
            path.contains("include/buildconfig.h")                                                                                                                                                       // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            path.contains("tools/qt/code_verifier/src/com/ngos/devtools/code_verifier/verifiers/zzz_types/cpp_h/cppreleaseusageverifier.cpp")                                                            // Colorize: green
           )                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            return;                                                                                                                                                                                      // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    for (qint64 i = 0; i < lines.size(); ++i)                                                                                                                                                            // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        QString line = lines.at(i);                                                                                                                                                                      // Colorize: green
        VERIFIER_IGNORE(line, "// Ignore CppReleaseUsageVerifier");                                                                                                                                      // Colorize: green
        removeComments(line);                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (                                                                                                                                                                                             // Colorize: green
            line.contains("NGOS_BUILD_RELEASE")                                                                                                                                                          // Colorize: green
            &&                                                                                                                                                                                           // Colorize: green
            !                                                                                                                                                                                            // Colorize: green
            (                                                                                                                                                                                            // Colorize: green
             line.startsWith("#if NGOS_BUILD_RELEASE == OPTION_NO")                                                                                                                                      // Colorize: green
             &&                                                                                                                                                                                          // Colorize: green
             (                                                                                                                                                                                           // Colorize: green
              (                                                                                                                                                                                          // Colorize: green
               i + 1 < lines.size()                                                                                                                                                                      // Colorize: green
               &&                                                                                                                                                                                        // Colorize: green
               lines.at(i + 1).startsWith("#define")                                                                                                                                                     // Colorize: green
               &&                                                                                                                                                                                        // Colorize: green
               lines.at(i + 1).contains("_ASSERT")                                                                                                                                                       // Colorize: green
              )                                                                                                                                                                                          // Colorize: green
              ||                                                                                                                                                                                         // Colorize: green
              (                                                                                                                                                                                          // Colorize: green
               i + 2 < lines.size()                                                                                                                                                                      // Colorize: green
               &&                                                                                                                                                                                        // Colorize: green
               lines.at(i + 1).contains("_LD((\"") // TODO: Could we remove?                                                                                                                             // Colorize: green
               &&                                                                                                                                                                                        // Colorize: green
               (                                                                                                                                                                                         // Colorize: green
                lines.at(i + 2) == "#else"                                                                                                                                                               // Colorize: green
                ||                                                                                                                                                                                       // Colorize: green
                lines.at(i + 2) == "#endif"                                                                                                                                                              // Colorize: green
               )                                                                                                                                                                                         // Colorize: green
              )                                                                                                                                                                                          // Colorize: green
             )                                                                                                                                                                                           // Colorize: green
            )                                                                                                                                                                                            // Colorize: green
           )                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            worker->addError(path, i, "You can't use NGOS_BUILD_RELEASE here");                                                                                                                          // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
CppReleaseUsageVerifier cppReleaseUsageVerifierInstance;                                                                                                                                                 // Colorize: green
