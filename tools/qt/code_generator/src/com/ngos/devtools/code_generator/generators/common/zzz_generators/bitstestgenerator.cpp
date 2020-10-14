#include "bitstestgenerator.h"

#include <QDir>
#include <QFile>

#include <com/ngos/devtools/shared/console/console.h>



BitsTestGenerator::BitsTestGenerator()
    : CommonGenerator()
    , mDefinitionRegExp("^(?:struct|class|union|enum(?: class)?) +(\\w+).*$")
    , mBitsDefinitionRegExp("^ *\\w+ +(\\w+) *: *(\\d+);.*$")
{
    // Nothing
}

bool BitsTestGenerator::generate(const QString &path)
{
    return generateTests(path + "/src/os/shared", path + "/src/os/shared/uefibase/test/com/ngos/shared/uefibase/sections/section0/generated/com/ngos/shared/common/types.h");
}

bool BitsTestGenerator::generateTests(const QString &path, const QString &destinationFilePath)
{
    QList<BitsStructure> bits;

    if (!obtainBitsFromFolder(path, bits))
    {
        Console::err("Failed to get structures with bits");

        return false;
    }



    QStringList lines;

    lines.append("#include <buildconfig.h>");
    lines.append("#include <com/ngos/shared/uefibase/testengine.h>");

    for (qint64 i = 0; i < bits.length(); ++i)
    {
        lines.append(QString("#include <%1>").arg(bits.at(i).includePath));
    }

    lines.sort();

    addThreeBlankLines(lines);



    lines.append("#if NGOS_BUILD_TEST_MODE == OPTION_YES");

    addThreeBlankLines(lines);



    lines.append("TEST_CASES(section0, generated_com_ngos_shared_common_types);");
    lines.append("{"); // Ignore CppSingleCharVerifier
    lines.append("}"); // Ignore CppSingleCharVerifier
    lines.append("TEST_CASES_END();");



    addThreeBlankLines(lines);

    lines.append("#endif");



    return save(destinationFilePath, lines);
}

bool BitsTestGenerator::obtainBitsFromFolder(const QString &path, QList<BitsStructure> &bits)
{
    QFileInfoList files = QDir(path).entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);

    for (qint64 i = 0; i < files.length(); ++i)
    {
        QFileInfo file = files.at(i);

        QString fileName = file.fileName();

        if (file.isDir())
        {
            if (!obtainBitsFromFolder(path + '/' + fileName, bits))
            {
                return false;
            }
        }
        else
        {
            if (fileName.endsWith(".h"))
            {
                if (!obtainBitsFromFile(path + '/' + fileName, bits))
                {
                    return false;
                }
            }
        }
    }

    return true;
}

bool BitsTestGenerator::obtainBitsFromFile(const QString &path, QList<BitsStructure> &bits)
{
    if (
        path.contains("/src/os/shared/common/src/com/ngos/shared/common/dmi/entry/lib/dmichassiscontainedelementtype.h")
        ||
        path.contains("/src/os/shared/common/src/com/ngos/shared/common/dmi/entry/lib/dmiprocessorvoltage.h")
       )
    {
        return true;
    }



    QFile file(path);

    if (!file.open(QIODevice::ReadOnly))
    {
        return false;
    }

    QString content = QString::fromUtf8(file.readAll());
    file.close();



    QStringList lines = content.split('\n');

    for (qint64 i = 0; i < lines.length(); ++i)
    {
        lines[i] = lines.at(i).trimmed();
    }



    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);

        QRegularExpressionMatch match = mDefinitionRegExp.match(line);

        if (match.hasMatch())
        {
            BitsStructure structure;

            quint8 totalLength = 0;



            qint64 level = 0;
            qint64 j     = i;

            do
            {
                ++j;

                if (j >= lines.length())
                {
                    break;
                }

                QString anotherLine = lines.at(j);

                if (anotherLine == '{')
                {
                    ++level;
                }
                else
                if (
                    anotherLine == '}'
                    ||
                    anotherLine == "};"
                    ||
                    anotherLine == "} __attribute__((packed));"
                   )
                {
                    --level;

                    if (level <= 0)
                    {
                        break;
                    }
                }



                QRegularExpressionMatch match2 = mBitsDefinitionRegExp.match(anotherLine);

                if (match2.hasMatch())
                {
                    bool ok;



                    BitsField field;

                    field.name   = match2.captured(1);
                    field.length = match2.captured(2).toUShort(&ok);

                    if (
                        !ok
                        ||
                        field.length <= 0
                        ||
                        field.length >= 64
                       )
                    {
                        Console::err(QString("Failed to parse bits length in line: %1").arg(anotherLine));

                        return false;
                    }

                    totalLength += field.length;



                    structure.fields.append(field);
                }
            } while(true);



            if (!structure.fields.isEmpty())
            {
                qint64 index;



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
                        QFile::exists(parentFolder + "/../../../Makefile")
                        ||
                        QDir(parentFolder + "/../../../").entryList(QStringList() << "*.pro", QDir::Files).length() > 0
                       )
                    {
                        break;
                    }
                } while(true);



                structure.name        = match.captured(1);
                structure.includePath = path.mid(index + 1);



                structure.width = 0;

                for (qint64 k = j - 1; k > i; --k)
                {
                    QString anotherLine = lines.at(k);

                    if (anotherLine.contains("value"))
                    {
                        if (anotherLine.contains("value8;"))
                        {
                            structure.width = 8;
                        }
                        else
                        if (anotherLine.contains("value16;"))
                        {
                            structure.width = 16;
                        }
                        else
                        if (anotherLine.contains("value32;"))
                        {
                            structure.width = 32;
                        }
                        else
                        if (anotherLine.contains("value64;"))
                        {
                            structure.width = 64;
                        }

                        break;
                    }
                }

                if (structure.width <= 0)
                {
                    Console::err(QString("Failed to get value attribure for structure %1").arg(structure.name));

                    return false;
                }



                if (structure.width != totalLength)
                {
                    Console::err(QString("Total length of bits doesn't match to bits width for structure %1").arg(structure.name));

                    return false;
                }



                bits.append(structure);
            }
        }
    }



    return true;
}



BitsTestGenerator bitsTestGeneratorInstance;
