#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELPORTARBITRATIONCAPABILITYFLAGS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELPORTARBITRATIONCAPABILITYFLAGS_H



#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef bad_uint8 pci_express_virtual_channel_port_arbitration_capability_flags;

enum class PciExpressVirtualChannelPortArbitrationCapabilityFlag: pci_express_virtual_channel_port_arbitration_capability_flags
{
    NONE                                                        = 0,
    NON_CONFIGURABLE_HARDWARE_FIXED_ARBITRATION_SCHEME          = (1ULL << 0),
    WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_32_PHASES             = (1ULL << 1),
    WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_64_PHASES             = (1ULL << 2),
    WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_128_PHASES            = (1ULL << 3),
    TIME_BASED_WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_128_PHASES = (1ULL << 4),
    WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_256_PHASES            = (1ULL << 5)
};

DEFINE_FLAGS(PciExpressVirtualChannelPortArbitrationCapabilityFlags, pci_express_virtual_channel_port_arbitration_capability_flags); // TEST: NO



inline const char8* flagToString(PciExpressVirtualChannelPortArbitrationCapabilityFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case PciExpressVirtualChannelPortArbitrationCapabilityFlag::NONE:                                                        return "NONE";
        case PciExpressVirtualChannelPortArbitrationCapabilityFlag::NON_CONFIGURABLE_HARDWARE_FIXED_ARBITRATION_SCHEME:          return "NON_CONFIGURABLE_HARDWARE_FIXED_ARBITRATION_SCHEME";
        case PciExpressVirtualChannelPortArbitrationCapabilityFlag::WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_32_PHASES:             return "WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_32_PHASES";
        case PciExpressVirtualChannelPortArbitrationCapabilityFlag::WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_64_PHASES:             return "WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_64_PHASES";
        case PciExpressVirtualChannelPortArbitrationCapabilityFlag::WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_128_PHASES:            return "WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_128_PHASES";
        case PciExpressVirtualChannelPortArbitrationCapabilityFlag::TIME_BASED_WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_128_PHASES: return "TIME_BASED_WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_128_PHASES";
        case PciExpressVirtualChannelPortArbitrationCapabilityFlag::WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_256_PHASES:            return "WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_256_PHASES";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(PciExpressVirtualChannelPortArbitrationCapabilityFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[67];

    sprintf(res, "0x%02X (%s)", (pci_express_virtual_channel_port_arbitration_capability_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const PciExpressVirtualChannelPortArbitrationCapabilityFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[330];

    FLAGS_TO_STRING(res, flags.flags, PciExpressVirtualChannelPortArbitrationCapabilityFlag);

    return res;
}



inline const char8* flagsToFullString(const PciExpressVirtualChannelPortArbitrationCapabilityFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[337];

    FLAGS_TO_FULL_STRING(res, flags.flags, PciExpressVirtualChannelPortArbitrationCapabilityFlag, "0x%02X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELPORTARBITRATIONCAPABILITYFLAGS_H
