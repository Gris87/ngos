#ifndef OS_SHARED_COMMON_SRC_BITS64_CPU_X86BUG_H
#define OS_SHARED_COMMON_SRC_BITS64_CPU_X86BUG_H



#include <common/src/com/ngos/shared/common/cpu/x86bugword.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>
#include <common/src/com/ngos/shared/common/ngos/utils.h>



enum class X86Bug: u16 // Ignore CppEnumVerifier
{
    TEST                = WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 0),  // Not a bug, used for testing
    CPU_MELTDOWN        = WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 1),  // CPU is affected by meltdown attack and needs kernel page table isolation
    SPECTRE_V1          = WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 2),  // CPU is affected by Spectre variant 1 attack with conditional branches
    SPECTRE_V2          = WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 3),  // CPU is affected by Spectre variant 2 attack with indirect branches
    SPEC_STORE_BYPASS   = WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 4),  // CPU is affected by speculative store bypass attack
    L1TF                = WORD_BIT(x86BugWord::NGOS_COMMON_FLAGS, 5),  // CPU is affected by L1 Terminal Fault
};



#endif // OS_SHARED_COMMON_SRC_BITS64_CPU_X86BUG_H
