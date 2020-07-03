#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMPOWERSUPPLYENTRY_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMPOWERSUPPLYENTRY_H



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
    u8                                  powerUnitGroup;
    DmiStringId                         location;
    DmiStringId                         deviceName;
    DmiStringId                         manufacturer;
    DmiStringId                         serialNumber;
    DmiStringId                         assetTagNumber;
    DmiStringId                         modelPartNumber;
    DmiStringId                         revisionLevel;
    u16                                 maxPowerCapacity;
    DmiSystemPowerSupplyCharacteristics powerSupplyCharacteristics;
    u16                                 inputVoltageProbeHandle;
    u16                                 coolingDeviceHandle;
    u16                                 inputCurrentProbeHandle;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMPOWERSUPPLYENTRY_H
