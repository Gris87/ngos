#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELARBITRATIONSELECT_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELARBITRATIONSELECT_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressVirtualChannelArbitrationSelect: bad_uint8
{
    NONE                                             = 0,
    WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_32_PHASES  = 1,
    WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_64_PHASES  = 2,
    WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_128_PHASES = 3
};



inline const char8* enumToString(PciExpressVirtualChannelArbitrationSelect select) // TEST: NO
{
    // COMMON_LT((" | select = %u", select)); // Commented to avoid bad looking logs



    switch (select)
    {
        case PciExpressVirtualChannelArbitrationSelect::NONE:                                             return "NONE";
        case PciExpressVirtualChannelArbitrationSelect::WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_32_PHASES:  return "WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_32_PHASES";
        case PciExpressVirtualChannelArbitrationSelect::WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_64_PHASES:  return "WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_64_PHASES";
        case PciExpressVirtualChannelArbitrationSelect::WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_128_PHASES: return "WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_128_PHASES";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressVirtualChannelArbitrationSelect select) // TEST: NO
{
    // COMMON_LT((" | select = %u", select)); // Commented to avoid bad looking logs



    static char8 res[56];

    sprintf(res, "0x%02X (%s)", (bad_uint8)select, enumToString(select));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELARBITRATIONSELECT_H
