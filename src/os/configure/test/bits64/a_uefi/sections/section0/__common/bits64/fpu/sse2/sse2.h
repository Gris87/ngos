#ifndef CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_FPU_SSE2_SSE2_H
#define CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_FPU_SSE2_SSE2_H



#include <buildconfig.h>
#include <src/bits64/cpu/cpu.h>

#include "test/bits64/a_uefi/testengine.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse2/asm_testsse2addpd.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse2/asm_testsse2divpd.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse2/asm_testsse2maxpd.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse2/asm_testsse2minpd.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse2/asm_testsse2mulpd.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse2/asm_testsse2rcppd.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse2/asm_testsse2rsqrtpd.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse2/asm_testsse2sqrtpd.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse2/asm_testsse2subpd.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __common_bits64_fpu_sse2_sse2);
{
    TEST_CASE("addpd");
    {
        if (CPU::hasFlag(X86Feature::XMM2))
        {
            double a[2] = { 0.5, 0.4 };
            double b[2] = { 0.8, 0.3 };
            double c[2];

            testSse2Addpd(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.4);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.3);

            TEST_ASSERT_FLOAT_EQUALS(c[0], 1.3);
            TEST_ASSERT_FLOAT_EQUALS(c[1], 0.7);
        }
    }
    TEST_CASE_END();



    TEST_CASE("subpd");
    {
        if (CPU::hasFlag(X86Feature::XMM2))
        {
            double a[2] = { 0.1, 0.5 };
            double b[2] = { 0.7, 0.3 };
            double c[2];

            testSse2Subpd(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.5);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.3);

            TEST_ASSERT_FLOAT_EQUALS(c[0], -0.6);
            TEST_ASSERT_FLOAT_EQUALS(c[1], 0.2);
        }
    }
    TEST_CASE_END();



    TEST_CASE("mulpd");
    {
        if (CPU::hasFlag(X86Feature::XMM2))
        {
            double a[2] = { 0.3, 0.5 };
            double b[2] = { 0.4, 0.6 };
            double c[2];

            testSse2Mulpd(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.5);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 0.4);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.6);

            TEST_ASSERT_FLOAT_EQUALS(c[0], 0.12);
            TEST_ASSERT_FLOAT_EQUALS(c[1], 0.3);
        }
    }
    TEST_CASE_END();



    TEST_CASE("divpd");
    {
        if (CPU::hasFlag(X86Feature::XMM2))
        {
            double a[2] = { 0.8, 0.2 };
            double b[2] = { 0.3, 0.1 };
            double c[2];

            testSse2Divpd(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.2);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.1);

            TEST_ASSERT_FLOAT_EQUALS(c[0], 2.666);
            TEST_ASSERT_FLOAT_EQUALS(c[1], 2.0);
        }
    }
    TEST_CASE_END();



    TEST_CASE("sqrtpd");
    {
        if (CPU::hasFlag(X86Feature::XMM2))
        {
            double a[2] = { 1.0, 4.0 };
            double b[2];

            testSse2Sqrtpd(a, b);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 1.0);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 4.0);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 1.0);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 2.0);
        }
    }
    TEST_CASE_END();



    TEST_CASE("rcppd");
    {
        if (CPU::hasFlag(X86Feature::XMM2))
        {
            double a[2] = { 0.1, 0.3 };
            double b[2];

            testSse2Rcppd(a, b);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.3);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 10.0);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 3.333);
        }
    }
    TEST_CASE_END();



    TEST_CASE("rsqrtpd");
    {
        if (CPU::hasFlag(X86Feature::XMM2))
        {
            double a[2] = { 1.0, 4.0 };
            double b[2];

            testSse2Rsqrtpd(a, b);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 1.0);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 4.0);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 1.0);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.5);
        }
    }
    TEST_CASE_END();



    TEST_CASE("maxpd");
    {
        if (CPU::hasFlag(X86Feature::XMM2))
        {
            double a[2] = { 0.9, 0.3 };
            double b[2] = { 0.1, 0.5 };
            double c[2];

            testSse2Maxpd(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.3);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.5);

            TEST_ASSERT_FLOAT_EQUALS(c[0], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(c[1], 0.5);
        }
    }
    TEST_CASE_END();



    TEST_CASE("minpd");
    {
        if (CPU::hasFlag(X86Feature::XMM2))
        {
            double a[2] = { 0.9, 0.3 };
            double b[2] = { 0.1, 0.5 };
            double c[2];

            testSse2Minpd(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.3);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.5);

            TEST_ASSERT_FLOAT_EQUALS(c[0], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(c[1], 0.3);
        }
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_FPU_SSE2_SSE2_H
