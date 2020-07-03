#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMICACHEENTRY_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMICACHEENTRY_H



#include <com/ngos/shared/common/dmi/dmientryheader.h>
#include <com/ngos/shared/common/dmi/dmistringid.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmicacheassociativity.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmicacheconfiguration.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmicacheerrorcorrectiontype.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmicachesize.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmicachesize2.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmicachesramtypeflags.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmicachetype.h>



#define DMI_CACHE_MAXIMUM_CACHE_SIZE_NEED_TO_EXTEND 0xFFFF
#define DMI_CACHE_INSTALLED_SIZE_NO_CACHE           0x0000
#define DMI_CACHE_INSTALLED_SIZE_NEED_TO_EXTEND     0xFFFF
#define DMI_CACHE_CACHE_SPEED_UNKNOWN               0x0000



struct DmiCacheEntry
{
    DmiEntryHeader        header;
    DmiStringId           socketDesignation;
    DmiCacheConfiguration cacheConfiguration;
    DmiCacheSize          maximumCacheSize;
    DmiCacheSize          installedSize;
    DmiCacheSramTypeFlags supportedSramType;
    DmiCacheSramTypeFlags currentSramType;
} __attribute__((packed));



struct DmiCacheEntryV21: public DmiCacheEntry
{
    u8                          cacheSpeed;
    DmiCacheErrorCorrectionType errorCorrectionType;
    DmiCacheType                systemCacheType;
    DmiCacheAssociativity       associativity;
} __attribute__((packed));



struct DmiCacheEntryV31: public DmiCacheEntryV21
{
    DmiCacheSize2 maximumCacheSize2;
    DmiCacheSize2 installedSize2;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMICACHEENTRY_H
