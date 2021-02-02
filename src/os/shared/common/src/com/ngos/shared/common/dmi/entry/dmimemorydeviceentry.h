#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIMEMORYDEVICEENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIMEMORYDEVICEENTRY_H



#include <com/ngos/shared/common/dmi/dmientryheader.h>
#include <com/ngos/shared/common/dmi/dmistringid.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmimemorydeviceattributes.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmimemorydeviceextendedsize.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmimemorydeviceformfactor.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmimemorydeviceoperatingmodecapabilityflags.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmimemorydevicesize.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmimemorydevicetechnology.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmimemorydevicetype.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmimemorydevicetypedetailflags.h>



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
    bad_uint16                            memoryArrayHandle;
    bad_uint16                            memoryErrorInformationHandle;
    bad_uint16                            totalWidth;
    bad_uint16                            dataWidth;
    DmiMemoryDeviceSize            size;
    DmiMemoryDeviceFormFactor      formFactor;
    bad_uint8                             deviceSet;
    DmiStringId                    deviceLocator;
    DmiStringId                    bankLocator;
    DmiMemoryDeviceType            memoryType;
    DmiMemoryDeviceTypeDetailFlags typeDetail;
} __attribute__((packed));



struct DmiMemoryDeviceEntryV23: public DmiMemoryDeviceEntry
{
    bad_uint16         speed;
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
    bad_uint16                         configuredMemorySpeed;
} __attribute__((packed));



struct DmiMemoryDeviceEntryV28: public DmiMemoryDeviceEntryV27
{
    bad_uint16 minimumVoltage;
    bad_uint16 maximumVoltage;
    bad_uint16 configuredVoltage;
} __attribute__((packed));



struct DmiMemoryDeviceEntryV32: public DmiMemoryDeviceEntryV28
{
    DmiMemoryDeviceTechnology                   memoryTechnology;
    DmiMemoryDeviceOperatingModeCapabilityFlags memoryOperatingModeCapability;
    DmiStringId                                 firmwareVersion;
    bad_uint16                                         moduleManufacturerID;
    bad_uint16                                         moduleProductID;
    bad_uint16                                         memorySubsystemControllerManufacturerID;
    bad_uint16                                         memorySubsystemControllerProductID;
    bad_uint64                                         nonVolatileSize;
    bad_uint64                                         volatileSize;
    bad_uint64                                         cacheSize;
    bad_uint64                                         logicalSize;
} __attribute__((packed));



struct DmiMemoryDeviceEntryV33: public DmiMemoryDeviceEntryV32
{
    bad_uint32 extendedSpeed;
    bad_uint32 extendedConfiguredMemorySpeed;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIMEMORYDEVICEENTRY_H
