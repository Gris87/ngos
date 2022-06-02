#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICOOLINGDEVICETYPEANDSTATUS_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICOOLINGDEVICETYPEANDSTATUS_H



#include <com/ngos/shared/common/dmi/lib/entry/lib/dmicoolingdevicestatus.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmicoolingdevicetype.h>



struct DmiCoolingDeviceTypeAndStatus
{
    union
    {
        struct
        {
            u8 deviceType: 5; // TODO: Use enum DmiCoolingDeviceType
            u8 status:     3; // TODO: Use enum DmiCoolingDeviceStatus
        };

        u8 value8;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICOOLINGDEVICETYPEANDSTATUS_H
