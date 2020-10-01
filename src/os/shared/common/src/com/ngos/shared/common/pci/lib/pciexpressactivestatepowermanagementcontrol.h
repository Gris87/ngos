#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSACTIVESTATEPOWERMANAGEMENTCONTROL_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSACTIVESTATEPOWERMANAGEMENTCONTROL_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressActiveStatePowerManagementControl: u8
{
    DISABLED           = 0,
    L0S_ENTRY_ENABLED  = 1,
    L1_ENTRY_ENABLED   = 2,
    L0S_AND_L1_ENABLED = 3
};



inline const char8* enumToString(PciExpressActiveStatePowerManagementControl control) // TEST: NO
{
    // COMMON_LT((" | control = %u", control)); // Commented to avoid bad looking logs



    switch (control)
    {
        case PciExpressActiveStatePowerManagementControl::DISABLED:           return "DISABLED";
        case PciExpressActiveStatePowerManagementControl::L0S_ENTRY_ENABLED:  return "L0S_ENTRY_ENABLED";
        case PciExpressActiveStatePowerManagementControl::L1_ENTRY_ENABLED:   return "L1_ENTRY_ENABLED";
        case PciExpressActiveStatePowerManagementControl::L0S_AND_L1_ENABLED: return "L0S_AND_L1_ENABLED";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressActiveStatePowerManagementControl control) // TEST: NO
{
    // COMMON_LT((" | control = %u", control)); // Commented to avoid bad looking logs



    static char8 res[26];

    sprintf(res, "0x%02X (%s)", (u8)control, enumToString(control));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSACTIVESTATEPOWERMANAGEMENTCONTROL_H
