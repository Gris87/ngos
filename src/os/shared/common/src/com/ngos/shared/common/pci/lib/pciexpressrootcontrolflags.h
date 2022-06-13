#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCONTROLFLAGS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCONTROLFLAGS_H



#include <com/ngos/shared/common/bits/flags.h>
#include <com/ngos/shared/common/bits/macros.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u16 pci_express_root_control_flags;

enum class PciExpressRootControlFlag: pci_express_root_control_flags
{
    NONE                                     = 0,
    SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE = BIT_0,
    SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE   = BIT_1,
    SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE       = BIT_2,
    PME_INTERRUPT_ENABLE                     = BIT_3,
    CRS_SOFTWARE_VISIBILITY_ENABLE           = BIT_4
};

DEFINE_FLAGS(PciExpressRootControlFlags, pci_express_root_control_flags); // TEST: NO



inline const char8* flagToString(PciExpressRootControlFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case PciExpressRootControlFlag::NONE:                                     return "NONE";
        case PciExpressRootControlFlag::SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE: return "SYSTEM_ERROR_ON_CORRECTABLE_ERROR_ENABLE";
        case PciExpressRootControlFlag::SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE:   return "SYSTEM_ERROR_ON_NON_FATAL_ERROR_ENABLE";
        case PciExpressRootControlFlag::SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE:       return "SYSTEM_ERROR_ON_FATAL_ERROR_ENABLE";
        case PciExpressRootControlFlag::PME_INTERRUPT_ENABLE:                     return "PME_INTERRUPT_ENABLE";
        case PciExpressRootControlFlag::CRS_SOFTWARE_VISIBILITY_ENABLE:           return "CRS_SOFTWARE_VISIBILITY_ENABLE";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(PciExpressRootControlFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[50];

    sprintf(res, "0x%04X (%s)", (pci_express_root_control_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const PciExpressRootControlFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[190];

    FLAGS_TO_STRING(res, flags.flags, PciExpressRootControlFlag);

    return res;
}



inline const char8* flagsToFullString(const PciExpressRootControlFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[199];

    FLAGS_TO_FULL_STRING(res, flags.flags, PciExpressRootControlFlag, "0x%04X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCONTROLFLAGS_H
