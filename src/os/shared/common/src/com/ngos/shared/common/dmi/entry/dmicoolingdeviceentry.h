#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMICOOLINGDEVICEENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMICOOLINGDEVICEENTRY_H



#include <com/ngos/shared/common/dmi/dmientryheader.h>
#include <com/ngos/shared/common/dmi/dmistringid.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmicoolingdevicetypeandstatus.h>



#define DMI_COOLING_DEVICE_TEMPERATURE_PROBE_HANDLE_NOT_AVAILABLE 0xFFFF
#define DMI_COOLING_DEVICE_COOLING_UNIT_GROUP_NO_GROUP            0x00
#define DMI_COOLING_DEVICE_NOMINAL_SPEED_UNKNOWN                  0x8000



struct DmiCoolingDeviceEntry
{
    DmiEntryHeader                header;
    bad_uint16                           temperatureProbeHandle;
    DmiCoolingDeviceTypeAndStatus deviceTypeAndStatus;
    bad_uint8                            coolingUnitGroup;
    bad_uint32                           oemDefined;
    bad_uint16                           nominalSpeed;
} __attribute__((packed));



struct DmiCoolingDeviceEntryV27: public DmiCoolingDeviceEntry
{
    DmiStringId description;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMICOOLINGDEVICEENTRY_H
