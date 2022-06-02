#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIONBOARDDEVICESEXTENDEDDEVICETYPEANDENABLED_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIONBOARDDEVICESEXTENDEDDEVICETYPEANDENABLED_H



#include <com/ngos/shared/common/dmi/lib/entry/lib/dmionboarddevicesextendeddevicetype.h>



struct DmiOnboardDevicesExtendedDeviceTypeAndEnabled
{
    union
    {
        struct
        {
            u8 deviceType: 7; // TODO: Use enum DmiOnboardDevicesExtendedDeviceType
            u8 enabled:    1;
        };

        u8 value8;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIONBOARDDEVICESEXTENDEDDEVICETYPEANDENABLED_H
