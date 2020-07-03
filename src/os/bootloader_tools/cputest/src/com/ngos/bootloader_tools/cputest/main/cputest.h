#ifndef CPUTEST_SRC_COM_NGOS_BOOTLOADER_TOOLS_CPUTEST_MAIN_CPUTEST_H
#define CPUTEST_SRC_COM_NGOS_BOOTLOADER_TOOLS_CPUTEST_MAIN_CPUTEST_H



#include <com/ngos/shared/common/ngos/status.h>

#include "com/ngos/bootloader_tools/cputest/other/cacheinfo.h"



class CpuTest
{
public:
    static NgosStatus init(); // TEST: NO

    static const CacheInfo& getLevel1DataCache(); // TEST: NO
    static const CacheInfo& getLevel1InstructionCache(); // TEST: NO
    static const CacheInfo& getLevel2Cache(); // TEST: NO
    static const CacheInfo& getLevel3Cache(); // TEST: NO
    static u64 getCpuSpeed(); // TEST: NO

private:
    static NgosStatus initCpuCaches(); // TEST: NO
    static NgosStatus initCpuCachesIntel(); // TEST: NO
    static NgosStatus initCpuCachesAmd(); // TEST: NO
    static NgosStatus initCpuCache(CacheInfo *cache, u32 size, u8 numberOfWays); // TEST: NO
    static NgosStatus initCpuSpeed(); // TEST: NO

    static CacheInfo sLevel1DataCache;
    static CacheInfo sLevel1InstructionCache;
    static CacheInfo sLevel2Cache;
    static CacheInfo sLevel3Cache;
    static u64       sCpuSpeed;
};



#endif // CPUTEST_SRC_COM_NGOS_BOOTLOADER_TOOLS_CPUTEST_MAIN_CPUTEST_H
