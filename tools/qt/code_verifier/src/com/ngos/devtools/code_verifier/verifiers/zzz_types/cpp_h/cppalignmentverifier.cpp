#include "cppalignmentverifier.h"

#include "com/ngos/devtools/code_verifier/other/codeverificationfiletype.h"



CppAlignmentVerifier::CppAlignmentVerifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
{
    // Nothing
}

void CppAlignmentVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);
        VERIFIER_IGNORE_REGION(lines, i, line, "// Ignore CppAlignmentVerifier");
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
                            anotherLineTrimmed == "};"
                            ||
                            anotherLineTrimmed == "//"
                            ||
                            anotherLineTrimmed == "/***"
                            ||
                            anotherLineTrimmed == "***"
                            ||
                            anotherLineTrimmed == "***/"
                            ||
                            anotherLineTrimmed.startsWith("} __attribute__((")
                            ||
                            anotherLineTrimmed.startsWith("} while(")
                            ||
                            anotherLineTrimmed.startsWith("#if")
                            ||
                            anotherLineTrimmed.startsWith("#else")
                            ||
                            anotherLineTrimmed.startsWith("#elif")
                            ||
                            anotherLineTrimmed.startsWith("#endif")
                            ||
                            anotherLineTrimmed.startsWith("// Ignore CppAlignmentVerifier [")
                           )
                        {
                            break;
                        }
                    } while(true);



                    do
                    {
                        ++endRow;

                        if (endRow >= lines.length())
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
                            anotherLineTrimmed == "};"
                            ||
                            anotherLineTrimmed == "//"
                            ||
                            anotherLineTrimmed == "/***"
                            ||
                            anotherLineTrimmed == "***"
                            ||
                            anotherLineTrimmed == "***/"
                            ||
                            anotherLineTrimmed.startsWith("} __attribute__((")
                            ||
                            anotherLineTrimmed.startsWith("} while(")
                            ||
                            anotherLineTrimmed.startsWith("#if")
                            ||
                            anotherLineTrimmed.startsWith("#else")
                            ||
                            anotherLineTrimmed.startsWith("#elif")
                            ||
                            anotherLineTrimmed.startsWith("#endif")
                            ||
                            anotherLineTrimmed.startsWith("// Ignore CppAlignmentVerifier [")
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
                               n > 0
                               &&
                               (
                                scannedLine.at(n) == '*'
                                ||
                                scannedLine.at(n) == '&'
                               )
                              )
                        {
                            --n;
                        }

                        while (
                               n < line.length()
                               &&
                               n < scannedLine.length()
                               &&
                               (
                                line.at(n) == ' '
                                ||
                                line.at(n) == '*'
                                ||
                                line.at(n) == '&'
                               )
                               &&
                               (
                                scannedLine.at(n) == ' '
                                ||
                                scannedLine.at(n) == '*'
                                ||
                                scannedLine.at(n) == '&'
                               )
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
                                scannedLine.at(n) == '*'
                                ||
                                scannedLine.at(n) == '&'
                                ||
                                line.at(n) == ' '
                                ||
                                line.at(n) == '*'
                                ||
                                line.at(n) == '&'
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



CppAlignmentVerifier cppAlignmentVerifierInstance;
