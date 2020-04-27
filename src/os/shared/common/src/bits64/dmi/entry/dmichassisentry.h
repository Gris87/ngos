#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMICHASSISENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMICHASSISENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/dmistringid.h>
#include <common/src/bits64/dmi/entry/lib/dmichassiscontainedelement.h>
#include <common/src/bits64/dmi/entry/lib/dmichassissecuritystatus.h>
#include <common/src/bits64/dmi/entry/lib/dmichassisstate.h>
#include <common/src/bits64/dmi/entry/lib/dmichassistype.h>



#define DMI_CHASSIS_HEIGHT_NOT_AVAILABLE                          0x00
#define DMI_CHASSIS_NUMBER_OF_POWER_CORDS_NOT_AVAILABLE           0x00
#define DMI_CHASSIS_CONTAINED_ELEMENT_COUNT_NOT_AVAILABLE         0x00
#define DMI_CHASSIS_CONTAINED_ELEMENT_RECORD_LENGTH_NOT_AVAILABLE 0x00



struct DmiChassisEntry
{
    DmiEntryHeader header;
    DmiStringId    manufacturer;

    union
    {
        struct
        {
            u8 type:   7; // TODO: Use enum DmiChassisType
            u8 locked: 1;
        };

        u8 typeAndLocked;
    };

    DmiStringId                version;
    DmiStringId                serialNumber;
    DmiStringId                assetTag;
    DmiChassisState            bootUpState;
    DmiChassisState            powerSupplyState;
    DmiChassisState            thermalState;
    DmiChassisSecurityStatus   securityStatus;
    u32                        oemDefined;
    u8                         height;
    u8                         numberOfPowerCords;
    u8                         containedElementCount;
    u8                         containedElementRecordLength;
    DmiChassisContainedElement containedElements[0];
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMICHASSISENTRY_H
