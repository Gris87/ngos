#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMSLOTSENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMSLOTSENTRY_H



#include <com/ngos/shared/common/dmi/lib/dmientryheader.h>
#include <com/ngos/shared/common/dmi/lib/dmistringid.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmifunctionnumberanddevicenumber.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmisystemslotscharacteristicsflags.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmisystemslotsdatabuswidth.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmisystemslotslength.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmisystemslotspeergroup.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmisystemslotstype.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmisystemslotsusage.h>



struct DmiSystemSlotsEntry
{
    DmiEntryHeader                     header;
    DmiStringId                        slotDesignation;
    DmiSystemSlotsType                 slotType;
    DmiSystemSlotsDataBusWidth         slotDataBusWidth;
    DmiSystemSlotsUsage                currentUsage;
    DmiSystemSlotsLength               slotLength;
    u16                                slotID;
    DmiSystemSlotsCharacteristicsFlags slotCharacteristics;
} __attribute__((packed));



struct DmiSystemSlotsEntryV26: public DmiSystemSlotsEntry
{
    u16                              segmentGroupNumber;
    u8                               busNumber;
    DmiFunctionNumberAndDeviceNumber functionNumberAndDeviceNumber;
} __attribute__((packed));



struct DmiSystemSlotsEntryV32: public DmiSystemSlotsEntryV26
{
    u8                      dataBusWidth;
    u8                      peerGroupingCount;
    DmiSystemSlotsPeerGroup peerGroups[0];
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMSLOTSENTRY_H
