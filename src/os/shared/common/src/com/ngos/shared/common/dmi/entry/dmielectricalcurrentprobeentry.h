#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIELECTRICALCURRENTPROBEENTRY_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIELECTRICALCURRENTPROBEENTRY_H



#include <common/src/com/ngos/shared/common/dmi/dmientryheader.h>
#include <common/src/com/ngos/shared/common/dmi/dmistringid.h>
#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmielectricalcurrentprobelocation.h>
#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmielectricalcurrentprobestatus.h>



#define DMI_ELECTRICAL_CURRENT_PROBE_MAXIMUM_VALUE_UNKNOWN 0x8000
#define DMI_ELECTRICAL_CURRENT_PROBE_MINIMUM_VALUE_UNKNOWN 0x8000
#define DMI_ELECTRICAL_CURRENT_PROBE_RESOLUTION_UNKNOWN    0x8000
#define DMI_ELECTRICAL_CURRENT_PROBE_TOLERANCE_UNKNOWN     0x8000
#define DMI_ELECTRICAL_CURRENT_PROBE_ACCURACY_UNKNOWN      0x8000
#define DMI_ELECTRICAL_CURRENT_PROBE_NOMINAL_VALUE_UNKNOWN 0x8000



struct DmiElectricalCurrentProbeEntry
{
    DmiEntryHeader header;
    DmiStringId    description;

    union
    {
        struct
        {
            u8 location: 5; // TODO: Use enum DmiElectricalCurrentProbeLocation
            u8 status:   3; // TODO: Use enum DmiElectricalCurrentProbeStatus
        };

        u8 locationAndStatus;
    };

    u16 maximumValue;
    u16 minimumValue;
    u16 resolution;
    u16 tolerance;
    u16 accuracy;
    u32 oemDefined;
    u16 nominalValue;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIELECTRICALCURRENTPROBEENTRY_H
