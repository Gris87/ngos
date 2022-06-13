#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTLINKFREQUENCYCAPABILITYFLAGS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTLINKFREQUENCYCAPABILITYFLAGS_H



#include <com/ngos/shared/common/bits/flags.h>
#include <com/ngos/shared/common/bits/macros.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u16 pci_hyper_transport_link_frequency_capability_flags;

enum class PciHyperTransportLinkFrequencyCapabilityFlag: pci_hyper_transport_link_frequency_capability_flags
{
    NONE                              = 0,
    SUPPORT_200_MHZ                   = BIT_0,
    SUPPORT_300_MHZ                   = BIT_1,
    SUPPORT_400_MHZ                   = BIT_2,
    SUPPORT_500_MHZ                   = BIT_3,
    SUPPORT_600_MHZ                   = BIT_4,
    SUPPORT_800_MHZ                   = BIT_5,
    SUPPORT_1000_MHZ                  = BIT_6,
    SUPPORT_1200_MHZ                  = BIT_7,
    SUPPORT_1400_MHZ                  = BIT_8,
    SUPPORT_1600_MHZ                  = BIT_9,
    SUPPORT_1800_MHZ                  = BIT_10,
    SUPPORT_2000_MHZ                  = BIT_11,
    SUPPORT_2200_MHZ                  = BIT_12,
    SUPPORT_2400_MHZ                  = BIT_13,
    SUPPORT_2600_MHZ                  = BIT_14,
    SUPPORT_VENDOR_SPECIFIC_FREQUENCY = BIT_15
};

DEFINE_FLAGS(PciHyperTransportLinkFrequencyCapabilityFlags, pci_hyper_transport_link_frequency_capability_flags); // TEST: NO



inline const char8* flagToString(PciHyperTransportLinkFrequencyCapabilityFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case PciHyperTransportLinkFrequencyCapabilityFlag::NONE:                              return "NONE";
        case PciHyperTransportLinkFrequencyCapabilityFlag::SUPPORT_200_MHZ:                   return "SUPPORT_200_MHZ";
        case PciHyperTransportLinkFrequencyCapabilityFlag::SUPPORT_300_MHZ:                   return "SUPPORT_300_MHZ";
        case PciHyperTransportLinkFrequencyCapabilityFlag::SUPPORT_400_MHZ:                   return "SUPPORT_400_MHZ";
        case PciHyperTransportLinkFrequencyCapabilityFlag::SUPPORT_500_MHZ:                   return "SUPPORT_500_MHZ";
        case PciHyperTransportLinkFrequencyCapabilityFlag::SUPPORT_600_MHZ:                   return "SUPPORT_600_MHZ";
        case PciHyperTransportLinkFrequencyCapabilityFlag::SUPPORT_800_MHZ:                   return "SUPPORT_800_MHZ";
        case PciHyperTransportLinkFrequencyCapabilityFlag::SUPPORT_1000_MHZ:                  return "SUPPORT_1000_MHZ";
        case PciHyperTransportLinkFrequencyCapabilityFlag::SUPPORT_1200_MHZ:                  return "SUPPORT_1200_MHZ";
        case PciHyperTransportLinkFrequencyCapabilityFlag::SUPPORT_1400_MHZ:                  return "SUPPORT_1400_MHZ";
        case PciHyperTransportLinkFrequencyCapabilityFlag::SUPPORT_1600_MHZ:                  return "SUPPORT_1600_MHZ";
        case PciHyperTransportLinkFrequencyCapabilityFlag::SUPPORT_1800_MHZ:                  return "SUPPORT_1800_MHZ";
        case PciHyperTransportLinkFrequencyCapabilityFlag::SUPPORT_2000_MHZ:                  return "SUPPORT_2000_MHZ";
        case PciHyperTransportLinkFrequencyCapabilityFlag::SUPPORT_2200_MHZ:                  return "SUPPORT_2200_MHZ";
        case PciHyperTransportLinkFrequencyCapabilityFlag::SUPPORT_2400_MHZ:                  return "SUPPORT_2400_MHZ";
        case PciHyperTransportLinkFrequencyCapabilityFlag::SUPPORT_2600_MHZ:                  return "SUPPORT_2600_MHZ";
        case PciHyperTransportLinkFrequencyCapabilityFlag::SUPPORT_VENDOR_SPECIFIC_FREQUENCY: return "SUPPORT_VENDOR_SPECIFIC_FREQUENCY";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(PciHyperTransportLinkFrequencyCapabilityFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[43];

    sprintf(res, "0x%04X (%s)", (pci_hyper_transport_link_frequency_capability_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const PciHyperTransportLinkFrequencyCapabilityFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[328];

    FLAGS_TO_STRING(res, flags.flags, PciHyperTransportLinkFrequencyCapabilityFlag);

    return res;
}



inline const char8* flagsToFullString(const PciHyperTransportLinkFrequencyCapabilityFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[337];

    FLAGS_TO_FULL_STRING(res, flags.flags, PciHyperTransportLinkFrequencyCapabilityFlag, "0x%04X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTLINKFREQUENCYCAPABILITYFLAGS_H
