#ifndef BOOTPARAMS_UEFIMEMORYMAPINFO_H
#define BOOTPARAMS_UEFIMEMORYMAPINFO_H



#include <common/src/com/ngos/shared/common/ngos/types.h>
#include <common/src/com/ngos/shared/common/uefi/uefimemorydescriptor.h>



struct UefiMemoryMapInfo
{
    UefiMemoryDescriptor *map;
    u64                   size;
    u64                   descriptorSize;
    u32                   descriptorVersion;
};



#endif // BOOTPARAMS_UEFIMEMORYMAPINFO_H
