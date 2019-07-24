#include "qtpriverifier.h"

#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QQueue>

#include "src/other/codeverificationfiletype.h"



QtPriVerifier::QtPriVerifier()
    : BaseCodeVerifier(CodeVerificationFileType::PRI)
{
    // Nothing
}

void QtPriVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
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

    if (sourcesIndex < 0)
    {
        worker->addError(path, -1, "SOURCES definition absent");
    }

    if (headersIndex < 0)
    {
        worker->addError(path, -1, "HEADERS definition absent");
    }
}

qint64 QtPriVerifier::verifyFilesBlock(CodeWorkerThread *worker, const QString &path, const QStringList &lines, qint64 startPos, const QString &extension)
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



    if (block.length()) // block.length() > 0
    {
        for (qint64 i = 0; i < block.length(); ++i)
        {
            QString file = block.at(i);

            if (
                file.length() < 5
                ||
                !file.startsWith("    ")
                ||
                (
                 !file[4].isLetter()
                 &&
                 file[4] != '$'
                )
               )
            {
                worker->addError(path, startPos + i, "Invalid indentation");
            }

            block[i] = file.trimmed();

            if (block.at(i).startsWith("$$PWD/"))
            {
                block[i].remove(0, 6);
            }
            else
            {
                worker->addError(path, startPos + i, "Path should be started with $$PWD/");
            }
        }



        if (extension != "")
        {
            for (qint64 i = 0; i < block.length(); ++i)
            {
                if (!block.at(i).endsWith('.' + extension))
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
            worker->addWarning(path, startPos, "Files should be sorted or duplicates need to remove");
        }



        QQueue<QFileInfo> files;
        files.enqueue(QFileInfo(parentFolder));

        while (!files.isEmpty())
        {
            QFileInfo file = files.dequeue();

            QString filepath = file.absoluteFilePath();
            QString filename = file.fileName();

            if (file.isDir())
            {
                if (filename != ".git")
                {
                    QFileInfoList filesInfo = QDir(filepath).entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);

                    for (qint64 i = 0; i < filesInfo.length(); ++i)
                    {
                        files.enqueue(filesInfo.at(i));
                    }
                }
            }
            else
            {
                if (!filepath.contains("build/gen/"))
                {
                    QString relativePath;

                    if (extension != "")
                    {
                        if (filename.endsWith('.' + extension))
                        {
                            relativePath = filepath.mid(parentFolder.length());
                        }
                    }
                    else
                    {
                        if (
                            !filename.endsWith(".cpp")
                            &&
                            !filename.endsWith(".h")
                            &&
                            !filename.endsWith(".o")
                            &&
                            !filename.endsWith(".pri")
                            &&
                            !filename.endsWith(".pro")
                            &&
                            filename != ".gitignore"
                            &&
                            filename != ".qmake.stash"
                            &&
                            filename != "Makefile"
                           )
                        {
                            relativePath = filepath.mid(parentFolder.length());
                        }
                    }



                    if (relativePath != "")
                    {
                        if (!block.contains(relativePath))
                        {
                            worker->addError(path, startPos, QString("File absent: $$PWD/%1").arg(relativePath));
                        }
                    }
                }
            }
        }
    }
    else
    {
        worker->addError(path, startPos, "Atleast one file should be specified");
    }



    return block.length();
}



QtPriVerifier qtPriVerifierInstance;
