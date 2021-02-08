#ifndef COM_NGOS_SHARED_UEFIBASE_OTHER_UEFIBOOTMEMORYMAP_H
#define COM_NGOS_SHARED_UEFIBASE_OTHER_UEFIBOOTMEMORYMAP_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/uefi/uefimemorydescriptor.h>



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



#endif // COM_NGOS_SHARED_UEFIBASE_OTHER_UEFIBOOTMEMORYMAP_H
