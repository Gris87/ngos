#ifndef KERNEL_SRC_COM_NGOS_KERNEL_OTHER_MEMORYMANAGER_MEMORYBLOCKTYPE_H
#define KERNEL_SRC_COM_NGOS_KERNEL_OTHER_MEMORYMANAGER_MEMORYBLOCKTYPE_H



#include <com/ngos/kernel/other/memorymanager/memoryblockregion.h>



struct MemoryBlockType
{
    u64                count;
    u64                max;
    u64                totalSize;
    MemoryBlockRegion *regions;
};



#endif // KERNEL_SRC_COM_NGOS_KERNEL_OTHER_MEMORYMANAGER_MEMORYBLOCKTYPE_H
