#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_DMIMEMORYDEVICE_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_DMIMEMORYDEVICE_H



#include <ngos/types.h>



struct DmiMemoryDevice
{
    u16          handle;
    u64          size;
    const char8 *deviceLocator;
    const char8 *manufacturer;
    const char8 *serialNumber;
    const char8 *partNumber;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_DMIMEMORYDEVICE_H
