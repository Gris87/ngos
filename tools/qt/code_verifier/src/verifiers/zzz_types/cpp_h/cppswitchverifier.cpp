#include "cppswitchverifier.h"

#include "src/other/codeverificationfiletype.h"



CppSwitchVerifier::CppSwitchVerifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
{
    // Nothing
}

void CppSwitchVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE(line, "// Ignore CppSwitchVerifier");
        removeComments(line);



        QString lineTrimmed = line.trimmed();

        if (lineTrimmed.startsWith("switch ("))
        {
            if (lineTrimmed.endsWith(')'))
            {
                QString spaces = line.left(line.indexOf("switch ("));

                if (
                    i < lines.length() - 1
                    &&
                    lines.at(i + 1) == spaces + '{'
                   )
                {
                    qint64 startLine = i + 2;



                    i = startLine;

                    while (i < lines.length() && lines.at(i) != spaces + '}')
                    {
                        ++i;
                    }



                    if (i < lines.length())
                    {
                        qint64 endLine = i - 1;



                        bool defaultCaseFound = false;

                        for (qint64 j = startLine; j <= endLine; ++j)
                        {
                            QString switchLine        = lines.at(j);
                            QString switchLineTrimmed = switchLine.trimmed();

                            if (
                                switchLineTrimmed.startsWith("case ")
                                ||
                                switchLineTrimmed.startsWith("default:")
                               )
                            {
                                if (switchLineTrimmed.startsWith("default:"))
                                {
                                    defaultCaseFound = true;
                                }



                                qint64 index = 0;

                                do
                                {
                                    index = switchLineTrimmed.indexOf(':', index);

                                    if (index < 0)
                                    {
                                        break;
                                    }

                                    if (
                                        index < switchLineTrimmed.length() - 1
                                        &&
                                        switchLineTrimmed.at(index + 1) == '\''
                                       )
                                    {
                                        ++index;

                                        continue;
                                    }

                                    if (
                                        index >= switchLineTrimmed.length() - 1
                                        ||
                                        switchLineTrimmed.at(index + 1) != ':'
                                       )
                                    {
                                        break;
                                    }

                                    index += 2;
                                } while(true);



                                QString tail = switchLineTrimmed.mid(index + 1).trimmed();

                                if (
                                    !tail.startsWith("return ")
                                    &&
                                    !tail.endsWith("break;")
                                   )
                                {
                                    QString switchSpaces = switchLine.left(switchLine.indexOf(switchLineTrimmed));

                                    if (
                                        j <= endLine - 1
                                        &&
                                        lines.at(j + 1) == switchSpaces + '{'
                                       )
                                    {
                                        while (j <= endLine && lines.at(j) != switchSpaces + '}')
                                        {
                                            ++j;
                                        }

                                        if (j <= endLine)
                                        {
                                            if (
                                                j <= endLine - 1
                                                &&
                                                lines.at(j + 1) == switchSpaces + "break;"
                                               )
                                            {
                                                ++j;

                                                if (j <= endLine - 1)
                                                {
                                                    if (lines.at(j + 1).trimmed() == "")
                                                    {
                                                        ++j;
                                                    }
                                                    else
                                                    {
                                                        worker->addError(path, j, "Expected new line after break statement");
                                                    }
                                                }
                                            }
                                            else
                                            {
                                                worker->addError(path, j, "Expected break statement after closing bracket }");
                                            }
                                        }
                                        else
                                        {
                                            worker->addError(path, j, "Expected closing bracket }");
                                        }
                                    }
                                    else
                                    {
                                        if (
                                            j > endLine - 1
                                            ||
                                            !lines.at(j + 1).startsWith(switchSpaces + "case ")
                                           )
                                        {
                                            worker->addError(path, j, "Expected opening bracket {");
                                        }
                                    }
                                }
                            }
                            else
                            {
                                if (
                                    switchLineTrimmed != ""
                                    ||
                                    j == startLine
                                    ||
                                    (
                                     !lines.at(j - 1).trimmed().endsWith("break;")
                                     &&
                                     !lines.at(j - 1).contains("return ")
                                    )
                                   )
                                {
                                    worker->addError(path, j, "Unexpected line in switch statement");
                                }
                            }
                        }

                        if (!defaultCaseFound)
                        {
                            worker->addError(path, endLine + 1, "default case not found");
                        }
                    }
                    else
                    {
                        worker->addError(path, i, "Unexpected switch definition");
                    }
                }
                else
                {
                    worker->addError(path, i, "Unexpected switch definition");
                }
            }
            else
            {
                worker->addError(path, i, "Unexpected switch definition");
            }
        }
    }
}



CppSwitchVerifier cppSwitchVerifierInstance;
