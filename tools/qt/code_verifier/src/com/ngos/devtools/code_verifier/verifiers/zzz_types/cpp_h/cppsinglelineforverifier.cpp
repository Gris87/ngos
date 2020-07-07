#include "cppsinglelineforverifier.h"

#include <com/ngos/devtools/code_verifier/other/codeverificationfiletype.h>



CppSingleLineForVerifier::CppSingleLineForVerifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
{
    // Nothing
}

void CppSingleLineForVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// Ignore CppSingleLineForVerifier");
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
                } while(i < lines.length() && lines.at(i) != spaces + "    )");

                if (
                    i >= lines.length() - 1
                    ||
                    lines.at(i + 1) != spaces + '{'
                   )
                {
                    worker->addError(path, i, "Single line for statement is prohibited");
                }
            }
            else
            if (lineTrimmed == "for ( \\")
            {
                QString spaces = line.left(line.indexOf("for ("));

                do
                {
                    ++i;
                } while(i < lines.length() && lines.at(i) != spaces + "    ) \\"  && lines.at(i) != spaces + "    )");

                if (
                    i >= lines.length() - 1
                    ||
                    (
                     lines.at(i + 1) != spaces + '{'
                     &&
                     lines.at(i + 1) != spaces + "{ \\"
                    )
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
                        i >= lines.length() - 1
                        ||
                        lines.at(i + 1) != spaces + '{'
                       )
                    {
                        worker->addError(path, i, "Single line for statement is prohibited");
                    }
                }
                else
                if (lineTrimmed.endsWith(") \\"))
                {
                    QString spaces = line.left(line.indexOf("for ("));

                    if (
                        i >= lines.length() - 1
                        ||
                        (
                         lines.at(i + 1) != spaces + '{'
                         &&
                         lines.at(i + 1) != spaces + "{ \\"
                        )
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



CppSingleLineForVerifier cppSingleLineForVerifierInstance;
