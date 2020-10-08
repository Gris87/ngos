#include "bitstestgenerator.h"

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
    QList<BitsTestMetadata> bits = obtainBits(path);



    QStringList lines;



    return save(destinationFilePath, lines);
}

QList<BitsTestMetadata> BitsTestGenerator::obtainBits(const QString &path)
{
    QList<BitsTestMetadata> res;

    Console::err(path);

    return res;
}

bool BitsTestGenerator::obtainBitsFromFile(const QString &path, QList<BitsTestMetadata> &bits)
{
    Console::err(path);
    Console::err(QString::number(bits.length()));



    return true;
}



BitsTestGenerator bitsTestGeneratorInstance;
