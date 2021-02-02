#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSL1EXITLATENCY_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSL1EXITLATENCY_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressL1ExitLatency: bad_uint8
{
    LESS_THAN_1_MICROSECOND                 = 0,
    FROM_1_MICROSECOND_TO_2_MICROSECONDS    = 1,
    FROM_2_MICROSECONDS_TO_4_MICROSECONDS   = 2,
    FROM_4_MICROSECONDS_TO_8_MICROSECONDS   = 3,
    FROM_8_MICROSECONDS_TO_16_MICROSECONDS  = 4,
    FROM_16_MICROSECONDS_TO_32_MICROSECONDS = 5,
    FROM_32_MICROSECONDS_TO_64_MICROSECONDS = 6,
    MORE_THAN_64_MICROSECONDS               = 7
};



inline const char8* enumToString(PciExpressL1ExitLatency latency) // TEST: NO
{
    // COMMON_LT((" | latency = %u", latency)); // Commented to avoid bad looking logs



    switch (latency)
    {
        case PciExpressL1ExitLatency::LESS_THAN_1_MICROSECOND:                 return "LESS_THAN_1_MICROSECOND";
        case PciExpressL1ExitLatency::FROM_1_MICROSECOND_TO_2_MICROSECONDS:    return "FROM_1_MICROSECOND_TO_2_MICROSECONDS";
        case PciExpressL1ExitLatency::FROM_2_MICROSECONDS_TO_4_MICROSECONDS:   return "FROM_2_MICROSECONDS_TO_4_MICROSECONDS";
        case PciExpressL1ExitLatency::FROM_4_MICROSECONDS_TO_8_MICROSECONDS:   return "FROM_4_MICROSECONDS_TO_8_MICROSECONDS";
        case PciExpressL1ExitLatency::FROM_8_MICROSECONDS_TO_16_MICROSECONDS:  return "FROM_8_MICROSECONDS_TO_16_MICROSECONDS";
        case PciExpressL1ExitLatency::FROM_16_MICROSECONDS_TO_32_MICROSECONDS: return "FROM_16_MICROSECONDS_TO_32_MICROSECONDS";
        case PciExpressL1ExitLatency::FROM_32_MICROSECONDS_TO_64_MICROSECONDS: return "FROM_32_MICROSECONDS_TO_64_MICROSECONDS";
        case PciExpressL1ExitLatency::MORE_THAN_64_MICROSECONDS:               return "MORE_THAN_64_MICROSECONDS";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressL1ExitLatency latency) // TEST: NO
{
    // COMMON_LT((" | latency = %u", latency)); // Commented to avoid bad looking logs



    static char8 res[47];

    sprintf(res, "0x%02X (%s)", (bad_uint8)latency, enumToString(latency));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSL1EXITLATENCY_H
