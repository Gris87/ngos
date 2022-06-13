#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSRCRBHEADERCAPABILITIESFLAGS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSRCRBHEADERCAPABILITIESFLAGS_H



#include <com/ngos/shared/common/bits/flags.h>
#include <com/ngos/shared/common/bits/macros.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u32 pci_express_rcrb_header_capabilities_flags;

enum class PciExpressRcrbHeaderCapabilitiesFlag: pci_express_rcrb_header_capabilities_flags
{
    NONE                    = 0,
    CRS_SOFTWARE_VISIBILITY = BIT_0
};

DEFINE_FLAGS(PciExpressRcrbHeaderCapabilitiesFlags, pci_express_rcrb_header_capabilities_flags); // TEST: NO



inline const char8* flagToString(PciExpressRcrbHeaderCapabilitiesFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case PciExpressRcrbHeaderCapabilitiesFlag::NONE:                    return "NONE";
        case PciExpressRcrbHeaderCapabilitiesFlag::CRS_SOFTWARE_VISIBILITY: return "CRS_SOFTWARE_VISIBILITY";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(PciExpressRcrbHeaderCapabilitiesFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[37];

    sprintf(res, "0x%08X (%s)", (pci_express_rcrb_header_capabilities_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const PciExpressRcrbHeaderCapabilitiesFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[39];

    FLAGS_TO_STRING(res, flags.flags, PciExpressRcrbHeaderCapabilitiesFlag);

    return res;
}



inline const char8* flagsToFullString(const PciExpressRcrbHeaderCapabilitiesFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[52];

    FLAGS_TO_FULL_STRING(res, flags.flags, PciExpressRcrbHeaderCapabilitiesFlag, "0x%08X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSRCRBHEADERCAPABILITIESFLAGS_H
