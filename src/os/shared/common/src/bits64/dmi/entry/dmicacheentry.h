#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMICACHEENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMICACHEENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/entry/lib/dmicacheassociativity.h>
#include <common/src/bits64/dmi/entry/lib/dmicacheconfiguration.h>
#include <common/src/bits64/dmi/entry/lib/dmicacheerrorcorrectiontype.h>
#include <common/src/bits64/dmi/entry/lib/dmicachesize.h>
#include <common/src/bits64/dmi/entry/lib/dmicachesize2.h>
#include <common/src/bits64/dmi/entry/lib/dmicachesramtypeflags.h>
#include <common/src/bits64/dmi/entry/lib/dmicachetype.h>



struct DmiCacheEntry
{
    DmiEntryHeader              header;
    u8                          socketDesignationStringId;
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
