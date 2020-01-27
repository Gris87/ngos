#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICOOLINGDEVICETYPEANDSTATUS_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICOOLINGDEVICETYPEANDSTATUS_H



#include <common/src/bits64/dmi/entry/lib/dmicoolingdevicestatus.h>
#include <common/src/bits64/dmi/entry/lib/dmicoolingdevicetype.h>



struct DmiCoolingDeviceTypeAndStatus
{
    u8 type:   5; // TODO: Use enum DmiCoolingDeviceType
    u8 status: 3; // TODO: Use enum DmiCoolingDeviceStatus
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICOOLINGDEVICETYPEANDSTATUS_H
