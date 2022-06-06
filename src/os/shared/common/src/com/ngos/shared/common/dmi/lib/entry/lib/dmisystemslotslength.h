#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMSLOTSLENGTH_H                                                                                                                                      // Colorize: green
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMSLOTSLENGTH_H                                                                                                                                      // Colorize: green
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
enum class DmiSystemSlotsLength: u8                                                                                                                                                                      // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    NONE                   = 0,                                                                                                                                                                          // Colorize: green
    OTHER                  = 1,                                                                                                                                                                          // Colorize: green
    UNKNOWN                = 2,                                                                                                                                                                          // Colorize: green
    SHORT                  = 3,                                                                                                                                                                          // Colorize: green
    LONG                   = 4,                                                                                                                                                                          // Colorize: green
    _2_5_DRIVE_FORM_FACTOR = 5,                                                                                                                                                                          // Colorize: green
    _3_5_DRIVE_FORM_FACTOR = 6                                                                                                                                                                           // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToString(DmiSystemSlotsLength length) // TEST: NO                                                                                                                                // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | length = %u", length)); // Commented to avoid bad looking logs                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (length)                                                                                                                                                                                      // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case DmiSystemSlotsLength::NONE:                   return "NONE";                                                                                                                                // Colorize: green
        case DmiSystemSlotsLength::OTHER:                  return "OTHER";                                                                                                                               // Colorize: green
        case DmiSystemSlotsLength::UNKNOWN:                return "UNKNOWN";                                                                                                                             // Colorize: green
        case DmiSystemSlotsLength::SHORT:                  return "SHORT";                                                                                                                               // Colorize: green
        case DmiSystemSlotsLength::LONG:                   return "LONG";                                                                                                                                // Colorize: green
        case DmiSystemSlotsLength::_2_5_DRIVE_FORM_FACTOR: return "2_5_DRIVE_FORM_FACTOR";                                                                                                               // Colorize: green
        case DmiSystemSlotsLength::_3_5_DRIVE_FORM_FACTOR: return "3_5_DRIVE_FORM_FACTOR";                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToFullString(DmiSystemSlotsLength length) // TEST: NO                                                                                                                            // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | length = %u", length)); // Commented to avoid bad looking logs                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[29];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%02X (%s)", (u8)length, enumToString(length));                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMSLOTSLENGTH_H                                                                                                                                    // Colorize: green