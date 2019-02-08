#ifndef CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_FPU_AVX_AVX_H
#define CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_FPU_AVX_AVX_H



#include <buildconfig.h>
#include <src/bits64/cpu/cpu.h>

#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/avx/asm_testavxvaddps.h"
#include "test/bits64/a_uefi/testengine.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __common_bits64_fpu_avx_avx);
{
    TEST_CASE("vaddps");
    {
        if (CPU::hasFlag(X86Feature::AVX))
        {
            float a[4] = { 0.5, 0.4, 0.2, 0.1 };
            float b[4] = { 0.8, 0.3, 0.8, 0.6 };
            float c[4];

            testAvxVaddps(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.4);
            TEST_ASSERT_FLOAT_EQUALS(a[2], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[3], 0.1);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(b[2], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[3], 0.6);

            TEST_ASSERT_FLOAT_EQUALS(c[0], 1.3);
            TEST_ASSERT_FLOAT_EQUALS(c[1], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(c[2], 1.0);
            TEST_ASSERT_FLOAT_EQUALS(c[3], 0.7);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX not supported"));
        }
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_FPU_AVX_AVX_H
