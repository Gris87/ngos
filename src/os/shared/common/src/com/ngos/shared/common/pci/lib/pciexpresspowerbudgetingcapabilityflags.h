#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSPOWERBUDGETINGCAPABILITYFLAGS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSPOWERBUDGETINGCAPABILITYFLAGS_H



#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef bad_uint8 pci_express_power_budgeting_capability_flags;

enum class PciExpressPowerBudgetingCapabilityFlag: pci_express_power_budgeting_capability_flags
{
    NONE             = 0,
    SYSTEM_ALLOCATED = (1ULL << 0)
};

DEFINE_FLAGS(PciExpressPowerBudgetingCapabilityFlags, pci_express_power_budgeting_capability_flags); // TEST: NO



inline const char8* flagToString(PciExpressPowerBudgetingCapabilityFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case PciExpressPowerBudgetingCapabilityFlag::NONE:             return "NONE";
        case PciExpressPowerBudgetingCapabilityFlag::SYSTEM_ALLOCATED: return "SYSTEM_ALLOCATED";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(PciExpressPowerBudgetingCapabilityFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[24];

    sprintf(res, "0x%02X (%s)", (pci_express_power_budgeting_capability_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const PciExpressPowerBudgetingCapabilityFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[32];

    FLAGS_TO_STRING(res, flags.flags, PciExpressPowerBudgetingCapabilityFlag);

    return res;
}



inline const char8* flagsToFullString(const PciExpressPowerBudgetingCapabilityFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[39];

    FLAGS_TO_FULL_STRING(res, flags.flags, PciExpressPowerBudgetingCapabilityFlag, "0x%02X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSPOWERBUDGETINGCAPABILITYFLAGS_H
