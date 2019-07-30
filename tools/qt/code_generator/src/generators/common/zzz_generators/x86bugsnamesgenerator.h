#ifndef CODE_GENERATOR_SRC_GENERATORS_COMMON_ZZZ_GENERATORS_X86BUGSNAMESGENERATOR_H
#define CODE_GENERATOR_SRC_GENERATORS_COMMON_ZZZ_GENERATORS_X86BUGSNAMESGENERATOR_H



#include "src/generators/common/commongenerator.h"



class X86BugsNamesGenerator: public CommonGenerator
{
public:
    X86BugsNamesGenerator(); // TEST: NO

    bool generate(const QString &path) override; // TEST: NO
};



#endif // CODE_GENERATOR_SRC_GENERATORS_COMMON_ZZZ_GENERATORS_X86BUGSNAMESGENERATOR_H
