#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMPOWERSUPPLYTYPE_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMPOWERSUPPLYTYPE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class DmiSystemPowerSupplyType: u8
{
    NONE      = 0,
    OTHER     = 1,
    UNKNOWN   = 2,
    LINEAR    = 3,
    SWITCHING = 4,
    BATTERY   = 5,
    UPS       = 6,
    CONVERTER = 7,
    REGULATOR = 8
};



inline const char8* enumToString(DmiSystemPowerSupplyType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case DmiSystemPowerSupplyType::NONE:      return "NONE";
        case DmiSystemPowerSupplyType::OTHER:     return "OTHER";
        case DmiSystemPowerSupplyType::UNKNOWN:   return "UNKNOWN";
        case DmiSystemPowerSupplyType::LINEAR:    return "LINEAR";
        case DmiSystemPowerSupplyType::SWITCHING: return "SWITCHING";
        case DmiSystemPowerSupplyType::BATTERY:   return "BATTERY";
        case DmiSystemPowerSupplyType::UPS:       return "UPS";
        case DmiSystemPowerSupplyType::CONVERTER: return "CONVERTER";
        case DmiSystemPowerSupplyType::REGULATOR: return "REGULATOR";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiSystemPowerSupplyType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[17];

    sprintf(res, "0x%02X (%s)", (u8)type, enumToString(type));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMPOWERSUPPLYTYPE_H
