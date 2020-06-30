#include "cppexterndeclaredverifier.h"

#include "src/com/ngos/devtools/code_verifier/other/codeverificationfiletype.h"



CppExternDeclaredVerifier::CppExternDeclaredVerifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
{
    // Nothing
}

void CppExternDeclaredVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// Ignore CppExternDeclaredVerifier");
        // removeComments(line); // Do not remove comments



        QString comment;

        qint64 index = line.indexOf("//");

        if (index >= 0)
        {
            comment = line.mid(index + 2);
            line    = line.left(index);
        }



        if (line.contains("extern ") && !comment.contains("declared in")) // Ignore CppExternDeclaredVerifier
        {
            worker->addError(path, i, "It is required to specify where variable declared");
        }
    }
}



CppExternDeclaredVerifier cppExternDeclaredVerifierInstance;
