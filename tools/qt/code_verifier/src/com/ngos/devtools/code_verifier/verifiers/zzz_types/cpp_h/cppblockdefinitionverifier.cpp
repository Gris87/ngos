#include "cppblockdefinitionverifier.h"

#include <com/ngos/devtools/code_verifier/other/codeverificationfiletype.h>



CppBlockDefinitionVerifier::CppBlockDefinitionVerifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
{
    // Nothing
}

void CppBlockDefinitionVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.size(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// Ignore CppBlockDefinitionVerifier");
        removeComments(line);



        QString lineTrimmed = line.trimmed();

        if (
            lineTrimmed.endsWith('{')
            &&
            lineTrimmed.length() > 1
           )
        {
            worker->addError(path, i, "Code block should be started on the new line");
        }
        else
        if (
            lineTrimmed.startsWith('}')
            &&
            lineTrimmed != '}'
            &&
            lineTrimmed != "} \\"
            &&
            !lineTrimmed.startsWith("} while(")
            &&
            !lineTrimmed.endsWith(';')
           )
        {
            worker->addError(path, i, "Code block should be closed on the new line");
        }
        else
        if (
            lineTrimmed.startsWith("while (")
            &&
            lineTrimmed.endsWith(");")
           )
        {
            worker->addError(path, i, "While statement should be on the same line with the closing bracket");
        }
    }
}



CppBlockDefinitionVerifier cppBlockDefinitionVerifierInstance;
