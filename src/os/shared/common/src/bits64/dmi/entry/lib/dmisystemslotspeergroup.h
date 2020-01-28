#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMSLOTSPEERGROUP_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMSLOTSPEERGROUP_H



#include <common/src/bits64/dmi/entry/lib/dmisystemslotsdatabuswidth.h>



struct DmiSystemSlotsPeerGroup
{
    u16                        segmentGroupNumber;
    u8                         busNumber;

    u8                         deviceNumber:   5;
    u8                         functionNumber: 3;

    DmiSystemSlotsDataBusWidth dataBusWidth;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMSLOTSPEERGROUP_H
