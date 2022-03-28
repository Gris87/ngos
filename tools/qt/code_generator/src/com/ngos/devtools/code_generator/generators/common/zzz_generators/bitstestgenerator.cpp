#include "bitstestgenerator.h"

#include <QCryptographicHash>
#include <QDir>
#include <QFile>

#include <com/ngos/devtools/shared/console/console.h>



const char8 *BitsTestGenerator::sFieldShortcuts = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%&*+-()[]";



BitsTestGenerator::BitsTestGenerator()
    : CommonGenerator()
    , mDefinitionRegExp("^(?:struct|class|union|enum(?: class)?) +(\\w+).*$") // struct A ; class B; union C ; enum class D
    , mBitsDefinitionRegExp("^ *\\w+ +(\\w+) *: *(\\d+);.*$")                 // i64 a: 5;
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

    for (qint64 i = 0; i < bits.size(); ++i)
    {
        lines.append(QString("#include <%1>")
                                .arg(bits.at(i).includePath)
        );
    }

    lines.sort();

    addThreeBlankLines(lines);



    lines.append("#if NGOS_BUILD_TEST_MODE == OPTION_YES");

    addThreeBlankLines(lines);



    lines.append("TEST_CASES(section0, generated_com_ngos_shared_common_types);");
    lines.append("{"); // Ignore CppSingleCharVerifier

    for (qint64 i = 0; i < bits.size(); ++i)
    {
        const BitsStructure &structure = bits.at(i);



        // Ignore CppAlignmentVerifier [BEGIN]
        lines.append(QString("    TEST_CASE(\"%1\");")
                                .arg(structure.name)
        );
        lines.append("    {");
        // Ignore CppAlignmentVerifier [END]



        lines.append(QString("        %1 temp;")
                                .arg(structure.name)
        );

        addThreeBlankLines(lines);

        lines.append(QString("        // %1:")
                                .arg(structure.name)
        );



        lines.append("        //");

        if (!addBitsStructureLines(lines, structure))
        {
            Console::err("Failed to add bits structure");

            return false;
        }

        lines.append("        //");



        qint64 maximumFieldLength = 0;

        for (qint64 j = 0; j < structure.fields.size(); ++j)
        {
            qint64 fieldLength = structure.fields.at(j).name.length();

            if (fieldLength > maximumFieldLength)
            {
                maximumFieldLength = fieldLength;
            }
        }



        for (qint64 j = 0; j < structure.fields.size(); ++j)
        {
            const BitsField &field = structure.fields.at(j);

            lines.append(QString("        // %1 : %2 '%3'")
                                    .arg(field.name, -maximumFieldLength)
                                    .arg(field.length, -2)
                                    .arg(sFieldShortcuts[j])
            );
        }

        addThreeBlankLines(lines);



        QCryptographicHash hash(QCryptographicHash::Md5);
        hash.addData(structure.name.toUtf8());

        qint64 value = *((qint64 *)hash.result().data());



        if (structure.width < 64)
        {
            value = value & ((1ULL << structure.width) - 1);
        }



        if (!addBitsStructureLines(lines, structure, true, value))
        {
            Console::err("Failed to add bits structure");

            return false;
        }

        lines.append(QString("        temp.value%1 = 0x%2;")
                                .arg(structure.width)
                                .arg(QString::number(value, 16).toUpper(), structure.width / 4, QChar('0'))
        );
        lines.append("");



        qint8 offset = 0;

        for (qint64 j = 0; j < structure.fields.size(); ++j)
        {
            const BitsField &field = structure.fields.at(j);



            lines.append(QString("        TEST_ASSERT_EQUALS(temp.%1, %2%3);")
                                    .arg(field.name)
                                    .arg("", maximumFieldLength - field.name.length())
                                    .arg((value >> offset) & ((1ULL << field.length) - 1))
            );

            offset += field.length;
        }



        addThreeBlankLines(lines);



        offset = 0;

        for (qint64 j = 0; j < structure.fields.size(); ++j)
        {
            const BitsField &field = structure.fields.at(j);



            value           ^= ((1ULL << field.length) - 1) << offset;
            qint64 newValue =  (value >> offset) & ((1ULL << field.length) - 1);

            offset += field.length;



            if (!addBitsStructureLines(lines, structure, true, value))
            {
                Console::err("Failed to add bits structure");

                return false;
            }



            lines.append(QString("        temp.%1 = %2;")
                                    .arg(field.name)
                                    .arg(newValue)
            );
            lines.append("");
            lines.append(QString("        TEST_ASSERT_EQUALS(temp.value%1, 0x%2);")
                                    .arg(structure.width)
                                    .arg(QString::number(value, 16).toUpper(), structure.width / 4, QChar('0'))
            );



            if (j < structure.fields.size() - 1)
            {
                addThreeBlankLines(lines);
            }
        }



        lines.append("    }");
        lines.append("    TEST_CASE_END();");



        if (i < bits.size() - 1)
        {
            addThreeBlankLines(lines);
        }
    }

    lines.append("}"); // Ignore CppSingleCharVerifier
    lines.append("TEST_CASES_END();");



    addThreeBlankLines(lines);

    lines.append("#endif");



    return save(destinationFilePath, lines);
}

