#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPHYSICALMEMORYARRAYUSE_H                                                                                                                                 // Colorize: green
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPHYSICALMEMORYARRAYUSE_H                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/log/assert.h>                                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/log/log.h>                                                                                                                                                              // Colorize: green
#include <com/ngos/shared/common/ngos/types.h>                                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/printf/printf.h>                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
enum class DmiPhysicalMemoryArrayUse: u8                                                                                                                                                                 // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    NONE             = 0,                                                                                                                                                                                // Colorize: green
    OTHER            = 1,                                                                                                                                                                                // Colorize: green
    UNKNOWN          = 2,                                                                                                                                                                                // Colorize: green
    SYSTEM_MEMORY    = 3,                                                                                                                                                                                // Colorize: green
    VIDEO_MEMORY     = 4,                                                                                                                                                                                // Colorize: green
    FLASH_MEMORY     = 5,                                                                                                                                                                                // Colorize: green
    NON_VOLATILE_RAM = 6,                                                                                                                                                                                // Colorize: green
    CACHE_MEMORY     = 7                                                                                                                                                                                 // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToString(DmiPhysicalMemoryArrayUse use) // TEST: NO                                                                                                                              // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | use = %u", use)); // Commented to avoid bad looking logs                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (use)                                                                                                                                                                                         // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case DmiPhysicalMemoryArrayUse::NONE:             return "NONE";                                                                                                                                 // Colorize: green
        case DmiPhysicalMemoryArrayUse::OTHER:            return "OTHER";                                                                                                                                // Colorize: green
        case DmiPhysicalMemoryArrayUse::UNKNOWN:          return "UNKNOWN";                                                                                                                              // Colorize: green
        case DmiPhysicalMemoryArrayUse::SYSTEM_MEMORY:    return "SYSTEM_MEMORY";                                                                                                                        // Colorize: green
        case DmiPhysicalMemoryArrayUse::VIDEO_MEMORY:     return "VIDEO_MEMORY";                                                                                                                         // Colorize: green
        case DmiPhysicalMemoryArrayUse::FLASH_MEMORY:     return "FLASH_MEMORY";                                                                                                                         // Colorize: green
        case DmiPhysicalMemoryArrayUse::NON_VOLATILE_RAM: return "NON_VOLATILE_RAM";                                                                                                                     // Colorize: green
        case DmiPhysicalMemoryArrayUse::CACHE_MEMORY:     return "CACHE_MEMORY";                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToFullString(DmiPhysicalMemoryArrayUse use) // TEST: NO                                                                                                                          // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | use = %u", use)); // Commented to avoid bad looking logs                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[24];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%02X (%s)", (u8)use, enumToString(use));                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPHYSICALMEMORYARRAYUSE_H                                                                                                                               // Colorize: green