#ifndef COM_NGOS_SHARED_COMMON_CPU_CPUVENDOR_H                                                                                                                                                           // Colorize: green
#define COM_NGOS_SHARED_COMMON_CPU_CPUVENDOR_H                                                                                                                                                           // Colorize: green
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
enum class CpuVendor: good_U8                                                                                                                                                                            // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    NONE    = 0,                                                                                                                                                                                         // Colorize: green
    INTEL   = 1,                                                                                                                                                                                         // Colorize: green
    AMD     = 2,                                                                                                                                                                                         // Colorize: green
    UNKNOWN = 3                                                                                                                                                                                          // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToString(CpuVendor vendor) // TEST: NO                                                                                                                                           // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | vendor = %u", vendor)); // Commented to avoid bad looking logs                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (vendor)                                                                                                                                                                                      // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case CpuVendor::NONE:    return "NONE";                                                                                                                                                          // Colorize: green
        case CpuVendor::INTEL:   return "INTEL";                                                                                                                                                         // Colorize: green
        case CpuVendor::AMD:     return "AMD";                                                                                                                                                           // Colorize: green
        case CpuVendor::UNKNOWN: return "UNKNOWN";                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToFullString(CpuVendor vendor) // TEST: NO                                                                                                                                       // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | vendor = %u", vendor)); // Commented to avoid bad looking logs                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[15];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%02X (%s)", static_cast<good_U8>(vendor), enumToString(vendor));                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_CPU_CPUVENDOR_H                                                                                                                                                         // Colorize: green