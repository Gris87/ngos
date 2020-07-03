#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIBASEBOARDENTRY_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIBASEBOARDENTRY_H



#include <common/src/com/ngos/shared/common/dmi/dmientryheader.h>
#include <common/src/com/ngos/shared/common/dmi/dmistringid.h>
#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmibaseboardfeatureflags.h>
#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmibaseboardtype.h>



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



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIBASEBOARDENTRY_H
