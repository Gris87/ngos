#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_MEMORYMANAGER_MEMORYBLOCKREGION_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_MEMORYMANAGER_MEMORYBLOCKREGION_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <kernelbase/src/bits64/other/memorymanager/memoryblockregionflags.h>
#include <kernelbase/src/bits64/other/memorymanager/memoryblockregionnodeid.h>
#include <ngos/types.h>



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



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_MEMORYMANAGER_MEMORYBLOCKREGION_H
