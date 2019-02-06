#ifndef OS_KERNELBASE_SRC_BITS64_OTHER_MEMORYMANAGER_MEMORYBLOCKREGION_H
#define OS_KERNELBASE_SRC_BITS64_OTHER_MEMORYMANAGER_MEMORYBLOCKREGION_H



#include <ngos/types.h>
#include <src/bits64/log/assert.h>
#include <src/bits64/log/log.h>
#include <src/bits64/other/memorymanager/memoryblockregionflags.h>
#include <src/bits64/other/memorymanager/memoryblockregionnodeid.h>



struct MemoryBlockRegion
{
    u64                         start;
    u64                         size;
    memory_block_region_flags   flags;
    memory_block_region_node_id nodeId;



    inline u64 end()
    {
        COMMON_LT((""));



        return start + size;
    }
};



#endif // OS_KERNELBASE_SRC_BITS64_OTHER_MEMORYMANAGER_MEMORYBLOCKREGION_H
