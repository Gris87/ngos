#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIELECTRICALCURRENTPROBELOCATION_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIELECTRICALCURRENTPROBELOCATION_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>



enum class DmiElectricalCurrentProbeLocation: u8
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



inline const char8* enumToString(DmiElectricalCurrentProbeLocation location) // TEST: NO
{
    // COMMON_LT((" | location = %u", location)); // Commented to avoid bad looking logs



    switch (location)
    {
        case DmiElectricalCurrentProbeLocation::NONE:                     return "NONE";
        case DmiElectricalCurrentProbeLocation::OTHER:                    return "OTHER";
        case DmiElectricalCurrentProbeLocation::UNKNOWN:                  return "UNKNOWN";
        case DmiElectricalCurrentProbeLocation::PROCESSOR:                return "PROCESSOR";
        case DmiElectricalCurrentProbeLocation::DISK:                     return "DISK";
        case DmiElectricalCurrentProbeLocation::PERIPHERAL_BAY:           return "PERIPHERAL_BAY";
        case DmiElectricalCurrentProbeLocation::SYSTEM_MANAGEMENT_MODULE: return "SYSTEM_MANAGEMENT_MODULE";
        case DmiElectricalCurrentProbeLocation::MOTHERBOARD:              return "MOTHERBOARD";
        case DmiElectricalCurrentProbeLocation::MEMORY_MODULE:            return "MEMORY_MODULE";
        case DmiElectricalCurrentProbeLocation::PROCESSOR_MODULE:         return "PROCESSOR_MODULE";
        case DmiElectricalCurrentProbeLocation::POWER_UNIT:               return "POWER_UNIT";
        case DmiElectricalCurrentProbeLocation::ADD_IN_CARD:              return "ADD_IN_CARD";
        case DmiElectricalCurrentProbeLocation::FRONT_PANEL_BOARD:        return "FRONT_PANEL_BOARD";
        case DmiElectricalCurrentProbeLocation::BACK_PANEL_BOARD:         return "BACK_PANEL_BOARD";
        case DmiElectricalCurrentProbeLocation::POWER_SYSTEM_BOARD:       return "POWER_SYSTEM_BOARD";
        case DmiElectricalCurrentProbeLocation::DRIVE_BACK_PLANE:         return "DRIVE_BACK_PLANE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiElectricalCurrentProbeLocation location) // TEST: NO
{
    // COMMON_LT((" | location = %u", location)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%02X (%s)", location, enumToString(location));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIELECTRICALCURRENTPROBELOCATION_H
