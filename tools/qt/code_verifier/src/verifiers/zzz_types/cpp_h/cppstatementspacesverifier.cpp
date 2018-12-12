#include "cppstatementspacesverifier.h"

#include "src/other/codeverificationfiletype.h"



CppStatementSpacesVerifier::CppStatementSpacesVerifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
{
    // Nothing
}

void CppStatementSpacesVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// CppStatementSpacesVerifier");
        VERIFIER_REMOVE_COMMENTS(line);



        QString lineTrimmed = line.trimmed();

        if (
            lineTrimmed.startsWith("if(")
            ||
            lineTrimmed.startsWith("for(")
            ||
            lineTrimmed.startsWith("while(")
            ||
            lineTrimmed.startsWith("switch(")
            ||
            lineTrimmed.startsWith("catch(")
           )
        {
            worker->addWarning(path, i, "Need to add space before bracket (");
        }
    }
}



CppStatementSpacesVerifier cppStatementSpacesVerifierInstance;
