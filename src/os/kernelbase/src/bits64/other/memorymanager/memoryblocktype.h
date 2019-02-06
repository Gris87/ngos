#ifndef OS_COMMON_SRC_BITS64_MEMORYMANAGER_MEMORYBLOCKTYPE_H
#define OS_COMMON_SRC_BITS64_MEMORYMANAGER_MEMORYBLOCKTYPE_H



#include <src/bits64/other/memorymanager/memoryblockregion.h>



struct MemoryBlockType
{
    u64                count;
    u64                max;
    u64                totalSize;
    MemoryBlockRegion *regions;
};



#endif // OS_COMMON_SRC_BITS64_MEMORYMANAGER_MEMORYBLOCKTYPE_H