bool BitsTestGenerator::addBitsStructureLines(QStringList &lines, const BitsStructure &structure, bool useValue, qint64 value)
{
    QString     contentLine     = "|"; // Ignore CppSingleCharVerifier
    qint8       remainingLength = 8;
    qint8       offset          = structure.width;

    for (qint64 i = structure.fields.size() - 1; i >= 0; --i)
    {
        const BitsField &field = structure.fields.at(i);



        QString fieldContent;

        if (useValue)
        {
            offset -= field.length;

            fieldContent = QString("%1")
                                    .arg((value >> offset) & ((1ULL << field.length) - 1), field.length, 2, QChar('0'));
        }
        else
        {
            fieldContent = QString(field.length, QChar(sFieldShortcuts[i]));
        }



        while (fieldContent.length() > remainingLength)
        {
            if (remainingLength > 0)
            {
                qint8 freeSpaceLength = remainingLength * 3 - 1;

                QString spaces(structure.width  > 8 ? freeSpaceLength       / 2 : 1, ' ');
                QString spaces2(structure.width > 8 ? (freeSpaceLength + 1) / 2 : 1, ' ');

                contentLine.append(spaces);
                contentLine.append(fieldContent.left(remainingLength));
                contentLine.append(spaces2);
                contentLine.append("|"); // Ignore CppSingleCharVerifier

                fieldContent = fieldContent.mid(remainingLength);
            }

            lines.append(QString("        // %1")
                                    .arg(contentLine)
            );

            contentLine     = "|"; // Ignore CppSingleCharVerifier
            remainingLength = 8;
        }



        qint8 freeSpaceLength = fieldContent.length() * 3 - 1;

        QString spaces(structure.width  > 8 ? freeSpaceLength       / 2 : 1, ' ');
        QString spaces2(structure.width > 8 ? (freeSpaceLength + 1) / 2 : 1, ' ');

        contentLine.append(spaces);
        contentLine.append(fieldContent.left(remainingLength));
        contentLine.append(spaces2);
        contentLine.append("|"); // Ignore CppSingleCharVerifier

        remainingLength -= fieldContent.length();
    }

    lines.append(QString("        // %1")
                            .arg(contentLine)
    );



    return true;
}

bool BitsTestGenerator::obtainBitsFromFolder(const QString &path, QList<BitsStructure> &bits)
{
    QFileInfoList files = QDir(path).entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);

    for (qint64 i = 0; i < files.size(); ++i)
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

    for (qint64 i = 0; i < lines.size(); ++i)
    {
        lines[i] = lines.at(i).trimmed();
    }



    for (qint64 i = 0; i < lines.size(); ++i)
    {
        QString line = lines.at(i);

        QRegularExpressionMatch match = mDefinitionRegExp.match(line);

        if (match.hasMatch())
        {
            BitsStructure structure;

            qint8 totalLength = 0;



            qint64 level = 0;
            qint64 j     = i;

            do
            {
                ++j;

                if (j >= lines.size())
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
                    field.length = match2.captured(2).toShort(&ok);

                    if (
                        !ok
                        ||
                        field.length <= 0
                        ||
                        field.length >= 64
                       )
                    {
                        Console::err(QString("Failed to parse bits length in line: %1")
                                                .arg(anotherLine)
                        );

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
                        Console::err(QString("Failed to get relative path for \"%1\"")
                                                .arg(path)
                        );

                        return false;
                    }

                    parentFolder = parentFolder.left(index);



                    if (
                        QFile::exists(parentFolder + "/../../../Makefile")
                        ||
                        !QDir(parentFolder + "/../../../").entryList(QStringList() << "*.pro", QDir::Files).isEmpty()
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
                    Console::err(QString("Failed to get value attribute for structure %1")
                                            .arg(structure.name)
                    );

                    return false;
                }



                if (structure.width != totalLength)
                {
                    Console::err(QString("Total length of bits doesn't match to bits width for structure %1")
                                            .arg(structure.name)
                    );

                    return false;
                }



                bits.append(structure);
            }
        }
    }



    return true;
}



BitsTestGenerator bitsTestGeneratorInstance;
