#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIONBOARDDEVICESDEVICE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIONBOARDDEVICESDEVICE_H



#include <common/src/com/ngos/shared/common/dmi/dmistringid.h>
#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmionboarddevicesdevicetype.h>



struct DmiOnboardDevicesDevice
{
    union
    {
        struct
        {
            u8 deviceType: 7; // TODO: Use enum DmiOnboardDevicesDeviceType
            u8 enabled:    1;
        };

        u8 deviceTypeAndEnabled;
    };

    DmiStringId description;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIONBOARDDEVICESDEVICE_H
