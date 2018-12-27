#include "cppreleaseusageverifier.h"

#include "src/other/codeverificationfiletype.h"



CppReleaseUsageVerifier::CppReleaseUsageVerifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
{
    // Nothing
}

void CppReleaseUsageVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    if (
        path.contains("include/buildconfig.h")
        ||
        path.contains("tools/qt/code_verifier/src/verifiers/zzz_types/cpp_h/cppreleaseusageverifier.cpp")
       )
    {
        return;
    }



    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// Ignore CppReleaseUsageVerifier");



        if (
            line.contains("NGOS_BUILD_RELEASE")
            &&
            !
            (
             line.startsWith("#if NGOS_BUILD_RELEASE == OPTION_NO")
             &&
             (
              (
               i < lines.length() - 1
               &&
               lines.at(i + 1).startsWith("#define")
               &&
               lines.at(i + 1).contains("_ASSERT")
              )
              ||
              (
               i < lines.length() - 2
               &&
               lines.at(i + 1).contains("_LD((\"gdb_debug: ")
               &&
               (
                lines.at(i + 2) == "#else"
                ||
                lines.at(i + 2) == "#endif"
               )
              )
             )
            )
           )
        {
            worker->addError(path, i, "You can't use NGOS_BUILD_RELEASE here");
        }
    }
}



CppReleaseUsageVerifier cppReleaseUsageVerifierInstance;
