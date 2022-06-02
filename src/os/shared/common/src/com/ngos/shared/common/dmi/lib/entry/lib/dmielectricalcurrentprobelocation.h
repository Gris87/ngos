#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIELECTRICALCURRENTPROBELOCATION_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIELECTRICALCURRENTPROBELOCATION_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



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
    ADD_IN_CARD              = 11
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

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiElectricalCurrentProbeLocation location) // TEST: NO
{
    // COMMON_LT((" | location = %u", location)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%02X (%s)", (u8)location, enumToString(location));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIELECTRICALCURRENTPROBELOCATION_H
