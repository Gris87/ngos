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
            bad_uint8 location: 5; // TODO: Use enum DmiElectricalCurrentProbeLocation
            bad_uint8 status:   3; // TODO: Use enum DmiElectricalCurrentProbeStatus
        };

        bad_uint8 value8;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIELECTRICALCURRENTPROBELOCATIONANDSTATUS_H
