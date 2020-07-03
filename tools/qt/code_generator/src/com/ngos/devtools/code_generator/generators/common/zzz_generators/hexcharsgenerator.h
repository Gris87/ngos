#ifndef CODE_GENERATOR_SRC_COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_COMMON_ZZZ_GENERATORS_HEXCHARSGENERATOR_H
#define CODE_GENERATOR_SRC_COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_COMMON_ZZZ_GENERATORS_HEXCHARSGENERATOR_H



#include "com/ngos/devtools/code_generator/generators/common/commongenerator.h"



class HexCharsGenerator: public CommonGenerator
{
public:
    HexCharsGenerator(); // TEST: NO

    bool generate(const QString &path) override; // TEST: NO
};



#endif // CODE_GENERATOR_SRC_COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_COMMON_ZZZ_GENERATORS_HEXCHARSGENERATOR_H
