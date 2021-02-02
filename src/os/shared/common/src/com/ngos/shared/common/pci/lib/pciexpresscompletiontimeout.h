#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSCOMPLETIONTIMEOUT_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSCOMPLETIONTIMEOUT_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressCompletionTimeout: bad_uint8
{
    FROM_50_MICROSECONDS_TO_50_MILLISECONDS   = 0,
    FROM_50_MICROSECONDS_TO_100_MICROSECONDS  = 1,
    FROM_1_MILLISECOND_TO_10_MILLISECONDS     = 2,
    FROM_16_MILLISECONDS_TO_55_MILLISECONDS   = 5,
    FROM_65_MILLISECONDS_TO_210_MILLISECONDS  = 6,
    FROM_260_MILLISECONDS_TO_900_MILLISECONDS = 9,
    FROM_1_SECOND_TO_3_5_SECONDS              = 10,
    FROM_4_SECONDS_TO_13_SECONDS              = 13,
    FROM_17_SECONDS_TO_64_SECONDS             = 14
};



inline const char8* enumToString(PciExpressCompletionTimeout timeout) // TEST: NO
{
    // COMMON_LT((" | timeout = %u", timeout)); // Commented to avoid bad looking logs



    switch (timeout)
    {
        case PciExpressCompletionTimeout::FROM_50_MICROSECONDS_TO_50_MILLISECONDS:   return "FROM_50_MICROSECONDS_TO_50_MILLISECONDS";
        case PciExpressCompletionTimeout::FROM_50_MICROSECONDS_TO_100_MICROSECONDS:  return "FROM_50_MICROSECONDS_TO_100_MICROSECONDS";
        case PciExpressCompletionTimeout::FROM_1_MILLISECOND_TO_10_MILLISECONDS:     return "FROM_1_MILLISECOND_TO_10_MILLISECONDS";
        case PciExpressCompletionTimeout::FROM_16_MILLISECONDS_TO_55_MILLISECONDS:   return "FROM_16_MILLISECONDS_TO_55_MILLISECONDS";
        case PciExpressCompletionTimeout::FROM_65_MILLISECONDS_TO_210_MILLISECONDS:  return "FROM_65_MILLISECONDS_TO_210_MILLISECONDS";
        case PciExpressCompletionTimeout::FROM_260_MILLISECONDS_TO_900_MILLISECONDS: return "FROM_260_MILLISECONDS_TO_900_MILLISECONDS";
        case PciExpressCompletionTimeout::FROM_1_SECOND_TO_3_5_SECONDS:              return "FROM_1_SECOND_TO_3_5_SECONDS";
        case PciExpressCompletionTimeout::FROM_4_SECONDS_TO_13_SECONDS:              return "FROM_4_SECONDS_TO_13_SECONDS";
        case PciExpressCompletionTimeout::FROM_17_SECONDS_TO_64_SECONDS:             return "FROM_17_SECONDS_TO_64_SECONDS";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressCompletionTimeout timeout) // TEST: NO
{
    // COMMON_LT((" | timeout = %u", timeout)); // Commented to avoid bad looking logs



    static char8 res[49];

    sprintf(res, "0x%02X (%s)", (bad_uint8)timeout, enumToString(timeout));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSCOMPLETIONTIMEOUT_H
