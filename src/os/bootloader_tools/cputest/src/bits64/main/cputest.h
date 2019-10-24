#ifndef CPUTEST_SRC_BITS64_MAIN_CPUTEST_H
#define CPUTEST_SRC_BITS64_MAIN_CPUTEST_H



#include <ngos/status.h>

#include "src/bits64/other/cacheinfo.h"



class CpuTest
{
public:
    static NgosStatus init(); // TEST: NO

private:
    static NgosStatus initCpuCaches(); // TEST: NO
};



#endif // CPUTEST_SRC_BITS64_MAIN_CPUTEST_H
