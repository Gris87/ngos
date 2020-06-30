#ifndef CODE_GENERATOR_SRC_GENERATORS_COMMON_ZZZ_GENERATORS_NUMBERDECIMALSGENERATOR_H
#define CODE_GENERATOR_SRC_GENERATORS_COMMON_ZZZ_GENERATORS_NUMBERDECIMALSGENERATOR_H



#include "src/generators/common/commongenerator.h"



class NumberDecimalsGenerator: public CommonGenerator
{
public:
    NumberDecimalsGenerator(); // TEST: NO

    bool generate(const QString &path) override; // TEST: NO
};



#endif // CODE_GENERATOR_SRC_GENERATORS_COMMON_ZZZ_GENERATORS_NUMBERDECIMALSGENERATOR_H
