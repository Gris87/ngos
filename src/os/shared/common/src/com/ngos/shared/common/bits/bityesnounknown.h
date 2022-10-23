#ifndef COM_NGOS_SHARED_COMMON_BITS_BITYESNOUKNOWN_H                                                                                                                                                           // Colorize: green
#define COM_NGOS_SHARED_COMMON_BITS_BITYESNOUKNOWN_H                                                                                                                                                           // Colorize: green
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
enum class BitYesNoUnknown: good_U8                                                                                                                                                                             // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    NO_OR_UNKNOWN = 0,                                                                                                                                                                                             // Colorize: green
    YES           = 1                                                                                                                                                                                              // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToString(BitYesNoUnknown unknown) // TEST: NO                                                                                                                                               // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | unknown = %u", unknown)); // Commented to avoid bad looking logs                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (unknown)                                                                                                                                                                                         // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case BitYesNoUnknown::NO_OR_UNKNOWN: return "NO_OR_UNKNOWN";                                                                                                                                                                // Colorize: green
        case BitYesNoUnknown::YES:           return "YES";                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToFullString(BitYesNoUnknown unknown) // TEST: NO                                                                                                                                           // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | unknown = %u", unknown)); // Commented to avoid bad looking logs                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[15];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%02X (%s)", static_cast<good_U8>(unknown), enumToString(unknown));                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToHumanString(BitYesNoUnknown unknown) // TEST: NO                                                                                                                                          // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | unknown = %u", unknown)); // Commented to avoid bad looking logs                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (unknown)                                                                                                                                                                                         // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case BitYesNoUnknown::NO_OR_UNKNOWN: return "No / Unknown";                                                                                                                                                                // Colorize: green
        case BitYesNoUnknown::YES:           return "Yes";                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_BITS_BITYESNOUKNOWN_H                                                                                                                                                         // Colorize: green