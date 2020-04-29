#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMICOOLINGDEVICEENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMICOOLINGDEVICEENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/dmistringid.h>
#include <common/src/bits64/dmi/entry/lib/dmicoolingdevicestatus.h>
#include <common/src/bits64/dmi/entry/lib/dmicoolingdevicetype.h>



#define DMI_COOLING_DEVICE_TEMPERATURE_PROBE_HANDLE_NOT_AVAILABLE 0xFFFF
#define DMI_COOLING_DEVICE_COOLING_UNIT_GROUP_NO_GROUP            0x00
#define DMI_COOLING_DEVICE_NOMINAL_SPEED_UNKNOWN                  0x8000



struct DmiCoolingDeviceEntry
{
    DmiEntryHeader header;
    u16            temperatureProbeHandle;

    union
    {
        struct
        {
            u8 deviceType: 5; // TODO: Use enum DmiCoolingDeviceType
            u8 status:     3; // TODO: Use enum DmiCoolingDeviceStatus
        };

        u8 deviceTypeAndStatus;
    };

    u8          coolingUnitGroup;
    u32         oemDefined;
    u16         nominalSpeed;
    DmiStringId description;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMICOOLINGDEVICEENTRY_H
