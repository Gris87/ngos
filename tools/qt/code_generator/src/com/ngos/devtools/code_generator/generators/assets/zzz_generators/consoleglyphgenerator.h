#ifndef CODE_GENERATOR_SRC_COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_ASSETS_ZZZ_GENERATORS_CONSOLEGLYPHGENERATOR_H
#define CODE_GENERATOR_SRC_COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_ASSETS_ZZZ_GENERATORS_CONSOLEGLYPHGENERATOR_H



#include "src/com/ngos/devtools/code_generator/generators/assets/assetsgenerator.h"



class ConsoleGlyphGenerator: public AssetsGenerator
{
public:
    ConsoleGlyphGenerator(); // TEST: NO

    bool generate(const QString &path) override; // TEST: NO
};



#endif // CODE_GENERATOR_SRC_COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_ASSETS_ZZZ_GENERATORS_CONSOLEGLYPHGENERATOR_H
