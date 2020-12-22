#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIPOWERMANAGEMENTDATASELECT_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIPOWERMANAGEMENTDATASELECT_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciPowerManagementDataSelect: u8
{
    D0_POWER_CONSUMED              = 0,
    D1_POWER_CONSUMED              = 1,
    D2_POWER_CONSUMED              = 2,
    D3_POWER_CONSUMED              = 3,
    D0_POWER_DISSIPATED            = 4,
    D1_POWER_DISSIPATED            = 5,
    D2_POWER_DISSIPATED            = 6,
    D3_POWER_DISSIPATED            = 7,
    COMMON_LOGIC_POWER_CONSUMPTION = 8
};



inline const char8* enumToString(PciPowerManagementDataSelect select) // TEST: NO
{
    // COMMON_LT((" | select = %u", select)); // Commented to avoid bad looking logs



    switch (select)
    {
        case PciPowerManagementDataSelect::D0_POWER_CONSUMED:              return "D0_POWER_CONSUMED";
        case PciPowerManagementDataSelect::D1_POWER_CONSUMED:              return "D1_POWER_CONSUMED";
        case PciPowerManagementDataSelect::D2_POWER_CONSUMED:              return "D2_POWER_CONSUMED";
        case PciPowerManagementDataSelect::D3_POWER_CONSUMED:              return "D3_POWER_CONSUMED";
        case PciPowerManagementDataSelect::D0_POWER_DISSIPATED:            return "D0_POWER_DISSIPATED";
        case PciPowerManagementDataSelect::D1_POWER_DISSIPATED:            return "D1_POWER_DISSIPATED";
        case PciPowerManagementDataSelect::D2_POWER_DISSIPATED:            return "D2_POWER_DISSIPATED";
        case PciPowerManagementDataSelect::D3_POWER_DISSIPATED:            return "D3_POWER_DISSIPATED";
        case PciPowerManagementDataSelect::COMMON_LOGIC_POWER_CONSUMPTION: return "COMMON_LOGIC_POWER_CONSUMPTION";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciPowerManagementDataSelect select) // TEST: NO
{
    // COMMON_LT((" | select = %u", select)); // Commented to avoid bad looking logs



    static char8 res[38];

    sprintf(res, "0x%02X (%s)", (u8)select, enumToString(select));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIPOWERMANAGEMENTDATASELECT_H
