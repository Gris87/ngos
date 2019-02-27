#ifndef CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CPU_CPU_H
#define CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CPU_CPU_H



#include <buildconfig.h>
#include <common/src/bits64/cpu/cpu.h>

#include "test/bits64/a_uefi/testengine.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_cpu_cpu);
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



        u32 temp = flags[CPU_FEATURES_NGOS_OTHER_FLAGS];

        TEST_ASSERT_EQUALS(CPU::hasFlag(X86Feature::ALWAYS),        true);
        TEST_ASSERT_EQUALS(CPU::hasFlag(X86Feature::ALWAYS_ZERO),   false);
        TEST_ASSERT_EQUALS(flags[CPU_FEATURES_NGOS_OTHER_FLAGS],    temp);

        TEST_ASSERT_EQUALS(CPU::setFlag(X86Feature::ALWAYS_ZERO),   NgosStatus::OK);
        TEST_ASSERT_EQUALS(CPU::hasFlag(X86Feature::ALWAYS),        true);
        TEST_ASSERT_EQUALS(CPU::hasFlag(X86Feature::ALWAYS_ZERO),   true);
        TEST_ASSERT_EQUALS(flags[CPU_FEATURES_NGOS_OTHER_FLAGS],    temp | 0x02);

        TEST_ASSERT_EQUALS(CPU::clearFlag(X86Feature::ALWAYS_ZERO), NgosStatus::OK);
        TEST_ASSERT_EQUALS(CPU::hasFlag(X86Feature::ALWAYS),        true);
        TEST_ASSERT_EQUALS(CPU::hasFlag(X86Feature::ALWAYS_ZERO),   false);
        TEST_ASSERT_EQUALS(flags[CPU_FEATURES_NGOS_OTHER_FLAGS],    temp);
    }
    TEST_CASE_END();



    TEST_CASE("setBug()/clearBug()/hasBug()");
    {
        // HACK: Temporary fix for PIE. Try to find another solution
        u32 *bugs;

        // Ignore CppAlignmentVerifier [BEGIN]
        asm volatile(
            "leaq    _ZN3CPU5sBugsE(%%rip), %0"    // leaq    _ZN3CPU5sBugsE(%rip), %rbp  # Get address of CPU::sBugs variable to RBP. %RBP == bugs
                :                                   // Output parameters
                    "=r" (bugs)                    // "r" == any general register, "=" - write only
        );
        // Ignore CppAlignmentVerifier [END]



        u32 temp = bugs[CPU_BUGS_NGOS_COMMON_FLAGS];

        TEST_ASSERT_EQUALS(CPU::hasBug(X86Bug::TEST),        false);
        TEST_ASSERT_EQUALS(bugs[CPU_BUGS_NGOS_COMMON_FLAGS], temp);

        TEST_ASSERT_EQUALS(CPU::setBug(X86Bug::TEST),        NgosStatus::OK);
        TEST_ASSERT_EQUALS(CPU::hasBug(X86Bug::TEST),        true);
        TEST_ASSERT_EQUALS(bugs[CPU_BUGS_NGOS_COMMON_FLAGS], temp | 0x01);

        TEST_ASSERT_EQUALS(CPU::clearBug(X86Bug::TEST),      NgosStatus::OK);
        TEST_ASSERT_EQUALS(CPU::hasBug(X86Bug::TEST),        false);
        TEST_ASSERT_EQUALS(bugs[CPU_BUGS_NGOS_COMMON_FLAGS], temp);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CPU_CPU_H
