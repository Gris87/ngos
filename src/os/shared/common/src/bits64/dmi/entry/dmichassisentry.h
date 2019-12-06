#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMICHASSISENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMICHASSISENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/entry/lib/dmichassiscontainedelement.h>
#include <common/src/bits64/dmi/entry/lib/dmichassissecuritystatus.h>
#include <common/src/bits64/dmi/entry/lib/dmichassisstate.h>
#include <common/src/bits64/dmi/entry/lib/dmichassistype.h>



struct DmiChassisEntry
{
    DmiEntryHeader             header;
    u8                         manufacturerStringId;
    DmiChassisType             type;
    u8                         versionStringId;
    u8                         serialNumberStringId;
    u8                         assetTagStringId;
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
