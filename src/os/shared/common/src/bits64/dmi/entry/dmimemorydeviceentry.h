#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIMEMORYDEVICEENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIMEMORYDEVICEENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/dmistringid.h>
#include <common/src/bits64/dmi/entry/lib/dmimemorydeviceattributes.h>
#include <common/src/bits64/dmi/entry/lib/dmimemorydeviceextendedsize.h>
#include <common/src/bits64/dmi/entry/lib/dmimemorydeviceformfactor.h>
#include <common/src/bits64/dmi/entry/lib/dmimemorydeviceoperatingmodecapabilityflags.h>
#include <common/src/bits64/dmi/entry/lib/dmimemorydevicesize.h>
#include <common/src/bits64/dmi/entry/lib/dmimemorydevicetechnology.h>
#include <common/src/bits64/dmi/entry/lib/dmimemorydevicetype.h>
#include <common/src/bits64/dmi/entry/lib/dmimemorydevicetypedetailflags.h>



#define DMI_MEMORY_DEVICE_MEMORY_ERROR_INFORMATION_HANDLE_NOT_AVAILABLE 0xFFFE
#define DMI_MEMORY_DEVICE_MEMORY_ERROR_INFORMATION_HANDLE_NO_ERROR      0xFFFF
#define DMI_MEMORY_DEVICE_TOTAL_WIDTH_UNKNOWN                           0xFFFF
#define DMI_MEMORY_DEVICE_DATA_WIDTH_UNKNOWN                            0xFFFF
#define DMI_MEMORY_DEVICE_SIZE_NOT_INSTALLED                            0x0000
#define DMI_MEMORY_DEVICE_SIZE_UNKNOWN                                  0xFFFF
#define DMI_MEMORY_DEVICE_SIZE_NEED_TO_EXTEND                           0x7FFF
#define DMI_MEMORY_DEVICE_DEVICE_SET_NO_SET                             0x00
#define DMI_MEMORY_DEVICE_DEVICE_SET_UNKNOWN                            0xFF
#define DMI_MEMORY_DEVICE_SPEED_UNKNOWN                                 0x0000
#define DMI_MEMORY_DEVICE_SPEED_NEED_TO_EXTEND                          0xFFFF
#define DMI_MEMORY_DEVICE_RANK_UNKNOWN                                  0
#define DMI_MEMORY_DEVICE_CONFIGURED_MEMORY_SPEED_UNKNOWN               0x0000
#define DMI_MEMORY_DEVICE_CONFIGURED_MEMORY_SPEED_NEED_TO_EXTEND        0xFFFF
#define DMI_MEMORY_DEVICE_MINIMUM_VOLTAGE_UNKNOWN                       0x0000
#define DMI_MEMORY_DEVICE_MAXIMUM_VOLTAGE_UNKNOWN                       0x0000
#define DMI_MEMORY_DEVICE_CONFIGURED_VOLTAGE_UNKNOWN                    0x0000
#define DMI_MEMORY_DEVICE_NON_VOLATILE_SIZE_NOT_AVAILABLE               0x0000000000000000
#define DMI_MEMORY_DEVICE_NON_VOLATILE_SIZE_UNKNOWN                     0xFFFFFFFFFFFFFFFF
#define DMI_MEMORY_DEVICE_VOLATILE_SIZE_NOT_AVAILABLE                   0x0000000000000000
#define DMI_MEMORY_DEVICE_VOLATILE_SIZE_UNKNOWN                         0xFFFFFFFFFFFFFFFF
#define DMI_MEMORY_DEVICE_CACHE_SIZE_NOT_AVAILABLE                      0x0000000000000000
#define DMI_MEMORY_DEVICE_CACHE_SIZE_UNKNOWN                            0xFFFFFFFFFFFFFFFF
#define DMI_MEMORY_DEVICE_LOGICAL_SIZE_UNKNOWN                          0xFFFFFFFFFFFFFFFF



struct DmiMemoryDeviceEntry
{
    DmiEntryHeader                 header;
    u16                            memoryArrayHandle;
    u16                            memoryErrorInformationHandle;
    u16                            totalWidth;
    u16                            dataWidth;
    DmiMemoryDeviceSize            size;
    DmiMemoryDeviceFormFactor      formFactor;
    u8                             deviceSet;
    DmiStringId                    deviceLocator;
    DmiStringId                    bankLocator;
    DmiMemoryDeviceType            memoryType;
    DmiMemoryDeviceTypeDetailFlags typeDetail;
} __attribute__((packed));



struct DmiMemoryDeviceEntryV23: public DmiMemoryDeviceEntry
{
    u16         speed;
    DmiStringId manufacturer;
    DmiStringId serialNumber;
    DmiStringId assetTag;
    DmiStringId partNumber;
} __attribute__((packed));



struct DmiMemoryDeviceEntryV26: public DmiMemoryDeviceEntryV23
{
    DmiMemoryDeviceAttributes attributes;
} __attribute__((packed));



struct DmiMemoryDeviceEntryV27: public DmiMemoryDeviceEntryV26
{
    DmiMemoryDeviceExtendedSize extendedSize;
    u16                         configuredMemorySpeed;
} __attribute__((packed));



struct DmiMemoryDeviceEntryV28: public DmiMemoryDeviceEntryV27
{
    u16 minimumVoltage;
    u16 maximumVoltage;
    u16 configuredVoltage;
} __attribute__((packed));



struct DmiMemoryDeviceEntryV32: public DmiMemoryDeviceEntryV28
{
    DmiMemoryDeviceTechnology                   memoryTechnology;
    DmiMemoryDeviceOperatingModeCapabilityFlags memoryOperatingModeCapability;
    DmiStringId                                 firmwareVersion;
    u16                                         moduleManufacturerID;
    u16                                         moduleProductID;
    u16                                         memorySubsystemControllerManufacturerID;
    u16                                         memorySubsystemControllerProductID;
    u64                                         nonVolatileSize;
    u64                                         volatileSize;
    u64                                         cacheSize;
    u64                                         logicalSize;
} __attribute__((packed));



struct DmiMemoryDeviceEntryV33: public DmiMemoryDeviceEntryV32
{
    u32 extendedSpeed;
    u32 extendedConfiguredMemorySpeed;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIMEMORYDEVICEENTRY_H
