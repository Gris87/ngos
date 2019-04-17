#include "phpindentverifier.h"

#include "src/other/codeverificationfiletype.h"



#define SPACE_INDENT 4



PhpIndentVerifier::PhpIndentVerifier()
    : BaseCodeVerifier(VerificationFileType::PHP)
{
    // Nothing
}

void PhpIndentVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    qint64 expectedPos = -1;
    qint64 level       = 0;

    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE_REGION(lines, i, line, "// Ignore PhpIndentVerifier");
        removeComments(line);



        for (qint64 j = 0; j < line.length(); ++j)
        {
            QChar ch = line.at(j);

            if (ch != ' ')
            {
                if (ch == '\t')
                {
                    worker->addError(path, i, "Combination of tabs and spaces in indent");
                }
                else
                {
                    QString tail = line.mid(j);

                    if (expectedPos < 0)
                    {
                        if (j % SPACE_INDENT) // j % SPACE_INDENT != 0
                        {
                            worker->addError(path, i, "Invalid indentation");
                        }

                        if (tail == "if (" || tail == "while (")
                        {
                            expectedPos = j + tail.length();

                            level = 1;
                        }
                        else
                        if (
                            tail.startsWith("/*")
                            &&
                            !tail.endsWith("*/")
                           )
                        {
                            do
                            {
                                ++i;

                                if (i >= lines.length())
                                {
                                    break;
                                }



                                QString anotherLine = lines.at(i);

                                if (anotherLine.startsWith(line.left(j)))
                                {
                                    QString anotherTail = anotherLine.mid(j);

                                    if (
                                        !
                                        (
                                         anotherTail.length() > 1
                                         &&
                                         anotherTail.at(0) == ' '
                                         &&
                                         anotherTail.at(1) != ' '
                                        )
                                       )
                                    {
                                        worker->addError(path, i, "Invalid indentation");
                                    }
                                }
                                else
                                {
                                    worker->addError(path, i, "Invalid indentation");
                                }



                                if (anotherLine.endsWith("*/"))
                                {
                                    break;
                                }
                            } while(true);
                        }
                    }
                    else
                    {
                        if (tail == ')')
                        {
                            --expectedPos;
                            --level;
                        }



                        if (
                            j != expectedPos
                            &&
                            !tail.startsWith("| ")
                           )
                        {
                            worker->addError(path, i, "Invalid indentation");
                        }



                        if (tail == '(')
                        {
                            ++expectedPos;
                            ++level;
                        }
                        else
                        if (level <= 0)
                        {
                            expectedPos = -1;
                        }
                    }
                }

                break;
            }
        }
    }
}



PhpIndentVerifier phpIndentVerifierInstance;
