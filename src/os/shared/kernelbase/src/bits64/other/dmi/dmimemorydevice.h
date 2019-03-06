#ifndef DMIMEMORYDEVICE_H
#define DMIMEMORYDEVICE_H



#include <ngos/types.h>



struct DmiMemoryDevice
{
    const char *device;
    const char *bank;
    u64         size;
    u16         handle;
};



#endif // DMIMEMORYDEVICE_H
