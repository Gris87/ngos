#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMSLOTSENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMSLOTSENTRY_H



#include <com/ngos/shared/common/dmi/dmientryheader.h>
#include <com/ngos/shared/common/dmi/dmistringid.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmifunctionnumberanddevicenumber.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmisystemslotscharacteristicsflags.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmisystemslotsdatabuswidth.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmisystemslotslength.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmisystemslotspeergroup.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmisystemslotstype.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmisystemslotsusage.h>



struct DmiSystemSlotsEntry
{
    DmiEntryHeader                     header;
    DmiStringId                        slotDesignation;
    DmiSystemSlotsType                 slotType;
    DmiSystemSlotsDataBusWidth         slotDataBusWidth;
    DmiSystemSlotsUsage                currentUsage;
    DmiSystemSlotsLength               slotLength;
    bad_uint16                                slotID;
    DmiSystemSlotsCharacteristicsFlags slotCharacteristics;
} __attribute__((packed));



struct DmiSystemSlotsEntryV26: public DmiSystemSlotsEntry
{
    bad_uint16                              segmentGroupNumber;
    bad_uint8                               busNumber;
    DmiFunctionNumberAndDeviceNumber functionNumberAndDeviceNumber;
} __attribute__((packed));



struct DmiSystemSlotsEntryV32: public DmiSystemSlotsEntryV26
{
    bad_uint8                      dataBusWidth;
    bad_uint8                      peerGroupingCount;
    DmiSystemSlotsPeerGroup peerGroups[0];
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMSLOTSENTRY_H
