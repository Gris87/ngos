#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMITEMPERATUREPROBELOCATION_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMITEMPERATUREPROBELOCATION_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class DmiTemperatureProbeLocation: bad_uint8
{
    NONE                     = 0,
    OTHER                    = 1,
    UNKNOWN                  = 2,
    PROCESSOR                = 3,
    DISK                     = 4,
    PERIPHERAL_BAY           = 5,
    SYSTEM_MANAGEMENT_MODULE = 6,
    MOTHERBOARD              = 7,
    MEMORY_MODULE            = 8,
    PROCESSOR_MODULE         = 9,
    POWER_UNIT               = 10,
    ADD_IN_CARD              = 11,
    FRONT_PANEL_BOARD        = 12,
    BACK_PANEL_BOARD         = 13,
    POWER_SYSTEM_BOARD       = 14,
    DRIVE_BACK_PLANE         = 15
};



inline const char8* enumToString(DmiTemperatureProbeLocation location) // TEST: NO
{
    // COMMON_LT((" | location = %u", location)); // Commented to avoid bad looking logs



    switch (location)
    {
        case DmiTemperatureProbeLocation::NONE:                     return "NONE";
        case DmiTemperatureProbeLocation::OTHER:                    return "OTHER";
        case DmiTemperatureProbeLocation::UNKNOWN:                  return "UNKNOWN";
        case DmiTemperatureProbeLocation::PROCESSOR:                return "PROCESSOR";
        case DmiTemperatureProbeLocation::DISK:                     return "DISK";
        case DmiTemperatureProbeLocation::PERIPHERAL_BAY:           return "PERIPHERAL_BAY";
        case DmiTemperatureProbeLocation::SYSTEM_MANAGEMENT_MODULE: return "SYSTEM_MANAGEMENT_MODULE";
        case DmiTemperatureProbeLocation::MOTHERBOARD:              return "MOTHERBOARD";
        case DmiTemperatureProbeLocation::MEMORY_MODULE:            return "MEMORY_MODULE";
        case DmiTemperatureProbeLocation::PROCESSOR_MODULE:         return "PROCESSOR_MODULE";
        case DmiTemperatureProbeLocation::POWER_UNIT:               return "POWER_UNIT";
        case DmiTemperatureProbeLocation::ADD_IN_CARD:              return "ADD_IN_CARD";
        case DmiTemperatureProbeLocation::FRONT_PANEL_BOARD:        return "FRONT_PANEL_BOARD";
        case DmiTemperatureProbeLocation::BACK_PANEL_BOARD:         return "BACK_PANEL_BOARD";
        case DmiTemperatureProbeLocation::POWER_SYSTEM_BOARD:       return "POWER_SYSTEM_BOARD";
        case DmiTemperatureProbeLocation::DRIVE_BACK_PLANE:         return "DRIVE_BACK_PLANE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiTemperatureProbeLocation location) // TEST: NO
{
    // COMMON_LT((" | location = %u", location)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%02X (%s)", (bad_uint8)location, enumToString(location));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMITEMPERATUREPROBELOCATION_H
