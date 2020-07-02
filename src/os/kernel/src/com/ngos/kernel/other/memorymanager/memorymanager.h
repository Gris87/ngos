#ifndef KERNEL_SRC_COM_NGOS_KERNEL_OTHER_MEMORYMANAGER_MEMORYMANAGER_H
#define KERNEL_SRC_COM_NGOS_KERNEL_OTHER_MEMORYMANAGER_MEMORYMANAGER_H



#include <ngos/status.h>
#include <ngos/types.h>

#include <src/com/ngos/kernel/other/memorymanager/memoryblock.h>



#define INIT_MEMORYBLOCK_REGIONS 128



class MemoryManager
{
public:
    static NgosStatus init();

    static NgosStatus add(u64 start, u64 size);
    static NgosStatus reserve(u64 start, u64 size);

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static NgosStatus insertRegion(MemoryBlockType *type, u64 index, u64 start, u64 size, const MemoryBlockRegionFlags &flags, memory_block_region_node_id nodeId);
    static NgosStatus removeRegion(MemoryBlockType *type, u64 index);
    static NgosStatus removeRegions(MemoryBlockType *type, u64 index, u64 count);
    static NgosStatus mergeRegions(MemoryBlockType *type);
    static NgosStatus addRange(MemoryBlockType *type, u64 start, u64 size, const MemoryBlockRegionFlags &flags, memory_block_region_node_id nodeId);

    static MemoryBlock       sMemoryBlock;
    static MemoryBlockRegion sMemoryRegions[INIT_MEMORYBLOCK_REGIONS];
    static MemoryBlockRegion sReservedRegions[INIT_MEMORYBLOCK_REGIONS];
};



#endif // KERNEL_SRC_COM_NGOS_KERNEL_OTHER_MEMORYMANAGER_MEMORYMANAGER_H
