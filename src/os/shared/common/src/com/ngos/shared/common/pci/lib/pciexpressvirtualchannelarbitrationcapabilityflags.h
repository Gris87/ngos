#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELARBITRATIONCAPABILITYFLAGS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELARBITRATIONCAPABILITYFLAGS_H



#include <com/ngos/shared/common/bits/flags.h>
#include <com/ngos/shared/common/bits/macros.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u8 pci_express_virtual_channel_arbitration_capability_flags;

enum class PciExpressVirtualChannelArbitrationCapabilityFlag: pci_express_virtual_channel_arbitration_capability_flags
{
    NONE                                             = 0,
    HARDWARE_FIXED_ARBITRATION_SCHEME                = BIT_0,
    WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_32_PHASES  = BIT_1,
    WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_64_PHASES  = BIT_2,
    WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_128_PHASES = BIT_3
};

DEFINE_FLAGS(PciExpressVirtualChannelArbitrationCapabilityFlags, pci_express_virtual_channel_arbitration_capability_flags); // TEST: NO



inline const char8* flagToString(PciExpressVirtualChannelArbitrationCapabilityFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case PciExpressVirtualChannelArbitrationCapabilityFlag::NONE:                                             return "NONE";
        case PciExpressVirtualChannelArbitrationCapabilityFlag::HARDWARE_FIXED_ARBITRATION_SCHEME:                return "HARDWARE_FIXED_ARBITRATION_SCHEME";
        case PciExpressVirtualChannelArbitrationCapabilityFlag::WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_32_PHASES:  return "WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_32_PHASES";
        case PciExpressVirtualChannelArbitrationCapabilityFlag::WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_64_PHASES:  return "WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_64_PHASES";
        case PciExpressVirtualChannelArbitrationCapabilityFlag::WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_128_PHASES: return "WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_128_PHASES";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(PciExpressVirtualChannelArbitrationCapabilityFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[56];

    sprintf(res, "0x%02X (%s)", (pci_express_virtual_channel_arbitration_capability_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const PciExpressVirtualChannelArbitrationCapabilityFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[200];

    FLAGS_TO_STRING(res, flags.flags, PciExpressVirtualChannelArbitrationCapabilityFlag);

    return res;
}



inline const char8* flagsToFullString(const PciExpressVirtualChannelArbitrationCapabilityFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[207];

    FLAGS_TO_FULL_STRING(res, flags.flags, PciExpressVirtualChannelArbitrationCapabilityFlag, "0x%02X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELARBITRATIONCAPABILITYFLAGS_H
