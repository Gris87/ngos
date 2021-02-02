#ifndef COM_NGOS_SHARED_UEFIBASE_OTHER_UEFIBOOTMEMORYMAP_H
#define COM_NGOS_SHARED_UEFIBASE_OTHER_UEFIBOOTMEMORYMAP_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/uefi/uefimemorydescriptor.h>



#define MEMORY_MAP_DESCRIPTOR(bootMemoryMap, i) (UefiMemoryDescriptor *)((bad_uint64)(*(bootMemoryMap)->memoryMap) + (i) * (*(bootMemoryMap)->descriptorSize))



struct UefiBootMemoryMap
{
    UefiMemoryDescriptor **memoryMap;
    bad_uint64                   *memoryMapSize;
    bad_uint64                   *descriptorSize;
    bad_uint32                   *descriptorVersion;
    bad_uint64                   *mapKey;
    bad_uint64                   *bufferSize;
};



#endif // COM_NGOS_SHARED_UEFIBASE_OTHER_UEFIBOOTMEMORYMAP_H
