#include "phpstatementspacesverifier.h"

#include <com/ngos/devtools/code_verifier/other/codeverificationfiletype.h>



PhpStatementSpacesVerifier::PhpStatementSpacesVerifier()
    : BaseCodeVerifier(CodeVerificationFileType::PHP)
{
    // Nothing
}

void PhpStatementSpacesVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// PhpStatementSpacesVerifier");
        removeComments(line);



        QString lineTrimmed = line.trimmed();

        if (
            lineTrimmed.startsWith("if(")
            ||
            lineTrimmed.startsWith("for(")
            ||
            lineTrimmed.startsWith("while(")
            ||
            lineTrimmed.startsWith("switch(")
           )
        {
            worker->addWarning(path, i, "Need to add space before bracket (");
        }
    }
}



PhpStatementSpacesVerifier phpStatementSpacesVerifierInstance;
