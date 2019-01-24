#include "cpufeaturesnamesgenerator.h"

#include <QFile>
#include <QRegularExpression>
#include <console/console.h>



#define ORIGINAL_FILE_PATH "/src/os/common/src/bits64/cpu/cpufeatures.h"
#define FILE_PATH          "/src/os/common/src/bits64/cpu/generated/cpufeaturesnames.h"



CpuFeaturesNamesGenerator::CpuFeaturesNamesGenerator()
    : CommonGenerator()
{
    // Nothing
}

bool CpuFeaturesNamesGenerator::generate(const QString &path)
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
    QStringList features;

    for (qint64 i = 0; i < originalLines.length(); ++i)
    {
        QString originalLine = originalLines.at(i).trimmed();

        if (originalLine.startsWith("#define AMOUNT_OF_WORDS_FOR_X86_FEATURES"))
        {
            bool ok;

            amountOfWords = originalLine.mid(41).trimmed().toLongLong(&ok);

            if (!ok)
            {
                Console::err(QString("Failed to get amount of words from string: %1").arg(originalLine));

                return false;
            }
        }
        else
        if (originalLine.contains("WORD_BIT(") && !originalLine.startsWith("#define WORD_BIT("))
        {
            features.append(originalLine);
        }
    }



    if (amountOfWords <= 0)
    {
        Console::err("Failed to get amount of words");

        return false;
    }



    QStringList lines;

    lines.append("#include <ngos/status.h>");
    lines.append("#include <src/bits64/cpu/cpufeatures.h>");
    lines.append("#include <src/bits64/log/assert.h>");
    lines.append("#include <src/bits64/log/log.h>");

    addThreeBlankLines(lines);



    lines.append("extern const char* cpuFeaturesNames[AMOUNT_OF_WORDS_FOR_X86_FEATURES << 5]; // cpuFeaturesNames declared in cpu.cpp file // \"<< 5\" == \"* 32\"");
    addThreeBlankLines(lines);



    // Ignore CppAlignmentVerifier [BEGIN]
    lines.append("inline NgosStatus initCpuFeaturesNames() // TEST: NO");
    lines.append(QString('{'));
    lines.append("    COMMON_LT((\"\"));");
    addThreeBlankLines(lines);
    // Ignore CppAlignmentVerifier [END]



    QRegularExpression regexp("^ *(\\w+) *= *WORD_BIT\\((\\w+), *(\\d+)\\),?(?: *\\/\\/[^\"]*\"([^\"]*)\")?.*$");

    QStringList wordBlock;



    qint64  currentWord      = 0;
    qint64  lastFeatureIndex = 0;
    QString lastFeatureWord  = "";

    while (lastFeatureIndex < features.length())
    {
        QString feature = features.at(lastFeatureIndex);



        QRegularExpressionMatch match = regexp.match(feature);

        if (!match.hasMatch())
        {
            Console::err(QString("Feature declaration is invalid: %1").arg(feature));

            return false;
        }



        QString featureName    = match.captured(1).toLower();
        QString featureWord    = match.captured(2);
        QString featureBit     = match.captured(3);
        QString featureAltName = match.captured(4);

        if (!featureAltName.isNull())
        {
            featureName = featureAltName;
        }
        else
        {
            if (featureName.startsWith('_'))
            {
                featureName.remove(0, 1);
            }
        }



        bool ok;

        qint64 bit = featureBit.toLongLong(&ok);

        if (!ok)
        {
            Console::err(QString("Feature declaration is invalid: %1").arg(feature));

            return false;
        }

        if (bit < 0 || bit >= 32)
        {
            Console::err(QString("bit is invalid for feature: %1").arg(feature));

            return false;
        }



        if (featureWord != lastFeatureWord)
        {
            if (lastFeatureWord != "")
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

            lastFeatureWord = featureWord;



            wordBlock.clear();

            for (qint64 i = 0; i < 32; ++i)
            {
                wordBlock.append(QString("    cpuFeaturesNames[WORD_BIT(%1, %2)] %3 \"\";").arg(featureWord).arg(i).arg('=', i > 9 ? 1 : 2, QChar(' ')));
            }
        }



        wordBlock[bit] = QString("    cpuFeaturesNames[WORD_BIT(%1, %2)] %3 \"%4\";").arg(featureWord).arg(bit).arg('=', bit > 9 ? 1 : 2, QChar(' ')).arg(featureName);



        ++lastFeatureIndex;
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
        Console::err("List of features is invalid");

        return false;
    }



    return save(path + FILE_PATH, lines);
}



CpuFeaturesNamesGenerator cpuFeaturesNamesGeneratorInstance;
