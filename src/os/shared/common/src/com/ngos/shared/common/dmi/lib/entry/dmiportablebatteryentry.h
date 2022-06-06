#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIPORTABLEBATTERYENTRY_H                                                                                                                                       // Colorize: green
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIPORTABLEBATTERYENTRY_H                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/dmi/lib/dmientryheader.h>                                                                                                                                               // Colorize: green
#include <com/ngos/shared/common/dmi/lib/dmistringid.h>                                                                                                                                                  // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmiportablebatterydevicechemistry.h>                                                                                                                  // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmiportablebatterymanufacturedate.h>                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define DMI_PORTABLE_BATTERY_DESIGN_CAPACITY_UNKNOWN               0x0000                                                                                                                                // Colorize: green
#define DMI_PORTABLE_BATTERY_DESIGN_VOLTAGE_UNKNOWN                0x0000                                                                                                                                // Colorize: green
#define DMI_PORTABLE_BATTERY_MAXIMUM_ERROR_IN_BATTERY_DATA_UNKNOWN 0xFF                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
struct DmiPortableBatteryEntry                                                                                                                                                                           // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    DmiEntryHeader                    header;                                                                                                                                                            // Colorize: green
    DmiStringId                       location;                                                                                                                                                          // Colorize: green
    DmiStringId                       manufacturer;                                                                                                                                                      // Colorize: green
    DmiStringId                       manufactureDate;                                                                                                                                                   // Colorize: green
    DmiStringId                       serialNumber;                                                                                                                                                      // Colorize: green
    DmiStringId                       deviceName;                                                                                                                                                        // Colorize: green
    DmiPortableBatteryDeviceChemistry deviceChemistry;                                                                                                                                                   // Colorize: green
    u16                               designCapacity;                                                                                                                                                    // Colorize: green
    u16                               designVoltage;                                                                                                                                                     // Colorize: green
    DmiStringId                       sbdsVersionNumber;                                                                                                                                                 // Colorize: green
    u8                                maximumErrorInBatteryData;                                                                                                                                         // Colorize: green
} __attribute__((packed));                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
struct DmiPortableBatteryEntryV22: public DmiPortableBatteryEntry                                                                                                                                        // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    u16                               sbdsSerialNumber;                                                                                                                                                  // Colorize: green
    DmiPortableBatteryManufactureDate sbdsManufactureDate;                                                                                                                                               // Colorize: green
    DmiStringId                       sbdsDeviceChemistry;                                                                                                                                               // Colorize: green
    u8                                designCapacityMultiplier;                                                                                                                                          // Colorize: green
    u32                               oemSpecific;                                                                                                                                                       // Colorize: green
} __attribute__((packed));                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIPORTABLEBATTERYENTRY_H                                                                                                                                     // Colorize: green