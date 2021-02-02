#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMITEMPERATUREPROBELOCATIONANDSTATUS_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMITEMPERATUREPROBELOCATIONANDSTATUS_H



#include <com/ngos/shared/common/dmi/entry/lib/dmitemperatureprobelocation.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmitemperatureprobestatus.h>



struct DmiTemperatureProbeLocationAndStatus
{
    union
    {
        struct
        {
            bad_uint8 location: 5; // TODO: Use enum DmiTemperatureProbeLocation
            bad_uint8 status:   3; // TODO: Use enum DmiTemperatureProbeStatus
        };

        bad_uint8 value8;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMITEMPERATUREPROBELOCATIONANDSTATUS_H
