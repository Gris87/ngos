#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_MACHINE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_MACHINE_H



#include <common/src/com/ngos/shared/common/ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile
#include <common/src/com/ngos/shared/common/printf/printf.h>
#endif



enum class ElfMachine: u16
{
    NONE             = 0,
    MACHINE_M32      = 0x0001,
    MACHINE_SPARC    = 0x0002,
    MACHINE_X86      = 0x0003,
    MACHINE_68K      = 0x0004,
    MACHINE_88K      = 0x0005,
    MACHINE_860      = 0x0007,
    MACHINE_MIPS     = 0x0008,
    MACHINE_POWER_PC = 0x0014,
    MACHINE_S390     = 0x0016,
    MACHINE_ARM      = 0x0028,
    MACHINE_SUPERH   = 0x002A,
    MACHINE_IA_64    = 0x0032,
    MACHINE_X86_64   = 0x003E,
    MACHINE_AARCH64  = 0x00B7,
    MACHINE_RISC_V   = 0x00F3
};



inline const char8* enumToString(ElfMachine machine) // TEST: NO
{
    // COMMON_LT((" | machine = %u", machine)); // Commented to avoid bad looking logs



    switch (machine)
    {
        case ElfMachine::NONE:             return "NONE";
        case ElfMachine::MACHINE_M32:      return "MACHINE_M32";
        case ElfMachine::MACHINE_SPARC:    return "MACHINE_SPARC";
        case ElfMachine::MACHINE_X86:      return "MACHINE_X86";
        case ElfMachine::MACHINE_68K:      return "MACHINE_68K";
        case ElfMachine::MACHINE_88K:      return "MACHINE_88K";
        case ElfMachine::MACHINE_860:      return "MACHINE_860";
        case ElfMachine::MACHINE_MIPS:     return "MACHINE_MIPS";
        case ElfMachine::MACHINE_POWER_PC: return "MACHINE_POWER_PC";
        case ElfMachine::MACHINE_S390:     return "MACHINE_S390";
        case ElfMachine::MACHINE_ARM:      return "MACHINE_ARM";
        case ElfMachine::MACHINE_SUPERH:   return "MACHINE_SUPERH";
        case ElfMachine::MACHINE_IA_64:    return "MACHINE_IA_64";
        case ElfMachine::MACHINE_X86_64:   return "MACHINE_X86_64";
        case ElfMachine::MACHINE_AARCH64:  return "MACHINE_AARCH64";
        case ElfMachine::MACHINE_RISC_V:   return "MACHINE_RISC_V";

        default: return "UNKNOWN";
    }
}



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile



inline const char8* enumToFullString(ElfMachine machine) // TEST: NO
{
    // COMMON_LT((" | machine = %u", machine)); // Commented to avoid bad looking logs



    static char8 res[26];

    sprintf(res, "0x%04X (%s)", machine, enumToString(machine));

    return res;
}



#endif



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_ELF_MACHINE_H
