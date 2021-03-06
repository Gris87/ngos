#include "phpalignmentverifier.h"

#include <com/ngos/devtools/code_verifier/other/codeverificationfiletype.h>



PhpAlignmentVerifier::PhpAlignmentVerifier()
    : BaseCodeVerifier(CodeVerificationFileType::PHP)
{
    // Nothing
}

void PhpAlignmentVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.size(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE_REGION(lines, i, line, "// Ignore PhpAlignmentVerifier");
        removeComments(line);



        qint64 startPos = 0;

        while (startPos < line.length() && line.at(startPos) == ' ')
        {
            ++startPos;
        }



        qint64 startRow = -1;
        qint64 endRow   = -1;



        for (qint64 j = startPos + 1; j < line.length() - 1; ++j)
        {
            QChar ch      = line.at(j);
            QChar chPrev1 = line.at(j - 1);
            QChar chNext1 = line.at(j + 1);

            if (
                ch == ' '
                &&
                chPrev1 == ' '
                &&
                chNext1 != ' '
               )
            {
                if (startRow < 0 || endRow < 0)
                {
                    startRow = i;
                    endRow   = i;



                    do
                    {
                        --startRow;

                        if (startRow < 0)
                        {
                            break;
                        }



                        QString anotherLine = lines.at(startRow);

                        if (anotherLine == "")
                        {
                            break;
                        }



                        QString anotherLineTrimmed = anotherLine.trimmed();

                        if (
                            anotherLineTrimmed == '{'
                            ||
                            anotherLineTrimmed == '}'
                            ||
                            anotherLineTrimmed == "//"
                            ||
                            anotherLineTrimmed.startsWith("} while(")
                            ||
                            anotherLineTrimmed.startsWith("// Ignore PhpAlignmentVerifier [")
                           )
                        {
                            break;
                        }
                    } while(true);



                    do
                    {
                        ++endRow;

                        if (endRow >= lines.size())
                        {
                            break;
                        }



                        QString anotherLine = lines.at(endRow);

                        if (anotherLine == "")
                        {
                            break;
                        }



                        QString anotherLineTrimmed = anotherLine.trimmed();

                        if (
                            anotherLineTrimmed == '{'
                            ||
                            anotherLineTrimmed == '}'
                            ||
                            anotherLineTrimmed == "//"
                            ||
                            anotherLineTrimmed.startsWith("} while(")
                            ||
                            anotherLineTrimmed.startsWith("// Ignore PhpAlignmentVerifier [")
                           )
                        {
                            break;
                        }
                    } while(true);



                    ++startRow;
                    --endRow;
                }



                for (qint64 k = startRow; k <= endRow ; ++k)
                {
                    if (k == i)
                    {
                        continue;
                    }



                    QString scannedLine = lines.at(k);

                    if (j < scannedLine.length() - 1)
                    {
                        qint64 n = j;

                        while (
                               n < line.length()
                               &&
                               n < scannedLine.length()
                               &&
                               line.at(n) == ' '
                               &&
                               scannedLine.at(n) == ' '
                              )
                        {
                            ++n;
                        }



                        if (
                            n < line.length()
                            &&
                            n < scannedLine.length()
                           )
                        {
                            if (
                                scannedLine.at(n) == ' '
                                ||
                                line.at(n) == ' '
                               )
                            {
                                worker->addWarning(path, k, QString("Alignment is invalid in position %1").arg(j + 1));
                            }
                        }
                        else
                        {
                            worker->addError(path, k, QString("Unexpected behavior during alignment verification in position %1").arg(j + 1));
                        }
                    }
                }
            }
        }
    }
}



PhpAlignmentVerifier phpAlignmentVerifierInstance;
