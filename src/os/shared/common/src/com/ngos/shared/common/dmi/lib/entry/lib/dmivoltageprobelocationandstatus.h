#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIVOLTAGEPROBELOCATIONANDSTATUS_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIVOLTAGEPROBELOCATIONANDSTATUS_H



#include <com/ngos/shared/common/dmi/lib/entry/lib/dmivoltageprobelocation.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmivoltageprobestatus.h>



struct DmiVoltageProbeLocationAndStatus
{
    union
    {
        struct
        {
            u8 location: 5; // TODO: Use enum DmiVoltageProbeLocation
            u8 status:   3; // TODO: Use enum DmiVoltageProbeStatus
        };

        u8 value8;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIVOLTAGEPROBELOCATIONANDSTATUS_H
