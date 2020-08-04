#ifndef COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_CONFIGURE_ZZZ_GENERATORS_ASMOFFSETSGENERATOR_H
#define COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_CONFIGURE_ZZZ_GENERATORS_ASMOFFSETSGENERATOR_H



#include <com/ngos/devtools/code_generator/generators/configure/configuregenerator.h>



class AsmOffsetsGenerator: public ConfigureGenerator
{
public:
    AsmOffsetsGenerator(); // TEST: NO

    bool generate(const QString &path) override; // TEST: NO
};



#endif // COM_NGOS_DEVTOOLS_CODE_GENERATOR_GENERATORS_CONFIGURE_ZZZ_GENERATORS_ASMOFFSETSGENERATOR_H
