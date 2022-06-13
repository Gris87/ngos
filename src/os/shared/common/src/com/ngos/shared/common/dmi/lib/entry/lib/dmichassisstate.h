#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISSTATE_H                                                                                                                                           // Colorize: green
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISSTATE_H                                                                                                                                           // Colorize: green
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
// Verified with DmiSpecVerifier [BEGIN] // https://www.dmtf.org/sites/default/files/standards/documents/DSP0134_3.4.0.pdf                                                                               // Colorize: green
enum class DmiChassisState: good_U8                                                                                                                                                                      // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    NONE            = 0,                                                                                                                                                                                 // Colorize: green
    OTHER           = 1, // Other                                                                                                                                                                        // Colorize: green
    UNKNOWN         = 2, // Unknown                                                                                                                                                                      // Colorize: green
    SAFE            = 3, // Safe                                                                                                                                                                         // Colorize: green
    WARNING         = 4, // Warning                                                                                                                                                                      // Colorize: green
    CRITICAL        = 5, // Critical                                                                                                                                                                     // Colorize: green
    NON_RECOVERABLE = 6  // Non-recoverable                                                                                                                                                              // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
// Verified with DmiSpecVerifier [END] // https://www.dmtf.org/sites/default/files/standards/documents/DSP0134_3.4.0.pdf                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToString(DmiChassisState state) // TEST: NO                                                                                                                                      // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | state = %u", state)); // Commented to avoid bad looking logs                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (state)                                                                                                                                                                                       // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case DmiChassisState::NONE:            return "NONE";                                                                                                                                            // Colorize: green
        case DmiChassisState::OTHER:           return "OTHER";                                                                                                                                           // Colorize: green
        case DmiChassisState::UNKNOWN:         return "UNKNOWN";                                                                                                                                         // Colorize: green
        case DmiChassisState::SAFE:            return "SAFE";                                                                                                                                            // Colorize: green
        case DmiChassisState::WARNING:         return "WARNING";                                                                                                                                         // Colorize: green
        case DmiChassisState::CRITICAL:        return "CRITICAL";                                                                                                                                        // Colorize: green
        case DmiChassisState::NON_RECOVERABLE: return "NON_RECOVERABLE";                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToFullString(DmiChassisState state) // TEST: NO                                                                                                                                  // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | state = %u", state)); // Commented to avoid bad looking logs                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[23];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%02X (%s)", (u8)state, enumToString(state));                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISSTATE_H                                                                                                                                         // Colorize: green
