#ifndef CODE_GENERATOR_SRC_GENERATORS_COMMON_ZZZ_GENERATORS_CPUBUGSNAMESGENERATOR_H
#define CODE_GENERATOR_SRC_GENERATORS_COMMON_ZZZ_GENERATORS_CPUBUGSNAMESGENERATOR_H



#include "src/generators/common/commongenerator.h"



class CpuBugsNamesGenerator: public CommonGenerator
{
public:
    CpuBugsNamesGenerator(); // TEST: NO

    bool generate(const QString &path) override; // TEST: NO
};



#endif // CODE_GENERATOR_SRC_GENERATORS_COMMON_ZZZ_GENERATORS_CPUBUGSNAMESGENERATOR_H
