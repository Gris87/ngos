#include "phpsinglelineforverifier.h"

#include <com/ngos/devtools/code_verifier/other/codeverificationfiletype.h>



PhpSingleLineForVerifier::PhpSingleLineForVerifier()
    : BaseCodeVerifier(CodeVerificationFileType::PHP)
{
    // Nothing
}

void PhpSingleLineForVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.size(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// Ignore PhpSingleLineForVerifier");
        removeComments(line);



        QString lineTrimmed = line.trimmed();

        if (lineTrimmed.startsWith("for ("))
        {
            if (lineTrimmed == "for (")
            {
                QString spaces = line.left(line.indexOf("for ("));

                do
                {
                    ++i;
                } while(i < lines.size() && lines.at(i) != spaces + "    )");

                if (
                    i >= lines.size() - 1
                    ||
                    lines.at(i + 1) != spaces + '{'
                   )
                {
                    worker->addError(path, i, "Single line for statement is prohibited");
                }
            }
            else
            {
                if (lineTrimmed.endsWith(')'))
                {
                    QString spaces = line.left(line.indexOf("for ("));

                    if (
                        i >= lines.size() - 1
                        ||
                        lines.at(i + 1) != spaces + '{'
                       )
                    {
                        worker->addError(path, i, "Single line for statement is prohibited");
                    }
                }
                else
                {
                    worker->addError(path, i, "Single line for statement is prohibited");
                }
            }
        }
    }
}



PhpSingleLineForVerifier phpSingleLineForVerifierInstance;
