#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSUNCORRECTABLEERRORFLAGS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSUNCORRECTABLEERRORFLAGS_H



#include <com/ngos/shared/common/bits/flags.h>
#include <com/ngos/shared/common/bits/macros.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u32 pci_express_uncorrectable_error_flags;

enum class PciExpressUncorrectableErrorFlag: pci_express_uncorrectable_error_flags
{
    NONE                         = 0,
    DATA_LINK_PROTOCOL_ERROR     = BIT_4,
    SURPRISE_DOWN_ERROR          = BIT_5,
    POISONED_TLP                 = BIT_12,
    FLOW_CONTROL_PROTOCOL_ERROR  = BIT_13,
    COMPLETION_TIMEOUT           = BIT_14,
    COMPLETER_ABORT              = BIT_15,
    UNEXPECTED_COMPLETION        = BIT_16,
    RECEIVER_OVERFLOW            = BIT_17,
    MALFORMED_TLP                = BIT_18,
    ECRC_ERROR                   = BIT_19,
    UNSUPPORTED_REQUEST_ERROR    = BIT_20,
    ACS_VOILATION                = BIT_21,
    UNCORRECTABLE_INTERNAL_ERROR = BIT_22,
    MC_BLOCKED_TLP               = BIT_23,
    ATOMIC_OP_EGRESS_BLOCKED     = BIT_24,
    TLP_PREFIX_BLOCKED_ERROR     = BIT_25
};

DEFINE_FLAGS(PciExpressUncorrectableErrorFlags, pci_express_uncorrectable_error_flags); // TEST: NO



inline const char8* flagToString(PciExpressUncorrectableErrorFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case PciExpressUncorrectableErrorFlag::NONE:                         return "NONE";
        case PciExpressUncorrectableErrorFlag::DATA_LINK_PROTOCOL_ERROR:     return "DATA_LINK_PROTOCOL_ERROR";
        case PciExpressUncorrectableErrorFlag::SURPRISE_DOWN_ERROR:          return "SURPRISE_DOWN_ERROR";
        case PciExpressUncorrectableErrorFlag::POISONED_TLP:                 return "POISONED_TLP";
        case PciExpressUncorrectableErrorFlag::FLOW_CONTROL_PROTOCOL_ERROR:  return "FLOW_CONTROL_PROTOCOL_ERROR";
        case PciExpressUncorrectableErrorFlag::COMPLETION_TIMEOUT:           return "COMPLETION_TIMEOUT";
        case PciExpressUncorrectableErrorFlag::COMPLETER_ABORT:              return "COMPLETER_ABORT";
        case PciExpressUncorrectableErrorFlag::UNEXPECTED_COMPLETION:        return "UNEXPECTED_COMPLETION";
        case PciExpressUncorrectableErrorFlag::RECEIVER_OVERFLOW:            return "RECEIVER_OVERFLOW";
        case PciExpressUncorrectableErrorFlag::MALFORMED_TLP:                return "MALFORMED_TLP";
        case PciExpressUncorrectableErrorFlag::ECRC_ERROR:                   return "ECRC_ERROR";
        case PciExpressUncorrectableErrorFlag::UNSUPPORTED_REQUEST_ERROR:    return "UNSUPPORTED_REQUEST_ERROR";
        case PciExpressUncorrectableErrorFlag::ACS_VOILATION:                return "ACS_VOILATION";
        case PciExpressUncorrectableErrorFlag::UNCORRECTABLE_INTERNAL_ERROR: return "UNCORRECTABLE_INTERNAL_ERROR";
        case PciExpressUncorrectableErrorFlag::MC_BLOCKED_TLP:               return "MC_BLOCKED_TLP";
        case PciExpressUncorrectableErrorFlag::ATOMIC_OP_EGRESS_BLOCKED:     return "ATOMIC_OP_EGRESS_BLOCKED";
        case PciExpressUncorrectableErrorFlag::TLP_PREFIX_BLOCKED_ERROR:     return "TLP_PREFIX_BLOCKED_ERROR";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(PciExpressUncorrectableErrorFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[42];

    sprintf(res, "0x%08X (%s)", (pci_express_uncorrectable_error_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const PciExpressUncorrectableErrorFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[365];

    FLAGS_TO_STRING(res, flags.flags, PciExpressUncorrectableErrorFlag);

    return res;
}



inline const char8* flagsToFullString(const PciExpressUncorrectableErrorFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[378];

    FLAGS_TO_FULL_STRING(res, flags.flags, PciExpressUncorrectableErrorFlag, "0x%08X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSUNCORRECTABLEERRORFLAGS_H
