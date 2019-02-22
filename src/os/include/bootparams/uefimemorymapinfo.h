#ifndef BOOTPARAMS_UEFIMEMORYMAPINFO_H
#define BOOTPARAMS_UEFIMEMORYMAPINFO_H



#include <ngos/types.h>
#include <uefi/uefimemorydescriptor.h>



struct UefiMemoryMapInfo
{
    UefiMemoryDescriptor *map;
    u64                   size;
    u64                   descriptorSize;
    u32                   descriptorVersion;
};



#endif // BOOTPARAMS_UEFIMEMORYMAPINFO_H
