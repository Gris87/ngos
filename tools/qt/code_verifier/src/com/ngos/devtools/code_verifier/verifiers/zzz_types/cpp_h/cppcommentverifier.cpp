#include "cppcommentverifier.h"

#include <com/ngos/devtools/code_verifier/other/codeverificationfiletype.h>



CppCommentVerifier::CppCommentVerifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
{
    // Nothing
}

void CppCommentVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// CppCommentVerifier");
        removeStrings(line);



        qint64 index = line.indexOf("//");

        if (index >= 0)
        {
            line = line.mid(index + 2);

            if (
                line != ""
                &&
                !line.startsWith(' ')
               )
            {
                worker->addWarning(path, i, "Invalid comment definition");
            }
        }
    }
}



CppCommentVerifier cppCommentVerifierInstance;
