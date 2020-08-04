#ifndef COM_NGOS_KERNEL_OTHER_MEMORYMANAGER_MEMORYBLOCK_H
#define COM_NGOS_KERNEL_OTHER_MEMORYMANAGER_MEMORYBLOCK_H



#include <com/ngos/kernel/other/memorymanager/memoryblocktype.h>



struct MemoryBlock
{
    MemoryBlockType memory;
    MemoryBlockType reserved;
};



#endif // COM_NGOS_KERNEL_OTHER_MEMORYMANAGER_MEMORYBLOCK_H
