#include "cppsinglelineifverifier.h"

#include <com/ngos/devtools/code_verifier/other/codeverificationfiletype.h>



CppSingleLineIfVerifier::CppSingleLineIfVerifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
{
    // Nothing
}

void CppSingleLineIfVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.size(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// Ignore CppSingleLineIfVerifier");
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
                } while(i < lines.size() && lines.at(i) != spaces + "   )");

                if (
                    i >= lines.size() - 1
                    ||
                    lines.at(i + 1) != spaces + '{'
                   )
                {
                    worker->addError(path, i, "Single line if statement is prohibited");
                }
            }
            else
            if (lineTrimmed == "if ( \\")
            {
                QString spaces = line.left(line.indexOf("if ("));

                do
                {
                    ++i;
                } while(i < lines.size() && lines.at(i) != spaces + "   ) \\"  && lines.at(i) != spaces + "   )");

                if (
                    i >= lines.size() - 1
                    ||
                    (
                     lines.at(i + 1) != spaces + '{'
                     &&
                     lines.at(i + 1) != spaces + "{ \\"
                    )
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
                        i >= lines.size() - 1
                        ||
                        lines.at(i + 1) != spaces + '{'
                       )
                    {
                        worker->addError(path, i, "Single line if statement is prohibited");
                    }
                }
                else
                if (lineTrimmed.endsWith(") \\"))
                {
                    QString spaces = line.left(line.indexOf("if ("));

                    if (
                        i >= lines.size() - 1
                        ||
                        (
                         lines.at(i + 1) != spaces + '{'
                         &&
                         lines.at(i + 1) != spaces + "{ \\"
                        )
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



CppSingleLineIfVerifier cppSingleLineIfVerifierInstance;
