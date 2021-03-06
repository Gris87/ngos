#include "cppblockorderverifier.h"

#include <com/ngos/devtools/code_verifier/other/codeverificationfiletype.h>



#define BLOCK_TYPE_NONE     0
#define BLOCK_TYPE_INCLUDES 1
#define BLOCK_TYPE_DEFINES  2
#define BLOCK_TYPE_CODE     3



CppBlockOrderVerifier::CppBlockOrderVerifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
{
    // Nothing
}

void CppBlockOrderVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    qint64 fileHeaderOffset = 0;

    while (fileHeaderOffset < lines.size() && lines.at(fileHeaderOffset).startsWith("//"))
    {
        ++fileHeaderOffset;
    }



    QList<QStringList> blocks;
    QList<qint64>      blockStarts;
    QList<quint8>      blockTypes;
    QStringList        currentBlock;
    qint64             currentBlockStart = -1;
    quint8             currentBlockType  = BLOCK_TYPE_NONE;



    for (qint64 i = 0; i < lines.size(); ++i)
    {
        QString line = lines.at(i);



        quint8 blockType = currentBlockType;

        if (line.startsWith("#include "))
        {
            blockType = BLOCK_TYPE_INCLUDES;
        }
        else
        if (line.startsWith("#define "))
        {
            if (
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
                blockType = BLOCK_TYPE_DEFINES;
            }
        }
        else
        if (
            line.startsWith("/*")
            &&
            !line.endsWith("*/")
           )
        {
            do
            {
                ++i;

                if (i >= lines.size())
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
            line != ""
            &&
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
            if (
                !
                (
                 blockType == BLOCK_TYPE_DEFINES
                 &&
                 i > 0
                 &&
                 lines.at(i - 1).endsWith(" \\")
                )
               )
            {
                blockType = BLOCK_TYPE_CODE;
            }
        }



        if (currentBlockType != blockType)
        {
            if (!currentBlock.isEmpty())
            {
                blocks.append(currentBlock);
                blockStarts.append(currentBlockStart);
                blockTypes.append(currentBlockType);

                currentBlock.clear();
            }

            currentBlockType  = blockType;
            currentBlockStart = i;
        }

        if (currentBlockType != BLOCK_TYPE_NONE)
        {
            currentBlock.append(line);
        }
    }

    if (!currentBlock.isEmpty())
    {
        blocks.append(currentBlock);
        blockStarts.append(currentBlockStart);
        blockTypes.append(currentBlockType);
    }



    for (qint64 i = 1; i < blocks.size(); ++i)
    {
        QStringList block = blocks.at(i - 1);

        while (
               !block.isEmpty()
               &&
               (
                block.constLast().startsWith("//")
                ||
                block.constLast().startsWith("#if")
                ||
                block.constLast().startsWith("#else")
                ||
                block.constLast().startsWith("#elif")
                ||
                block.constLast().startsWith("#endif")
               )
              )
        {
            block.removeLast();
        }

        if (
            block.size() < 4
            ||
            block.at(block.size() - 1) != ""
            ||
            block.at(block.size() - 2) != ""
            ||
            block.at(block.size() - 3) != ""
            ||
            block.at(block.size() - 4) == ""
           )
        {
            worker->addError(path, blockStarts.at(i), "Blocks should be separated by 3 blank lines");
        }
    }

    for (qint64 i = 1; i < blockTypes.size(); ++i)
    {
        if (blockTypes.at(i - 1) > blockTypes.at(i))
        {
            worker->addError(path, blockStarts.at(i), "Invalid order of code blocks");
        }
    }
}



CppBlockOrderVerifier cppBlockOrderVerifierInstance;
