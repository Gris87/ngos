#include "bytesdecimalsgenerator.h"

#include <QFile>
#include <QRegularExpression>

#include <com/ngos/devtools/shared/console/console.h>



#define FILE_PATH "/src/os/shared/common/src/com/ngos/shared/common/string/generated/bytesdecimals.cpp"



BytesDecimalsGenerator::BytesDecimalsGenerator()
    : CommonGenerator()
{
    // Nothing
}

bool BytesDecimalsGenerator::generate(const QString &path)
{
    QStringList lines;



    lines.append("#include \"bytesdecimals.h\"");

    addThreeBlankLines(lines);



    QString lastNumber;
    qint64  decimalIndecies[1019];
    qint64  curIndex = -3;



    lines.append("const char8* bytesDecimalsFull =");

    for (qint64 i = 6; i < 1019; ++i) // Skip first 6 since "i / 1024" gives zero, up to 1019 since qRound(1019 / 1024) gives one
    {
        QString number = QString::number(qRound(i / 10.240)); // "/ 10.240" == "* 100 / 1024"

        if (number.length() == 1)
        {
            number = '0' + number;
        }
        else
        if (number.endsWith('0'))
        {
            number.replace(1, 1, "\\nullptr");
        }



        if (number != lastNumber)
        {
            lastNumber = number;

            lines.append(QString("    \".%1\" // %2").arg(number).arg(i));

            curIndex += 3;
        }



        decimalIndecies[i] = curIndex;
    }

    lines.append(";"); // Ignore CppSingleCharVerifier

    addThreeBlankLines(lines);



    lines.append("const char8* bytesDecimals[1019] =");
    lines.append("{"); // Ignore CppSingleCharVerifier

    for (qint64 i = 0; i < 1019; ++i)
    {
        if (i < 6)
        {
            lines.append(QString("    \"\", // %1").arg(i));
        }
        else
        {
            lines.append(QString("    &bytesDecimalsFull[%1]%2 // %3").arg(decimalIndecies[i]).arg(i < 1019 ? "," : "").arg(i)); // Ignore CppSingleCharVerifier
        }
    }

    lines.append("};");



    return save(path + FILE_PATH, lines);
}



BytesDecimalsGenerator bytesDecimalsGeneratorInstance;
