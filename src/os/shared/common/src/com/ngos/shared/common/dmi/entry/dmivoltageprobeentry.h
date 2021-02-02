#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIVOLTAGEPROBEENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIVOLTAGEPROBEENTRY_H



#include <com/ngos/shared/common/dmi/dmientryheader.h>
#include <com/ngos/shared/common/dmi/dmistringid.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmivoltageprobelocationandstatus.h>



#define DMI_VOLTAGE_PROBE_MAXIMUM_VALUE_UNKNOWN 0x8000
#define DMI_VOLTAGE_PROBE_MINIMUM_VALUE_UNKNOWN 0x8000
#define DMI_VOLTAGE_PROBE_RESOLUTION_UNKNOWN    0x8000
#define DMI_VOLTAGE_PROBE_TOLERANCE_UNKNOWN     0x8000
#define DMI_VOLTAGE_PROBE_ACCURACY_UNKNOWN      0x8000
#define DMI_VOLTAGE_PROBE_NOMINAL_VALUE_UNKNOWN 0x8000



struct DmiVoltageProbeEntry
{
    DmiEntryHeader                   header;
    DmiStringId                      description;
    DmiVoltageProbeLocationAndStatus locationAndStatus;
    bad_uint16                              maximumValue;
    bad_uint16                              minimumValue;
    bad_uint16                              resolution;
    bad_uint16                              tolerance;
    bad_uint16                              accuracy;
    bad_uint32                              oemDefined;
    bad_uint16                              nominalValue;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIVOLTAGEPROBEENTRY_H
