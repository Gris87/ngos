#ifndef COM_NGOS_BOOTLOADER_TOOLS_CPUTEST_OTHER_CACHEINFO_H
#define COM_NGOS_BOOTLOADER_TOOLS_CPUTEST_OTHER_CACHEINFO_H



#include <com/ngos/shared/common/ngos/types.h>



struct CacheInfo
{
    bad_uint32 size;
    bad_uint8  numberOfWays;
};



#endif // COM_NGOS_BOOTLOADER_TOOLS_CPUTEST_OTHER_CACHEINFO_H
