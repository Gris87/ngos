#include "cpubugsnamesgenerator.h"

#include <QFile>
#include <QRegularExpression>
#include <console/console.h>



#define ORIGINAL_FILE_PATH "/src/os/common/src/bits64/cpu/cpubugs.h"
#define FILE_PATH          "/src/os/common/src/bits64/cpu/generated/cpubugsnames.h"



CpuBugsNamesGenerator::CpuBugsNamesGenerator()
    : CommonGenerator()
{
    // Nothing
}

bool CpuBugsNamesGenerator::generate(const QString &path)
{
    QFile file(path + ORIGINAL_FILE_PATH);

    if (!file.open(QIODevice::ReadOnly))
    {
        Console::err(QString("Failed to open file: %1").arg(path + ORIGINAL_FILE_PATH));

        return false;
    }

    QStringList originalLines = QString::fromUtf8(file.readAll()).split('\n');
    file.close();



    qint64      amountOfWords = 0;
    QStringList bugs;

    for (qint64 i = 0; i < originalLines.length(); ++i)
    {
        QString originalLine = originalLines.at(i).trimmed();

        if (originalLine.startsWith("#define AMOUNT_OF_WORDS_FOR_X86_BUGS"))
        {
            bool ok;

            amountOfWords = originalLine.mid(37).trimmed().toLongLong(&ok);

            if (!ok)
            {
                Console::err(QString("Failed to get amount of words from string: %1").arg(originalLine));

                return false;
            }
        }
        else
        if (originalLine.contains("WORD_BIT(") && !originalLine.startsWith("#define WORD_BIT("))
        {
            bugs.append(originalLine);
        }
    }



    if (amountOfWords <= 0)
    {
        Console::err("Failed to get amount of words");

        return false;
    }



    QStringList lines;

    lines.append("#include <ngos/status.h>");
    lines.append("#include <src/bits64/cpu/cpubugs.h>");
    lines.append("#include <src/bits64/log/assert.h>");
    lines.append("#include <src/bits64/log/log.h>");

    addThreeBlankLines(lines);



    lines.append("extern const char* cpuBugsNames[AMOUNT_OF_WORDS_FOR_X86_BUGS << 5]; // cpuBugsNames declared in cpu.cpp file // \"<< 5\" == \"* 32\"");
    addThreeBlankLines(lines);



    // Ignore CppAlignmentVerifier [BEGIN]
    lines.append("inline NgosStatus initCpuBugsNames() // TEST: NO");
    lines.append(QString('{'));
    lines.append("    COMMON_LT((\"\"));");
    addThreeBlankLines(lines);
    // Ignore CppAlignmentVerifier [END]



    QRegularExpression regexp("^ *(\\w+) *= *WORD_BIT\\((\\w+), *(\\d+)\\),?(?: *\\/\\/[^\"]*\"([^\"]*)\")?.*$");

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
                wordBlock.append(QString("    cpuBugsNames[WORD_BIT(%1, %2)] %3 \"\";").arg(bugWord).arg(i).arg('=', i > 9 ? 1 : 2, QChar(' ')));
            }
        }



        wordBlock[bit] = QString("    cpuBugsNames[WORD_BIT(%1, %2)] %3 \"%4\";").arg(bugWord).arg(bit).arg('=', bit > 9 ? 1 : 2, QChar(' ')).arg(bugName);



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
    ++currentWord;

    addThreeBlankLines(lines);
    lines.append("    return NgosStatus::OK;");
    lines.append(QString('}'));
    // Ignore CppAlignmentVerifier [END]



    if (currentWord != amountOfWords)
    {
        Console::err("List of bugs is invalid");

        return false;
    }



    return save(path + FILE_PATH, lines);
}



CpuBugsNamesGenerator cpuBugsNamesGeneratorInstance;
