#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMANAGEMENTDEVICETYPE_H                                                                                                                                   // Colorize: green
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMANAGEMENTDEVICETYPE_H                                                                                                                                   // Colorize: green
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
enum class DmiManagementDeviceType: u8                                                                                                                                                                   // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    NONE                         = 0,                                                                                                                                                                    // Colorize: green
    OTHER                        = 1,                                                                                                                                                                    // Colorize: green
    UNKNOWN                      = 2,                                                                                                                                                                    // Colorize: green
    NATIONAL_SEMICONDUCTOR_LM_75 = 3,                                                                                                                                                                    // Colorize: green
    NATIONAL_SEMICONDUCTOR_LM_78 = 4,                                                                                                                                                                    // Colorize: green
    NATIONAL_SEMICONDUCTOR_LM_79 = 5,                                                                                                                                                                    // Colorize: green
    NATIONAL_SEMICONDUCTOR_LM_80 = 6,                                                                                                                                                                    // Colorize: green
    NATIONAL_SEMICONDUCTOR_LM_81 = 7,                                                                                                                                                                    // Colorize: green
    ANALOG_DEVICES_ADM9240       = 8,                                                                                                                                                                    // Colorize: green
    DALLAS_SEMICONDUCTOR_DS1780  = 9,                                                                                                                                                                    // Colorize: green
    MAXIM_1617                   = 10,                                                                                                                                                                   // Colorize: green
    GENESYS_GL518SM              = 11,                                                                                                                                                                   // Colorize: green
    WINBOND_W83781D              = 12,                                                                                                                                                                   // Colorize: green
    HOLTEK_HT82H791              = 13                                                                                                                                                                    // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToString(DmiManagementDeviceType type) // TEST: NO                                                                                                                               // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (type)                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case DmiManagementDeviceType::NONE:                         return "NONE";                                                                                                                       // Colorize: green
        case DmiManagementDeviceType::OTHER:                        return "OTHER";                                                                                                                      // Colorize: green
        case DmiManagementDeviceType::UNKNOWN:                      return "UNKNOWN";                                                                                                                    // Colorize: green
        case DmiManagementDeviceType::NATIONAL_SEMICONDUCTOR_LM_75: return "NATIONAL_SEMICONDUCTOR_LM_75";                                                                                               // Colorize: green
        case DmiManagementDeviceType::NATIONAL_SEMICONDUCTOR_LM_78: return "NATIONAL_SEMICONDUCTOR_LM_78";                                                                                               // Colorize: green
        case DmiManagementDeviceType::NATIONAL_SEMICONDUCTOR_LM_79: return "NATIONAL_SEMICONDUCTOR_LM_79";                                                                                               // Colorize: green
        case DmiManagementDeviceType::NATIONAL_SEMICONDUCTOR_LM_80: return "NATIONAL_SEMICONDUCTOR_LM_80";                                                                                               // Colorize: green
        case DmiManagementDeviceType::NATIONAL_SEMICONDUCTOR_LM_81: return "NATIONAL_SEMICONDUCTOR_LM_81";                                                                                               // Colorize: green
        case DmiManagementDeviceType::ANALOG_DEVICES_ADM9240:       return "ANALOG_DEVICES_ADM9240";                                                                                                     // Colorize: green
        case DmiManagementDeviceType::DALLAS_SEMICONDUCTOR_DS1780:  return "DALLAS_SEMICONDUCTOR_DS1780";                                                                                                // Colorize: green
        case DmiManagementDeviceType::MAXIM_1617:                   return "MAXIM_1617";                                                                                                                 // Colorize: green
        case DmiManagementDeviceType::GENESYS_GL518SM:              return "GENESYS_GL518SM";                                                                                                            // Colorize: green
        case DmiManagementDeviceType::WINBOND_W83781D:              return "WINBOND_W83781D";                                                                                                            // Colorize: green
        case DmiManagementDeviceType::HOLTEK_HT82H791:              return "HOLTEK_HT82H791";                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const char8* enumToFullString(DmiManagementDeviceType type) // TEST: NO                                                                                                                           // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static char8 res[36];                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%02X (%s)", (u8)type, enumToString(type));                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMANAGEMENTDEVICETYPE_H                                                                                                                                 // Colorize: green