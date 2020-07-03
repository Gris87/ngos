#include "cppsemicolonverifier.h"

#include "com/ngos/devtools/code_verifier/other/codeverificationfiletype.h"



CppSemicolonVerifier::CppSemicolonVerifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
{
    // Nothing
}

void CppSemicolonVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    if (path.endsWith("/cppsemicolonverifier.cpp"))
    {
        return;
    }



    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// CppSemicolonVerifier");
        removeComments(line);



        QString lineTrimmed = line.trimmed();



        if (
            line.contains(";;")
            ||
            (
             lineTrimmed.startsWith(';')
             &&
             i > 0
             &&
             lines.at(i - 1).endsWith(';')
            )
           )
        {
            worker->addWarning(path, i, "Double semicolons \";;\" found");
        }
    }
}



CppSemicolonVerifier cppSemicolonVerifierInstance;
