#include "bitstestgenerator.h"

#include <com/ngos/devtools/shared/console/console.h>



BitsTestGenerator::BitsTestGenerator()
    : CommonGenerator()
{
    // Nothing
}

bool BitsTestGenerator::generate(const QString &path)
{
    return generateTests(path, path);
}

bool BitsTestGenerator::generateTests(const QString &path, const QString &fileName)
{
    Console::err(path);
    Console::err(fileName);



    return true;
}



BitsTestGenerator bitsTestGeneratorInstance;
