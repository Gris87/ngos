#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICOOLINGDEVICETYPEANDSTATUS_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICOOLINGDEVICETYPEANDSTATUS_H



#include <com/ngos/shared/common/dmi/entry/lib/dmicoolingdevicestatus.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmicoolingdevicetype.h>



struct DmiCoolingDeviceTypeAndStatus
{
    union
    {
        struct
        {
            bad_uint8 deviceType: 5; // TODO: Use enum DmiCoolingDeviceType
            bad_uint8 status:     3; // TODO: Use enum DmiCoolingDeviceStatus
        };

        bad_uint8 value8;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICOOLINGDEVICETYPEANDSTATUS_H
