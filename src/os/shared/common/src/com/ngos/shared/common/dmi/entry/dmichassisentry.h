#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMICHASSISENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMICHASSISENTRY_H



#include <com/ngos/shared/common/dmi/dmientryheader.h>
#include <com/ngos/shared/common/dmi/dmistringid.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmichassiscontainedelement.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmichassissecuritystatus.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmichassisstate.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmichassistypeandlocked.h>



#define DMI_CHASSIS_CONTAINED_ELEMENT(entry, i) (DmiChassisContainedElement *)((u64)(entry)->containedElements + (i) * (entry)->containedElementRecordLength)



#define DMI_CHASSIS_HEIGHT_NOT_AVAILABLE                          0x00
#define DMI_CHASSIS_NUMBER_OF_POWER_CORDS_NOT_AVAILABLE           0x00
#define DMI_CHASSIS_CONTAINED_ELEMENT_COUNT_NOT_AVAILABLE         0x00
#define DMI_CHASSIS_CONTAINED_ELEMENT_RECORD_LENGTH_NOT_AVAILABLE 0x00



struct DmiChassisEntry
{
    DmiEntryHeader          header;
    DmiStringId             manufacturer;
    DmiChassisTypeAndLocked typeAndLocked;
    DmiStringId             version;
    DmiStringId             serialNumber;
    DmiStringId             assetTag;
} __attribute__((packed));



struct DmiChassisEntryV21: public DmiChassisEntry
{
    DmiChassisState          bootUpState;
    DmiChassisState          powerSupplyState;
    DmiChassisState          thermalState;
    DmiChassisSecurityStatus securityStatus;
} __attribute__((packed));



struct DmiChassisEntryV23: public DmiChassisEntryV21
{
    u32                        oemDefined;
    u8                         height;
    u8                         numberOfPowerCords;
    u8                         containedElementCount;
    u8                         containedElementRecordLength;
    DmiChassisContainedElement containedElements[0];
} __attribute__((packed));



// Since amount of containedElements may be different we will calculate location of DmiChassisEntryV27 as &containedElements[0] + containedElementCount * containedElementRecordLength
struct DmiChassisEntryV27
{
    DmiStringId skuNumber;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMICHASSISENTRY_H
