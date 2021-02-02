#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIBASEBOARDENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIBASEBOARDENTRY_H



#include <com/ngos/shared/common/dmi/dmientryheader.h>
#include <com/ngos/shared/common/dmi/dmistringid.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmibaseboardfeatureflags.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmibaseboardtype.h>



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
    bad_uint16                      chassisHandle;
    DmiBaseboardType         boardType;
    bad_uint8                       numberOfContainedObjectHandles;
    bad_uint16                      containedObjectHandles[0];
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIBASEBOARDENTRY_H
