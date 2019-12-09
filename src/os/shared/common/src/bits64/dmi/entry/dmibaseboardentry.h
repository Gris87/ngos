#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIBASEBOARDENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIBASEBOARDENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/entry/lib/dmibaseboardfeatureflags.h>
#include <common/src/bits64/dmi/entry/lib/dmibaseboardtype.h>



struct DmiBaseboardEntry
{
    DmiEntryHeader              header;
    u8                          manufacturerStringId;
    u8                          productStringId;
    u8                          versionStringId;
    u8                          serialNumberStringId;
    u8                          assetTagStringId;
    dmi_baseboard_feature_flags featureFlags;
    u8                          locationInChassisStringId;
    u16                         chassisHandle;
    DmiBaseboardType            boardType;
    u8                          numberOfContainedObjectHandles;
    u16                         containedObjectHandles[0];
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIBASEBOARDENTRY_H
