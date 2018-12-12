#ifndef OS_KERNELBASE_SRC_BITS64_OTHER_MEMORYMANAGER_MEMORYBLOCKTYPE_H
#define OS_KERNELBASE_SRC_BITS64_OTHER_MEMORYMANAGER_MEMORYBLOCKTYPE_H



#include <src/bits64/other/memorymanager/memoryblockregion.h>



struct MemoryBlockType
{
    u64                count;
    u64                max;
    u64                totalSize;
    MemoryBlockRegion *regions;
};



#endif // OS_KERNELBASE_SRC_BITS64_OTHER_MEMORYMANAGER_MEMORYBLOCKTYPE_H
