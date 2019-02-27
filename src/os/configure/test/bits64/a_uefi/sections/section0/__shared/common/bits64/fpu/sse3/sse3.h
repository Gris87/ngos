#ifndef CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_FPU_SSE3_SSE3_H
#define CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_FPU_SSE3_SSE3_H



#include <buildconfig.h>
#include <common/src/bits64/cpu/cpu.h>

#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse3/asm_testsse3addsubpd.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse3/asm_testsse3addsubps.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse3/asm_testsse3haddpd.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse3/asm_testsse3haddps.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse3/asm_testsse3hsubpd.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse3/asm_testsse3hsubps.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse3/asm_testsse3phaddd.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse3/asm_testsse3phaddw.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse3/asm_testsse3phsubd.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse3/asm_testsse3phsubw.h"
#include "test/bits64/a_uefi/testengine.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __common_bits64_fpu_sse3_sse3);
{
    TEST_CASE("addsubps");
    {
        if (CPU::hasFlag(X86Feature::XMM3))
        {
            float a[4] = { 0.5, 0.4, 0.2, 0.1 };
            float b[4] = { 0.8, 0.3, 0.8, 0.6 };
            float c[4];

            testSse3Addsubps(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.4);
            TEST_ASSERT_FLOAT_EQUALS(a[2], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[3], 0.1);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(b[2], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[3], 0.6);

            TEST_ASSERT_FLOAT_EQUALS(c[0], -0.3);
            TEST_ASSERT_FLOAT_EQUALS(c[1], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(c[2], -0.6);
            TEST_ASSERT_FLOAT_EQUALS(c[3], 0.7);
        }
        else
        {
            UEFI_LVV(("X86Feature::XMM3 not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("addsubpd");
    {
        if (CPU::hasFlag(X86Feature::XMM3))
        {
            double a[2] = { 0.5, 0.4 };
            double b[2] = { 0.8, 0.3 };
            double c[2];

            testSse3Addsubpd(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.4);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.3);

            TEST_ASSERT_FLOAT_EQUALS(c[0], -0.3);
            TEST_ASSERT_FLOAT_EQUALS(c[1], 0.7);
        }
        else
        {
            UEFI_LVV(("X86Feature::XMM3 not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("haddps");
    {
        if (CPU::hasFlag(X86Feature::XMM3))
        {
            float a[4] = { 0.8, 0.5, 0.7, 0.4 };
            float b[4] = { 0.3, 0.2, 0.4, 0.6 };
            float c[4];

            testSse3Haddps(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[2], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[3], 0.4);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(b[2], 0.4);
            TEST_ASSERT_FLOAT_EQUALS(b[3], 0.6);

            TEST_ASSERT_FLOAT_EQUALS(c[0], 1.3);
            TEST_ASSERT_FLOAT_EQUALS(c[1], 1.1);
            TEST_ASSERT_FLOAT_EQUALS(c[2], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(c[3], 1.0);
        }
        else
        {
            UEFI_LVV(("X86Feature::XMM3 not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("haddpd");
    {
        if (CPU::hasFlag(X86Feature::XMM3))
        {
            double a[2] = { 0.1, 0.6 };
            double b[2] = { 0.7, 0.8 };
            double c[2];

            testSse3Haddpd(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.6);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.8);

            TEST_ASSERT_FLOAT_EQUALS(c[0], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(c[1], 1.5);
        }
        else
        {
            UEFI_LVV(("X86Feature::XMM3 not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("hsubps");
    {
        if (CPU::hasFlag(X86Feature::XMM3))
        {
            float a[4] = { 0.1, 0.7, 0.5, 0.9 };
            float b[4] = { 0.2, 0.8, 0.3, 0.7 };
            float c[4];

            testSse3Hsubps(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[2], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[3], 0.9);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[2], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(b[3], 0.7);

            TEST_ASSERT_FLOAT_EQUALS(c[0], -0.6);
            TEST_ASSERT_FLOAT_EQUALS(c[1], -0.4);
            TEST_ASSERT_FLOAT_EQUALS(c[2], -0.6);
            TEST_ASSERT_FLOAT_EQUALS(c[3], -0.4);
        }
        else
        {
            UEFI_LVV(("X86Feature::XMM3 not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("hsubpd");
    {
        if (CPU::hasFlag(X86Feature::XMM3))
        {
            double a[2] = { 0.5, 0.3 };
            double b[2] = { 0.9, 0.2 };
            double c[2];

            testSse3Hsubpd(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.3);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.2);

            TEST_ASSERT_FLOAT_EQUALS(c[0], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(c[1], 0.7);
        }
        else
        {
            UEFI_LVV(("X86Feature::XMM3 not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("phaddw");
    {
        if (CPU::hasFlag(X86Feature::SSSE3))
        {
            u16 a[8] = { 6, 3, 12, 90, 37, 25, 19, 34 };
            u16 b[8] = { 9, 7, 67, 34, 24, 79, 20, 74 };
            u16 c[8];

            testSse3Phaddw(a, b, c);

            TEST_ASSERT_EQUALS(a[0], 6);
            TEST_ASSERT_EQUALS(a[1], 3);
            TEST_ASSERT_EQUALS(a[2], 12);
            TEST_ASSERT_EQUALS(a[3], 90);
            TEST_ASSERT_EQUALS(a[4], 37);
            TEST_ASSERT_EQUALS(a[5], 25);
            TEST_ASSERT_EQUALS(a[6], 19);
            TEST_ASSERT_EQUALS(a[7], 34);

            TEST_ASSERT_EQUALS(b[0], 9);
            TEST_ASSERT_EQUALS(b[1], 7);
            TEST_ASSERT_EQUALS(b[2], 67);
            TEST_ASSERT_EQUALS(b[3], 34);
            TEST_ASSERT_EQUALS(b[4], 24);
            TEST_ASSERT_EQUALS(b[5], 79);
            TEST_ASSERT_EQUALS(b[6], 20);
            TEST_ASSERT_EQUALS(b[7], 74);

            TEST_ASSERT_EQUALS(c[0], 9);
            TEST_ASSERT_EQUALS(c[1], 102);
            TEST_ASSERT_EQUALS(c[2], 62);
            TEST_ASSERT_EQUALS(c[3], 53);
            TEST_ASSERT_EQUALS(c[4], 16);
            TEST_ASSERT_EQUALS(c[5], 101);
            TEST_ASSERT_EQUALS(c[6], 103);
            TEST_ASSERT_EQUALS(c[7], 94);
        }
        else
        {
            UEFI_LVV(("X86Feature::SSSE3 not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("phaddd");
    {
        if (CPU::hasFlag(X86Feature::SSSE3))
        {
            u32 a[4] = { 6, 3, 12, 90 };
            u32 b[4] = { 9, 7, 67, 34 };
            u32 c[4];

            testSse3Phaddd(a, b, c);

            TEST_ASSERT_EQUALS(a[0], 6);
            TEST_ASSERT_EQUALS(a[1], 3);
            TEST_ASSERT_EQUALS(a[2], 12);
            TEST_ASSERT_EQUALS(a[3], 90);

            TEST_ASSERT_EQUALS(b[0], 9);
            TEST_ASSERT_EQUALS(b[1], 7);
            TEST_ASSERT_EQUALS(b[2], 67);
            TEST_ASSERT_EQUALS(b[3], 34);

            TEST_ASSERT_EQUALS(c[0], 9);
            TEST_ASSERT_EQUALS(c[1], 102);
            TEST_ASSERT_EQUALS(c[2], 16);
            TEST_ASSERT_EQUALS(c[3], 101);
        }
        else
        {
            UEFI_LVV(("X86Feature::SSSE3 not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("phsubw");
    {
        if (CPU::hasFlag(X86Feature::SSSE3))
        {
            u16 a[8] = { 6, 3, 12, 90, 37, 25, 19, 34 };
            u16 b[8] = { 9, 7, 67, 34, 24, 79, 20, 74 };
            u16 c[8];

            testSse3Phsubw(a, b, c);

            TEST_ASSERT_EQUALS(a[0], 6);
            TEST_ASSERT_EQUALS(a[1], 3);
            TEST_ASSERT_EQUALS(a[2], 12);
            TEST_ASSERT_EQUALS(a[3], 90);
            TEST_ASSERT_EQUALS(a[4], 37);
            TEST_ASSERT_EQUALS(a[5], 25);
            TEST_ASSERT_EQUALS(a[6], 19);
            TEST_ASSERT_EQUALS(a[7], 34);

            TEST_ASSERT_EQUALS(b[0], 9);
            TEST_ASSERT_EQUALS(b[1], 7);
            TEST_ASSERT_EQUALS(b[2], 67);
            TEST_ASSERT_EQUALS(b[3], 34);
            TEST_ASSERT_EQUALS(b[4], 24);
            TEST_ASSERT_EQUALS(b[5], 79);
            TEST_ASSERT_EQUALS(b[6], 20);
            TEST_ASSERT_EQUALS(b[7], 74);

            TEST_ASSERT_EQUALS(c[0], 3);
            TEST_ASSERT_EQUALS(c[1], 65458);
            TEST_ASSERT_EQUALS(c[2], 12);
            TEST_ASSERT_EQUALS(c[3], 65521);
            TEST_ASSERT_EQUALS(c[4], 2);
            TEST_ASSERT_EQUALS(c[5], 33);
            TEST_ASSERT_EQUALS(c[6], 65481);
            TEST_ASSERT_EQUALS(c[7], 65482);
        }
        else
        {
            UEFI_LVV(("X86Feature::SSSE3 not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("phsubd");
    {
        if (CPU::hasFlag(X86Feature::SSSE3))
        {
            u32 a[4] = { 6, 3, 12, 90 };
            u32 b[4] = { 9, 7, 67, 34 };
            u32 c[4];

            testSse3Phsubd(a, b, c);

            TEST_ASSERT_EQUALS(a[0], 6);
            TEST_ASSERT_EQUALS(a[1], 3);
            TEST_ASSERT_EQUALS(a[2], 12);
            TEST_ASSERT_EQUALS(a[3], 90);

            TEST_ASSERT_EQUALS(b[0], 9);
            TEST_ASSERT_EQUALS(b[1], 7);
            TEST_ASSERT_EQUALS(b[2], 67);
            TEST_ASSERT_EQUALS(b[3], 34);

            TEST_ASSERT_EQUALS(c[0], 3);
            TEST_ASSERT_EQUALS(c[1], 4294967218);
            TEST_ASSERT_EQUALS(c[2], 2);
            TEST_ASSERT_EQUALS(c[3], 33);
        }
        else
        {
            UEFI_LVV(("X86Feature::SSSE3 not supported"));
        }
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_FPU_SSE3_SSE3_H
