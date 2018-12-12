#ifndef ELF_ELFMACHINE_H
#define ELF_ELFMACHINE_H



#include <Qt>



enum class ElfMachine: quint16
{
    NONE                = 0x00,
    MACHINE_M32         = 0x01,
    MACHINE_SPARC       = 0x02,
    MACHINE_X86         = 0x03,
    MACHINE_68K         = 0x04,
    MACHINE_88K         = 0x05,
    MACHINE_860         = 0x07,
    MACHINE_MIPS        = 0x08,
    MACHINE_POWER_PC    = 0x14,
    MACHINE_S390        = 0x16,
    MACHINE_ARM         = 0x28,
    MACHINE_SUPERH      = 0x2A,
    MACHINE_IA_64       = 0x32,
    MACHINE_X86_64      = 0x3E,
    MACHINE_AARCH64     = 0xB7,
    MACHINE_RISC_V      = 0xF3
};



#endif // ELF_ELFMACHINE_H
