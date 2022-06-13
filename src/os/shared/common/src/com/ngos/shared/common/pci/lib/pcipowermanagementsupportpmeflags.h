#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIPOWERMANAGEMENTSUPPORTPMEFLAGS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIPOWERMANAGEMENTSUPPORTPMEFLAGS_H



#include <com/ngos/shared/common/bits/flags.h>
#include <com/ngos/shared/common/bits/macros.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u8 pci_power_management_support_pme_flags;

enum class PciPowerManagementSupportPmeFlag: pci_power_management_support_pme_flags
{
    NONE         = 0,
    FROM_D0      = BIT_0,
    FROM_D1      = BIT_1,
    FROM_D2      = BIT_2,
    FROM_D3_HOT  = BIT_3,
    FROM_D3_COLD = BIT_4
};

DEFINE_FLAGS(PciPowerManagementSupportPmeFlags, pci_power_management_support_pme_flags); // TEST: NO



inline const char8* flagToString(PciPowerManagementSupportPmeFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case PciPowerManagementSupportPmeFlag::NONE:         return "NONE";
        case PciPowerManagementSupportPmeFlag::FROM_D0:      return "FROM_D0";
        case PciPowerManagementSupportPmeFlag::FROM_D1:      return "FROM_D1";
        case PciPowerManagementSupportPmeFlag::FROM_D2:      return "FROM_D2";
        case PciPowerManagementSupportPmeFlag::FROM_D3_HOT:  return "FROM_D3_HOT";
        case PciPowerManagementSupportPmeFlag::FROM_D3_COLD: return "FROM_D3_COLD";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(PciPowerManagementSupportPmeFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (pci_power_management_support_pme_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const PciPowerManagementSupportPmeFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[72];

    FLAGS_TO_STRING(res, flags.flags, PciPowerManagementSupportPmeFlag);

    return res;
}



inline const char8* flagsToFullString(const PciPowerManagementSupportPmeFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[79];

    FLAGS_TO_FULL_STRING(res, flags.flags, PciPowerManagementSupportPmeFlag, "0x%02X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIPOWERMANAGEMENTSUPPORTPMEFLAGS_H
