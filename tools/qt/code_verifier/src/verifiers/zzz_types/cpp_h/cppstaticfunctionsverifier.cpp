#include "cppstaticfunctionsverifier.h"

#include "src/other/codeverificationfiletype.h"



CppStaticFunctionsVerifier::CppStaticFunctionsVerifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
    , mStaticFunctionRegexp("^static .*$")
{
    // Nothing
}

void CppStaticFunctionsVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// CppStaticFunctionsVerifier");
        VERIFIER_REMOVE_COMMENTS(line);



        QRegularExpressionMatch match = mStaticFunctionRegexp.match(line);

        if (match.hasMatch())
        {
            worker->addWarning(path, i, "static functions are prohibited");
        }
    }
}



CppStaticFunctionsVerifier cppStaticFunctionsVerifierInstance;
