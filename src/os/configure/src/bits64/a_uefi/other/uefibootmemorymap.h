#ifndef CONFIGURE_SRC_BITS64_A_UEFI_OTHER_UEFIBOOTMEMORYMAP_H
#define CONFIGURE_SRC_BITS64_A_UEFI_OTHER_UEFIBOOTMEMORYMAP_H



#include <ngos/types.h>

#include "src/bits64/a_uefi/uefi/lib/efimemorydescriptor.h"



struct UefiBootMemoryMap
{
    EfiMemoryDescriptor **memoryMap;
    u64                  *memoryMapSize;
    u64                  *descriptorSize;
    u32                  *descriptorVersion;
    u64                  *mapKey;
    u64                  *bufferSize;
};



#endif // CONFIGURE_SRC_BITS64_A_UEFI_OTHER_UEFIBOOTMEMORYMAP_H
