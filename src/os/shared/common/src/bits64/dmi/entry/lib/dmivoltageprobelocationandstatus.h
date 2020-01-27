#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIVOLTAGEPROBELOCATIONANDSTATUS_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIVOLTAGEPROBELOCATIONANDSTATUS_H



#include <common/src/bits64/dmi/entry/lib/dmivoltageprobelocation.h>
#include <common/src/bits64/dmi/entry/lib/dmivoltageprobestatus.h>



struct DmiVoltageProbeLocationAndStatus
{
    u8 location: 5; // TODO: Use enum DmiVoltageProbeLocation
    u8 status:   3; // TODO: Use enum DmiVoltageProbeStatus
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIVOLTAGEPROBELOCATIONANDSTATUS_H
