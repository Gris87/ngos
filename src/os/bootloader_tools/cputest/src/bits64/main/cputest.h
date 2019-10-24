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
    static NgosStatus initCpuCache(CacheInfo *cache, u32 size, u8 numberOfWays); // TEST: NO

    static CacheInfo sLevel1DataCache;
    static CacheInfo sLevel1InstructionCache;
    static CacheInfo sLevel2Cache;
    static CacheInfo sLevel3Cache;
};



#endif // CPUTEST_SRC_BITS64_MAIN_CPUTEST_H
