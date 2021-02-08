#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTSLAVEPRIMARYINTERFACEFEATUREFLAGS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTSLAVEPRIMARYINTERFACEFEATUREFLAGS_H



#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u8 pci_hyper_transport_slave_primary_interface_feature_flags;

enum class PciHyperTransportSlavePrimaryInterfaceFeatureFlag: pci_hyper_transport_slave_primary_interface_feature_flags
{
    NONE                       = 0,
    ISOCHRONOUS_FLOW_CONTROL   = (1ULL << 0),
    LDTSTOP                    = (1ULL << 1),
    CRC_TEST_MODE              = (1ULL << 2),
    EXTENDED_CTL_TIME_REQUIRED = (1ULL << 3),
    _64_BIT_ADDRESSING         = (1ULL << 4),
    DISABLE_UNIT_ID_REORDER    = (1ULL << 5),
    SOURCE_ID                  = (1ULL << 6)
};

DEFINE_FLAGS(PciHyperTransportSlavePrimaryInterfaceFeatureFlags, pci_hyper_transport_slave_primary_interface_feature_flags); // TEST: NO



inline const char8* flagToString(PciHyperTransportSlavePrimaryInterfaceFeatureFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case PciHyperTransportSlavePrimaryInterfaceFeatureFlag::NONE:                       return "NONE";
        case PciHyperTransportSlavePrimaryInterfaceFeatureFlag::ISOCHRONOUS_FLOW_CONTROL:   return "ISOCHRONOUS_FLOW_CONTROL";
        case PciHyperTransportSlavePrimaryInterfaceFeatureFlag::LDTSTOP:                    return "LDTSTOP";
        case PciHyperTransportSlavePrimaryInterfaceFeatureFlag::CRC_TEST_MODE:              return "CRC_TEST_MODE";
        case PciHyperTransportSlavePrimaryInterfaceFeatureFlag::EXTENDED_CTL_TIME_REQUIRED: return "EXTENDED_CTL_TIME_REQUIRED";
        case PciHyperTransportSlavePrimaryInterfaceFeatureFlag::_64_BIT_ADDRESSING:         return "64_BIT_ADDRESSING";
        case PciHyperTransportSlavePrimaryInterfaceFeatureFlag::DISABLE_UNIT_ID_REORDER:    return "DISABLE_UNIT_ID_REORDER";
        case PciHyperTransportSlavePrimaryInterfaceFeatureFlag::SOURCE_ID:                  return "SOURCE_ID";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(PciHyperTransportSlavePrimaryInterfaceFeatureFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[34];

    sprintf(res, "0x%02X (%s)", (pci_hyper_transport_slave_primary_interface_feature_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const PciHyperTransportSlavePrimaryInterfaceFeatureFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[153];

    FLAGS_TO_STRING(res, flags.flags, PciHyperTransportSlavePrimaryInterfaceFeatureFlag);

    return res;
}



inline const char8* flagsToFullString(const PciHyperTransportSlavePrimaryInterfaceFeatureFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[160];

    FLAGS_TO_FULL_STRING(res, flags.flags, PciHyperTransportSlavePrimaryInterfaceFeatureFlag, "0x%02X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTSLAVEPRIMARYINTERFACEFEATUREFLAGS_H
