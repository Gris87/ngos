#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICACHECONFIGURATION_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICACHECONFIGURATION_H



#include <common/src/bits64/dmi/entry/lib/dmicachelocation.h>
#include <common/src/bits64/dmi/entry/lib/dmicacheoperationalmode.h>



struct DmiCacheConfiguration
{
    u16 __reserved:      6;
    u16 operationalMode: 2; // TODO: Use enum DmiCacheOperationalMode
    u16 enabled:         1;
    u16 location:        2; // TODO: Use enum DmiCacheLocation
    u16 __reserved2:     1;
    u16 socketed:        1;
    u16 level:           3;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICACHECONFIGURATION_H
