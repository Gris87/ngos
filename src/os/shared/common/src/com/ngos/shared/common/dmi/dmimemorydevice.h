#ifndef COM_NGOS_SHARED_COMMON_DMI_DMIMEMORYDEVICE_H
#define COM_NGOS_SHARED_COMMON_DMI_DMIMEMORYDEVICE_H



#include <com/ngos/shared/common/dmi/entry/lib/dmimemorydevicetype.h>
#include <com/ngos/shared/common/ngos/types.h>



#define MEMORY_DEVICE_SIZE_UNKNOWN 0xFFFFFFFFFFFFFFFF



struct DmiMemoryDevice
{
    DmiMemoryDeviceType  memoryType;
    bad_uint32                  speed;
    bad_uint64                  size;
    bad_uint64                  start;
    bad_uint64                  end;
    const char8         *deviceLocator;
    const char8         *manufacturer;
    const char8         *serialNumber;
    const char8         *partNumber;
};



#endif // COM_NGOS_SHARED_COMMON_DMI_DMIMEMORYDEVICE_H
