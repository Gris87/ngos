#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSPOWERBUDGETINGPOWERMANAGEMENTSTATE_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSPOWERBUDGETINGPOWERMANAGEMENTSTATE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressPowerBudgetingPowerManagementState: u8
{
    D0 = 0,
    D1 = 1,
    D2 = 2,
    D3 = 3
};



inline const char8* enumToString(PciExpressPowerBudgetingPowerManagementState state) // TEST: NO
{
    // COMMON_LT((" | state = %u", state)); // Commented to avoid bad looking logs



    switch (state)
    {
        case PciExpressPowerBudgetingPowerManagementState::D0: return "D0";
        case PciExpressPowerBudgetingPowerManagementState::D1: return "D1";
        case PciExpressPowerBudgetingPowerManagementState::D2: return "D2";
        case PciExpressPowerBudgetingPowerManagementState::D3: return "D3";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressPowerBudgetingPowerManagementState state) // TEST: NO
{
    // COMMON_LT((" | state = %u", state)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", (u8)state, enumToString(state));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSPOWERBUDGETINGPOWERMANAGEMENTSTATE_H
