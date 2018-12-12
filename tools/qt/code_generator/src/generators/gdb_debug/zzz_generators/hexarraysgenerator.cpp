#include "hexarraysgenerator.h"



#define FILE_PATH "/src/generated/hexarrays.h"



HexArraysGenerator::HexArraysGenerator()
    : GdbDebugGenerator()
{
    // Nothing
}

bool HexArraysGenerator::generate(const QString &path)
{
    QStringList lines;



    lines.append("#include <QString>");



    addThreeBlankLines(lines);



    lines.append("QString hexArray[] =");
    lines.append(QString('{'));

    for (qint64 i = 0; i <= 0xFF; ++i)
    {
        QString line = QString("    \"%1\"").arg(i, 2, 16, QChar('0')).toUpper();

        if (i < 0xFF)
        {
            line.append(',');
        }

        lines.append(line);
    }

    lines.append("};");



    addThreeBlankLines(lines);



    lines.append("QChar charArray[] =");
    lines.append(QString('{'));

    for (qint64 i = 0; i <= 0xFF; ++i)
    {
        char ch;

        if (i >= 0x20 && i < 0x7F)
        {
            ch = i;
        }
        else
        {
            ch = '.';
        }



        QString line = "    '";

        if (
            ch == '\''
            ||
            ch == '\"'
            ||
            ch == '\\'
           )
        {
            line.append('\\');
        }

        line.append(ch);
        line.append('\'');

        if (i < 0xFF)
        {
            line.append(',');
        }

        line.append(QString("%1 // 0x%2").arg(QChar(' '), 11 - line.length(), QChar(' ')).arg(QString("%1").arg(i, 2, 16, QChar('0')).toUpper()));



        lines.append(line);
    }

    lines.append("};");



    return save(path + FILE_PATH, lines);
}



HexArraysGenerator hexArraysGeneratorInstance;
