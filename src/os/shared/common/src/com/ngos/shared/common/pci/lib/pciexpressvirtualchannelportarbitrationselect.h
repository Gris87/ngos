#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELPORTARBITRATIONSELECT_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELPORTARBITRATIONSELECT_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressVirtualChannelPortArbitrationSelect: bad_uint8
{
    NONE                                                        = 0,
    WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_32_PHASES             = 1,
    WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_64_PHASES             = 2,
    WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_128_PHASES            = 3,
    TIME_BASED_WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_128_PHASES = 4,
    WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_256_PHASES            = 5
};



inline const char8* enumToString(PciExpressVirtualChannelPortArbitrationSelect select) // TEST: NO
{
    // COMMON_LT((" | select = %u", select)); // Commented to avoid bad looking logs



    switch (select)
    {
        case PciExpressVirtualChannelPortArbitrationSelect::NONE:                                                        return "NONE";
        case PciExpressVirtualChannelPortArbitrationSelect::WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_32_PHASES:             return "WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_32_PHASES";
        case PciExpressVirtualChannelPortArbitrationSelect::WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_64_PHASES:             return "WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_64_PHASES";
        case PciExpressVirtualChannelPortArbitrationSelect::WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_128_PHASES:            return "WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_128_PHASES";
        case PciExpressVirtualChannelPortArbitrationSelect::TIME_BASED_WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_128_PHASES: return "TIME_BASED_WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_128_PHASES";
        case PciExpressVirtualChannelPortArbitrationSelect::WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_256_PHASES:            return "WEIGHTED_ROUND_ROBIN_ARBITRATION_WITH_256_PHASES";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressVirtualChannelPortArbitrationSelect select) // TEST: NO
{
    // COMMON_LT((" | select = %u", select)); // Commented to avoid bad looking logs



    static char8 res[67];

    sprintf(res, "0x%02X (%s)", (bad_uint8)select, enumToString(select));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELPORTARBITRATIONSELECT_H
