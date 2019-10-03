#ifndef CODE_GENERATOR_SRC_GENERATORS_ASSETS_ZZZ_GENERATORS_GUIGLYPHGENERATOR_H
#define CODE_GENERATOR_SRC_GENERATORS_ASSETS_ZZZ_GENERATORS_GUIGLYPHGENERATOR_H



#include "src/generators/assets/assetsgenerator.h"



class GuiGlyphGenerator: public AssetsGenerator
{
public:
    GuiGlyphGenerator(); // TEST: NO

    bool generate(const QString &path) override; // TEST: NO
};



#endif // CODE_GENERATOR_SRC_GENERATORS_ASSETS_ZZZ_GENERATORS_GUIGLYPHGENERATOR_H
