#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSACCESSCONTROLSERVICESACSCONTROLFLAGS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSACCESSCONTROLSERVICESACSCONTROLFLAGS_H



#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef bad_uint16 pci_express_access_control_services_acs_control_flags;

enum class PciExpressAccessControlServicesAcsControlFlag: pci_express_access_control_services_acs_control_flags
{
    NONE = 0,
    ACS_SOURCE_VALIDATION_ENABLE       = (1ULL << 0),
    ACS_TRANSLATION_BLOCKING_ENABLE    = (1ULL << 1),
    ACS_P2P_REQUEST_REDIRECT_ENABLE    = (1ULL << 2),
    ACS_P2P_COMPLETION_REDIRECT_ENABLE = (1ULL << 3),
    ACS_UPSTREAM_FORWARDING_ENABLE     = (1ULL << 4),
    ACS_P2P_EGRESS_CONTROL_ENABLE      = (1ULL << 5),
    ACS_DIRECT_TRANSLATED_P2P_ENABLE   = (1ULL << 6)
};

DEFINE_FLAGS(PciExpressAccessControlServicesAcsControlFlags, pci_express_access_control_services_acs_control_flags); // TEST: NO



inline const char8* flagToString(PciExpressAccessControlServicesAcsControlFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case PciExpressAccessControlServicesAcsControlFlag::NONE:                               return "NONE";
        case PciExpressAccessControlServicesAcsControlFlag::ACS_SOURCE_VALIDATION_ENABLE:       return "ACS_SOURCE_VALIDATION_ENABLE";
        case PciExpressAccessControlServicesAcsControlFlag::ACS_TRANSLATION_BLOCKING_ENABLE:    return "ACS_TRANSLATION_BLOCKING_ENABLE";
        case PciExpressAccessControlServicesAcsControlFlag::ACS_P2P_REQUEST_REDIRECT_ENABLE:    return "ACS_P2P_REQUEST_REDIRECT_ENABLE";
        case PciExpressAccessControlServicesAcsControlFlag::ACS_P2P_COMPLETION_REDIRECT_ENABLE: return "ACS_P2P_COMPLETION_REDIRECT_ENABLE";
        case PciExpressAccessControlServicesAcsControlFlag::ACS_UPSTREAM_FORWARDING_ENABLE:     return "ACS_UPSTREAM_FORWARDING_ENABLE";
        case PciExpressAccessControlServicesAcsControlFlag::ACS_P2P_EGRESS_CONTROL_ENABLE:      return "ACS_P2P_EGRESS_CONTROL_ENABLE";
        case PciExpressAccessControlServicesAcsControlFlag::ACS_DIRECT_TRANSLATED_P2P_ENABLE:   return "ACS_DIRECT_TRANSLATED_P2P_ENABLE";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(PciExpressAccessControlServicesAcsControlFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[44];

    sprintf(res, "0x%04X (%s)", (pci_express_access_control_services_acs_control_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const PciExpressAccessControlServicesAcsControlFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[249];

    FLAGS_TO_STRING(res, flags.flags, PciExpressAccessControlServicesAcsControlFlag);

    return res;
}



inline const char8* flagsToFullString(const PciExpressAccessControlServicesAcsControlFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[258];

    FLAGS_TO_FULL_STRING(res, flags.flags, PciExpressAccessControlServicesAcsControlFlag, "0x%04X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSACCESSCONTROLSERVICESACSCONTROLFLAGS_H
