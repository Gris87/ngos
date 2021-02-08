#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSENDPOINTL1ACCEPTABLELATENCY_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSENDPOINTL1ACCEPTABLELATENCY_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressEndpointL1AcceptableLatency: u8
{
    MAXIMUM_OF_1_MICROSECONDS  = 0,
    MAXIMUM_OF_2_MICROSECONDS  = 1,
    MAXIMUM_OF_4_MICROSECONDS  = 2,
    MAXIMUM_OF_8_MICROSECONDS  = 3,
    MAXIMUM_OF_16_MICROSECONDS = 4,
    MAXIMUM_OF_32_MICROSECONDS = 5,
    MAXIMUM_OF_64_MICROSECONDS = 6,
    NO_LIMIT                   = 7
};



inline const char8* enumToString(PciExpressEndpointL1AcceptableLatency latency) // TEST: NO
{
    // COMMON_LT((" | latency = %u", latency)); // Commented to avoid bad looking logs



    switch (latency)
    {
        case PciExpressEndpointL1AcceptableLatency::MAXIMUM_OF_1_MICROSECONDS:  return "MAXIMUM_OF_1_MICROSECONDS";
        case PciExpressEndpointL1AcceptableLatency::MAXIMUM_OF_2_MICROSECONDS:  return "MAXIMUM_OF_2_MICROSECONDS";
        case PciExpressEndpointL1AcceptableLatency::MAXIMUM_OF_4_MICROSECONDS:  return "MAXIMUM_OF_4_MICROSECONDS";
        case PciExpressEndpointL1AcceptableLatency::MAXIMUM_OF_8_MICROSECONDS:  return "MAXIMUM_OF_8_MICROSECONDS";
        case PciExpressEndpointL1AcceptableLatency::MAXIMUM_OF_16_MICROSECONDS: return "MAXIMUM_OF_16_MICROSECONDS";
        case PciExpressEndpointL1AcceptableLatency::MAXIMUM_OF_32_MICROSECONDS: return "MAXIMUM_OF_32_MICROSECONDS";
        case PciExpressEndpointL1AcceptableLatency::MAXIMUM_OF_64_MICROSECONDS: return "MAXIMUM_OF_64_MICROSECONDS";
        case PciExpressEndpointL1AcceptableLatency::NO_LIMIT:                   return "NO_LIMIT";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressEndpointL1AcceptableLatency latency) // TEST: NO
{
    // COMMON_LT((" | latency = %u", latency)); // Commented to avoid bad looking logs



    static char8 res[34];

    sprintf(res, "0x%02X (%s)", (u8)latency, enumToString(latency));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSENDPOINTL1ACCEPTABLELATENCY_H
