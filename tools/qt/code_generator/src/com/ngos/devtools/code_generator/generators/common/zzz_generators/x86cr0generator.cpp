#include "x86cr0generator.h"

#include <QFile>
#include <QRegularExpression>

#include <com/ngos/devtools/shared/console/console.h>



#define ORIGINAL_FILE_PATH "/src/os/shared/common/src/com/ngos/shared/common/cpu/lib/registers/x86cr0flags.h"
#define FILE_PATH          "/src/os/shared/common/src/com/ngos/shared/common/cpu/lib/generated/x86cr0.h"




X86Cr0Generator::X86Cr0Generator()
    : CommonGenerator()
{
    // Nothing
}

bool X86Cr0Generator::generate(const QString &path)
{
    QStringList originalLines;

    // Read lines from original file
    {
        QFile file(path + ORIGINAL_FILE_PATH);

        if (!file.open(QIODevice::ReadOnly))
        {
            Console::err(QString("Failed to open file: %1")
                                    .arg(path + ORIGINAL_FILE_PATH)
            );

            return false;
        }

        originalLines = QString::fromUtf8(file.readAll()).split('\n');
        file.close();
    }



    QStringList lines;

    // Iterate over original file lines and parse them
    {
        QRegularExpression regexp("^ *(\\w+)( *)= *(\\(1ULL *<< *\\d+\\)),? *(//.*)$"); // PROTECTED_MODE_ENABLE = (1ULL << 0),  // If 1, system is in protected mode, else system is in real mode

        for (qint64 i = 0; i < originalLines.size(); ++i)
        {
            QString originalLine = originalLines.at(i).trimmed();

            QRegularExpressionMatch match = regexp.match(originalLine);

            if (match.hasMatch())
            {
                QString name    = match.captured(1);
                QString spaces  = match.captured(2);
                QString value   = match.captured(3);
                QString comment = match.captured(4);

                if (name.startsWith('_'))
                {
                    name.remove(0, 1);
                    spaces.append(' ');
                }

                comment = comment.left(comment.indexOf("//", 2)).trimmed();

                lines.append(QString("#define X86_CR0_%1%2%3%4")
                                        .arg(name)
                                        .arg(spaces)
                                        .arg(value, -13, QChar(' '))
                                        .arg(comment)
                );
            }
        }
    }



    return save(path + FILE_PATH, lines);
}



X86Cr0Generator x86Cr0GeneratorInstance;
