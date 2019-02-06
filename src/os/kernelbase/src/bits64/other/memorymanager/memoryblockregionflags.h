#ifndef OS_KERNELBASE_SRC_BITS64_OTHER_MEMORYMANAGER_MEMORYBLOCKREGIONFLAGS_H
#define OS_KERNELBASE_SRC_BITS64_OTHER_MEMORYMANAGER_MEMORYBLOCKREGIONFLAGS_H



#include <ngos/types.h>



typedef u8 memory_block_region_flags;

enum class MemoryBlockRegionFlag: memory_block_region_flags
{
    NONE    = 0,
    HOTPLUG = (1ULL << 0), // hotpluggable region
    MIRROR  = (1ULL << 1), // mirrored region
    NOMAP   = (1ULL << 2)  // don't add to kernel direct mapping
};



#endif // OS_KERNELBASE_SRC_BITS64_OTHER_MEMORYMANAGER_MEMORYBLOCKREGIONFLAGS_H
