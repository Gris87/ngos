#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_DMI_ENTRY_DMIBASEBOARDENTRY_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_DMI_ENTRY_DMIBASEBOARDENTRY_H



#include <kernelbase/src/bits64/other/dmi/dmientryheader.h>



struct DmiBaseboardEntry
{
    DmiEntryHeader header;
    u8             manufacturer;
    u8             product;
    u8             version;
    u8             serialNumber;
    u8             assetTag;
    u8             featureFlags;
    u8             locationInChassis;
    u16            chassisHandle;
    u8             boardType;
    u8             numberOfContainedObjectHandles;
    u16            containedObjectHandles[0];
} __attribute__((packed));



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_DMI_ENTRY_DMIBASEBOARDENTRY_H
