#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_DMIMEMORYDEVICE_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_DMIMEMORYDEVICE_H



#include <ngos/types.h>



struct DmiMemoryDevice
{
    const char8 *device;
    const char8 *bank;
    u64          size;
    u16          handle;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_DMIMEMORYDEVICE_H
