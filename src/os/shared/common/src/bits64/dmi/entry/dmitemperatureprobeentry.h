#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMITEMPERATUREPROBEENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMITEMPERATUREPROBEENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/entry/lib/dmitemperatureprobelocationandstatus.h>



struct DmiTemperatureProbeEntry
{
    DmiEntryHeader                       header;
    u8                                   descriptionStringId;
    DmiTemperatureProbeLocationAndStatus locationAndStatus;
    u16                                  maximumValue;
    u16                                  minimumValue;
    u16                                  resolution;
    u16                                  tolerance;
    u16                                  accuracy;
    u32                                  oemDefined;
    u16                                  nominalValue;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMITEMPERATUREPROBEENTRY_H