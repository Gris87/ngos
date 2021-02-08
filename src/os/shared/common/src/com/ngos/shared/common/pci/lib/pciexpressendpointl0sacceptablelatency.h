#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSENDPOINTL0SACCEPTABLELATENCY_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSENDPOINTL0SACCEPTABLELATENCY_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressEndpointL0sAcceptableLatency: u8
{
    MAXIMUM_OF_64_NANOSECONDS  = 0,
    MAXIMUM_OF_128_NANOSECONDS = 1,
    MAXIMUM_OF_256_NANOSECONDS = 2,
    MAXIMUM_OF_512_NANOSECONDS = 3,
    MAXIMUM_OF_1_MICROSECONDS  = 4,
    MAXIMUM_OF_2_MICROSECONDS  = 5,
    MAXIMUM_OF_4_MICROSECONDS  = 6,
    NO_LIMIT                   = 7
};



inline const char8* enumToString(PciExpressEndpointL0sAcceptableLatency latency) // TEST: NO
{
    // COMMON_LT((" | latency = %u", latency)); // Commented to avoid bad looking logs



    switch (latency)
    {
        case PciExpressEndpointL0sAcceptableLatency::MAXIMUM_OF_64_NANOSECONDS:  return "MAXIMUM_OF_64_NANOSECONDS";
        case PciExpressEndpointL0sAcceptableLatency::MAXIMUM_OF_128_NANOSECONDS: return "MAXIMUM_OF_128_NANOSECONDS";
        case PciExpressEndpointL0sAcceptableLatency::MAXIMUM_OF_256_NANOSECONDS: return "MAXIMUM_OF_256_NANOSECONDS";
        case PciExpressEndpointL0sAcceptableLatency::MAXIMUM_OF_512_NANOSECONDS: return "MAXIMUM_OF_512_NANOSECONDS";
        case PciExpressEndpointL0sAcceptableLatency::MAXIMUM_OF_1_MICROSECONDS:  return "MAXIMUM_OF_1_MICROSECONDS";
        case PciExpressEndpointL0sAcceptableLatency::MAXIMUM_OF_2_MICROSECONDS:  return "MAXIMUM_OF_2_MICROSECONDS";
        case PciExpressEndpointL0sAcceptableLatency::MAXIMUM_OF_4_MICROSECONDS:  return "MAXIMUM_OF_4_MICROSECONDS";
        case PciExpressEndpointL0sAcceptableLatency::NO_LIMIT:                   return "NO_LIMIT";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressEndpointL0sAcceptableLatency latency) // TEST: NO
{
    // COMMON_LT((" | latency = %u", latency)); // Commented to avoid bad looking logs



    static char8 res[34];

    sprintf(res, "0x%02X (%s)", (u8)latency, enumToString(latency));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSENDPOINTL0SACCEPTABLELATENCY_H
