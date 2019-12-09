#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPHYSICALMEMORYARRAYUSE_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPHYSICALMEMORYARRAYUSE_H



#include <ngos/types.h>



enum class DmiPhysicalMemoryArrayUse: u8
{
    NONE             = 0,
    OTHER            = 1,
    UNKNOWN          = 2,
    SYSTEM_MEMORY    = 3,
    VIDEO_MEMORY     = 4,
    FLASH_MEMORY     = 5,
    NON_VOLATILE_RAM = 6,
    CACHE_MEMORY     = 7
};



inline const char8* dmiPhysicalMemoryArrayUseToString(DmiPhysicalMemoryArrayUse use) // TEST: NO
{
    // COMMON_LT((" | use = %u", use)); // Commented to avoid bad looking logs



    switch (use)
    {
        case DmiPhysicalMemoryArrayUse::NONE:             return "NONE";
        case DmiPhysicalMemoryArrayUse::OTHER:            return "OTHER";
        case DmiPhysicalMemoryArrayUse::UNKNOWN:          return "UNKNOWN";
        case DmiPhysicalMemoryArrayUse::SYSTEM_MEMORY:    return "SYSTEM_MEMORY";
        case DmiPhysicalMemoryArrayUse::VIDEO_MEMORY:     return "VIDEO_MEMORY";
        case DmiPhysicalMemoryArrayUse::FLASH_MEMORY:     return "FLASH_MEMORY";
        case DmiPhysicalMemoryArrayUse::NON_VOLATILE_RAM: return "NON_VOLATILE_RAM";
        case DmiPhysicalMemoryArrayUse::CACHE_MEMORY:     return "CACHE_MEMORY";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPHYSICALMEMORYARRAYUSE_H
