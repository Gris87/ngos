#include "qtincludesverifier.h"

#include <QDir>
#include <QFile>

#include "src/other/codeverificationfiletype.h"



QtIncludesVerifier::QtIncludesVerifier()
    : BaseCodeVerifier(VerificationFileType::INCLUDES)
{
    // Nothing
}

void QtIncludesVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    QString parentFolder = path.left(path.lastIndexOf('/') + 1);



    QStringList block;

    for (qint64 i = 0; i < lines.length(); ++i)
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
                    !line.contains("src/os/shared/")
                    &&
                    !line.contains("build/gen/")
                    &&
                    !QFile::exists(parentFolder + '/' + line + "/Makefile")
                    &&
                    !QDir(parentFolder + '/' + line).entryList(QStringList() << "*.pro", QDir::Files).length() // QDir(parentFolder + '/' + line).entryList(QStringList() << "*.pro", QDir::Files).length() == 0
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
        worker->addWarning(path, -1, "Includes should be sorted");
    }



    QStringList blockTarget;

    blockTarget.append("3rd_party/libs/freetype/include/");
    blockTarget.append("include/");
    blockTarget.append("include/stdinc/");

    addSubfoldersWithMakefile(blockTarget, parentFolder, "src/apps");
    addSubfoldersWithMakefile(blockTarget, parentFolder, "src/libs");
    addSubfoldersWithMakefile(blockTarget, parentFolder, "src/os");

    addSubfoldersWithQtPro(blockTarget, parentFolder, "tools/qt");

    blockTarget.sort();



    if (block != blockTarget)
    {
        worker->addWarning(path, -1, QString("Expecting the following list of includes:\n%1").arg(blockTarget.join('\n')));
    }
}

void QtIncludesVerifier::addSubfoldersWithMakefile(QStringList &block, const QString &parentFolder, const QString &path)
{
    QStringList subfolders = QDir(parentFolder + '/' + path).entryList(QDir::Dirs | QDir::NoDotAndDotDot);

    for (qint64 i = 0; i < subfolders.length(); ++i)
    {
        QString subfolder     = subfolders.at(i);
        QString subfolderPath = path + '/' + subfolder;

        QFile makeFile(parentFolder + '/' + subfolderPath + "/Makefile");



        if (
            subfolder == "include"
            ||
            subfolder == "shared"
            ||
            makeFile.exists()
           )
        {
            block.append(subfolderPath + '/');
        }
    }
}

void QtIncludesVerifier::addSubfoldersWithQtPro(QStringList &block, const QString &parentFolder, const QString &path)
{
    QStringList subfolders = QDir(parentFolder + '/' + path).entryList(QDir::Dirs | QDir::NoDotAndDotDot);

    for (qint64 i = 0; i < subfolders.length(); ++i)
    {
        QString subfolder     = subfolders.at(i);
        QString subfolderPath = path + '/' + subfolder;

        QFile proFile(parentFolder + '/' + subfolderPath + '/' + subfolder + ".pro");



        if (
            subfolder == "include"
            ||
            proFile.exists()
           )
        {
            block.append(subfolderPath + '/');

            if (subfolder != "include")
            {
                if (proFile.open(QIODevice::ReadOnly))
                {
                    if (proFile.readAll().contains("QT += core gui widgets"))
                    {
                        block.append(subfolderPath + "/build/gen/");
                    }

                    proFile.close();
                }
            }
        }
    }
}



QtIncludesVerifier qtIncludesVerifierInstance;
