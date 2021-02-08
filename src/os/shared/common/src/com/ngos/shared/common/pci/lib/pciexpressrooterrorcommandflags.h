#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTERRORCOMMANDFLAGS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTERRORCOMMANDFLAGS_H



#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u32 pci_express_root_error_command_flags;

enum class PciExpressRootErrorCommandFlag: pci_express_root_error_command_flags
{
    NONE                        = 0,
    CORRECTABLE_ERROR_REPORTING = (1ULL << 0),
    NON_FATAL_ERROR_REPORTING   = (1ULL << 1),
    FATAL_ERROR_REPORTING       = (1ULL << 2)
};

DEFINE_FLAGS(PciExpressRootErrorCommandFlags, pci_express_root_error_command_flags); // TEST: NO



inline const char8* flagToString(PciExpressRootErrorCommandFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case PciExpressRootErrorCommandFlag::NONE:                        return "NONE";
        case PciExpressRootErrorCommandFlag::CORRECTABLE_ERROR_REPORTING: return "CORRECTABLE_ERROR_REPORTING";
        case PciExpressRootErrorCommandFlag::NON_FATAL_ERROR_REPORTING:   return "NON_FATAL_ERROR_REPORTING";
        case PciExpressRootErrorCommandFlag::FATAL_ERROR_REPORTING:       return "FATAL_ERROR_REPORTING";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(PciExpressRootErrorCommandFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[41];

    sprintf(res, "0x%08X (%s)", (pci_express_root_error_command_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const PciExpressRootErrorCommandFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[95];

    FLAGS_TO_STRING(res, flags.flags, PciExpressRootErrorCommandFlag);

    return res;
}



inline const char8* flagsToFullString(const PciExpressRootErrorCommandFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[108];

    FLAGS_TO_FULL_STRING(res, flags.flags, PciExpressRootErrorCommandFlag, "0x%08X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTERRORCOMMANDFLAGS_H
