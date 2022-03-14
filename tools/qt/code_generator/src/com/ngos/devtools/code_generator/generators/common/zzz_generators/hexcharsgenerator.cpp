#include "hexcharsgenerator.h"

#include <QFile>
#include <QRegularExpression>

#include <com/ngos/devtools/shared/console/console.h>



#define FILE_PATH "/src/os/shared/common/src/com/ngos/shared/common/hex/generated/hexchars.cpp"



HexCharsGenerator::HexCharsGenerator()
    : CommonGenerator()
{
    // Nothing
}

bool HexCharsGenerator::generate(const QString &path)
{
    QStringList lines;



    lines.append("#include <com/ngos/shared/common/hex/hex.h>");

    addThreeBlankLines(lines);



    const char *digits = "0123456789ABCDEF";



    lines.append("u16 Hex::sHexChars[256] =");
    lines.append("{"); // Ignore CppSingleCharVerifier

    for (qint64 i = 0; i < 16; ++i)
    {
        QString line;
        QString comment;

        for (qint64 j = 0; j < 16; ++j)
        {
            if (j > 0)
            {
                line.append(", ");
            }

            line.append(QString("0x%1%2")
                                .arg((quint8)digits[j], 2, 16, QChar('0'))
                                .arg((quint8)digits[i], 2, 16, QChar('0'))
                        );

            comment.append(digits[i]);
            comment.append(digits[j]);
        }

        lines.append(QString("    %1%2 // %3")
                             .arg(line)
                             .arg(i < 15 ? ',' : ' ')
                             .arg(comment)
                     );
    }

    lines.append("};");



    return save(path + FILE_PATH, lines);
}



HexCharsGenerator hexCharsGeneratorInstance;
