#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMITEMPERATUREPROBELOCATIONANDSTATUS_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMITEMPERATUREPROBELOCATIONANDSTATUS_H



#include <com/ngos/shared/common/dmi/lib/entry/lib/dmitemperatureprobelocation.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmitemperatureprobestatus.h>



struct DmiTemperatureProbeLocationAndStatus
{
    union
    {
        struct
        {
            u8 location: 5; // TODO: Use enum DmiTemperatureProbeLocation
            u8 status:   3; // TODO: Use enum DmiTemperatureProbeStatus
        };

        u8 value8;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMITEMPERATUREPROBELOCATIONANDSTATUS_H
