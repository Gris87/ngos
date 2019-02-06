#ifndef OS_COMMON_SRC_BITS64_MEMORYMANAGER_MEMORYBLOCK_H
#define OS_COMMON_SRC_BITS64_MEMORYMANAGER_MEMORYBLOCK_H



#include <src/bits64/other/memorymanager/memoryblocktype.h>



struct MemoryBlock
{
    MemoryBlockType memory;
    MemoryBlockType reserved;
};



#endif // OS_COMMON_SRC_BITS64_MEMORYMANAGER_MEMORYBLOCK_H
