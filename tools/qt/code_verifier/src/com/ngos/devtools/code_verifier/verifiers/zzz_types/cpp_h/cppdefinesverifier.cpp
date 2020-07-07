#include "cppdefinesverifier.h"

#include <com/ngos/devtools/code_verifier/other/codeverificationfiletype.h>



CppDefinesVerifier::CppDefinesVerifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
{
    // Nothing
}

void CppDefinesVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    if (
        path.endsWith("/src/os/shared/common/src/com/ngos/shared/common/log/assert.h")
        ||
        path.endsWith("/src/os/shared/common/src/com/ngos/shared/common/log/log.h")
       )
    {
        return;
    }



    qint64 fileHeaderOffset = 0;

    while (fileHeaderOffset < lines.length() && lines.at(fileHeaderOffset).startsWith("//"))
    {
        ++fileHeaderOffset;
    }



    qint64 startLine = -1;
    qint64 endLine   = -1;

    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);

        if (
            line.startsWith("#define ")
            &&
            !
            (
             i == fileHeaderOffset + 1
             &&
             lines.at(i - 1).startsWith("#ifndef ")
             &&
             line == "#define " + lines.at(i - 1).mid(8)
            )
           )
        {
            if (startLine < 0)
            {
                startLine = i;
            }

            endLine = i;
        }
    }



    if (startLine >= 0)
    {
        QStringList currentBlock;



        for (qint64 i = startLine; i <= endLine; ++i)
        {
            QString line = lines.at(i);

            if (line == "")
            {
                if (currentBlock.length() > 0)
                {
                    currentBlock.clear();
                }
            }
            else
            if (line.startsWith("#define "))
            {
                currentBlock.append(line);
            }
            else
            {
                if (
                    line.startsWith("/*")
                    &&
                    !line.endsWith("*/")
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

                        if (anotherLine.endsWith("*/"))
                        {
                            break;
                        }
                    } while(true);
                }
                else
                if (
                    !line.startsWith("//")
                    &&
                    !line.startsWith("/*")
                    &&
                    !line.startsWith("#if")
                    &&
                    !line.startsWith("#else")
                    &&
                    !line.startsWith("#elif")
                    &&
                    !line.startsWith("#endif")
                   )
                {
                    bool multiline = currentBlock.length(); // currentBlock.length() > 0

                    for (qint64 j = 0; j < currentBlock.length(); ++j)
                    {
                        if (!currentBlock.at(j).endsWith(" \\"))
                        {
                            multiline = false;

                            break;
                        }
                    }

                    if (!multiline)
                    {
                        worker->addError(path, i, "Unexpected line between defines");
                    }
                }
            }
        }
    }
}



CppDefinesVerifier cppDefinesVerifierInstance;
