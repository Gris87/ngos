#ifndef COM_NGOS_BOOTLOADER_TOOLS_CPUTEST_MAIN_CPUTEST_H
#define COM_NGOS_BOOTLOADER_TOOLS_CPUTEST_MAIN_CPUTEST_H



#include <com/ngos/bootloader_tools/cputest/other/cacheinfo.h>
#include <com/ngos/shared/common/ngos/status.h>



class CpuTest
{
public:
    static NgosStatus init(); // TEST: NO

    static const CacheInfo& getLevel1DataCache(); // TEST: NO
    static const CacheInfo& getLevel1InstructionCache(); // TEST: NO
    static const CacheInfo& getLevel2Cache(); // TEST: NO
    static const CacheInfo& getLevel3Cache(); // TEST: NO
    static bad_uint64 getCpuSpeed(); // TEST: NO

private:
    static NgosStatus initCpuCaches(); // TEST: NO
    static NgosStatus initCpuCachesIntel(); // TEST: NO
    static NgosStatus initCpuCachesAmd(); // TEST: NO
    static NgosStatus initCpuCache(CacheInfo *cache, bad_uint32 size, bad_uint8 numberOfWays); // TEST: NO
    static NgosStatus initCpuSpeed(); // TEST: NO

    static CacheInfo sLevel1DataCache;
    static CacheInfo sLevel1InstructionCache;
    static CacheInfo sLevel2Cache;
    static CacheInfo sLevel3Cache;
    static bad_uint64       sCpuSpeed;
};



#endif // COM_NGOS_BOOTLOADER_TOOLS_CPUTEST_MAIN_CPUTEST_H
