#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIBASEBOARDENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIBASEBOARDENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/dmistringid.h>
#include <common/src/bits64/dmi/entry/lib/dmibaseboardfeatureflags.h>
#include <common/src/bits64/dmi/entry/lib/dmibaseboardtype.h>



struct DmiBaseboardEntry
{
    DmiEntryHeader           header;
    DmiStringId              manufacturer;
    DmiStringId              product;
    DmiStringId              version;
    DmiStringId              serialNumber;
    DmiStringId              assetTag;
    DmiBaseboardFeatureFlags featureFlags;
    DmiStringId              locationInChassis;
    u16                      chassisHandle;
    DmiBaseboardType         boardType;
    u8                       numberOfContainedObjectHandles;
    u16                      containedObjectHandles[0];
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIBASEBOARDENTRY_H
