#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIELECTRICALCURRENTPROBELOCATIONANDSTATUS_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIELECTRICALCURRENTPROBELOCATIONANDSTATUS_H



#include <common/src/bits64/dmi/entry/lib/dmielectricalcurrentprobelocation.h>
#include <common/src/bits64/dmi/entry/lib/dmielectricalcurrentprobestatus.h>



struct DmiElectricalCurrentProbeLocationAndStatus
{
    u8 location: 5; // TODO: Use enum DmiElectricalCurrentProbeLocation
    u8 status:   3; // TODO: Use enum DmiElectricalCurrentProbeStatus
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIELECTRICALCURRENTPROBELOCATIONANDSTATUS_H
