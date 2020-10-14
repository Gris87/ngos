#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIONBOARDDEVICESDEVICETYPEANDENABLED_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIONBOARDDEVICESDEVICETYPEANDENABLED_H



#include <com/ngos/shared/common/dmi/entry/lib/dmionboarddevicesdevicetype.h>



struct DmiOnboardDevicesDeviceTypeAndEnabled
{
    union
    {
        struct
        {
            u8 deviceType: 7; // TODO: Use enum DmiOnboardDevicesDeviceType
            u8 enabled:    1;
        };

        u8 value8;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIONBOARDDEVICESDEVICETYPEANDENABLED_H
