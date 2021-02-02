#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIONBOARDDEVICESEXTENDEDDEVICETYPEANDENABLED_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIONBOARDDEVICESEXTENDEDDEVICETYPEANDENABLED_H



#include <com/ngos/shared/common/dmi/entry/lib/dmionboarddevicesextendeddevicetype.h>



struct DmiOnboardDevicesExtendedDeviceTypeAndEnabled
{
    union
    {
        struct
        {
            bad_uint8 deviceType: 7; // TODO: Use enum DmiOnboardDevicesExtendedDeviceType
            bad_uint8 enabled:    1;
        };

        bad_uint8 value8;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIONBOARDDEVICESEXTENDEDDEVICETYPEANDENABLED_H
