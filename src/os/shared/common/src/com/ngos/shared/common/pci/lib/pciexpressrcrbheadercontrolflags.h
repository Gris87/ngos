#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSRCRBHEADERCONTROLFLAGS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSRCRBHEADERCONTROLFLAGS_H



#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u32 pci_express_rcrb_header_control_flags;

enum class PciExpressRcrbHeaderControlFlag: pci_express_rcrb_header_control_flags
{
    NONE                            = 0,
    CRS_SOFTWARE_VISIBILITY_ENABLED = (1ULL << 0)
};

DEFINE_FLAGS(PciExpressRcrbHeaderControlFlags, pci_express_rcrb_header_control_flags); // TEST: NO



inline const char8* flagToString(PciExpressRcrbHeaderControlFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case PciExpressRcrbHeaderControlFlag::NONE:                            return "NONE";
        case PciExpressRcrbHeaderControlFlag::CRS_SOFTWARE_VISIBILITY_ENABLED: return "CRS_SOFTWARE_VISIBILITY_ENABLED";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(PciExpressRcrbHeaderControlFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[45];

    sprintf(res, "0x%08X (%s)", (pci_express_rcrb_header_control_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const PciExpressRcrbHeaderControlFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[47];

    FLAGS_TO_STRING(res, flags.flags, PciExpressRcrbHeaderControlFlag);

    return res;
}



inline const char8* flagsToFullString(const PciExpressRcrbHeaderControlFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[60];

    FLAGS_TO_FULL_STRING(res, flags.flags, PciExpressRcrbHeaderControlFlag, "0x%08X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSRCRBHEADERCONTROLFLAGS_H
