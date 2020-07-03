#include "qtproverifier.h"

#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QQueue>

#include "com/ngos/devtools/code_verifier/other/codeverificationfiletype.h"



// Ignore CppAlignmentVerifier [BEGIN]
#define WARNINGS_AS_ERRORS \
    "# Warnings as errors - BEGIN\n" \
    "win32-msvc* {\n" \
    "    QMAKE_CXXFLAGS += /WX\n" \
    "} else {\n" \
    "    QMAKE_CXXFLAGS += -Werror\n" \
    "}\n" \
    "# Warnings as errors - END\n"



#define RELEASE_OPTIMIZATION \
    "# Release optimization - BEGIN\n" \
    "QMAKE_CFLAGS_RELEASE -= -O1\n" \
    "QMAKE_CFLAGS_RELEASE -= -O2\n" \
    "QMAKE_CFLAGS_RELEASE += -O3\n" \
    "\n" \
    "QMAKE_CXXFLAGS_RELEASE -= -O1\n" \
    "QMAKE_CXXFLAGS_RELEASE -= -O2\n" \
    "QMAKE_CXXFLAGS_RELEASE += -O3\n" \
    "# Release optimization - END\n"



#define TARGET_DIRS \
    "# Target dirs - BEGIN\n" \
    "DESTDIR     = build/\n" \
    "OBJECTS_DIR = build/gen\n" \
    "MOC_DIR     = build/gen\n" \
    "RCC_DIR     = build/gen\n" \
    "UI_DIR      = build/gen\n" \
    "# Target dirs - END\n"
// Ignore CppAlignmentVerifier [END]



QtProVerifier::QtProVerifier()
    : BaseCodeVerifier(CodeVerificationFileType::PRO)
{
    // Nothing
}

void QtProVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &content, const QStringList &lines)
{
    if (path.contains("/tools/qt/") && !path.endsWith("/tools/qt/qt.pro"))
    {
        verifyDefinitions(worker, path, content);
    }

    verifyFileBlocks(worker, path, lines);
}

void QtProVerifier::verifyDefinitions(CodeWorkerThread *worker, const QString &path, const QString &content)
{
    if (!content.contains(WARNINGS_AS_ERRORS))
    {
        worker->addError(path, -1, "Warnings as errors definition absent");
    }

    if (!content.contains(RELEASE_OPTIMIZATION))
    {
        worker->addError(path, -1, "Release optimization definition absent");
    }

    if (!content.contains(TARGET_DIRS))
    {
        worker->addError(path, -1, "Target dirs definition absent");
    }
}

void QtProVerifier::verifyFileBlocks(CodeWorkerThread *worker, const QString &path, const QStringList &lines)
{
    qint64 sourcesIndex   = -1;
    qint64 headersIndex   = -1;
    qint64 formsIndex     = -1;
    qint64 distFilesIndex = -1;

    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);

        if (line.startsWith("SOURCES"))
        {
            if (sourcesIndex < 0)
            {
                sourcesIndex = i;
            }
            else
            {
                worker->addError(path, i, "SOURCES was specified already");
            }

            if (line == "SOURCES += \\")
            {
                i += verifyFilesBlock(worker, path, lines, i + 1, "cpp");
            }
            else
            {
                worker->addError(path, i, "Unexpected SOURCES definition");
            }
        }
        else
        if (line.startsWith("HEADERS"))
        {
            if (headersIndex < 0)
            {
                headersIndex = i;
            }
            else
            {
                worker->addError(path, i, "HEADERS was specified already");
            }

            if (line == "HEADERS += \\")
            {
                i += verifyFilesBlock(worker, path, lines, i + 1, QString('h'));
            }
            else
            {
                worker->addError(path, i, "Unexpected HEADERS definition");
            }
        }
        else
        if (line.startsWith("FORMS"))
        {
            if (formsIndex < 0)
            {
                formsIndex = i;
            }
            else
            {
                worker->addError(path, i, "FORMS was specified already");
            }

            if (line == "FORMS += \\")
            {
                i += verifyFilesBlock(worker, path, lines, i + 1, "ui");
            }
            else
            {
                worker->addError(path, i, "Unexpected FORMS definition");
            }
        }
        else
        if (line.startsWith("DISTFILES"))
        {
            if (distFilesIndex < 0)
            {
                distFilesIndex = i;
            }
            else
            {
                worker->addError(path, i, "DISTFILES was specified already");
            }

            if (line == "DISTFILES += \\")
            {
                i += verifyFilesBlock(worker, path, lines, i + 1, "");
            }
            else
            {
                worker->addError(path, i, "Unexpected DISTFILES definition");
            }
        }
    }
}

