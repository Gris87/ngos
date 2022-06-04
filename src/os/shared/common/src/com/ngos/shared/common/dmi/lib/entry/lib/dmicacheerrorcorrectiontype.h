#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHEERRORCORRECTIONTYPE_H                                                                                                                               // Colorize: green
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHEERRORCORRECTIONTYPE_H                                                                                                                               // Colorize: green
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
enum class DmiCacheErrorCorrectionType: u8                                                                                                                                                               // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    NULL       = 0,                                                                                                                                                                                      // Colorize: green
    OTHER      = 1,                                                                                                                                                                                      // Colorize: green
    UNKNOWN    = 2,                                                                                                                                                                                      // Colorize: green
    NONE       = 3,                                                                                                                                                                                      // Colorize: green
    PARITY     = 4,                                                                                                                                                                                      // Colorize: green
    SINGLE_BIT = 5,                                                                                                                                                                                      // Colorize: green
    MULTI_BIT  = 6                                                                                                                                                                                       // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToString(DmiCacheErrorCorrectionType type) // TEST: NO                                                                                                                           // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (type)                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case DmiCacheErrorCorrectionType::NULL:       return "NULL";                                                                                                                                     // Colorize: green
        case DmiCacheErrorCorrectionType::OTHER:      return "OTHER";                                                                                                                                    // Colorize: green
        case DmiCacheErrorCorrectionType::UNKNOWN:    return "UNKNOWN";                                                                                                                                  // Colorize: green
        case DmiCacheErrorCorrectionType::NONE:       return "NONE";                                                                                                                                     // Colorize: green
        case DmiCacheErrorCorrectionType::PARITY:     return "PARITY";                                                                                                                                   // Colorize: green
        case DmiCacheErrorCorrectionType::SINGLE_BIT: return "SINGLE_BIT";                                                                                                                               // Colorize: green
        case DmiCacheErrorCorrectionType::MULTI_BIT:  return "MULTI_BIT";                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToFullString(DmiCacheErrorCorrectionType type) // TEST: NO                                                                                                                       // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[18];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%02X (%s)", (u8)type, enumToString(type));                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHEERRORCORRECTIONTYPE_H                                                                                                                             // Colorize: green
