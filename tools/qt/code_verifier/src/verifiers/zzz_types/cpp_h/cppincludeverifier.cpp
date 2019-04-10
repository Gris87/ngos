#include "cppincludeverifier.h"

#include <QDir>
#include <QFile>

#include "src/other/codeverificationfiletype.h"



#define INCLUDE_BLOCK_TYPE_NONE         0
#define INCLUDE_BLOCK_TYPE_OWN          1
#define INCLUDE_BLOCK_TYPE_LIBRARIES    2
#define INCLUDE_BLOCK_TYPE_PROJECT      3



CppIncludeVerifier::CppIncludeVerifier()
    : BaseCodeVerifier(VERIFICATION_COMMON_CPP)
{
    // Nothing
}

void CppIncludeVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines)
{
    if (
        path.endsWith("_linux.cpp")
        ||
        path.endsWith("_linux.h")
        ||
        path.endsWith("_win.cpp")
        ||
        path.endsWith("_win.h")
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

    for (qint64 i = fileHeaderOffset; i < lines.length(); ++i)
    {
        QString line = lines.at(i);

        if (line.startsWith("#include "))
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
        if (
            startLine == fileHeaderOffset
            ||
            (
             startLine == 5 + fileHeaderOffset
             &&
             (
              lines.at(fileHeaderOffset + 0).startsWith("#ifndef ")
              &&
              lines.at(fileHeaderOffset + 1).startsWith("#define ")
              &&
              lines.at(fileHeaderOffset + 2) == ""
              &&
              lines.at(fileHeaderOffset + 3) == ""
              &&
              lines.at(fileHeaderOffset + 4) == ""
              &&
              lines.at(lines.length() - 2).startsWith("#endif")
             )
            )
           )
        {
            qint64 index = path.lastIndexOf('/');

            if (index < 0)
            {
                worker->addError(path, -1, "Failed to get parent path");

                return;
            }

            QString parentFolder = path.left(index);



            QString projectPath;

            index = path.indexOf("/include/");

            if (index >= 0)
            {
                index = path.indexOf('/', index + 9);

                if (index < 0)
                {
                    worker->addError(path, -1, "Failed to get project path");

                    return;
                }

                projectPath = path.left(index);
            }
            else
            {
                QString tempParentFolder = parentFolder;

                do
                {
                    if (
                        QFile::exists(tempParentFolder + "/Makefile")
                        ||
                        QDir(tempParentFolder).entryList(QStringList() << "*.pro" << "*.pri", QDir::Files).length() // QDir(tempParentFolder).entryList(QStringList() << "*.pro" << "*.pri", QDir::Files).length() > 0
                       )
                    {
                        break;
                    }



                    index = tempParentFolder.lastIndexOf('/');

                    if (index < 0)
                    {
                        worker->addError(path, -1, "Failed to get project path");

                        return;
                    }

                    tempParentFolder = tempParentFolder.left(index);
                } while(true);

                projectPath = tempParentFolder;
            }



            QList<QStringList> blocks;
            QList<qint64>      blockStarts;
            QList<quint8>      blockTypes;
            QStringList        currentBlock;
            qint64             currentBlockStart = -1;
            quint8             currentBlockType  = INCLUDE_BLOCK_TYPE_NONE;



            for (qint64 i = startLine; i <= endLine; ++i)
            {
                QString line = lines.at(i);

                if (line == "")
                {
                    if (currentBlock.length()) // currentBlock.length() > 0
                    {
                        blocks.append(currentBlock);
                        blockStarts.append(currentBlockStart);
                        blockTypes.append(currentBlockType);

                        currentBlock.clear();

                        currentBlockStart = -1;
                        currentBlockType  = INCLUDE_BLOCK_TYPE_NONE;
                    }
                    else
                    {
                        worker->addError(path, i, "Extra line between includes");
                    }
                }
                else
                if (line.startsWith("#include "))
                {
                    if (line != "#include FT_FREETYPE_H")
                    {
                        currentBlock.append(line);

                        if (currentBlockStart < 0)
                        {
                            currentBlockStart = i;
                        }



                        QString includeFile   = line.mid(9).trimmed();
                        bool    globalInclude = includeFile.startsWith('<') && includeFile.endsWith('>');

                        includeFile = includeFile.mid(1, includeFile.length() - 2);



                        quint8 includeType = INCLUDE_BLOCK_TYPE_NONE;



                        QString tempIncludeFile = includeFile;

                        tempIncludeFile = tempIncludeFile.replace(".h", ".cpp");

                        if (
                            path.endsWith(tempIncludeFile)
                            ||
                            (
                             path.endsWith("_linux.cpp")
                             &&
                             QString(path.left(path.length() - 10) + ".cpp").endsWith(tempIncludeFile)
                            )
                            ||
                            (
                             path.endsWith("_win.cpp")
                             &&
                             QString(path.left(path.length() - 8) + ".cpp").endsWith(tempIncludeFile)
                            )
                            ||
                            (
                             tempIncludeFile.startsWith("ui_")
                             &&
                             path.endsWith(tempIncludeFile.mid(3))
                            )
                           )
                        {
                            includeType = INCLUDE_BLOCK_TYPE_OWN;

                            if (includeFile.contains('/'))
                            {
                                worker->addError(path, i, "Should be local file in the same folder");
                            }
                        }
                        else
                        {
                            QString objectName = includeFile.mid(includeFile.lastIndexOf('/') + 1).remove(".h");

                            if (
                                content.contains("public " + objectName, Qt::CaseInsensitive)
                                ||
                                content.contains("protected " + objectName, Qt::CaseInsensitive)
                                ||
                                content.contains("private " + objectName, Qt::CaseInsensitive)
                               )
                            {
                                includeType = INCLUDE_BLOCK_TYPE_OWN;
                            }
                            else
                            {
                                if (QFile::exists(projectPath + '/' + includeFile))
                                {
                                    includeType = INCLUDE_BLOCK_TYPE_PROJECT;

                                    if (
                                        projectPath != parentFolder
                                        &&
                                        QFile::exists(parentFolder + '/' + includeFile)
                                       )
                                    {
                                        worker->addError(path, i, "Don't know what file should be included");
                                    }
                                }
                                else
                                {
                                    if (!globalInclude && QFile::exists(parentFolder + '/' + includeFile))
                                    {
                                        includeType = INCLUDE_BLOCK_TYPE_PROJECT;

                                        worker->addError(path, i, "Should be specified relative path from project root");
                                    }
                                    else
                                    {
                                        includeType = INCLUDE_BLOCK_TYPE_LIBRARIES;

                                        if (!globalInclude)
                                        {
                                            worker->addError(path, i, "Unknown file location");
                                        }
                                    }
                                }
                            }
                        }



                        if (currentBlockType == INCLUDE_BLOCK_TYPE_NONE)
                        {
                            currentBlockType = includeType;
                        }
                        else
                        if (currentBlockType != includeType)
                        {
                            worker->addError(path, i, "Combination of different include types");
                        }
                    }
                }
                else
                {
                    worker->addError(path, i, "Unexpected line between includes");
                }
            }

            if (currentBlock.length()) // currentBlock.length() > 0
            {
                blocks.append(currentBlock);
                blockStarts.append(currentBlockStart);
                blockTypes.append(currentBlockType);
            }



            for (qint64 i = 0; i < blocks.length(); ++i)
            {
                QStringList block = blocks.at(i);

                QStringList blockOriginal = block;
                block.sort();
                block.removeDuplicates();

                if (block != blockOriginal)
                {
                    worker->addWarning(path, blockStarts.at(i), "Includes should be sorted or duplicates need to remove");
                }
            }



            for (qint64 i = 1; i < blockTypes.length(); ++i)
            {
                if (blockTypes.at(i - 1) > blockTypes.at(i))
                {
                    worker->addWarning(path, blockStarts.at(i), "Invalid order of includes");
                }
                else
                if (blockTypes.at(i - 1) == blockTypes.at(i))
                {
                    worker->addWarning(path, blockStarts.at(i), "Includes should be combined");
                }
            }
        }
        else
        {
            worker->addError(path, startLine, "Unexpected #include position");
        }
    }
}



CppIncludeVerifier cppIncludeVerifierInstance;
