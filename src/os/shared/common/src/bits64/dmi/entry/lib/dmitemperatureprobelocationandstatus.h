#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMITEMPERATUREPROBELOCATIONANDSTATUS_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMITEMPERATUREPROBELOCATIONANDSTATUS_H



#include <common/src/bits64/dmi/entry/lib/dmitemperatureprobelocation.h>
#include <common/src/bits64/dmi/entry/lib/dmitemperatureprobestatus.h>



struct DmiTemperatureProbeLocationAndStatus
{
    u8 location: 5; // TODO: Use enum DmiTemperatureProbeLocation
    u8 status:   3; // TODO: Use enum DmiTemperatureProbeStatus
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMITEMPERATUREPROBELOCATIONANDSTATUS_H