qint64 QtProVerifier::verifyFilesBlock(CodeWorkerThread *worker, const QString &path, const QStringList &lines, qint64 startPos, const QString &extension)
{
    QStringList block;

    for (qint64 i = startPos; i < lines.length(); ++i)
    {
        QString line = lines.at(i);

        if (line.endsWith('\\'))
        {
            if (line.endsWith(" \\"))
            {
                block.append(line.left(line.length() - 2));
            }
            else
            {
                worker->addWarning(path, i, "Space character expected before \\");

                block.append(line.left(line.length() - 1));
            }
        }
        else
        {
            if (line.trimmed() != "")
            {
                block.append(line);
            }
            else
            {
                worker->addError(path, i, "Invalid file specification");
            }

            break;
        }
    }



    if (block.length() > 0)
    {
        for (qint64 i = 0; i < block.length(); ++i)
        {
            QString file = block.at(i);

            if (
                file.length() < 5
                ||
                !file.startsWith("    ")
                ||
                !file[4].isLetter()
               )
            {
                worker->addError(path, startPos + i, "Invalid indentation");
            }

            block[i] = file.trimmed();
        }



        bool cppExtension = (extension == "cpp");

        if (extension != "")
        {
            for (qint64 i = 0; i < block.length(); ++i)
            {
                if (
                    !block.at(i).endsWith('.' + extension)
                    &&
                    (
                     !cppExtension
                     ||
                     !block.at(i).endsWith(".S")
                    )
                   )
                {
                    worker->addError(path, startPos + i, "Invalid file extension");
                }
            }
        }



        QString parentFolder = path.left(path.lastIndexOf('/') + 1);

        for (qint64 i = 0; i < block.length(); ++i)
        {
            if (!QFile::exists(parentFolder + '/' + block.at(i)))
            {
                worker->addError(path, startPos + i, "File not found");
            }
        }



        QStringList blockOriginal = block;
        block.sort();
        block.removeDuplicates();

        if (block != blockOriginal)
        {
            worker->addWarning(path, startPos, QString("Files should be sorted or duplicates need to remove:\n%1").arg(block.join('\n')));
        }



        QQueue<QFileInfo> files;
        files.enqueue(QFileInfo(parentFolder));

        while (!files.isEmpty())
        {
            QFileInfo file = files.dequeue();

            QString filePath = file.absoluteFilePath();
            QString fileName = file.fileName();

            if (file.isDir())
            {
                if (
                    fileName != ".git"
                    &&
                    fileName != "assets"
                    &&
                    fileName != "build"
                   )
                {
                    QFileInfoList filesInfo = QDir(filePath).entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);

                    for (qint64 i = 0; i < filesInfo.length(); ++i)
                    {
                        files.enqueue(filesInfo.at(i));
                    }
                }
            }
            else
            {
                QString relativePath;

                if (extension != "")
                {
                    if (
                        fileName.endsWith('.' + extension)
                        ||
                        (
                         cppExtension
                         &&
                         fileName.endsWith(".S")
                        )
                       )
                    {
                        relativePath = filePath.mid(parentFolder.length());
                    }
                }
                else
                {
                    if (
                        !fileName.endsWith(".cpp")
                        &&
                        !fileName.endsWith(".h")
                        &&
                        !fileName.endsWith(".S")
                        &&
                        !fileName.endsWith(".o")
                        &&
                        !fileName.endsWith(".pri")
                        &&
                        !fileName.endsWith(".pro")
                        &&
                        fileName != ".gitignore"
                        &&
                        fileName != ".qmake.stash"
                        &&
                        fileName != "Makefile"
                       )
                    {
                        relativePath = filePath.mid(parentFolder.length());
                    }
                }



                if (relativePath != "")
                {
                    if (!block.contains(relativePath))
                    {
                        worker->addError(path, startPos, QString("File absent: %1").arg(relativePath));
                    }
                }
            }
        }
    }
    else
    {
        worker->addError(path, startPos, "At least one file should be specified");
    }



    return block.length();
}



QtProVerifier qtProVerifierInstance;
