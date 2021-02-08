#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSPOWERBUDGETINGPOWERRAIL_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSPOWERBUDGETINGPOWERRAIL_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressPowerBudgetingPowerRail: u8
{
    POWER_12V  = 0,
    POWER_3_3V = 1,
    POWER_1_8V = 2,
    THERMAL    = 7
};



inline const char8* enumToString(PciExpressPowerBudgetingPowerRail rail) // TEST: NO
{
    // COMMON_LT((" | rail = %u", rail)); // Commented to avoid bad looking logs



    switch (rail)
    {
        case PciExpressPowerBudgetingPowerRail::POWER_12V:  return "POWER_12V";
        case PciExpressPowerBudgetingPowerRail::POWER_3_3V: return "POWER_3_3V";
        case PciExpressPowerBudgetingPowerRail::POWER_1_8V: return "POWER_1_8V";
        case PciExpressPowerBudgetingPowerRail::THERMAL:    return "THERMAL";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressPowerBudgetingPowerRail rail) // TEST: NO
{
    // COMMON_LT((" | rail = %u", rail)); // Commented to avoid bad looking logs



    static char8 res[18];

    sprintf(res, "0x%02X (%s)", (u8)rail, enumToString(rail));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSPOWERBUDGETINGPOWERRAIL_H
