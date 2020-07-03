#ifndef KERNEL_SRC_COM_NGOS_KERNEL_OTHER_MEMORYMANAGER_MEMORYBLOCKREGION_H
#define KERNEL_SRC_COM_NGOS_KERNEL_OTHER_MEMORYMANAGER_MEMORYBLOCKREGION_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>

#include <com/ngos/kernel/other/memorymanager/memoryblockregionflags.h>
#include <com/ngos/kernel/other/memorymanager/memoryblockregionnodeid.h>



struct MemoryBlockRegion
{
    u64                         start;
    u64                         size;
    MemoryBlockRegionFlags      flags;
    memory_block_region_node_id nodeId; // TODO: encapsulate into a struct



    inline u64 end()
    {
        COMMON_LT((""));



        return start + size;
    }
};



#endif // KERNEL_SRC_COM_NGOS_KERNEL_OTHER_MEMORYMANAGER_MEMORYBLOCKREGION_H
