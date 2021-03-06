#include "cppstaticfunctionsverifier.h"

#include <com/ngos/devtools/code_verifier/other/codeverificationfiletype.h>



CppStaticFunctionsVerifier::CppStaticFunctionsVerifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
    , mStaticFunctionRegexp("^static .*$")
{
    // Nothing
}

void CppStaticFunctionsVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.size(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// CppStaticFunctionsVerifier");
        removeComments(line);



        QRegularExpressionMatch match = mStaticFunctionRegexp.match(line);

        if (match.hasMatch())
        {
            worker->addWarning(path, i, "static functions are prohibited");
        }
    }
}



CppStaticFunctionsVerifier cppStaticFunctionsVerifierInstance;
