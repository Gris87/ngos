#ifndef CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_FPU_SSE2_SSE2_H
#define CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_FPU_SSE2_SSE2_H



#include <buildconfig.h>
#include <common/src/bits64/cpu/cpu.h>

#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse2/asm_testsse2addpd.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse2/asm_testsse2divpd.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse2/asm_testsse2maxpd.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse2/asm_testsse2minpd.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse2/asm_testsse2mulpd.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse2/asm_testsse2paddb.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse2/asm_testsse2paddd.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse2/asm_testsse2paddq.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse2/asm_testsse2paddw.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse2/asm_testsse2psubb.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse2/asm_testsse2psubd.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse2/asm_testsse2psubq.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse2/asm_testsse2psubw.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse2/asm_testsse2sqrtpd.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse2/asm_testsse2subpd.h"
#include "test/bits64/a_uefi/testengine.h"



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
        else
        {
            UEFI_LVV(("X86Feature::XMM2 not supported"));
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
        else
        {
            UEFI_LVV(("X86Feature::XMM2 not supported"));
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
        else
        {
            UEFI_LVV(("X86Feature::XMM2 not supported"));
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
        else
        {
            UEFI_LVV(("X86Feature::XMM2 not supported"));
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
        else
        {
            UEFI_LVV(("X86Feature::XMM2 not supported"));
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
        else
        {
            UEFI_LVV(("X86Feature::XMM2 not supported"));
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
        else
        {
            UEFI_LVV(("X86Feature::XMM2 not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("paddb");
    {
        if (CPU::hasFlag(X86Feature::XMM2))
        {
            u8 a[16] = { 100, 30, 64, 13, 32, 97, 24, 68, 21, 64, 20, 74, 23, 19, 3, 7 };
            u8 b[16] = { 200, 98, 97, 32, 14, 95, 13, 47, 13, 10, 47, 64, 12, 74, 1, 8 };
            u8 c[16];

            testSse2Paddb(a, b, c);

            TEST_ASSERT_EQUALS(a[0],  100);
            TEST_ASSERT_EQUALS(a[1],  30);
            TEST_ASSERT_EQUALS(a[2],  64);
            TEST_ASSERT_EQUALS(a[3],  13);
            TEST_ASSERT_EQUALS(a[4],  32);
            TEST_ASSERT_EQUALS(a[5],  97);
            TEST_ASSERT_EQUALS(a[6],  24);
            TEST_ASSERT_EQUALS(a[7],  68);
            TEST_ASSERT_EQUALS(a[8],  21);
            TEST_ASSERT_EQUALS(a[9],  64);
            TEST_ASSERT_EQUALS(a[10], 20);
            TEST_ASSERT_EQUALS(a[11], 74);
            TEST_ASSERT_EQUALS(a[12], 23);
            TEST_ASSERT_EQUALS(a[13], 19);
            TEST_ASSERT_EQUALS(a[14], 3);
            TEST_ASSERT_EQUALS(a[15], 7);

            TEST_ASSERT_EQUALS(b[0],  200);
            TEST_ASSERT_EQUALS(b[1],  98);
            TEST_ASSERT_EQUALS(b[2],  97);
            TEST_ASSERT_EQUALS(b[3],  32);
            TEST_ASSERT_EQUALS(b[4],  14);
            TEST_ASSERT_EQUALS(b[5],  95);
            TEST_ASSERT_EQUALS(b[6],  13);
            TEST_ASSERT_EQUALS(b[7],  47);
            TEST_ASSERT_EQUALS(b[8],  13);
            TEST_ASSERT_EQUALS(b[9],  10);
            TEST_ASSERT_EQUALS(b[10], 47);
            TEST_ASSERT_EQUALS(b[11], 64);
            TEST_ASSERT_EQUALS(b[12], 12);
            TEST_ASSERT_EQUALS(b[13], 74);
            TEST_ASSERT_EQUALS(b[14], 1);
            TEST_ASSERT_EQUALS(b[15], 8);

            TEST_ASSERT_EQUALS(c[0],  44);
            TEST_ASSERT_EQUALS(c[1],  128);
            TEST_ASSERT_EQUALS(c[2],  161);
            TEST_ASSERT_EQUALS(c[3],  45);
            TEST_ASSERT_EQUALS(c[4],  46);
            TEST_ASSERT_EQUALS(c[5],  192);
            TEST_ASSERT_EQUALS(c[6],  37);
            TEST_ASSERT_EQUALS(c[7],  115);
            TEST_ASSERT_EQUALS(c[8],  34);
            TEST_ASSERT_EQUALS(c[9],  74);
            TEST_ASSERT_EQUALS(c[10], 67);
            TEST_ASSERT_EQUALS(c[11], 138);
            TEST_ASSERT_EQUALS(c[12], 35);
            TEST_ASSERT_EQUALS(c[13], 93);
            TEST_ASSERT_EQUALS(c[14], 4);
            TEST_ASSERT_EQUALS(c[15], 15);
        }
        else
        {
            UEFI_LVV(("X86Feature::XMM2 not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("paddw");
    {
        if (CPU::hasFlag(X86Feature::XMM2))
        {
            u16 a[8] = { 100, 30, 64, 13, 32, 97, 24, 68 };
            u16 b[8] = { 200, 98, 97, 32, 14, 95, 13, 47 };
            u16 c[8];

            testSse2Paddw(a, b, c);

            TEST_ASSERT_EQUALS(a[0], 100);
            TEST_ASSERT_EQUALS(a[1], 30);
            TEST_ASSERT_EQUALS(a[2], 64);
            TEST_ASSERT_EQUALS(a[3], 13);
            TEST_ASSERT_EQUALS(a[4], 32);
            TEST_ASSERT_EQUALS(a[5], 97);
            TEST_ASSERT_EQUALS(a[6], 24);
            TEST_ASSERT_EQUALS(a[7], 68);

            TEST_ASSERT_EQUALS(b[0], 200);
            TEST_ASSERT_EQUALS(b[1], 98);
            TEST_ASSERT_EQUALS(b[2], 97);
            TEST_ASSERT_EQUALS(b[3], 32);
            TEST_ASSERT_EQUALS(b[4], 14);
            TEST_ASSERT_EQUALS(b[5], 95);
            TEST_ASSERT_EQUALS(b[6], 13);
            TEST_ASSERT_EQUALS(b[7], 47);

            TEST_ASSERT_EQUALS(c[0], 300);
            TEST_ASSERT_EQUALS(c[1], 128);
            TEST_ASSERT_EQUALS(c[2], 161);
            TEST_ASSERT_EQUALS(c[3], 45);
            TEST_ASSERT_EQUALS(c[4], 46);
            TEST_ASSERT_EQUALS(c[5], 192);
            TEST_ASSERT_EQUALS(c[6], 37);
            TEST_ASSERT_EQUALS(c[7], 115);
        }
        else
        {
            UEFI_LVV(("X86Feature::XMM2 not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("paddd");
    {
        if (CPU::hasFlag(X86Feature::XMM2))
        {
            u32 a[4] = { 100, 30, 64, 13 };
            u32 b[4] = { 200, 98, 97, 32 };
            u32 c[4];

            testSse2Paddd(a, b, c);

            TEST_ASSERT_EQUALS(a[0], 100);
            TEST_ASSERT_EQUALS(a[1], 30);
            TEST_ASSERT_EQUALS(a[2], 64);
            TEST_ASSERT_EQUALS(a[3], 13);

            TEST_ASSERT_EQUALS(b[0], 200);
            TEST_ASSERT_EQUALS(b[1], 98);
            TEST_ASSERT_EQUALS(b[2], 97);
            TEST_ASSERT_EQUALS(b[3], 32);

            TEST_ASSERT_EQUALS(c[0], 300);
            TEST_ASSERT_EQUALS(c[1], 128);
            TEST_ASSERT_EQUALS(c[2], 161);
            TEST_ASSERT_EQUALS(c[3], 45);
        }
        else
        {
            UEFI_LVV(("X86Feature::XMM2 not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("paddq");
    {
        if (CPU::hasFlag(X86Feature::XMM2))
        {
            u64 a[2] = { 100, 30 };
            u64 b[2] = { 200, 98 };
            u64 c[2];

            testSse2Paddq(a, b, c);

            TEST_ASSERT_EQUALS(a[0], 100);
            TEST_ASSERT_EQUALS(a[1], 30);

            TEST_ASSERT_EQUALS(b[0], 200);
            TEST_ASSERT_EQUALS(b[1], 98);

            TEST_ASSERT_EQUALS(c[0], 300);
            TEST_ASSERT_EQUALS(c[1], 128);
        }
        else
        {
            UEFI_LVV(("X86Feature::XMM2 not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("psubb");
    {
        if (CPU::hasFlag(X86Feature::XMM2))
        {
            u8 a[16] = { 100, 30, 64, 13, 32, 97, 24, 68, 21, 64, 20, 74, 23, 19, 3, 7 };
            u8 b[16] = { 200, 98, 97, 32, 14, 95, 13, 47, 13, 10, 47, 64, 12, 74, 1, 8 };
            u8 c[16];

            testSse2Psubb(a, b, c);

            TEST_ASSERT_EQUALS(a[0],  100);
            TEST_ASSERT_EQUALS(a[1],  30);
            TEST_ASSERT_EQUALS(a[2],  64);
            TEST_ASSERT_EQUALS(a[3],  13);
            TEST_ASSERT_EQUALS(a[4],  32);
            TEST_ASSERT_EQUALS(a[5],  97);
            TEST_ASSERT_EQUALS(a[6],  24);
            TEST_ASSERT_EQUALS(a[7],  68);
            TEST_ASSERT_EQUALS(a[8],  21);
            TEST_ASSERT_EQUALS(a[9],  64);
            TEST_ASSERT_EQUALS(a[10], 20);
            TEST_ASSERT_EQUALS(a[11], 74);
            TEST_ASSERT_EQUALS(a[12], 23);
            TEST_ASSERT_EQUALS(a[13], 19);
            TEST_ASSERT_EQUALS(a[14], 3);
            TEST_ASSERT_EQUALS(a[15], 7);

            TEST_ASSERT_EQUALS(b[0],  200);
            TEST_ASSERT_EQUALS(b[1],  98);
            TEST_ASSERT_EQUALS(b[2],  97);
            TEST_ASSERT_EQUALS(b[3],  32);
            TEST_ASSERT_EQUALS(b[4],  14);
            TEST_ASSERT_EQUALS(b[5],  95);
            TEST_ASSERT_EQUALS(b[6],  13);
            TEST_ASSERT_EQUALS(b[7],  47);
            TEST_ASSERT_EQUALS(b[8],  13);
            TEST_ASSERT_EQUALS(b[9],  10);
            TEST_ASSERT_EQUALS(b[10], 47);
            TEST_ASSERT_EQUALS(b[11], 64);
            TEST_ASSERT_EQUALS(b[12], 12);
            TEST_ASSERT_EQUALS(b[13], 74);
            TEST_ASSERT_EQUALS(b[14], 1);
            TEST_ASSERT_EQUALS(b[15], 8);

            TEST_ASSERT_EQUALS(c[0],  156);
            TEST_ASSERT_EQUALS(c[1],  188);
            TEST_ASSERT_EQUALS(c[2],  223);
            TEST_ASSERT_EQUALS(c[3],  237);
            TEST_ASSERT_EQUALS(c[4],  18);
            TEST_ASSERT_EQUALS(c[5],  2);
            TEST_ASSERT_EQUALS(c[6],  11);
            TEST_ASSERT_EQUALS(c[7],  21);
            TEST_ASSERT_EQUALS(c[8],  8);
            TEST_ASSERT_EQUALS(c[9],  54);
            TEST_ASSERT_EQUALS(c[10], 229);
            TEST_ASSERT_EQUALS(c[11], 10);
            TEST_ASSERT_EQUALS(c[12], 11);
            TEST_ASSERT_EQUALS(c[13], 201);
            TEST_ASSERT_EQUALS(c[14], 2);
            TEST_ASSERT_EQUALS(c[15], 255);
        }
        else
        {
            UEFI_LVV(("X86Feature::XMM2 not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("psubw");
    {
        if (CPU::hasFlag(X86Feature::XMM2))
        {
            u16 a[8] = { 100, 30, 64, 13, 32, 97, 24, 68 };
            u16 b[8] = { 200, 98, 97, 32, 14, 95, 13, 47 };
            u16 c[8];

            testSse2Psubw(a, b, c);

            TEST_ASSERT_EQUALS(a[0], 100);
            TEST_ASSERT_EQUALS(a[1], 30);
            TEST_ASSERT_EQUALS(a[2], 64);
            TEST_ASSERT_EQUALS(a[3], 13);
            TEST_ASSERT_EQUALS(a[4], 32);
            TEST_ASSERT_EQUALS(a[5], 97);
            TEST_ASSERT_EQUALS(a[6], 24);
            TEST_ASSERT_EQUALS(a[7], 68);

            TEST_ASSERT_EQUALS(b[0], 200);
            TEST_ASSERT_EQUALS(b[1], 98);
            TEST_ASSERT_EQUALS(b[2], 97);
            TEST_ASSERT_EQUALS(b[3], 32);
            TEST_ASSERT_EQUALS(b[4], 14);
            TEST_ASSERT_EQUALS(b[5], 95);
            TEST_ASSERT_EQUALS(b[6], 13);
            TEST_ASSERT_EQUALS(b[7], 47);

            TEST_ASSERT_EQUALS(c[0], 65436);
            TEST_ASSERT_EQUALS(c[1], 65468);
            TEST_ASSERT_EQUALS(c[2], 65503);
            TEST_ASSERT_EQUALS(c[3], 65517);
            TEST_ASSERT_EQUALS(c[4], 18);
            TEST_ASSERT_EQUALS(c[5], 2);
            TEST_ASSERT_EQUALS(c[6], 11);
            TEST_ASSERT_EQUALS(c[7], 21);
        }
        else
        {
            UEFI_LVV(("X86Feature::XMM2 not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("psubd");
    {
        if (CPU::hasFlag(X86Feature::XMM2))
        {
            u32 a[4] = { 100, 30, 64, 13 };
            u32 b[4] = { 200, 98, 97, 32 };
            u32 c[4];

            testSse2Psubd(a, b, c);

            TEST_ASSERT_EQUALS(a[0], 100);
            TEST_ASSERT_EQUALS(a[1], 30);
            TEST_ASSERT_EQUALS(a[2], 64);
            TEST_ASSERT_EQUALS(a[3], 13);

            TEST_ASSERT_EQUALS(b[0], 200);
            TEST_ASSERT_EQUALS(b[1], 98);
            TEST_ASSERT_EQUALS(b[2], 97);
            TEST_ASSERT_EQUALS(b[3], 32);

            TEST_ASSERT_EQUALS(c[0], 4294967196);
            TEST_ASSERT_EQUALS(c[1], 4294967228);
            TEST_ASSERT_EQUALS(c[2], 4294967263);
            TEST_ASSERT_EQUALS(c[3], 4294967277);
        }
        else
        {
            UEFI_LVV(("X86Feature::XMM2 not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("psubq");
    {
        if (CPU::hasFlag(X86Feature::XMM2))
        {
            u64 a[2] = { 100, 30 };
            u64 b[2] = { 200, 98 };
            u64 c[2];

            testSse2Psubq(a, b, c);

            TEST_ASSERT_EQUALS(a[0], 100);
            TEST_ASSERT_EQUALS(a[1], 30);

            TEST_ASSERT_EQUALS(b[0], 200);
            TEST_ASSERT_EQUALS(b[1], 98);

            TEST_ASSERT_EQUALS(c[0], 0xFFFFFFFFFFFFFF9C);
            TEST_ASSERT_EQUALS(c[1], 0xFFFFFFFFFFFFFFBC);
        }
        else
        {
            UEFI_LVV(("X86Feature::XMM2 not supported"));
        }
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_FPU_SSE2_SSE2_H
