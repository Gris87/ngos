#include "x86featuresnamesgenerator.h"

#include <QFile>
#include <QRegularExpression>

#include <com/ngos/devtools/shared/console/console.h>



#define ORIGINAL_FILE_PATH "/src/os/shared/common/src/com/ngos/shared/common/cpu/x86feature.h"
#define FILE_PATH          "/src/os/shared/common/src/com/ngos/shared/common/cpu/generated/x86featuresnames.cpp"



X86FeaturesNamesGenerator::X86FeaturesNamesGenerator()
    : CommonGenerator()
{
    // Nothing
}

bool X86FeaturesNamesGenerator::generate(const QString &path)
{
    QFile file(path + ORIGINAL_FILE_PATH);

    if (!file.open(QIODevice::ReadOnly))
    {
        Console::err(QString("Failed to open file: %1").arg(path + ORIGINAL_FILE_PATH));

        return false;
    }

    QStringList originalLines = QString::fromUtf8(file.readAll()).split('\n');
    file.close();



    QStringList features;

    for (qint64 i = 0; i < originalLines.length(); ++i)
    {
        QString originalLine = originalLines.at(i).trimmed();

        if (originalLine.contains("WORD_BIT("))
        {
            features.append(originalLine);
        }
    }



    QStringList lines;

    lines.append("#include \"x86featuresnames.h\"");
    addOneBlankLine(lines);
    lines.append("#include <com/ngos/shared/common/log/assert.h>");
    lines.append("#include <com/ngos/shared/common/log/log.h>");
    lines.append("#include <com/ngos/shared/common/ngos/utils.h>");

    addThreeBlankLines(lines);



    lines.append("const char8* x86FeaturesNames[(u64)x86FeatureWord::MAXIMUM * 32];");
    addThreeBlankLines(lines);



    // Ignore CppAlignmentVerifier [BEGIN]
    lines.append("NgosStatus initX86FeaturesNames()");
    lines.append("{"); // Ignore CppSingleCharVerifier
    lines.append("    COMMON_LT((\"\"));");
    addThreeBlankLines(lines);
    // Ignore CppAlignmentVerifier [END]



    QRegularExpression regexp("^ *(\\w+) *= *WORD_BIT\\(([\\w:]+), *(\\d+)\\),?(?: *\\/\\/[^\"]*\"([^\"]*)\")?.*$");

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
                wordBlock.append(QString("    x86FeaturesNames[WORD_BIT(%1, %2)] %3 \"\";").arg(featureWord).arg(i).arg('=', i > 9 ? 1 : 2, QChar(' ')));
            }
        }



        wordBlock[bit] = QString("    x86FeaturesNames[WORD_BIT(%1, %2)] %3 \"%4\";").arg(featureWord).arg(bit).arg('=', bit > 9 ? 1 : 2, QChar(' ')).arg(featureName);



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

    addThreeBlankLines(lines);
    lines.append("    return NgosStatus::OK;");
    lines.append(QString('}'));
    // Ignore CppAlignmentVerifier [END]



    return save(path + FILE_PATH, lines);
}



X86FeaturesNamesGenerator x86FeaturesNamesGeneratorInstance;
