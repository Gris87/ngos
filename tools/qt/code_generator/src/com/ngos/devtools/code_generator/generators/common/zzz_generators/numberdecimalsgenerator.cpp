#include "numberdecimalsgenerator.h"

#include <QFile>
#include <QRegularExpression>

#include <com/ngos/devtools/shared/console/console.h>



#define FILE_PATH "/src/os/shared/common/src/com/ngos/shared/common/string/generated/numberdecimals.cpp"



NumberDecimalsGenerator::NumberDecimalsGenerator()
    : CommonGenerator()
{
    // Nothing
}

bool NumberDecimalsGenerator::generate(const QString &path)
{
    QStringList lines;



    lines.append("#include \"numberdecimals.h\"");

    addThreeBlankLines(lines);



    QString lastNumber;
    qint64  decimalIndecies[995];
    qint64  curIndex = -3;



    lines.append("const char8* numberDecimalsFull =");

    for (qint64 i = 5; i < 995; ++i) // Skip first 5 since "i / 1000" gives zero, up to 995 since qRound(995 / 1000) gives one
    {
        QString number = QString::number(qRound(i / 10.0)); // "/ 10.0" == "* 100 / 1000"

        if (number.length() == 1)
        {
            number = '0' + number;
        }
        else
        if (number.endsWith('0'))
        {
            number.replace(1, 1, "\\0");
        }



        if (number != lastNumber)
        {
            lastNumber = number;

            lines.append(QString("    \".%1\" // %2")
                                    .arg(number)
                                    .arg(i)
            );

            curIndex += 3;
        }



        decimalIndecies[i] = curIndex;
    }

    lines.append(";"); // Ignore CppSingleCharVerifier

    addThreeBlankLines(lines);



    lines.append("const char8* numberDecimals[995] =");
    lines.append("{"); // Ignore CppSingleCharVerifier

    for (qint64 i = 0; i < 995; ++i)
    {
        if (i < 5)
        {
            lines.append(QString("    \"\", // %1")
                                    .arg(i)
            );
        }
        else
        {
            lines.append(QString("    &numberDecimalsFull[%1]%2 // %3")
                                    .arg(decimalIndecies[i])
                                    .arg(i < 995 ? "," : "") // Ignore CppSingleCharVerifier
                                    .arg(i)
            );
        }
    }

    lines.append("};");



    return save(path + FILE_PATH, lines);
}



NumberDecimalsGenerator numberDecimalsGeneratorInstance;
