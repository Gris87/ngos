#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCICARDBUSCONTROLFLAGS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCICARDBUSCONTROLFLAGS_H



#include <com/ngos/shared/common/bits/flags.h>
#include <com/ngos/shared/common/bits/macros.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u16 pci_card_bus_control_flags;

enum class PciCardBusControlFlag: pci_card_bus_control_flags
{
    NONE                         = 0,
    PARITY_ERROR_RESPONSE_ENABLE = BIT_0,
    SYSTEM_ERROR_ENABLE          = BIT_1,
    ISA_ENABLE                   = BIT_2,
    VGA_ENABLE                   = BIT_3,
    MASTER_ABORT_MODE            = BIT_5,
    CARD_BUS_RESET               = BIT_6,
    IREQ_ENABLE                  = BIT_7,
    MEMORY_BASE0_PREFETCHABLE    = BIT_8,
    MEMORY_BASE1_PREFETCHABLE    = BIT_9,
    WRITE_POSTING_ENABLE         = BIT_10
};

DEFINE_FLAGS(PciCardBusControlFlags, pci_card_bus_control_flags); // TEST: NO



inline const char8* flagToString(PciCardBusControlFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case PciCardBusControlFlag::NONE:                         return "NONE";
        case PciCardBusControlFlag::PARITY_ERROR_RESPONSE_ENABLE: return "PARITY_ERROR_RESPONSE_ENABLE";
        case PciCardBusControlFlag::SYSTEM_ERROR_ENABLE:          return "SYSTEM_ERROR_ENABLE";
        case PciCardBusControlFlag::ISA_ENABLE:                   return "ISA_ENABLE";
        case PciCardBusControlFlag::VGA_ENABLE:                   return "VGA_ENABLE";
        case PciCardBusControlFlag::MASTER_ABORT_MODE:            return "MASTER_ABORT_MODE";
        case PciCardBusControlFlag::CARD_BUS_RESET:               return "CARD_BUS_RESET";
        case PciCardBusControlFlag::IREQ_ENABLE:                  return "IREQ_ENABLE";
        case PciCardBusControlFlag::MEMORY_BASE0_PREFETCHABLE:    return "MEMORY_BASE0_PREFETCHABLE";
        case PciCardBusControlFlag::MEMORY_BASE1_PREFETCHABLE:    return "MEMORY_BASE1_PREFETCHABLE";
        case PciCardBusControlFlag::WRITE_POSTING_ENABLE:         return "WRITE_POSTING_ENABLE";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(PciCardBusControlFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[38];

    sprintf(res, "0x%04X (%s)", (pci_card_bus_control_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const PciCardBusControlFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[222];

    FLAGS_TO_STRING(res, flags.flags, PciCardBusControlFlag);

    return res;
}



inline const char8* flagsToFullString(const PciCardBusControlFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[231];

    FLAGS_TO_FULL_STRING(res, flags.flags, PciCardBusControlFlag, "0x%04X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCICARDBUSCONTROLFLAGS_H
