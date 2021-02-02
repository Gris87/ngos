#ifndef COM_NGOS_KERNEL_OTHER_MEMORYMANAGER_MEMORYBLOCKTYPE_H
#define COM_NGOS_KERNEL_OTHER_MEMORYMANAGER_MEMORYBLOCKTYPE_H



#include <com/ngos/kernel/other/memorymanager/memoryblockregion.h>



struct MemoryBlockType
{
    bad_uint64                count;
    bad_uint64                max;
    bad_uint64                totalSize;
    MemoryBlockRegion *regions;
};



#endif // COM_NGOS_KERNEL_OTHER_MEMORYMANAGER_MEMORYBLOCKTYPE_H
