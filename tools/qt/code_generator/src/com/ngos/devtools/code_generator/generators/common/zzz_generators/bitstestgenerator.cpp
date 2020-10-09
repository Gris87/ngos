#include "bitstestgenerator.h"

#include <QDir>

#include <com/ngos/devtools/shared/console/console.h>



BitsTestGenerator::BitsTestGenerator()
    : CommonGenerator()
{
    // Nothing
}

bool BitsTestGenerator::generate(const QString &path)
{
    return generateTests(path + "/src/os/shared", path + "/src/os/shared/uefibase/test/com/ngos/shared/uefibase/sections/section0/generated/com/ngos/shared/common/types.h");
}

bool BitsTestGenerator::generateTests(const QString &path, const QString &destinationFilePath)
{
    QList<BitsTestMetadata> bits;

    if (!obtainBitsFromFolder(path, bits))
    {
        Console::err("Failed to get structures with bits");

        return false;
    }



    QStringList lines;

    lines.append("#include <buildconfig.h>");
    lines.append("#include <com/ngos/shared/uefibase/testengine.h>");

    addThreeBlankLines(lines);



    lines.append("#if NGOS_BUILD_TEST_MODE == OPTION_YES");

    addThreeBlankLines(lines);



    lines.append("TEST_CASES(section0, generated_com_ngos_shared_common_types);");
    lines.append("{"); // Ignore CppSingleCharVerifier
    lines.append("}"); // Ignore CppSingleCharVerifier
    lines.append("TEST_CASES_END();");



    addThreeBlankLines(lines);

    lines.append("#endif");



    return save(destinationFilePath, lines);
}

bool BitsTestGenerator::obtainBitsFromFolder(const QString &path, QList<BitsTestMetadata> &bits)
{
    QFileInfoList files = QDir(path).entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);

    for (qint64 i = 0; i < files.length(); ++i)
    {
        QFileInfo file = files.at(i);

        QString fileName = file.fileName();

        if (file.isDir())
        {
            if (!obtainBitsFromFolder(path + '/' + fileName, bits))
            {
                return false;
            }
        }
        else
        {
            if (fileName.endsWith(".h"))
            {
                if (!obtainBitsFromFile(path + '/' + fileName, bits))
                {
                    return false;
                }
            }
        }
    }

    return true;
}

bool BitsTestGenerator::obtainBitsFromFile(const QString &path, QList<BitsTestMetadata> &bits)
{
    Console::err(path);
    Console::err(QString::number(bits.length()));



    return true;
}



BitsTestGenerator bitsTestGeneratorInstance;
