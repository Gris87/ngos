#ifndef OS_COMMON_SRC_BITS64_CPU_CPUBUGS_H
#define OS_COMMON_SRC_BITS64_CPU_CPUBUGS_H



#include <ngos/types.h>
#include <ngos/utils.h>



#define AMOUNT_OF_WORDS_FOR_X86_BUGS    1

#define CPU_BUGS_NGOS_COMMON_FLAGS      0



enum class X86Bug: u16
{
    TEST                = WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 0),  // Not a bug, used for testing
    CPU_MELTDOWN        = WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 1),  // CPU is affected by meltdown attack and needs kernel page table isolation
    SPECTRE_V1          = WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 2),  // CPU is affected by Spectre variant 1 attack with conditional branches
    SPECTRE_V2          = WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 3),  // CPU is affected by Spectre variant 2 attack with indirect branches
    SPEC_STORE_BYPASS   = WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 4),  // CPU is affected by speculative store bypass attack
    L1TF                = WORD_BIT(CPU_BUGS_NGOS_COMMON_FLAGS, 5),  // CPU is affected by L1 Terminal Fault
};



#endif // OS_COMMON_SRC_BITS64_CPU_CPUBUGS_H
