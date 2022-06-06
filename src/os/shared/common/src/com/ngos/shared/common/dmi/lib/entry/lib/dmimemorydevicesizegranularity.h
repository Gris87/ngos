#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICESIZEGRANULARITY_H                                                                                                                            // Colorize: green
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICESIZEGRANULARITY_H                                                                                                                            // Colorize: green
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
enum class DmiMemoryDeviceSizeGranularity: u8                                                                                                                                                            // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    _1_MEGABYTE = 0,                                                                                                                                                                                     // Colorize: green
    _1_KILOBYTE = 1                                                                                                                                                                                      // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToString(DmiMemoryDeviceSizeGranularity granularity) // TEST: NO                                                                                                                 // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | granularity = %u", granularity)); // Commented to avoid bad looking logs                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (granularity)                                                                                                                                                                                 // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case DmiMemoryDeviceSizeGranularity::_1_MEGABYTE: return "1_MEGABYTE";                                                                                                                           // Colorize: green
        case DmiMemoryDeviceSizeGranularity::_1_KILOBYTE: return "1_KILOBYTE";                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToFullString(DmiMemoryDeviceSizeGranularity granularity) // TEST: NO                                                                                                             // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | granularity = %u", granularity)); // Commented to avoid bad looking logs                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[18];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%02X (%s)", (u8)granularity, enumToString(granularity));                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICESIZEGRANULARITY_H                                                                                                                          // Colorize: green