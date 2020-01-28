#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMISYSTEMPOWERSUPPLYENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMISYSTEMPOWERSUPPLYENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/entry/lib/dmisystempowersupplycharacteristics.h>



struct DmiSystemPowerSupplyEntry
{
    DmiEntryHeader                      header;
    u8                                  powerUnitGroup;
    u8                                  locationStringId;
    u8                                  deviceNameStringId;
    u8                                  manufacturerStringId;
    u8                                  serialNumberStringId;
    u8                                  assetTagNumberStringId;
    u8                                  modelPartNumberStringId;
    u8                                  revisionLevelStringId;
    u16                                 maxPowerCapacity;
    DmiSystemPowerSupplyCharacteristics powerSupplyCharacteristics;
    u16                                 inputVoltageProbeHandle;
    u16                                 coolingDeviceHandle;
    u16                                 inputCurrentProbeHandle;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMISYSTEMPOWERSUPPLYENTRY_H
