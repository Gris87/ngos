#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIBRIDGECONTROLFLAGS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIBRIDGECONTROLFLAGS_H



#include <com/ngos/shared/common/bits/flags.h>
#include <com/ngos/shared/common/bits/macros.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u16 pci_bridge_control_flags;

enum class PciBridgeControlFlag: pci_bridge_control_flags
{
    NONE                              = 0,
    PARITY_ERROR_RESPONSE_ENABLE      = BIT_0,
    SYSTEM_ERROR_ENABLE               = BIT_1,
    ISA_ENABLE                        = BIT_2,
    VGA_ENABLE                        = BIT_3,
    MASTER_ABORT_MODE                 = BIT_5,
    SECONDARY_BUS_RESET               = BIT_6,
    FAST_BACK_TO_BACK_ENABLE          = BIT_7,
    PRIMARY_DISCARD_TIMER             = BIT_8,
    SECONDARY_DISCARD_TIMER           = BIT_9,
    DISCARD_TIMER_STATUS              = BIT_10,
    DISCARD_TIMER_SYSTEM_ERROR_ENABLE = BIT_11
};

DEFINE_FLAGS(PciBridgeControlFlags, pci_bridge_control_flags); // TEST: NO



inline const char8* flagToString(PciBridgeControlFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case PciBridgeControlFlag::NONE:                              return "NONE";
        case PciBridgeControlFlag::PARITY_ERROR_RESPONSE_ENABLE:      return "PARITY_ERROR_RESPONSE_ENABLE";
        case PciBridgeControlFlag::SYSTEM_ERROR_ENABLE:               return "SYSTEM_ERROR_ENABLE";
        case PciBridgeControlFlag::ISA_ENABLE:                        return "ISA_ENABLE";
        case PciBridgeControlFlag::VGA_ENABLE:                        return "VGA_ENABLE";
        case PciBridgeControlFlag::MASTER_ABORT_MODE:                 return "MASTER_ABORT_MODE";
        case PciBridgeControlFlag::SECONDARY_BUS_RESET:               return "SECONDARY_BUS_RESET";
        case PciBridgeControlFlag::FAST_BACK_TO_BACK_ENABLE:          return "FAST_BACK_TO_BACK_ENABLE";
        case PciBridgeControlFlag::PRIMARY_DISCARD_TIMER:             return "PRIMARY_DISCARD_TIMER";
        case PciBridgeControlFlag::SECONDARY_DISCARD_TIMER:           return "SECONDARY_DISCARD_TIMER";
        case PciBridgeControlFlag::DISCARD_TIMER_STATUS:              return "DISCARD_TIMER_STATUS";
        case PciBridgeControlFlag::DISCARD_TIMER_SYSTEM_ERROR_ENABLE: return "DISCARD_TIMER_SYSTEM_ERROR_ENABLE";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(PciBridgeControlFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[43];

    sprintf(res, "0x%04X (%s)", (pci_bridge_control_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const PciBridgeControlFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[270];

    FLAGS_TO_STRING(res, flags.flags, PciBridgeControlFlag);

    return res;
}



inline const char8* flagsToFullString(const PciBridgeControlFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[279];

    FLAGS_TO_FULL_STRING(res, flags.flags, PciBridgeControlFlag, "0x%04X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIBRIDGECONTROLFLAGS_H
