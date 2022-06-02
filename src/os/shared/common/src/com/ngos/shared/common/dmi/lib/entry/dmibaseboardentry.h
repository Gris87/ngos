#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIBASEBOARDENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIBASEBOARDENTRY_H



#include <com/ngos/shared/common/dmi/lib/dmientryheader.h>
#include <com/ngos/shared/common/dmi/lib/dmistringid.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmibaseboardfeatureflags.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmibaseboardtype.h>



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



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIBASEBOARDENTRY_H
