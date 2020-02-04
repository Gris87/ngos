#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMITEMPERATUREPROBEENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMITEMPERATUREPROBEENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/entry/lib/dmitemperatureprobelocation.h>
#include <common/src/bits64/dmi/entry/lib/dmitemperatureprobestatus.h>



struct DmiTemperatureProbeEntry
{
    DmiEntryHeader header;
    u8             descriptionStringId;

    union
    {
        struct
        {
            u8 location: 5; // TODO: Use enum DmiTemperatureProbeLocation
            u8 status:   3; // TODO: Use enum DmiTemperatureProbeStatus
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



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMITEMPERATUREPROBEENTRY_H
