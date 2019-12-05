#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIMEMORYDEVICEENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIMEMORYDEVICEENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>



struct DmiMemoryDeviceEntry
{
    DmiEntryHeader header;
    u16            physicalMemoryArrayHandle;
    u16            memoryErrorInformationHandle;
    u16            totalWidth;
    u16            dataWidth;
    u16            size;
    u8             formFactor;
    u8             deviceSet;
    u8             deviceLocator;
    u8             bankLocator;
    u8             memoryType;
    u16            typeDetail;
    u16            speed;
    u8             manufacturer;
    u8             serialNumber;
    u8             assetTag;
    u8             partNumber;
    u8             attributes;
    u32            extendedSize;
    u16            configuredMemorySpeed;
    u16            minimumVoltage;
    u16            maximumVoltage;
    u16            configuredVoltage;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIMEMORYDEVICEENTRY_H
