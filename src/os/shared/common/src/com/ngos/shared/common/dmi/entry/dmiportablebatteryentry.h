#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIPORTABLEBATTERYENTRY_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIPORTABLEBATTERYENTRY_H



#include <common/src/com/ngos/shared/common/dmi/dmientryheader.h>
#include <common/src/com/ngos/shared/common/dmi/dmistringid.h>
#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmiportablebatterydevicechemistry.h>
#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmiportablebatterymanufacturedate.h>



#define DMI_PORTABLE_BATTERY_DESIGN_CAPACITY_UNKNOWN               0x0000
#define DMI_PORTABLE_BATTERY_DESIGN_VOLTAGE_UNKNOWN                0x0000
#define DMI_PORTABLE_BATTERY_MAXIMUM_ERROR_IN_BATTERY_DATA_UNKNOWN 0xFF



struct DmiPortableBatteryEntry
{
    DmiEntryHeader                    header;
    DmiStringId                       location;
    DmiStringId                       manufacturer;
    DmiStringId                       manufactureDate;
    DmiStringId                       serialNumber;
    DmiStringId                       deviceName;
    DmiPortableBatteryDeviceChemistry deviceChemistry;
    u16                               designCapacity;
    u16                               designVoltage;
    DmiStringId                       sbdsVersionNumber;
    u8                                maximumErrorInBatteryData;
} __attribute__((packed));



struct DmiPortableBatteryEntryV22: public DmiPortableBatteryEntry
{
    u16                               sbdsSerialNumber;
    DmiPortableBatteryManufactureDate sbdsManufactureDate;
    DmiStringId                       sbdsDeviceChemistry;
    u8                                designCapacityMultiplier;
    u32                               oemSpecific;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIPORTABLEBATTERYENTRY_H
