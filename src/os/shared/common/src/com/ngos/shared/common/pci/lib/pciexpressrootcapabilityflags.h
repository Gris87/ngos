#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCAPABILITYFLAGS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCAPABILITYFLAGS_H



#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u16 pci_express_root_capability_flags;

enum class PciExpressRootCapabilityFlag: pci_express_root_capability_flags
{
    NONE                    = 0,
    CRS_SOFTWARE_VISIBILITY = (1ULL << 0)
};

DEFINE_FLAGS(PciExpressRootCapabilityFlags, pci_express_root_capability_flags); // TEST: NO



inline const char8* flagToString(PciExpressRootCapabilityFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case PciExpressRootCapabilityFlag::NONE:                    return "NONE";
        case PciExpressRootCapabilityFlag::CRS_SOFTWARE_VISIBILITY: return "CRS_SOFTWARE_VISIBILITY";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(PciExpressRootCapabilityFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[33];

    sprintf(res, "0x%04X (%s)", (pci_express_root_capability_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const PciExpressRootCapabilityFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[39];

    FLAGS_TO_STRING(res, flags.flags, PciExpressRootCapabilityFlag);

    return res;
}



inline const char8* flagsToFullString(const PciExpressRootCapabilityFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[48];

    FLAGS_TO_FULL_STRING(res, flags.flags, PciExpressRootCapabilityFlag, "0x%04X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCAPABILITYFLAGS_H
