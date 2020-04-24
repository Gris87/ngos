#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIVOLTAGEPROBEENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIVOLTAGEPROBEENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/entry/lib/dmivoltageprobelocation.h>
#include <common/src/bits64/dmi/entry/lib/dmivoltageprobestatus.h>



#define DMI_VOLTAGE_PROBE_MAXIMUM_VALUE_UNKNOWN 0x8000
#define DMI_VOLTAGE_PROBE_MINIMUM_VALUE_UNKNOWN 0x8000
#define DMI_VOLTAGE_PROBE_RESOLUTION_UNKNOWN    0x8000
#define DMI_VOLTAGE_PROBE_TOLERANCE_UNKNOWN     0x8000
#define DMI_VOLTAGE_PROBE_ACCURACY_UNKNOWN      0x8000
#define DMI_VOLTAGE_PROBE_NOMINAL_VALUE_UNKNOWN 0x8000



struct DmiVoltageProbeEntry
{
    DmiEntryHeader header;
    u8             descriptionStringId;

    union
    {
        struct
        {
            u8 location: 5; // TODO: Use enum DmiVoltageProbeLocation
            u8 status:   3; // TODO: Use enum DmiVoltageProbeStatus
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



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIVOLTAGEPROBEENTRY_H
