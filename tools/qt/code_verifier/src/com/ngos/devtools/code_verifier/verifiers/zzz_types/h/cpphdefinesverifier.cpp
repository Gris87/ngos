#include "cpphdefinesverifier.h"

#include <QDir>
#include <QFile>

#include <com/ngos/devtools/code_verifier/other/codeverificationfiletype.h>



CppHDefinesVerifier::CppHDefinesVerifier()
    : BaseCodeVerifier(CodeVerificationFileType::H)
{
    // Nothing
}

void CppHDefinesVerifier::verify(CodeWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    qint64 fileHeaderOffset = 0;

    while (fileHeaderOffset < lines.size() && lines.at(fileHeaderOffset).startsWith("//"))
    {
        ++fileHeaderOffset;
    }



    if (lines.size() < 5 + fileHeaderOffset)
    {
        worker->addError(path, -1, "Header file contains too few lines");

        return;
    }



    QString relativePath;



    qint64 index = path.indexOf("/include/");

    if (index >= 0)
    {
        relativePath = path.mid(index + 9);
    }
    else
    {
        index = path.indexOf("/shared/");

        if (index >= 0)
        {
            index = path.indexOf('/', index + 8);

            if (index < 0)
            {
                worker->addError(path, -1, "Failed to get relative path");

                return;
            }



            index = path.indexOf('/', index + 1);

            if (index < 0)
            {
                worker->addError(path, -1, "Failed to get relative path");

                return;
            }



            relativePath = path.mid(index + 1);
        }
        else
        {
            QString parentFolder = path;

            do
            {
                index = parentFolder.lastIndexOf('/');

                if (index < 0)
                {
                    worker->addError(path, -1, "Failed to get relative path");

                    return;
                }

                parentFolder = parentFolder.left(index);



                if (
                    QFile::exists(parentFolder + "/../../Makefile")
                    ||
                    !QDir(parentFolder + "/../../").entryList(QStringList() << "*.pro", QDir::Files).isEmpty()
                   )
                {
                    break;
                }
            } while(true);



            index = parentFolder.lastIndexOf('/');

            if (index < 0)
            {
                worker->addError(path, -1, "Failed to get relative path");

                return;
            }

            relativePath = path.mid(index + 1);
        }
    }



    QString defineName = relativePath.toUpper().replace('.', '_').replace('/', '_');

    if (lines.at(fileHeaderOffset + 0) != "#ifndef " + defineName)
    {
        worker->addError(path, 0, QString("Expected \"#ifndef %1\"")
                                            .arg(defineName)
                         );
    }

    if (lines.at(fileHeaderOffset + 1) != "#define " + defineName)
    {
        worker->addError(path, 1, QString("Expected \"#define %1\"")
                                            .arg(defineName)
                         );
    }

    if (lines.at(lines.size() - 2) != "#endif // " + defineName)
    {
        worker->addError(path, lines.size() - 2, QString("Expected \"#endif // %1\"")
                                                            .arg(defineName)
                         );
    }

    if (
        lines.at(fileHeaderOffset + 2) != ""
        ||
        lines.at(fileHeaderOffset + 3) != ""
        ||
        lines.at(fileHeaderOffset + 4) != ""
       )
    {
        worker->addError(path, 2, QString("Expected 3 blank lines after \"#define %1\"")
                                            .arg(defineName)
                         );
    }

    if (
        lines.at(lines.size() - 3) != ""
        ||
        lines.at(lines.size() - 4) != ""
        ||
        lines.at(lines.size() - 5) != ""
       )
    {
        worker->addError(path, lines.size() - 3, QString("Expected 3 blank lines before \"#endif // %1\"")
                                                            .arg(defineName)
                         );
    }
}



CppHDefinesVerifier cppHDefinesVerifierInstance;
