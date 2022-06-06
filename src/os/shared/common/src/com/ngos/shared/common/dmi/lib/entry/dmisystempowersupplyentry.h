#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMPOWERSUPPLYENTRY_H                                                                                                                                     // Colorize: green
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMPOWERSUPPLYENTRY_H                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/dmi/lib/dmientryheader.h>                                                                                                                                               // Colorize: green
#include <com/ngos/shared/common/dmi/lib/dmistringid.h>                                                                                                                                                  // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmisystempowersupplycharacteristics.h>                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define DMI_SYSTEM_POWER_SUPPLY_POWER_UNIT_GROUP_NO_GROUP                0x00                                                                                                                            // Colorize: green
#define DMI_SYSTEM_POWER_SUPPLY_MAX_POWER_CAPACITY_UNKNOWN               0x8000                                                                                                                          // Colorize: green
#define DMI_SYSTEM_POWER_SUPPLY_INPUT_VOLTAGE_PROBE_HANDLE_NOT_AVAILABLE 0xFFFF                                                                                                                          // Colorize: green
#define DMI_SYSTEM_POWER_SUPPLY_COOLING_DEVICE_HANDLE_NOT_AVAILABLE      0xFFFF                                                                                                                          // Colorize: green
#define DMI_SYSTEM_POWER_SUPPLY_INPUT_CURRENT_PROBE_HANDLE_NOT_AVAILABLE 0xFFFF                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
struct DmiSystemPowerSupplyEntry                                                                                                                                                                         // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    DmiEntryHeader                      header;                                                                                                                                                          // Colorize: green
    u8                                  powerUnitGroup;                                                                                                                                                  // Colorize: green
    DmiStringId                         location;                                                                                                                                                        // Colorize: green
    DmiStringId                         deviceName;                                                                                                                                                      // Colorize: green
    DmiStringId                         manufacturer;                                                                                                                                                    // Colorize: green
    DmiStringId                         serialNumber;                                                                                                                                                    // Colorize: green
    DmiStringId                         assetTagNumber;                                                                                                                                                  // Colorize: green
    DmiStringId                         modelPartNumber;                                                                                                                                                 // Colorize: green
    DmiStringId                         revisionLevel;                                                                                                                                                   // Colorize: green
    u16                                 maxPowerCapacity;                                                                                                                                                // Colorize: green
    DmiSystemPowerSupplyCharacteristics powerSupplyCharacteristics;                                                                                                                                      // Colorize: green
    u16                                 inputVoltageProbeHandle;                                                                                                                                         // Colorize: green
    u16                                 coolingDeviceHandle;                                                                                                                                             // Colorize: green
    u16                                 inputCurrentProbeHandle;                                                                                                                                         // Colorize: green
} __attribute__((packed));                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMPOWERSUPPLYENTRY_H                                                                                                                                   // Colorize: green