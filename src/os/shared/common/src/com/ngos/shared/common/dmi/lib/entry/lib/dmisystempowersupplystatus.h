#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMPOWERSUPPLYSTATUS_H                                                                                                                                // Colorize: green
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMPOWERSUPPLYSTATUS_H                                                                                                                                // Colorize: green
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
enum class DmiSystemPowerSupplyStatus: u16                                                                                                                                                                // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    NONE         = 0,                                                                                                                                                                                    // Colorize: green
    OTHER        = 1,                                                                                                                                                                                    // Colorize: green
    UNKNOWN      = 2,                                                                                                                                                                                    // Colorize: green
    OK           = 3,                                                                                                                                                                                    // Colorize: green
    NON_CRITICAL = 4,                                                                                                                                                                                    // Colorize: green
    CRITICAL     = 5                                                                                                                                                                                     // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToString(DmiSystemPowerSupplyStatus status) // TEST: NO                                                                                                                          // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | status = %u", status)); // Commented to avoid bad looking logs                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (status)                                                                                                                                                                                      // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case DmiSystemPowerSupplyStatus::NONE:         return "NONE";                                                                                                                                    // Colorize: green
        case DmiSystemPowerSupplyStatus::OTHER:        return "OTHER";                                                                                                                                   // Colorize: green
        case DmiSystemPowerSupplyStatus::UNKNOWN:      return "UNKNOWN";                                                                                                                                 // Colorize: green
        case DmiSystemPowerSupplyStatus::OK:           return "OK";                                                                                                                                      // Colorize: green
        case DmiSystemPowerSupplyStatus::NON_CRITICAL: return "NON_CRITICAL";                                                                                                                            // Colorize: green
        case DmiSystemPowerSupplyStatus::CRITICAL:     return "CRITICAL";                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToFullString(DmiSystemPowerSupplyStatus status) // TEST: NO                                                                                                                      // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | status = %u", status)); // Commented to avoid bad looking logs                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[22];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%04X (%s)", (u8)status, enumToString(status));                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMPOWERSUPPLYSTATUS_H                                                                                                                              // Colorize: green