#ifndef CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_FPU_SSE2_SSE2_H
#define CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_FPU_SSE2_SSE2_H



#include <buildconfig.h>
#include <src/bits64/cpu/cpu.h>

#include "test/bits64/a_uefi/testengine.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse2/asm/testsse2addpd.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __common_bits64_fpu_sse2_sse2);
{
    TEST_CASE("addpd");
    {
        if (CPU::hasFlag(X86Feature::XMM2))
        {
            double a[4] = { 0.1, 0.6 };
            double b[4] = { 0.5, 0.4 };
            double c[4];

            testSse2Addpd(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.6);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.4);

            TEST_ASSERT_FLOAT_EQUALS(c[0], 0.6);
            TEST_ASSERT_FLOAT_EQUALS(c[1], 1.0);
        }
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_FPU_SSE2_SSE2_H
