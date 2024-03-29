#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSCORRECTABLEERRORFLAGS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSCORRECTABLEERRORFLAGS_H



#include <com/ngos/shared/common/bits/flags.h>
#include <com/ngos/shared/common/bits/macros.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u32 pci_express_correctable_error_flags;

enum class PciExpressCorrectableErrorFlag: pci_express_correctable_error_flags
{
    NONE                     = 0,
    RECEIVER_ERROR           = BIT_0,
    BAD_TLP                  = BIT_6,
    BAD_DLLP                 = BIT_7,
    REPLAY_NUM_ROLLOVER      = BIT_8,
    REPLAY_TIMER_TIMEOUT     = BIT_12,
    ADVISORY_NON_FATAL_ERROR = BIT_13,
    CORRECTED_INTERNAL_ERROR = BIT_14,
    HEADER_LOG_OVERFLOW      = BIT_15
};

DEFINE_FLAGS(PciExpressCorrectableErrorFlags, pci_express_correctable_error_flags); // TEST: NO



inline const char8* flagToString(PciExpressCorrectableErrorFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case PciExpressCorrectableErrorFlag::NONE:                     return "NONE";
        case PciExpressCorrectableErrorFlag::RECEIVER_ERROR:           return "RECEIVER_ERROR";
        case PciExpressCorrectableErrorFlag::BAD_TLP:                  return "BAD_TLP";
        case PciExpressCorrectableErrorFlag::BAD_DLLP:                 return "BAD_DLLP";
        case PciExpressCorrectableErrorFlag::REPLAY_NUM_ROLLOVER:      return "REPLAY_NUM_ROLLOVER";
        case PciExpressCorrectableErrorFlag::REPLAY_TIMER_TIMEOUT:     return "REPLAY_TIMER_TIMEOUT";
        case PciExpressCorrectableErrorFlag::ADVISORY_NON_FATAL_ERROR: return "ADVISORY_NON_FATAL_ERROR";
        case PciExpressCorrectableErrorFlag::CORRECTED_INTERNAL_ERROR: return "CORRECTED_INTERNAL_ERROR";
        case PciExpressCorrectableErrorFlag::HEADER_LOG_OVERFLOW:      return "HEADER_LOG_OVERFLOW";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(PciExpressCorrectableErrorFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[38];

    sprintf(res, "0x%08X (%s)", (pci_express_correctable_error_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const PciExpressCorrectableErrorFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[172];

    FLAGS_TO_STRING(res, flags.flags, PciExpressCorrectableErrorFlag);

    return res;
}



inline const char8* flagsToFullString(const PciExpressCorrectableErrorFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[185];

    FLAGS_TO_FULL_STRING(res, flags.flags, PciExpressCorrectableErrorFlag, "0x%08X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSCORRECTABLEERRORFLAGS_H
