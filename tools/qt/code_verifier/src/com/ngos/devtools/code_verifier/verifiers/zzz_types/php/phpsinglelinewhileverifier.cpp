#include "phpsinglelinewhileverifier.h"

#include <com/ngos/devtools/code_verifier/other/codeverificationfiletype.h>



PhpSingleLineWhileVerifier::PhpSingleLineWhileVerifier()
    : BaseCodeVerifier(CodeVerificationFileType::PHP)
{
    // Nothing
}

void PhpSingleLineWhileVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.size(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// Ignore PhpSingleLineWhileVerifier");
        removeComments(line);



        QString lineTrimmed = line.trimmed();

        if (lineTrimmed.startsWith("while ("))
        {
            if (lineTrimmed == "while (")
            {
                QString spaces = line.left(line.indexOf("while ("));

                do
                {
                    ++i;
                } while(i < lines.size() && lines.at(i) != spaces + "      )");

                if (
                    i >= lines.size() - 1
                    ||
                    lines.at(i + 1) != spaces + '{'
                   )
                {
                    worker->addError(path, i, "Single line while statement is prohibited");
                }
            }
            else
            {
                if (lineTrimmed.endsWith(')'))
                {
                    QString spaces = line.left(line.indexOf("while ("));

                    if (
                        i >= lines.size() - 1
                        ||
                        lines.at(i + 1) != spaces + '{'
                       )
                    {
                        worker->addError(path, i, "Single line while statement is prohibited");
                    }
                }
                else
                {
                    worker->addError(path, i, "Single line while statement is prohibited");
                }
            }
        }
    }
}



PhpSingleLineWhileVerifier phpSingleLineWhileVerifierInstance;
