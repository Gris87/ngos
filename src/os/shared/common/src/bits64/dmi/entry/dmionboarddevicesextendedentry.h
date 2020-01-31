#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIONBOARDDEVICESEXTENDEDENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIONBOARDDEVICESEXTENDEDENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/entry/lib/dmionboarddevicesextendeddevicetype.h>



struct DmiOnboardDevicesExtendedEntry
{
    DmiEntryHeader header;
    u8             referenceDesignationStringId;

    u8             deviceType: 7; // TODO: Use enum DmiOnboardDevicesExtendedDeviceType
    u8             enabled:    1;

    u8             deviceTypeInstance;
    u16            segmentGroupNumber;
    u8             busNumber;

    u8             deviceNumber:   5;
    u8             functionNumber: 3;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIONBOARDDEVICESEXTENDEDENTRY_H