#ifndef OS_SHARED_UEFIBASE_SRC_COM_NGOS_SHARED_UEFIBASE_OTHER_UEFIBOOTMEMORYMAP_H
#define OS_SHARED_UEFIBASE_SRC_COM_NGOS_SHARED_UEFIBASE_OTHER_UEFIBOOTMEMORYMAP_H



#include <common/src/com/ngos/shared/common/ngos/types.h>
#include <common/src/com/ngos/shared/common/uefi/uefimemorydescriptor.h>



#define MEMORY_MAP_DESCRIPTOR(bootMemoryMap, i) (UefiMemoryDescriptor *)((u64)(*(bootMemoryMap)->memoryMap) + (i) * (*(bootMemoryMap)->descriptorSize))



struct UefiBootMemoryMap
{
    UefiMemoryDescriptor **memoryMap;
    u64                   *memoryMapSize;
    u64                   *descriptorSize;
    u32                   *descriptorVersion;
    u64                   *mapKey;
    u64                   *bufferSize;
};



#endif // OS_SHARED_UEFIBASE_SRC_COM_NGOS_SHARED_UEFIBASE_OTHER_UEFIBOOTMEMORYMAP_H
