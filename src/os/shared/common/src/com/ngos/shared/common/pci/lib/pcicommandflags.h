#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCICOMMANDFLAGS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCICOMMANDFLAGS_H



#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef bad_uint16 pci_command_flags;

enum class PciCommandFlag: pci_command_flags
{
    NONE                               = 0,
    IO_SPACE_ENABLE                    = (1ULL << 0),
    MEMORY_SPACE_ENABLE                = (1ULL << 1),
    BUS_MASTER_ENABLE                  = (1ULL << 2),
    SPECIAL_CYCLE_ENABLE               = (1ULL << 3),
    MEMORY_WRITE_AND_INVALIDATE_ENABLE = (1ULL << 4),
    VGA_PALETTE_SNOOP_ENABLE           = (1ULL << 5),
    PARITY_ERROR_RESPONSE              = (1ULL << 6),
    WAIT_CYCLE_CONTROL                 = (1ULL << 7),
    SYSTEM_ERROR_ENABLE                = (1ULL << 8),
    FAST_BACK_TO_BACK_ENABLE           = (1ULL << 9),
    INTERRUPT_DISABLE                  = (1ULL << 10)
};

DEFINE_FLAGS(PciCommandFlags, pci_command_flags); // TEST: NO



inline const char8* flagToString(PciCommandFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case PciCommandFlag::NONE:                               return "NONE";
        case PciCommandFlag::IO_SPACE_ENABLE:                    return "IO_SPACE_ENABLE";
        case PciCommandFlag::MEMORY_SPACE_ENABLE:                return "MEMORY_SPACE_ENABLE";
        case PciCommandFlag::BUS_MASTER_ENABLE:                  return "BUS_MASTER_ENABLE";
        case PciCommandFlag::SPECIAL_CYCLE_ENABLE:               return "SPECIAL_CYCLE_ENABLE";
        case PciCommandFlag::MEMORY_WRITE_AND_INVALIDATE_ENABLE: return "MEMORY_WRITE_AND_INVALIDATE_ENABLE";
        case PciCommandFlag::VGA_PALETTE_SNOOP_ENABLE:           return "VGA_PALETTE_SNOOP_ENABLE";
        case PciCommandFlag::PARITY_ERROR_RESPONSE:              return "PARITY_ERROR_RESPONSE";
        case PciCommandFlag::WAIT_CYCLE_CONTROL:                 return "WAIT_CYCLE_CONTROL";
        case PciCommandFlag::SYSTEM_ERROR_ENABLE:                return "SYSTEM_ERROR_ENABLE";
        case PciCommandFlag::FAST_BACK_TO_BACK_ENABLE:           return "FAST_BACK_TO_BACK_ENABLE";
        case PciCommandFlag::INTERRUPT_DISABLE:                  return "INTERRUPT_DISABLE";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(PciCommandFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[44];

    sprintf(res, "0x%04X (%s)", (pci_command_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const PciCommandFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[274];

    FLAGS_TO_STRING(res, flags.flags, PciCommandFlag);

    return res;
}



inline const char8* flagsToFullString(const PciCommandFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[283];

    FLAGS_TO_FULL_STRING(res, flags.flags, PciCommandFlag, "0x%04X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCICOMMANDFLAGS_H
