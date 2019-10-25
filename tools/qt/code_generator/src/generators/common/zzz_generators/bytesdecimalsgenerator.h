#ifndef CODE_GENERATOR_SRC_GENERATORS_COMMON_ZZZ_GENERATORS_BYTESDECIMALSGENERATOR_H
#define CODE_GENERATOR_SRC_GENERATORS_COMMON_ZZZ_GENERATORS_BYTESDECIMALSGENERATOR_H



#include "src/generators/common/commongenerator.h"



class BytesDecimalsGenerator: public CommonGenerator
{
public:
    BytesDecimalsGenerator(); // TEST: NO

    bool generate(const QString &path) override; // TEST: NO
};



#endif // CODE_GENERATOR_SRC_GENERATORS_COMMON_ZZZ_GENERATORS_BYTESDECIMALSGENERATOR_H
