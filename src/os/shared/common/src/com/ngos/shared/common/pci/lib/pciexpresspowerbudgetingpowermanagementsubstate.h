#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSPOWERBUDGETINGPOWERMANAGEMENTSUBSTATE_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSPOWERBUDGETINGPOWERMANAGEMENTSUBSTATE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressPowerBudgetingPowerManagementSubState: u8
{
    DEFAULT           = 0,
    DEVICE_SPECIFIC_1 = 1,
    DEVICE_SPECIFIC_2 = 2,
    DEVICE_SPECIFIC_3 = 3,
    DEVICE_SPECIFIC_4 = 4,
    DEVICE_SPECIFIC_5 = 5,
    DEVICE_SPECIFIC_6 = 6,
    DEVICE_SPECIFIC_7 = 7
};



inline const char8* enumToString(PciExpressPowerBudgetingPowerManagementSubState state) // TEST: NO
{
    // COMMON_LT((" | state = %u", state)); // Commented to avoid bad looking logs



    switch (state)
    {
        case PciExpressPowerBudgetingPowerManagementSubState::DEFAULT:           return "DEFAULT";
        case PciExpressPowerBudgetingPowerManagementSubState::DEVICE_SPECIFIC_1: return "DEVICE_SPECIFIC_1";
        case PciExpressPowerBudgetingPowerManagementSubState::DEVICE_SPECIFIC_2: return "DEVICE_SPECIFIC_2";
        case PciExpressPowerBudgetingPowerManagementSubState::DEVICE_SPECIFIC_3: return "DEVICE_SPECIFIC_3";
        case PciExpressPowerBudgetingPowerManagementSubState::DEVICE_SPECIFIC_4: return "DEVICE_SPECIFIC_4";
        case PciExpressPowerBudgetingPowerManagementSubState::DEVICE_SPECIFIC_5: return "DEVICE_SPECIFIC_5";
        case PciExpressPowerBudgetingPowerManagementSubState::DEVICE_SPECIFIC_6: return "DEVICE_SPECIFIC_6";
        case PciExpressPowerBudgetingPowerManagementSubState::DEVICE_SPECIFIC_7: return "DEVICE_SPECIFIC_7";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressPowerBudgetingPowerManagementSubState state) // TEST: NO
{
    // COMMON_LT((" | state = %u", state)); // Commented to avoid bad looking logs



    static char8 res[25];

    sprintf(res, "0x%02X (%s)", (u8)state, enumToString(state));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSPOWERBUDGETINGPOWERMANAGEMENTSUBSTATE_H
