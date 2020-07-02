#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_DMIMEMORYDEVICE_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_DMIMEMORYDEVICE_H



#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmimemorydevicetype.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



#define MEMORY_DEVICE_SIZE_UNKNOWN 0xFFFFFFFFFFFFFFFF



struct DmiMemoryDevice
{
    DmiMemoryDeviceType  memoryType;
    u32                  speed;
    u64                  size;
    u64                  start;
    u64                  end;
    const char8         *deviceLocator;
    const char8         *manufacturer;
    const char8         *serialNumber;
    const char8         *partNumber;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_DMIMEMORYDEVICE_H
