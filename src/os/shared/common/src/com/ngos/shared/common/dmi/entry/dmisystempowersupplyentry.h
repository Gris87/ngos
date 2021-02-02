#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMPOWERSUPPLYENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMPOWERSUPPLYENTRY_H



#include <com/ngos/shared/common/dmi/dmientryheader.h>
#include <com/ngos/shared/common/dmi/dmistringid.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmisystempowersupplycharacteristics.h>



#define DMI_SYSTEM_POWER_SUPPLY_POWER_UNIT_GROUP_NO_GROUP                0x00
#define DMI_SYSTEM_POWER_SUPPLY_MAX_POWER_CAPACITY_UNKNOWN               0x8000
#define DMI_SYSTEM_POWER_SUPPLY_INPUT_VOLTAGE_PROBE_HANDLE_NOT_AVAILABLE 0xFFFF
#define DMI_SYSTEM_POWER_SUPPLY_COOLING_DEVICE_HANDLE_NOT_AVAILABLE      0xFFFF
#define DMI_SYSTEM_POWER_SUPPLY_INPUT_CURRENT_PROBE_HANDLE_NOT_AVAILABLE 0xFFFF



struct DmiSystemPowerSupplyEntry
{
    DmiEntryHeader                      header;
    bad_uint8                                  powerUnitGroup;
    DmiStringId                         location;
    DmiStringId                         deviceName;
    DmiStringId                         manufacturer;
    DmiStringId                         serialNumber;
    DmiStringId                         assetTagNumber;
    DmiStringId                         modelPartNumber;
    DmiStringId                         revisionLevel;
    bad_uint16                                 maxPowerCapacity;
    DmiSystemPowerSupplyCharacteristics powerSupplyCharacteristics;
    bad_uint16                                 inputVoltageProbeHandle;
    bad_uint16                                 coolingDeviceHandle;
    bad_uint16                                 inputCurrentProbeHandle;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMPOWERSUPPLYENTRY_H
