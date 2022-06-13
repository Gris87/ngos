#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTLINKERRORFLAGS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTLINKERRORFLAGS_H



#include <com/ngos/shared/common/bits/flags.h>
#include <com/ngos/shared/common/bits/macros.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u8 pci_hyper_transport_link_error_flags;

enum class PciHyperTransportLinkErrorFlag: pci_hyper_transport_link_error_flags
{
    NONE               = 0,
    PROTOCOL_ERROR     = BIT_0,
    OVERFLOW_ERROR     = BIT_1,
    END_OF_CHAIN_ERROR = BIT_2,
    CTL_TIMEOUT        = BIT_3
};

DEFINE_FLAGS(PciHyperTransportLinkErrorFlags, pci_hyper_transport_link_error_flags); // TEST: NO



inline const char8* flagToString(PciHyperTransportLinkErrorFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case PciHyperTransportLinkErrorFlag::NONE:               return "NONE";
        case PciHyperTransportLinkErrorFlag::PROTOCOL_ERROR:     return "PROTOCOL_ERROR";
        case PciHyperTransportLinkErrorFlag::OVERFLOW_ERROR:     return "OVERFLOW_ERROR";
        case PciHyperTransportLinkErrorFlag::END_OF_CHAIN_ERROR: return "END_OF_CHAIN_ERROR";
        case PciHyperTransportLinkErrorFlag::CTL_TIMEOUT:        return "CTL_TIMEOUT";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(PciHyperTransportLinkErrorFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[26];

    sprintf(res, "0x%02X (%s)", (pci_hyper_transport_link_error_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const PciHyperTransportLinkErrorFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[82];

    FLAGS_TO_STRING(res, flags.flags, PciHyperTransportLinkErrorFlag);

    return res;
}



inline const char8* flagsToFullString(const PciHyperTransportLinkErrorFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[89];

    FLAGS_TO_FULL_STRING(res, flags.flags, PciHyperTransportLinkErrorFlag, "0x%02X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTLINKERRORFLAGS_H
