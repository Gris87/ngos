#ifndef COM_NGOS_KERNEL_OTHER_MEMORYMANAGER_MEMORYBLOCKREGIONFLAGS_H
#define COM_NGOS_KERNEL_OTHER_MEMORYMANAGER_MEMORYBLOCKREGIONFLAGS_H



#include <com/ngos/shared/common/bits/flags.h>
#include <com/ngos/shared/common/bits/macros.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u8 memory_block_region_flags;

enum class MemoryBlockRegionFlag: memory_block_region_flags
{
    NONE    = 0,
    HOTPLUG = BIT_0, // hotpluggable region
    MIRROR  = BIT_1, // mirrored region
    NOMAP   = BIT_2  // don't add to kernel direct mapping
};

DEFINE_FLAGS(MemoryBlockRegionFlags, memory_block_region_flags); // TEST: NO



inline const char8* flagToString(MemoryBlockRegionFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case MemoryBlockRegionFlag::NONE:    return "NONE";
        case MemoryBlockRegionFlag::HOTPLUG: return "HOTPLUG";
        case MemoryBlockRegionFlag::MIRROR:  return "MIRROR";
        case MemoryBlockRegionFlag::NOMAP:   return "NOMAP";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(MemoryBlockRegionFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", (memory_block_region_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const MemoryBlockRegionFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[40];

    FLAGS_TO_STRING(res, flags.flags, MemoryBlockRegionFlag);

    return res;
}



inline const char8* flagsToFullString(const MemoryBlockRegionFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[47];

    FLAGS_TO_FULL_STRING(res, flags.flags, MemoryBlockRegionFlag, "0x%02X");

    return res;
}



#endif // COM_NGOS_KERNEL_OTHER_MEMORYMANAGER_MEMORYBLOCKREGIONFLAGS_H
