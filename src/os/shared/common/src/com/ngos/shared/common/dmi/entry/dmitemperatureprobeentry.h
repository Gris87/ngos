#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMITEMPERATUREPROBEENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMITEMPERATUREPROBEENTRY_H



#include <com/ngos/shared/common/dmi/dmientryheader.h>
#include <com/ngos/shared/common/dmi/dmistringid.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmitemperatureprobelocationandstatus.h>



#define DMI_TEMPERATURE_PROBE_MAXIMUM_VALUE_UNKNOWN 0x8000
#define DMI_TEMPERATURE_PROBE_MINIMUM_VALUE_UNKNOWN 0x8000
#define DMI_TEMPERATURE_PROBE_RESOLUTION_UNKNOWN    0x8000
#define DMI_TEMPERATURE_PROBE_TOLERANCE_UNKNOWN     0x8000
#define DMI_TEMPERATURE_PROBE_ACCURACY_UNKNOWN      0x8000
#define DMI_TEMPERATURE_PROBE_NOMINAL_VALUE_UNKNOWN 0x8000



struct DmiTemperatureProbeEntry
{
    DmiEntryHeader                       header;
    DmiStringId                          description;
    DmiTemperatureProbeLocationAndStatus locationAndStatus;
    u16                                  maximumValue;
    u16                                  minimumValue;
    u16                                  resolution;
    u16                                  tolerance;
    u16                                  accuracy;
    u32                                  oemDefined;
    u16                                  nominalValue;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMITEMPERATUREPROBEENTRY_H
