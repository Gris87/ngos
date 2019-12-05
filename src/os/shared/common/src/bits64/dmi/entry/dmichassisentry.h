#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMICHASSISENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMICHASSISENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>



struct DmiChassisEntry
{
    DmiEntryHeader header;
    u8             manufacturer;
    u8             type;
    u8             version;
    u8             serialNumber;
    u8             assetTag;
    u8             bootUpState;
    u8             powerSupplyState;
    u8             thermalState;
    u8             securityStatus;
    u32            oemDefined;
    u8             height;
    u8             numberOfPowerCords;
    u8             containedElementCount;
    u8             containedElementRecordLength;
    u8             containedElements[0];
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMICHASSISENTRY_H
