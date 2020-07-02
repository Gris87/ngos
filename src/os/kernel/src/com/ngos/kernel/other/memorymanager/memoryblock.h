#ifndef KERNEL_SRC_COM_NGOS_KERNEL_OTHER_MEMORYMANAGER_MEMORYBLOCK_H
#define KERNEL_SRC_COM_NGOS_KERNEL_OTHER_MEMORYMANAGER_MEMORYBLOCK_H



#include <src/com/ngos/kernel/other/memorymanager/memoryblocktype.h>



struct MemoryBlock
{
    MemoryBlockType memory;
    MemoryBlockType reserved;
};



#endif // KERNEL_SRC_COM_NGOS_KERNEL_OTHER_MEMORYMANAGER_MEMORYBLOCK_H
