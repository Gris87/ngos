#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIPORTABLEBATTERYENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIPORTABLEBATTERYENTRY_H



#include <com/ngos/shared/common/dmi/dmientryheader.h>
#include <com/ngos/shared/common/dmi/dmistringid.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmiportablebatterydevicechemistry.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmiportablebatterymanufacturedate.h>



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
    bad_uint16                               designCapacity;
    bad_uint16                               designVoltage;
    DmiStringId                       sbdsVersionNumber;
    bad_uint8                                maximumErrorInBatteryData;
} __attribute__((packed));



struct DmiPortableBatteryEntryV22: public DmiPortableBatteryEntry
{
    bad_uint16                               sbdsSerialNumber;
    DmiPortableBatteryManufactureDate sbdsManufactureDate;
    DmiStringId                       sbdsDeviceChemistry;
    bad_uint8                                designCapacityMultiplier;
    bad_uint32                               oemSpecific;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIPORTABLEBATTERYENTRY_H
