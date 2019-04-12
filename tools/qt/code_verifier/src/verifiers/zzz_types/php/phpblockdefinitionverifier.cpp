#include "phpblockdefinitionverifier.h"

#include "src/other/codeverificationfiletype.h"



PhpBlockDefinitionVerifier::PhpBlockDefinitionVerifier()
    : BaseCodeVerifier(VerificationFileType::PHP)
{
    // Nothing
}

void PhpBlockDefinitionVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// Ignore PhpBlockDefinitionVerifier");
        VERIFIER_REMOVE_COMMENTS(line);



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
            !lineTrimmed.startsWith("} while(")
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



PhpBlockDefinitionVerifier phpBlockDefinitionVerifierInstance;
