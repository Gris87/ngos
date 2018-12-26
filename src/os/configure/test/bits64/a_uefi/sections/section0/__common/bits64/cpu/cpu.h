#ifndef CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_CPU_CPU_H
#define CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_CPU_CPU_H



#include <buildconfig.h>
#include <src/bits64/cpu/cpu.h>

#include "test/bits64/a_uefi/testengine.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __common_bits64_cpu_cpu);
{
    TEST_CASE("setFlag()/clearFlag()/hasFlag()");
    {
        // HACK: Temporary fix for PIE. Try to find another solution
        u32 *flags;

        // Ignore CppAlignmentVerifier [BEGIN]
        asm volatile(
            "leaq    _ZN3CPU6sFlagsE(%%rip), %0"    // leaq    _ZN3CPU6sFlagsE(%rip), %rbp  # Get address of CPU::sFlags variable to RBP. %RBP == flags
                :                                   // Output parameters
                    "=r" (flags)                    // "r" == any general register, "=" - write only
        );
        // Ignore CppAlignmentVerifier [END]



        TEST_ASSERT_EQUALS(CPU::hasFlag(X86Feature::ALWAYS),        true);
        TEST_ASSERT_EQUALS(CPU::hasFlag(X86Feature::ALWAYS_ZERO),   false);
        TEST_ASSERT_EQUALS(flags[CPU_FEATURES_NGOS_OTHER_FLAGS],    0x0000000D);

        TEST_ASSERT_EQUALS(CPU::setFlag(X86Feature::ALWAYS_ZERO),   NgosStatus::OK);
        TEST_ASSERT_EQUALS(CPU::hasFlag(X86Feature::ALWAYS),        true);
        TEST_ASSERT_EQUALS(CPU::hasFlag(X86Feature::ALWAYS_ZERO),   true);
        TEST_ASSERT_EQUALS(flags[CPU_FEATURES_NGOS_OTHER_FLAGS],    0x0000000F);

        TEST_ASSERT_EQUALS(CPU::clearFlag(X86Feature::ALWAYS_ZERO), NgosStatus::OK);
        TEST_ASSERT_EQUALS(CPU::hasFlag(X86Feature::ALWAYS),        true);
        TEST_ASSERT_EQUALS(CPU::hasFlag(X86Feature::ALWAYS_ZERO),   false);
        TEST_ASSERT_EQUALS(flags[CPU_FEATURES_NGOS_OTHER_FLAGS],    0x0000000D);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_CPU_CPU_H
