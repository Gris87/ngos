#include "generator.h"

#include <QDir>
#include <QFile>

#include <com/ngos/devtools/shared/console/console.h>



Generator::Generator()
{
    // Nothing
}

void Generator::addOneBlankLine(QStringList &lines)
{
    lines.append("");
}

void Generator::addThreeBlankLines(QStringList &lines)
{
    lines.append("");
    lines.append("");
    lines.append("");
}

bool Generator::save(const QString &path, const QStringList &lines)
{
    QString defineName;

    if (path.endsWith(".h"))
    {
        QString relativePath;



        qint64 index = path.indexOf("/include/");

        if (index >= 0)
        {
            relativePath = path.mid(index + 9);
        }
        else
        {
            QString parentFolder = path;

            do
            {
                index = parentFolder.lastIndexOf('/');

                if (index < 0)
                {
                    Console::err(QString("Failed to get relative path for \"%1\"").arg(path));

                    return false;
                }

                parentFolder = parentFolder.left(index);



                if (
                    QFile::exists(parentFolder + "/Makefile")
                    ||
                    QDir(parentFolder).entryList(QStringList() << "*.pro", QDir::Files).length() // QDir(parentFolder).entryList(QStringList() << "*.pro", QDir::Files).length() > 0
                   )
                {
                    break;
                }
            } while(true);



            index = parentFolder.lastIndexOf('/');

            if (index < 0)
            {
                Console::err(QString("Failed to get relative path for \"%1\"").arg(path));

                return false;
            }

            relativePath = path.mid(index + 1);
        }



        defineName = relativePath.toUpper().replace('.', '_').replace('/', '_');
    }



    QStringList resultLines;

    resultLines.append("// This file generated with the code_generator");
    resultLines.append("// Please do not modify it manually");

    if (defineName != "")
    {
        resultLines.append("#ifndef " + defineName);
        resultLines.append("#define " + defineName);
        resultLines.append("");
        resultLines.append("");
        resultLines.append("");
    }

    resultLines.append(lines);

    if (defineName != "")
    {
        resultLines.append("");
        resultLines.append("");
        resultLines.append("");
        resultLines.append("#endif // " + defineName);
    }

    resultLines.append("");



    QString folder = path.left(path.lastIndexOf('/'));

    if (!QDir().mkpath(folder))
    {
        Console::err(QString("Failed to create folder \"%1\" for file \"%2\"").arg(folder).arg(path));

        return false;
    }



    return save(path, resultLines.join('\n').toUtf8());
}

bool Generator::save(const QString &path, const QByteArray &bytes)
{
    QByteArray oldBytes;



    QFile file(path);

    if (
        file.exists()
        &&
        file.size() == bytes.size()
       )
    {
        if (file.open(QIODevice::ReadOnly))
        {
            oldBytes = file.readAll();
            file.close();
        }
    }



    if (bytes != oldBytes)
    {
        if (!file.open(QIODevice::WriteOnly))
        {
            Console::err(QString("Failed to create file \"%1\"").arg(path));

            return false;
        }

        file.write(bytes);
        file.close();



        Console::out(QString("Generated file: %1").arg(path));
    }
    else
    {
        Console::out(QString("Generated file: %1 [up-to-date]").arg(path, -90, QChar(' ')));
    }



    return true;
}
