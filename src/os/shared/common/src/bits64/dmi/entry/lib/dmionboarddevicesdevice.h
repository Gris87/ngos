#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIONBOARDDEVICESDEVICE_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIONBOARDDEVICESDEVICE_H



#include <common/src/bits64/dmi/entry/lib/dmionboarddevicesdevicetype.h>



struct DmiOnboardDevicesDevice
{
    u8 enabled:    1;
    u8 deviceType: 7; // TODO: Use enum DmiOnboardDevicesDeviceType

    u8 descriptionStringId;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIONBOARDDEVICESDEVICE_H
