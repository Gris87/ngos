#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSACTIVESTATEPOWERMANAGEMENTSUPPORT_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSACTIVESTATEPOWERMANAGEMENTSUPPORT_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressActiveStatePowerManagementSupport: bad_uint8
{
    NONE                 = 0,
    L0S_ENTRY_SUPPORTED  = 1,
    L1_ENTRY_SUPPORTED   = 2,
    L0S_AND_L1_SUPPORTED = 3
};



inline const char8* enumToString(PciExpressActiveStatePowerManagementSupport support) // TEST: NO
{
    // COMMON_LT((" | support = %u", support)); // Commented to avoid bad looking logs



    switch (support)
    {
        case PciExpressActiveStatePowerManagementSupport::NONE:                 return "NONE";
        case PciExpressActiveStatePowerManagementSupport::L0S_ENTRY_SUPPORTED:  return "L0S_ENTRY_SUPPORTED";
        case PciExpressActiveStatePowerManagementSupport::L1_ENTRY_SUPPORTED:   return "L1_ENTRY_SUPPORTED";
        case PciExpressActiveStatePowerManagementSupport::L0S_AND_L1_SUPPORTED: return "L0S_AND_L1_SUPPORTED";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressActiveStatePowerManagementSupport support) // TEST: NO
{
    // COMMON_LT((" | support = %u", support)); // Commented to avoid bad looking logs



    static char8 res[28];

    sprintf(res, "0x%02X (%s)", (bad_uint8)support, enumToString(support));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSACTIVESTATEPOWERMANAGEMENTSUPPORT_H
