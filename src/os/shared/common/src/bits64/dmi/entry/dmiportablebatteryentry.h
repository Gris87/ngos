#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIPORTABLEBATTERYENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIPORTABLEBATTERYENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/entry/lib/dmiportablebatterydevicechemistry.h>
#include <common/src/bits64/dmi/entry/lib/dmiportablebatterymanufacturedate.h>



struct DmiPortableBatteryEntry
{
    DmiEntryHeader                    header;
    u8                                locationStringId;
    u8                                manufacturerStringId;
    u8                                manufactureDateStringId;
    u8                                serialNumberStringId;
    u8                                deviceNameStringId;
    DmiPortableBatteryDeviceChemistry deviceChemistry;
    u16                               deviceCapacity;
    u16                               designVoltage;
    u8                                sbdsVersionNumberStringId;
    u8                                maximumErrorInBatteryData;
    u16                               sbdsSerialNumber;
    DmiPortableBatteryManufactureDate sbdsManufactureDate;
    u8                                sbdsDeviceChemistryStringId;
    u8                                designCapacityMultiplier;
    u32                               oemSpecific;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIPORTABLEBATTERYENTRY_H
