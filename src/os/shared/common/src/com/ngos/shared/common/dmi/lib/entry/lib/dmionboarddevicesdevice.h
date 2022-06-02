#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIONBOARDDEVICESDEVICE_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIONBOARDDEVICESDEVICE_H



#include <com/ngos/shared/common/dmi/lib/dmistringid.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmionboarddevicesdevicetypeandenabled.h>



struct DmiOnboardDevicesDevice
{
    DmiOnboardDevicesDeviceTypeAndEnabled deviceTypeAndEnabled;
    DmiStringId                           description;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIONBOARDDEVICESDEVICE_H
