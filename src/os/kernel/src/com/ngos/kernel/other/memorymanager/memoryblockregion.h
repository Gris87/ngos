#ifndef COM_NGOS_KERNEL_OTHER_MEMORYMANAGER_MEMORYBLOCKREGION_H
#define COM_NGOS_KERNEL_OTHER_MEMORYMANAGER_MEMORYBLOCKREGION_H



#include <com/ngos/kernel/other/memorymanager/memoryblockregionflags.h>
#include <com/ngos/kernel/other/memorymanager/memoryblockregionnodeid.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>



struct MemoryBlockRegion
{
    bad_uint64                         start;
    bad_uint64                         size;
    MemoryBlockRegionFlags      flags;
    memory_block_region_node_id nodeId; // TODO: encapsulate into a struct



    inline bad_uint64 end()
    {
        COMMON_LT((""));



        return start + size;
    }
};



#endif // COM_NGOS_KERNEL_OTHER_MEMORYMANAGER_MEMORYBLOCKREGION_H
