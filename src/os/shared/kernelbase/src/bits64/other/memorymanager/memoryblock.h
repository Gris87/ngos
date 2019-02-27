#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_MEMORYMANAGER_MEMORYBLOCK_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_MEMORYMANAGER_MEMORYBLOCK_H



#include <kernelbase/src/bits64/other/memorymanager/memoryblocktype.h>



struct MemoryBlock
{
    MemoryBlockType memory;
    MemoryBlockType reserved;
};



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_MEMORYMANAGER_MEMORYBLOCK_H
