#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSL0SEXITLATENCY_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSL0SEXITLATENCY_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressL0sExitLatency: bad_uint8
{
    LESS_THAN_64_NANOSECONDS                = 0,
    FROM_64_NANOSECONDS_TO_128_NANOSECONDS  = 1,
    FROM_128_NANOSECONDS_TO_256_NANOSECONDS = 2,
    FROM_256_NANOSECONDS_TO_512_NANOSECONDS = 3,
    FROM_512_NANOSECONDS_TO_1_MICROSECOND   = 4,
    FROM_1_MICROSECOND_TO_2_MICROSECONDS    = 5,
    FROM_2_MICROSECONDS_TO_4_MICROSECONDS   = 6,
    MORE_THAN_4_MICROSECONDS                = 7
};



inline const char8* enumToString(PciExpressL0sExitLatency latency) // TEST: NO
{
    // COMMON_LT((" | latency = %u", latency)); // Commented to avoid bad looking logs



    switch (latency)
    {
        case PciExpressL0sExitLatency::LESS_THAN_64_NANOSECONDS:                return "LESS_THAN_64_NANOSECONDS";
        case PciExpressL0sExitLatency::FROM_64_NANOSECONDS_TO_128_NANOSECONDS:  return "FROM_64_NANOSECONDS_TO_128_NANOSECONDS";
        case PciExpressL0sExitLatency::FROM_128_NANOSECONDS_TO_256_NANOSECONDS: return "FROM_128_NANOSECONDS_TO_256_NANOSECONDS";
        case PciExpressL0sExitLatency::FROM_256_NANOSECONDS_TO_512_NANOSECONDS: return "FROM_256_NANOSECONDS_TO_512_NANOSECONDS";
        case PciExpressL0sExitLatency::FROM_512_NANOSECONDS_TO_1_MICROSECOND:   return "FROM_512_NANOSECONDS_TO_1_MICROSECOND";
        case PciExpressL0sExitLatency::FROM_1_MICROSECOND_TO_2_MICROSECONDS:    return "FROM_1_MICROSECOND_TO_2_MICROSECONDS";
        case PciExpressL0sExitLatency::FROM_2_MICROSECONDS_TO_4_MICROSECONDS:   return "FROM_2_MICROSECONDS_TO_4_MICROSECONDS";
        case PciExpressL0sExitLatency::MORE_THAN_4_MICROSECONDS:                return "MORE_THAN_4_MICROSECONDS";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressL0sExitLatency latency) // TEST: NO
{
    // COMMON_LT((" | latency = %u", latency)); // Commented to avoid bad looking logs



    static char8 res[47];

    sprintf(res, "0x%02X (%s)", (bad_uint8)latency, enumToString(latency));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSL0SEXITLATENCY_H
