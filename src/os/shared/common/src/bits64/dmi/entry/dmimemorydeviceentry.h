#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIMEMORYDEVICEENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIMEMORYDEVICEENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/entry/lib/dmimemorydeviceattributes.h>
#include <common/src/bits64/dmi/entry/lib/dmimemorydeviceformfactor.h>
#include <common/src/bits64/dmi/entry/lib/dmimemorydeviceoperatingmodecapabilityflags.h>
#include <common/src/bits64/dmi/entry/lib/dmimemorydevicesize.h>
#include <common/src/bits64/dmi/entry/lib/dmimemorydevicetechnology.h>
#include <common/src/bits64/dmi/entry/lib/dmimemorydevicetype.h>
#include <common/src/bits64/dmi/entry/lib/dmimemorydevicetypedetailflags.h>



struct DmiMemoryDeviceEntry
{
    DmiEntryHeader                              header;
    u16                                         memoryArrayHandle;
    u16                                         memoryErrorInformationHandle;
    u16                                         totalWidth;
    u16                                         dataWidth;
    DmiMemoryDeviceSize                         size;
    DmiMemoryDeviceFormFactor                   formFactor;
    u8                                          deviceSet;
    u8                                          deviceLocatorStringId;
    u8                                          bankLocatorStringId;
    DmiMemoryDeviceType                         memoryType;
    DmiMemoryDeviceTypeDetailFlags              typeDetail;
    u16                                         speed;
    u8                                          manufacturerStringId;
    u8                                          serialNumberStringId;
    u8                                          assetTagStringId;
    u8                                          partNumberStringId;
    DmiMemoryDeviceAttributes                   attributes;
    u32                                         extendedSize;
    u16                                         configuredMemorySpeed;
    u16                                         minimumVoltage;
    u16                                         maximumVoltage;
    u16                                         configuredVoltage;
    DmiMemoryDeviceTechnology                   memoryTechnology;
    DmiMemoryDeviceOperatingModeCapabilityFlags memoryOperatingModeCapability;
    u8                                          firmwareVersionStringId;
    u16                                         moduleManufacturerID;
    u16                                         moduleProductID;
    u16                                         memorySubsystemControllerManufacturerID;
    u16                                         memorySubsystemControllerProductID;
    u64                                         nonVolatileSize;
    u64                                         volatileSize;
    u64                                         cacheSize;
    u64                                         logicalSize;
    u32                                         extendedSpeed;
    u32                                         extendedConfiguredMemorySpeed;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIMEMORYDEVICEENTRY_H
