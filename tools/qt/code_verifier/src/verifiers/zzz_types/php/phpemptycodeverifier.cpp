#include "phpemptycodeverifier.h"

#include "src/other/codeverificationfiletype.h"



PhpEmptyCodeVerifier::PhpEmptyCodeVerifier()
    : BaseCodeVerifier(VerificationFileType::PHP)
{
    // Nothing
}

void PhpEmptyCodeVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// Ignore PhpEmptyCodeVerifier");
        VERIFIER_REMOVE_COMMENTS(line);



        QString lineTrimmed = line.trimmed();

        if (lineTrimmed == '}')
        {
            if (i > 0)
            {
                QString anotherLineTrimmed = lines.at(i - 1).trimmed();

                if (anotherLineTrimmed == '{' || anotherLineTrimmed == "")
                {
                    worker->addWarning(path, i, "Empty code");
                }
            }
        }
        else
        {
            qint64 index = lineTrimmed.indexOf('{');

            if (index >= 0)
            {
                qint64 index2 = lineTrimmed.indexOf('}', index + 1);

                if (index2 >= 0)
                {
                    if (lineTrimmed.mid(index + 1, index2 - index - 1).trimmed() == "")
                    {
                        worker->addWarning(path, i, "Empty code");
                    }
                }
            }
        }
    }
}



PhpEmptyCodeVerifier phpEmptyCodeVerifierInstance;
