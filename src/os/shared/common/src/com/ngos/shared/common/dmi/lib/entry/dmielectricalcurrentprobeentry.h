#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIELECTRICALCURRENTPROBEENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIELECTRICALCURRENTPROBEENTRY_H



#include <com/ngos/shared/common/dmi/lib/dmientryheader.h>
#include <com/ngos/shared/common/dmi/lib/dmistringid.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmielectricalcurrentprobelocationandstatus.h>



#define DMI_ELECTRICAL_CURRENT_PROBE_MAXIMUM_VALUE_UNKNOWN 0x8000
#define DMI_ELECTRICAL_CURRENT_PROBE_MINIMUM_VALUE_UNKNOWN 0x8000
#define DMI_ELECTRICAL_CURRENT_PROBE_RESOLUTION_UNKNOWN    0x8000
#define DMI_ELECTRICAL_CURRENT_PROBE_TOLERANCE_UNKNOWN     0x8000
#define DMI_ELECTRICAL_CURRENT_PROBE_ACCURACY_UNKNOWN      0x8000
#define DMI_ELECTRICAL_CURRENT_PROBE_NOMINAL_VALUE_UNKNOWN 0x8000



struct DmiElectricalCurrentProbeEntry
{
    DmiEntryHeader                             header;
    DmiStringId                                description;
    DmiElectricalCurrentProbeLocationAndStatus locationAndStatus;
    u16                                        maximumValue;
    u16                                        minimumValue;
    u16                                        resolution;
    u16                                        tolerance;
    u16                                        accuracy;
    u32                                        oemDefined;
    u16                                        nominalValue;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIELECTRICALCURRENTPROBEENTRY_H
