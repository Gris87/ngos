#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMSLOTSPEERGROUP_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMSLOTSPEERGROUP_H



#include <com/ngos/shared/common/dmi/entry/lib/dmifunctionnumberanddevicenumber.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmisystemslotsdatabuswidth.h>



struct DmiSystemSlotsPeerGroup
{
    u16                              segmentGroupNumber;
    u8                               busNumber;
    DmiFunctionNumberAndDeviceNumber functionNumberAndDeviceNumber;
    u8                               dataBusWidth;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMSLOTSPEERGROUP_H
