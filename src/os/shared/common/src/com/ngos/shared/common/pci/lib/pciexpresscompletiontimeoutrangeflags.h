#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSCOMPLETIONTIMEOUTRANGEFLAGS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSCOMPLETIONTIMEOUTRANGEFLAGS_H



#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u8 pci_express_completion_timeout_range_flags;

enum class PciExpressCompletionTimeoutRangeFlag: pci_express_completion_timeout_range_flags
{
    NONE                                     = 0,
    FROM_50_MICROSECONDS_TO_10_MILLISECONDS  = (1ULL << 0),
    FROM_10_MILLISECONDS_TO_250_MILLISECONDS = (1ULL << 1),
    FROM_250_MILLISECONDS_TO_4_SECONDS       = (1ULL << 2),
    FROM_4_SECONDS_TO_64_SECONDS             = (1ULL << 3)
};

DEFINE_FLAGS(PciExpressCompletionTimeoutRangeFlags, pci_express_completion_timeout_range_flags); // TEST: NO



inline const char8* flagToString(PciExpressCompletionTimeoutRangeFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case PciExpressCompletionTimeoutRangeFlag::NONE:                                     return "NONE";
        case PciExpressCompletionTimeoutRangeFlag::FROM_50_MICROSECONDS_TO_10_MILLISECONDS:  return "FROM_50_MICROSECONDS_TO_10_MILLISECONDS";
        case PciExpressCompletionTimeoutRangeFlag::FROM_10_MILLISECONDS_TO_250_MILLISECONDS: return "FROM_10_MILLISECONDS_TO_250_MILLISECONDS";
        case PciExpressCompletionTimeoutRangeFlag::FROM_250_MILLISECONDS_TO_4_SECONDS:       return "FROM_250_MILLISECONDS_TO_4_SECONDS";
        case PciExpressCompletionTimeoutRangeFlag::FROM_4_SECONDS_TO_64_SECONDS:             return "FROM_4_SECONDS_TO_64_SECONDS";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(PciExpressCompletionTimeoutRangeFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[48];

    sprintf(res, "0x%02X (%s)", (pci_express_completion_timeout_range_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const PciExpressCompletionTimeoutRangeFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[166];

    FLAGS_TO_STRING(res, flags.flags, PciExpressCompletionTimeoutRangeFlag);

    return res;
}



inline const char8* flagsToFullString(const PciExpressCompletionTimeoutRangeFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[173];

    FLAGS_TO_FULL_STRING(res, flags.flags, PciExpressCompletionTimeoutRangeFlag, "0x%02X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSCOMPLETIONTIMEOUTRANGEFLAGS_H
