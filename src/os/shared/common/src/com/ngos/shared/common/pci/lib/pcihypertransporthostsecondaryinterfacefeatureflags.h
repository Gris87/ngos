#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTHOSTSECONDARYINTERFACEFEATUREFLAGS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTHOSTSECONDARYINTERFACEFEATUREFLAGS_H



#include <com/ngos/shared/common/bits/flags.h>
#include <com/ngos/shared/common/bits/macros.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u16 pci_hyper_transport_host_secondary_interface_feature_flags;

enum class PciHyperTransportHostSecondaryInterfaceFeatureFlag: pci_hyper_transport_host_secondary_interface_feature_flags
{
    NONE                       = 0,
    ISOCHRONOUS_FLOW_CONTROL   = BIT_0,
    LDTSTOP                    = BIT_1,
    CRC_TEST_MODE              = BIT_2,
    EXTENDED_CTL_TIME_REQUIRED = BIT_3,
    _64_BIT_ADDRESSING         = BIT_4,
    DISABLE_UNIT_ID_REORDER    = BIT_5,
    SOURCE_ID                  = BIT_6,
    EXTENDED_REGISTER_SET      = BIT_8,
    ENABLE_UPSTREAM_CONFIG     = BIT_9
};

DEFINE_FLAGS(PciHyperTransportHostSecondaryInterfaceFeatureFlags, pci_hyper_transport_host_secondary_interface_feature_flags); // TEST: NO



inline const char8* flagToString(PciHyperTransportHostSecondaryInterfaceFeatureFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case PciHyperTransportHostSecondaryInterfaceFeatureFlag::NONE:                       return "NONE";
        case PciHyperTransportHostSecondaryInterfaceFeatureFlag::ISOCHRONOUS_FLOW_CONTROL:   return "ISOCHRONOUS_FLOW_CONTROL";
        case PciHyperTransportHostSecondaryInterfaceFeatureFlag::LDTSTOP:                    return "LDTSTOP";
        case PciHyperTransportHostSecondaryInterfaceFeatureFlag::CRC_TEST_MODE:              return "CRC_TEST_MODE";
        case PciHyperTransportHostSecondaryInterfaceFeatureFlag::EXTENDED_CTL_TIME_REQUIRED: return "EXTENDED_CTL_TIME_REQUIRED";
        case PciHyperTransportHostSecondaryInterfaceFeatureFlag::_64_BIT_ADDRESSING:         return "64_BIT_ADDRESSING";
        case PciHyperTransportHostSecondaryInterfaceFeatureFlag::DISABLE_UNIT_ID_REORDER:    return "DISABLE_UNIT_ID_REORDER";
        case PciHyperTransportHostSecondaryInterfaceFeatureFlag::SOURCE_ID:                  return "SOURCE_ID";
        case PciHyperTransportHostSecondaryInterfaceFeatureFlag::EXTENDED_REGISTER_SET:      return "EXTENDED_REGISTER_SET";
        case PciHyperTransportHostSecondaryInterfaceFeatureFlag::ENABLE_UPSTREAM_CONFIG:     return "ENABLE_UPSTREAM_CONFIG";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(PciHyperTransportHostSecondaryInterfaceFeatureFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[36];

    sprintf(res, "0x%04X (%s)", (pci_hyper_transport_host_secondary_interface_feature_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const PciHyperTransportHostSecondaryInterfaceFeatureFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[202];

    FLAGS_TO_STRING(res, flags.flags, PciHyperTransportHostSecondaryInterfaceFeatureFlag);

    return res;
}



inline const char8* flagsToFullString(const PciHyperTransportHostSecondaryInterfaceFeatureFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[211];

    FLAGS_TO_FULL_STRING(res, flags.flags, PciHyperTransportHostSecondaryInterfaceFeatureFlag, "0x%04X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTHOSTSECONDARYINTERFACEFEATUREFLAGS_H
