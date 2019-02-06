#ifndef OS_COMMON_SRC_BITS64_MEMORYMANAGER_MEMORYMANAGER_H
#define OS_COMMON_SRC_BITS64_MEMORYMANAGER_MEMORYMANAGER_H



#include <ngos/status.h>
#include <ngos/types.h>
#include <src/bits64/other/memorymanager/memoryblock.h>



#define INIT_MEMORYBLOCK_REGIONS 128



class MemoryManager
{
public:
    static NgosStatus init();
    static NgosStatus insertRegion(MemoryBlockType *type, u64 index, u64 start, u64 size, memory_block_region_flags flags, memory_block_region_node_id nodeId);
    static NgosStatus removeRegion(MemoryBlockType *type, u64 index);
    static NgosStatus removeRegions(MemoryBlockType *type, u64 index, u64 count);
    static NgosStatus mergeRegions(MemoryBlockType *type);
    static NgosStatus addRange(MemoryBlockType *type, u64 start, u64 size, memory_block_region_flags flags, memory_block_region_node_id nodeId);
    static NgosStatus add(u64 start, u64 size);
    static NgosStatus reserve(u64 start, u64 size);

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static MemoryBlock       sMemoryBlock;
    static MemoryBlockRegion sMemoryRegions[INIT_MEMORYBLOCK_REGIONS];
    static MemoryBlockRegion sReservedRegions[INIT_MEMORYBLOCK_REGIONS];
};



#endif // OS_COMMON_SRC_BITS64_MEMORYMANAGER_MEMORYMANAGER_H
