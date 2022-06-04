#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICOOLINGDEVICESTATUS_H                                                                                                                                    // Colorize: green
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICOOLINGDEVICESTATUS_H                                                                                                                                    // Colorize: green
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
enum class DmiCoolingDeviceStatus: u8                                                                                                                                                                    // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    NONE            = 0,                                                                                                                                                                                 // Colorize: green
    OTHER           = 1,                                                                                                                                                                                 // Colorize: green
    UNKNOWN         = 2,                                                                                                                                                                                 // Colorize: green
    OK              = 3,                                                                                                                                                                                 // Colorize: green
    NON_CRITICAL    = 4,                                                                                                                                                                                 // Colorize: green
    CRITICAL        = 5,                                                                                                                                                                                 // Colorize: green
    NON_RECOVERABLE = 6                                                                                                                                                                                  // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToString(DmiCoolingDeviceStatus status) // TEST: NO                                                                                                                              // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | status = %u", status)); // Commented to avoid bad looking logs                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (status)                                                                                                                                                                                      // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case DmiCoolingDeviceStatus::NONE:            return "NONE";                                                                                                                                     // Colorize: green
        case DmiCoolingDeviceStatus::OTHER:           return "OTHER";                                                                                                                                    // Colorize: green
        case DmiCoolingDeviceStatus::UNKNOWN:         return "UNKNOWN";                                                                                                                                  // Colorize: green
        case DmiCoolingDeviceStatus::OK:              return "OK";                                                                                                                                       // Colorize: green
        case DmiCoolingDeviceStatus::NON_CRITICAL:    return "NON_CRITICAL";                                                                                                                             // Colorize: green
        case DmiCoolingDeviceStatus::CRITICAL:        return "CRITICAL";                                                                                                                                 // Colorize: green
        case DmiCoolingDeviceStatus::NON_RECOVERABLE: return "NON_RECOVERABLE";                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToFullString(DmiCoolingDeviceStatus status) // TEST: NO                                                                                                                          // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | status = %u", status)); // Commented to avoid bad looking logs                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[23];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%02X (%s)", (u8)status, enumToString(status));                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICOOLINGDEVICESTATUS_H                                                                                                                                  // Colorize: green
