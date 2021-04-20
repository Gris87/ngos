#include "qtincludesverifier.h"

#include <QDir>
#include <QFile>

#include <com/ngos/devtools/code_verifier/other/codeverificationfiletype.h>



QtIncludesVerifier::QtIncludesVerifier()
    : BaseCodeVerifier(CodeVerificationFileType::INCLUDES)
{
    // Nothing
}

void QtIncludesVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    QString parentFolder = path.left(path.lastIndexOf('/') + 1);



    QStringList block;

    for (qint64 i = 0; i < lines.size(); ++i)
    {
        QString line = lines.at(i);

        if (line != "")
        {
            if (line.startsWith("~/"))
            {
                if (!QDir(QDir::homePath() + '/' + line.mid(2)).exists())
                {
                    worker->addWarning(path, i, QString("Path %1 not found").arg(line));
                }
            }
            else
            {
                if (!QDir(parentFolder + '/' + line).exists())
                {
                    worker->addWarning(path, i, QString("Path %1 not found").arg(line));
                }
            }



            if (!line.startsWith("~/Qt/"))
            {
                block.append(line);

                if (
                    !line.contains("include/")
                    &&
                    !line.endsWith("/src/")
                    &&
                    !line.endsWith("/test/")
                    &&
                    !line.endsWith("/build/gen/")
                   )
                {
                    worker->addWarning(path, i, "Invalid path included");
                }
            }
        }
    }



    QStringList blockOriginal = block;
    block.sort();

    if (block != blockOriginal)
    {
        worker->addWarning(path, -1, QString("Includes should be sorted:\n%1").arg(block.join('\n')));
    }



    QStringList blockTarget;

    blockTarget.append("3rd_party/libs/freetype/include/");
    blockTarget.append("include/");
    blockTarget.append("include/stdinc/");

    addSubfoldersWithQtPro(blockTarget, parentFolder, "src/apps");
    addSubfoldersWithQtPro(blockTarget, parentFolder, "src/libs");
    addSubfoldersWithQtPro(blockTarget, parentFolder, "src/os");
    addSubfoldersWithQtPro(blockTarget, parentFolder, "src/os/bootloader_tools");
    addSubfoldersWithQtPro(blockTarget, parentFolder, "tools/qt");

    blockTarget.sort();



    if (block != blockTarget)
    {
        worker->addWarning(path, -1, QString("Expecting the following list of includes:\n%1").arg(blockTarget.join('\n')));
    }
}

void QtIncludesVerifier::addSubfoldersWithQtPro(QStringList &block, const QString &parentFolder, const QString &path)
{
    QStringList subfolders = QDir(parentFolder + '/' + path).entryList(QDir::Dirs | QDir::NoDotAndDotDot);

    for (qint64 i = 0; i < subfolders.size(); ++i)
    {
        QString subfolder     = subfolders.at(i);
        QString subfolderPath = path + '/' + subfolder;

        QFile proFile(parentFolder + '/' + subfolderPath + '/' + subfolder + ".pro");



        if (proFile.exists())
        {
            if (QDir(parentFolder + '/' + subfolderPath + "/src").exists())
            {
                block.append(subfolderPath + "/src/");
            }

            if (QDir(parentFolder + '/' + subfolderPath + "/test").exists())
            {
                block.append(subfolderPath + "/test/");
            }

            if (proFile.open(QIODevice::ReadOnly))
            {
                if (proFile.readAll().contains("QT += core gui widgets"))
                {
                    block.append(subfolderPath + "/build/gen/");
                }

                proFile.close();
            }
        }
        else
        if (subfolder == "shared")
        {
            QStringList sharedSubfolders = QDir(parentFolder + '/' + subfolderPath).entryList(QDir::Dirs | QDir::NoDotAndDotDot);

            for (qint64 j = 0; j < sharedSubfolders.size(); ++j)
            {
                QString sharedSubfolder     = sharedSubfolders.at(j);
                QString sharedSubfolderPath = subfolderPath + '/' + sharedSubfolder;

                if (QDir(parentFolder + '/' + sharedSubfolderPath + "/src").exists())
                {
                    block.append(sharedSubfolderPath + "/src/");
                }

                if (QDir(parentFolder + '/' + sharedSubfolderPath + "/test").exists())
                {
                    block.append(sharedSubfolderPath + "/test/");
                }
            }
        }
    }
}



QtIncludesVerifier qtIncludesVerifierInstance;
