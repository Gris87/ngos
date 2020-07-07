#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICOOLINGDEVICETYPE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICOOLINGDEVICETYPE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class DmiCoolingDeviceType: u8
{
    NONE                     = 0,
    OTHER                    = 1,
    UNKNOWN                  = 2,
    FAN                      = 3,
    CENTRIFUGAL_BLOWER       = 4,
    CHIP_FAN                 = 5,
    CABINET_FAN              = 6,
    POWER_SUPPLY_FAN         = 7,
    HEAT_PIPE                = 8,
    INTEGRATED_REFRIGERATION = 9,
    ACTIVE_COOLING           = 16,
    PASSIVE_COOLING          = 17
};



inline const char8* enumToString(DmiCoolingDeviceType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case DmiCoolingDeviceType::NONE:                     return "NONE";
        case DmiCoolingDeviceType::OTHER:                    return "OTHER";
        case DmiCoolingDeviceType::UNKNOWN:                  return "UNKNOWN";
        case DmiCoolingDeviceType::FAN:                      return "FAN";
        case DmiCoolingDeviceType::CENTRIFUGAL_BLOWER:       return "CENTRIFUGAL_BLOWER";
        case DmiCoolingDeviceType::CHIP_FAN:                 return "CHIP_FAN";
        case DmiCoolingDeviceType::CABINET_FAN:              return "CABINET_FAN";
        case DmiCoolingDeviceType::POWER_SUPPLY_FAN:         return "POWER_SUPPLY_FAN";
        case DmiCoolingDeviceType::HEAT_PIPE:                return "HEAT_PIPE";
        case DmiCoolingDeviceType::INTEGRATED_REFRIGERATION: return "INTEGRATED_REFRIGERATION";
        case DmiCoolingDeviceType::ACTIVE_COOLING:           return "ACTIVE_COOLING";
        case DmiCoolingDeviceType::PASSIVE_COOLING:          return "PASSIVE_COOLING";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiCoolingDeviceType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICOOLINGDEVICETYPE_H
