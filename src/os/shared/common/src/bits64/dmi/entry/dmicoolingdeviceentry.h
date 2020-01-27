#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMICOOLINGDEVICEENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMICOOLINGDEVICEENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/entry/lib/dmicoolingdevicetypeandstatus.h>



struct DmiCoolingDeviceEntry
{
    DmiEntryHeader                header;
    u16                           temperatureProbeHandle;
    DmiCoolingDeviceTypeAndStatus deviceTypeAndStatus;
    u8                            coolingUnitGroup;
    u32                           oemDefined;
    u16                           nominalSpeed;
    u8                            descriptionStringId;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMICOOLINGDEVICEENTRY_H
