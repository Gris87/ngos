#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIELECTRICALCURRENTPROBEENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIELECTRICALCURRENTPROBEENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/entry/lib/dmielectricalcurrentprobelocationandstatus.h>



struct DmiElectricalCurrentProbeEntry
{
    DmiEntryHeader                             header;
    u8                                         descriptionStringId;
    DmiElectricalCurrentProbeLocationAndStatus locationAndStatus;
    u16                                        maximumValue;
    u16                                        minimumValue;
    u16                                        resolution;
    u16                                        tolerance;
    u16                                        accuracy;
    u32                                        oemDefined;
    u16                                        nominalValue;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIELECTRICALCURRENTPROBEENTRY_H
