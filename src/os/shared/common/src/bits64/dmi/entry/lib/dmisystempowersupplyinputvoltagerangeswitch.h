#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMPOWERSUPPLYINPUTVOLTAGERANGESWITCH_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMPOWERSUPPLYINPUTVOLTAGERANGESWITCH_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>



enum class DmiSystemPowerSupplyInputVoltageRangeSwitch: u8
{
    NONE           = 0,
    OTHER          = 1,
    UNKNOWN        = 2,
    MANUAL         = 3,
    AUTO_SWITCH    = 4,
    WIDE_RANGE     = 5,
    NOT_APPLICABLE = 6
};



inline const char8* enumToString(DmiSystemPowerSupplyInputVoltageRangeSwitch rangeSwitch) // TEST: NO
{
    // COMMON_LT((" | rangeSwitch = %u", rangeSwitch)); // Commented to avoid bad looking logs



    switch (rangeSwitch)
    {
        case DmiSystemPowerSupplyInputVoltageRangeSwitch::NONE:           return "NONE";
        case DmiSystemPowerSupplyInputVoltageRangeSwitch::OTHER:          return "OTHER";
        case DmiSystemPowerSupplyInputVoltageRangeSwitch::UNKNOWN:        return "UNKNOWN";
        case DmiSystemPowerSupplyInputVoltageRangeSwitch::MANUAL:         return "MANUAL";
        case DmiSystemPowerSupplyInputVoltageRangeSwitch::AUTO_SWITCH:    return "AUTO_SWITCH";
        case DmiSystemPowerSupplyInputVoltageRangeSwitch::WIDE_RANGE:     return "WIDE_RANGE";
        case DmiSystemPowerSupplyInputVoltageRangeSwitch::NOT_APPLICABLE: return "NOT_APPLICABLE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiSystemPowerSupplyInputVoltageRangeSwitch rangeSwitch) // TEST: NO
{
    // COMMON_LT((" | rangeSwitch = %u", rangeSwitch)); // Commented to avoid bad looking logs



    static char8 res[22];

    sprintf(res, "0x%02X (%s)", rangeSwitch, enumToString(rangeSwitch));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMPOWERSUPPLYINPUTVOLTAGERANGESWITCH_H
