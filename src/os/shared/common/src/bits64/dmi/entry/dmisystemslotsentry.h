#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMISYSTEMSLOTSENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMISYSTEMSLOTSENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/entry/lib/dmisystemslotscharacteristicsflags.h>
#include <common/src/bits64/dmi/entry/lib/dmisystemslotsdatabuswidth.h>
#include <common/src/bits64/dmi/entry/lib/dmisystemslotslength.h>
#include <common/src/bits64/dmi/entry/lib/dmisystemslotspeergroup.h>
#include <common/src/bits64/dmi/entry/lib/dmisystemslotstype.h>
#include <common/src/bits64/dmi/entry/lib/dmisystemslotsusage.h>



struct DmiSystemSlotsEntry
{
    DmiEntryHeader                     header;
    u8                                 slotDesignationStringId;
    DmiSystemSlotsType                 slotType;
    DmiSystemSlotsDataBusWidth         slotDataBusWidth;
    DmiSystemSlotsUsage                currentUsage;
    DmiSystemSlotsLength               slotLength;
    u16                                slotID;
    DmiSystemSlotsCharacteristicsFlags slotCharacteristics;
    u16                                segmentGroupNumber;
    u8                                 busNumber;

    u8                                 deviceNumber:   5;
    u8                                 functionNumber: 3;

    DmiSystemSlotsDataBusWidth         dataBusWidth;
    u8                                 peerGroupingCount;
    DmiSystemSlotsPeerGroup            peerGroups[0];
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMISYSTEMSLOTSENTRY_H