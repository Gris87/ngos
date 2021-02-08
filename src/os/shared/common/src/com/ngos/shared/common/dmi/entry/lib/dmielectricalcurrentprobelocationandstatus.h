#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIELECTRICALCURRENTPROBELOCATIONANDSTATUS_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIELECTRICALCURRENTPROBELOCATIONANDSTATUS_H



#include <com/ngos/shared/common/dmi/entry/lib/dmielectricalcurrentprobelocation.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmielectricalcurrentprobestatus.h>



struct DmiElectricalCurrentProbeLocationAndStatus
{
    union
    {
        struct
        {
            u8 location: 5; // TODO: Use enum DmiElectricalCurrentProbeLocation
            u8 status:   3; // TODO: Use enum DmiElectricalCurrentProbeStatus
        };

        u8 value8;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIELECTRICALCURRENTPROBELOCATIONANDSTATUS_H
