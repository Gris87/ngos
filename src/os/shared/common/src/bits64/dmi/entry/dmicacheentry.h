#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMICACHEENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMICACHEENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/dmistringid.h>
#include <common/src/bits64/dmi/entry/lib/dmicacheassociativity.h>
#include <common/src/bits64/dmi/entry/lib/dmicacheconfiguration.h>
#include <common/src/bits64/dmi/entry/lib/dmicacheerrorcorrectiontype.h>
#include <common/src/bits64/dmi/entry/lib/dmicachesize.h>
#include <common/src/bits64/dmi/entry/lib/dmicachesize2.h>
#include <common/src/bits64/dmi/entry/lib/dmicachesramtypeflags.h>
#include <common/src/bits64/dmi/entry/lib/dmicachetype.h>



#define DMI_CACHE_MAXIMUM_CACHE_SIZE_NEED_TO_EXTEND 0xFFFF
#define DMI_CACHE_INSTALLED_SIZE_NO_CACHE           0x0000
#define DMI_CACHE_INSTALLED_SIZE_NEED_TO_EXTEND     0xFFFF
#define DMI_CACHE_CACHE_SPEED_UNKNOWN               0x0000



struct DmiCacheEntry
{
    DmiEntryHeader              header;
    DmiStringId                 socketDesignation;
    DmiCacheConfiguration       cacheConfiguration;
    DmiCacheSize                maximumCacheSize;
    DmiCacheSize                installedSize;
    DmiCacheSramTypeFlags       supportedSramType;
    DmiCacheSramTypeFlags       currentSramType;
    u8                          cacheSpeed;
    DmiCacheErrorCorrectionType errorCorrectionType;
    DmiCacheType                systemCacheType;
    DmiCacheAssociativity       associativity;
    DmiCacheSize2               maximumCacheSize2;
    DmiCacheSize2               installedSize2;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMICACHEENTRY_H
