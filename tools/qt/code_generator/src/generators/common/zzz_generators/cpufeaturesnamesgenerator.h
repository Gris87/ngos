#ifndef CODE_GENERATOR_SRC_GENERATORS_COMMON_ZZZ_GENERATORS_CPUFEATURESNAMESGENERATOR_H
#define CODE_GENERATOR_SRC_GENERATORS_COMMON_ZZZ_GENERATORS_CPUFEATURESNAMESGENERATOR_H



#include "src/generators/common/commongenerator.h"



class CpuFeaturesNamesGenerator: public CommonGenerator
{
public:
    CpuFeaturesNamesGenerator(); // TEST: NO

    bool generate(const QString &path) override; // TEST: NO
};



#endif // CODE_GENERATOR_SRC_GENERATORS_COMMON_ZZZ_GENERATORS_CPUFEATURESNAMESGENERATOR_H
