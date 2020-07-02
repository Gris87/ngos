#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_MEMORYMANAGER_MEMORYBLOCKTYPE_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_MEMORYMANAGER_MEMORYBLOCKTYPE_H



#include <kernelbase/src/bits64/other/memorymanager/memoryblockregion.h>



struct MemoryBlockType
{
    u64                count;
    u64                max;
    u64                totalSize;
    MemoryBlockRegion *regions;
};



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_MEMORYMANAGER_MEMORYBLOCKTYPE_H
