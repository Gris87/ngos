#include "x86bugsnamesgenerator.h"

#include <QFile>
#include <QRegularExpression>

#include <com/ngos/devtools/shared/console/console.h>



#define ORIGINAL_FILE_PATH "/src/os/shared/common/src/com/ngos/shared/common/cpu/x86bug.h"
#define FILE_PATH          "/src/os/shared/common/src/com/ngos/shared/common/cpu/generated/x86bugsnames.cpp"



X86BugsNamesGenerator::X86BugsNamesGenerator()
    : CommonGenerator()
{
    // Nothing
}

bool X86BugsNamesGenerator::generate(const QString &path)
{
    QFile file(path + ORIGINAL_FILE_PATH);

    if (!file.open(QIODevice::ReadOnly))
    {
        Console::err(QString("Failed to open file: %1").arg(path + ORIGINAL_FILE_PATH));

        return false;
    }

    QStringList originalLines = QString::fromUtf8(file.readAll()).split('\n');
    file.close();



    QStringList bugs;

    for (qint64 i = 0; i < originalLines.length(); ++i)
    {
        QString originalLine = originalLines.at(i).trimmed();

        if (originalLine.contains("WORD_BIT("))
        {
            bugs.append(originalLine);
        }
    }



    QStringList lines;

    lines.append("#include \"x86bugsnames.h\"");
    addOneBlankLine(lines);
    lines.append("#include <com/ngos/shared/common/log/assert.h>");
    lines.append("#include <com/ngos/shared/common/log/log.h>");
    lines.append("#include <com/ngos/shared/common/ngos/utils.h>");

    addThreeBlankLines(lines);



    lines.append("const char8* x86BugsNames[(u64)x86BugWord::MAXIMUM * 32];");
    addThreeBlankLines(lines);



    // Ignore CppAlignmentVerifier [BEGIN]
    lines.append("NgosStatus initX86BugsNames()");
    lines.append(QString('{'));
    lines.append("    COMMON_LT((\"\"));");
    addThreeBlankLines(lines);
    // Ignore CppAlignmentVerifier [END]



    QRegularExpression regexp("^ *(\\w+) *= *WORD_BIT\\(([\\w:]+), *(\\d+)\\),?(?: *\\/\\/[^\"]*\"([^\"]*)\")?.*$");

    QStringList wordBlock;



    qint64  currentWord  = 0;
    qint64  lastBugIndex = 0;
    QString lastBugWord  = "";

    while (lastBugIndex < bugs.length())
    {
        QString bug = bugs.at(lastBugIndex);



        QRegularExpressionMatch match = regexp.match(bug);

        if (!match.hasMatch())
        {
            Console::err(QString("Bug declaration is invalid: %1").arg(bug));

            return false;
        }



        QString bugName    = match.captured(1).toLower();
        QString bugWord    = match.captured(2);
        QString bugBit     = match.captured(3);
        QString bugAltName = match.captured(4);

        if (!bugAltName.isNull())
        {
            bugName = bugAltName;
        }
        else
        {
            if (bugName.startsWith('_'))
            {
                bugName.remove(0, 1);
            }
        }



        bool ok;

        qint64 bit = bugBit.toLongLong(&ok);

        if (!ok)
        {
            Console::err(QString("Bug declaration is invalid: %1").arg(bug));

            return false;
        }

        if (bit < 0 || bit >= 32)
        {
            Console::err(QString("bit is invalid for bug: %1").arg(bug));

            return false;
        }



        if (bugWord != lastBugWord)
        {
            if (lastBugWord != "")
            {
                if (currentWord > 0)
                {
                    addOneBlankLine(lines);
                }

                lines.append(QString("    // word %1").arg(currentWord));
                addOneBlankLine(lines);

                lines.append(wordBlock);
                ++currentWord;
            }

            lastBugWord = bugWord;



            wordBlock.clear();

            for (qint64 i = 0; i < 32; ++i)
            {
                wordBlock.append(QString("    x86BugsNames[WORD_BIT(%1, %2)] %3 \"\";").arg(bugWord).arg(i).arg('=', i > 9 ? 1 : 2, QChar(' ')));
            }
        }



        wordBlock[bit] = QString("    x86BugsNames[WORD_BIT(%1, %2)] %3 \"%4\";").arg(bugWord).arg(bit).arg('=', bit > 9 ? 1 : 2, QChar(' ')).arg(bugName);



        ++lastBugIndex;
    }



    // Ignore CppAlignmentVerifier [BEGIN]
    if (currentWord > 0)
    {
        addOneBlankLine(lines);
    }

    lines.append(QString("    // word %1").arg(currentWord));
    addOneBlankLine(lines);

    lines.append(wordBlock);

    addThreeBlankLines(lines);
    lines.append("    return NgosStatus::OK;");
    lines.append(QString('}'));
    // Ignore CppAlignmentVerifier [END]



    return save(path + FILE_PATH, lines);
}



X86BugsNamesGenerator x86BugsNamesGeneratorInstance;
