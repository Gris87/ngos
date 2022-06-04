#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICOOLINGDEVICETYPE_H                                                                                                                                      // Colorize: green
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICOOLINGDEVICETYPE_H                                                                                                                                      // Colorize: green
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
enum class DmiCoolingDeviceType: u8                                                                                                                                                                      // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    NONE                     = 0,                                                                                                                                                                        // Colorize: green
    OTHER                    = 1,                                                                                                                                                                        // Colorize: green
    UNKNOWN                  = 2,                                                                                                                                                                        // Colorize: green
    FAN                      = 3,                                                                                                                                                                        // Colorize: green
    CENTRIFUGAL_BLOWER       = 4,                                                                                                                                                                        // Colorize: green
    CHIP_FAN                 = 5,                                                                                                                                                                        // Colorize: green
    CABINET_FAN              = 6,                                                                                                                                                                        // Colorize: green
    POWER_SUPPLY_FAN         = 7,                                                                                                                                                                        // Colorize: green
    HEAT_PIPE                = 8,                                                                                                                                                                        // Colorize: green
    INTEGRATED_REFRIGERATION = 9,                                                                                                                                                                        // Colorize: green
    ACTIVE_COOLING           = 16,                                                                                                                                                                       // Colorize: green
    PASSIVE_COOLING          = 17                                                                                                                                                                        // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToString(DmiCoolingDeviceType type) // TEST: NO                                                                                                                                  // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (type)                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case DmiCoolingDeviceType::NONE:                     return "NONE";                                                                                                                              // Colorize: green
        case DmiCoolingDeviceType::OTHER:                    return "OTHER";                                                                                                                             // Colorize: green
        case DmiCoolingDeviceType::UNKNOWN:                  return "UNKNOWN";                                                                                                                           // Colorize: green
        case DmiCoolingDeviceType::FAN:                      return "FAN";                                                                                                                               // Colorize: green
        case DmiCoolingDeviceType::CENTRIFUGAL_BLOWER:       return "CENTRIFUGAL_BLOWER";                                                                                                                // Colorize: green
        case DmiCoolingDeviceType::CHIP_FAN:                 return "CHIP_FAN";                                                                                                                          // Colorize: green
        case DmiCoolingDeviceType::CABINET_FAN:              return "CABINET_FAN";                                                                                                                       // Colorize: green
        case DmiCoolingDeviceType::POWER_SUPPLY_FAN:         return "POWER_SUPPLY_FAN";                                                                                                                  // Colorize: green
        case DmiCoolingDeviceType::HEAT_PIPE:                return "HEAT_PIPE";                                                                                                                         // Colorize: green
        case DmiCoolingDeviceType::INTEGRATED_REFRIGERATION: return "INTEGRATED_REFRIGERATION";                                                                                                          // Colorize: green
        case DmiCoolingDeviceType::ACTIVE_COOLING:           return "ACTIVE_COOLING";                                                                                                                    // Colorize: green
        case DmiCoolingDeviceType::PASSIVE_COOLING:          return "PASSIVE_COOLING";                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToFullString(DmiCoolingDeviceType type) // TEST: NO                                                                                                                              // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[32];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%02X (%s)", (u8)type, enumToString(type));                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICOOLINGDEVICETYPE_H                                                                                                                                    // Colorize: green
