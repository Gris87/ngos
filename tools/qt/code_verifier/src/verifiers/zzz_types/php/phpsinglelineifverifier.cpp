#include "phpsinglelineifverifier.h"

#include "src/other/codeverificationfiletype.h"



PhpSingleLineIfVerifier::PhpSingleLineIfVerifier()
    : BaseCodeVerifier(CodeVerificationFileType::PHP)
{
    // Nothing
}

void PhpSingleLineIfVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// Ignore PhpSingleLineIfVerifier");
        removeComments(line);



        QString lineTrimmed = line.trimmed();

        if (lineTrimmed.startsWith("if ("))
        {
            if (lineTrimmed == "if (")
            {
                QString spaces = line.left(line.indexOf("if ("));

                do
                {
                    ++i;
                } while(i < lines.length() && lines.at(i) != spaces + "   )");

                if (
                    i >= lines.length() - 1
                    ||
                    lines.at(i + 1) != spaces + '{'
                   )
                {
                    worker->addError(path, i, "Single line if statement is prohibited");
                }
            }
            else
            {
                if (lineTrimmed.endsWith(')'))
                {
                    QString spaces = line.left(line.indexOf("if ("));

                    if (
                        i >= lines.length() - 1
                        ||
                        lines.at(i + 1) != spaces + '{'
                       )
                    {
                        worker->addError(path, i, "Single line if statement is prohibited");
                    }
                }
                else
                {
                    worker->addError(path, i, "Single line if statement is prohibited");
                }
            }
        }
    }
}



PhpSingleLineIfVerifier phpSingleLineIfVerifierInstance;
