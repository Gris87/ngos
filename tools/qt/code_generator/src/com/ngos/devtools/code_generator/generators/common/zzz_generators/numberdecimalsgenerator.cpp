#include "numberdecimalsgenerator.h"                                                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <QFile>                                                                                                                                                                                         // Colorize: green
#include <QRegularExpression>                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/devtools/shared/console/console.h>                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define FILE_PATH "/src/os/shared/common/src/com/ngos/shared/common/string/generated/numberdecimals.cpp"                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NumberDecimalsGenerator::NumberDecimalsGenerator()                                                                                                                                                         // Colorize: green
    : CommonGenerator()                                                                                                                                                                                  // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // Nothing                                                                                                                                                                                           // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
bool NumberDecimalsGenerator::generate(const QString &path)                                                                                                                                               // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    QStringList lines;                                                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Add include lines                                                                                                                                                                                 // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        lines.append("#include \"numberdecimals.h\"");                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        addThreeBlankLines(lines);                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    qint64 decimalIndecies[995];                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Generate numberDecimalsFull string and calculate decimalIndecies                                                                                                                                   // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        QString lastNumber;                                                                                                                                                                              // Colorize: green
        qint64  curIndex = -3;                                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        lines.append("const char8* numberDecimalsFull =");                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        for (qint64 i = 5; i < 995; ++i) // Skip first 5 since "i / 1000" gives zero, up to 995 since qRound(995 / 1000) gives one                                                                    // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            QString number = QString::number(qRound(i / 10.0)); // "/ 10.0" == "* 100 / 1000"                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (number.length() == 1)                                                                                                                                                                    // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                number = '0' + number;                                                                                                                                                                   // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
            else                                                                                                                                                                                         // Colorize: green
            if (number.endsWith('0'))                                                                                                                                                                    // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                number.replace(1, 1, "\\0");                                                                                                                                                             // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (number != lastNumber)                                                                                                                                                                    // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                lastNumber = number;                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                lines.append(QString("    \".%1\" // %2")                                                                                                                                                // Colorize: green
                                        .arg(number)                                                                                                                                                     // Colorize: green
                                        .arg(i)                                                                                                                                                          // Colorize: green
                );                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                curIndex += 3;                                                                                                                                                                           // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            decimalIndecies[i] = curIndex;                                                                                                                                                               // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        lines.append(";"); // Ignore CppSingleCharVerifier                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        addThreeBlankLines(lines);                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Generate bytesDecimals                                                                                                                                                                            // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        lines.append("const char8* numberDecimals[995] =");                                                                                                                                              // Colorize: green
        lines.append("{"); // Ignore CppSingleCharVerifier                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        for (qint64 i = 0; i < 995; ++i)                                                                                                                                                                // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            if (i < 5)                                                                                                                                                                                   // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                lines.append(QString("    \"\", // %1")                                                                                                                                                  // Colorize: green
                                        .arg(i)                                                                                                                                                          // Colorize: green
                );                                                                                                                                                                                       // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
            else                                                                                                                                                                                         // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                lines.append(QString("    &numberDecimalsFull[%1]%2 // %3")                                                                                                                               // Colorize: green
                                        .arg(decimalIndecies[i])                                                                                                                                         // Colorize: green
                                        .arg(i < 995 ? "," : "") // Ignore CppSingleCharVerifier                                                                                                        // Colorize: green
                                        .arg(i)                                                                                                                                                          // Colorize: green
                );                                                                                                                                                                                       // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        lines.append("};");                                                                                                                                                                              // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return save(path + FILE_PATH, lines);                                                                                                                                                                // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
NumberDecimalsGenerator numberDecimalsGeneratorInstance;                                                                                                                                                 // Colorize: green
