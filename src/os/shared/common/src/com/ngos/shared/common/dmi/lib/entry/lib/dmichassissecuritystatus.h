#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISSECURITYSTATUS_H                                                                                                                                  // Colorize: green
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISSECURITYSTATUS_H                                                                                                                                  // Colorize: green
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
enum class DmiChassisSecurityStatus: u8                                                                                                                                                                  // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    NULL                              = 0,                                                                                                                                                               // Colorize: green
    OTHER                             = 1,                                                                                                                                                               // Colorize: green
    UNKNOWN                           = 2,                                                                                                                                                               // Colorize: green
    NONE                              = 3,                                                                                                                                                               // Colorize: green
    EXTERNAL_INTERFACE_LOCKED_OUT     = 4,                                                                                                                                                               // Colorize: green
    EXTERNAL_INTERFACE_LOCKED_ENABLED = 5                                                                                                                                                                // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToString(DmiChassisSecurityStatus status) // TEST: NO                                                                                                                            // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | status = %u", status)); // Commented to avoid bad looking logs                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (status)                                                                                                                                                                                      // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case DmiChassisSecurityStatus::NULL:                              return "NULL";                                                                                                                 // Colorize: green
        case DmiChassisSecurityStatus::OTHER:                             return "OTHER";                                                                                                                // Colorize: green
        case DmiChassisSecurityStatus::UNKNOWN:                           return "UNKNOWN";                                                                                                              // Colorize: green
        case DmiChassisSecurityStatus::NONE:                              return "NONE";                                                                                                                 // Colorize: green
        case DmiChassisSecurityStatus::EXTERNAL_INTERFACE_LOCKED_OUT:     return "EXTERNAL_INTERFACE_LOCKED_OUT";                                                                                        // Colorize: green
        case DmiChassisSecurityStatus::EXTERNAL_INTERFACE_LOCKED_ENABLED: return "EXTERNAL_INTERFACE_LOCKED_ENABLED";                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToFullString(DmiChassisSecurityStatus status) // TEST: NO                                                                                                                        // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | status = %u", status)); // Commented to avoid bad looking logs                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[41];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%02X (%s)", (u8)status, enumToString(status));                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISSECURITYSTATUS_H                                                                                                                                // Colorize: green