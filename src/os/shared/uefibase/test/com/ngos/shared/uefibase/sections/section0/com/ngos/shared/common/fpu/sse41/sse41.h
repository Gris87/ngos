#ifndef OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_SSE41_SSE41_H
#define OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_SSE41_SSE41_H



#include <buildconfig.h>
#include <com/ngos/shared/common/cpu/cpu.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/sse41/asm_testsse41pmaxsb.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/sse41/asm_testsse41pmaxsd.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/sse41/asm_testsse41pmaxud.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/sse41/asm_testsse41pmaxuw.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/sse41/asm_testsse41pminsb.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/sse41/asm_testsse41pminsd.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/sse41/asm_testsse41pminud.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/sse41/asm_testsse41pminuw.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/sse41/asm_testsse41pmuldq.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/sse41/asm_testsse41pmulld.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_fpu_sse41_sse41);
{
    TEST_CASE("pmulld");
    {
        if (CPU::hasFlag(X86Feature::XMM4_1))
        {
            i32 a[4] = { 1981965841, -1987077212, 2003838066, -2103715301 };
            i32 b[4] = { 1987132191, 1271329132, -1321971178, -1219321901 };
            i32 c[4];

            testSse41Pmulld(a, b, c);

            TEST_ASSERT_EQUALS(a[0], 1981965841);
            TEST_ASSERT_EQUALS(a[1], -1987077212);
            TEST_ASSERT_EQUALS(a[2], 2003838066);
            TEST_ASSERT_EQUALS(a[3], -2103715301);

            TEST_ASSERT_EQUALS(b[0], 1987132191);
            TEST_ASSERT_EQUALS(b[1], 1271329132);
            TEST_ASSERT_EQUALS(b[2], -1321971178);
            TEST_ASSERT_EQUALS(b[3], -1219321901);

            TEST_ASSERT_EQUALS(c[0], 523323151);
            TEST_ASSERT_EQUALS(c[1], -1494020816);
            TEST_ASSERT_EQUALS(c[2], 1752671692);
            TEST_ASSERT_EQUALS(c[3], -1668183743);
        }
        else
        {
            UEFI_LVV(("X86Feature::XMM4_1 not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("pmuldq");
    {
        if (CPU::hasFlag(X86Feature::XMM4_1))
        {
            i32 a[4] = { 1981965841, -1987077212, 2003838066, -2103715301 };
            i32 b[4] = { 1987132191, 1271329132, -1321971178, -1219321901 };
            i64 c[2];

            testSse41Pmuldq(a, b, c);

            TEST_ASSERT_EQUALS(a[0], 1981965841);
            TEST_ASSERT_EQUALS(a[1], -1987077212);
            TEST_ASSERT_EQUALS(a[2], 2003838066);
            TEST_ASSERT_EQUALS(a[3], -2103715301);

            TEST_ASSERT_EQUALS(b[0], 1987132191);
            TEST_ASSERT_EQUALS(b[1], 1271329132);
            TEST_ASSERT_EQUALS(b[2], -1321971178);
            TEST_ASSERT_EQUALS(b[3], -1219321901);

            TEST_ASSERT_EQUALS(c[0], 3938428124113487631);
            TEST_ASSERT_EQUALS(c[1], -2649016168631261748);
        }
        else
        {
            UEFI_LVV(("X86Feature::XMM4_1 not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("pminsb");
    {
        if (CPU::hasFlag(X86Feature::XMM4_1))
        {
            i8 a[16] = { 10, 64, 32, -46, -34, 97, -13, 64, 31, 97, -43, 37, 67, -24, 95, 32 };
            i8 b[16] = { 31, 13, 92, -16, -54, 27, -73, 34, 41, 87, -63, 27, 47, -94, 35, 62 };
            i8 c[16];

            testSse41Pminsb(a, b, c);

            TEST_ASSERT_EQUALS(a[0],  10);
            TEST_ASSERT_EQUALS(a[1],  64);
            TEST_ASSERT_EQUALS(a[2],  32);
            TEST_ASSERT_EQUALS(a[3],  -46);
            TEST_ASSERT_EQUALS(a[4],  -34);
            TEST_ASSERT_EQUALS(a[5],  97);
            TEST_ASSERT_EQUALS(a[6],  -13);
            TEST_ASSERT_EQUALS(a[7],  64);
            TEST_ASSERT_EQUALS(a[8],  31);
            TEST_ASSERT_EQUALS(a[9],  97);
            TEST_ASSERT_EQUALS(a[10], -43);
            TEST_ASSERT_EQUALS(a[11], 37);
            TEST_ASSERT_EQUALS(a[12], 67);
            TEST_ASSERT_EQUALS(a[13], -24);
            TEST_ASSERT_EQUALS(a[14], 95);
            TEST_ASSERT_EQUALS(a[15], 32);

            TEST_ASSERT_EQUALS(b[0],  31);
            TEST_ASSERT_EQUALS(b[1],  13);
            TEST_ASSERT_EQUALS(b[2],  92);
            TEST_ASSERT_EQUALS(b[3],  -16);
            TEST_ASSERT_EQUALS(b[4],  -54);
            TEST_ASSERT_EQUALS(b[5],  27);
            TEST_ASSERT_EQUALS(b[6],  -73);
            TEST_ASSERT_EQUALS(b[7],  34);
            TEST_ASSERT_EQUALS(b[8],  41);
            TEST_ASSERT_EQUALS(b[9],  87);
            TEST_ASSERT_EQUALS(b[10], -63);
            TEST_ASSERT_EQUALS(b[11], 27);
            TEST_ASSERT_EQUALS(b[12], 47);
            TEST_ASSERT_EQUALS(b[13], -94);
            TEST_ASSERT_EQUALS(b[14], 35);
            TEST_ASSERT_EQUALS(b[15], 62);

            TEST_ASSERT_EQUALS(c[0],  10);
            TEST_ASSERT_EQUALS(c[1],  13);
            TEST_ASSERT_EQUALS(c[2],  32);
            TEST_ASSERT_EQUALS(c[3],  -46);
            TEST_ASSERT_EQUALS(c[4],  -54);
            TEST_ASSERT_EQUALS(c[5],  27);
            TEST_ASSERT_EQUALS(c[6],  -73);
            TEST_ASSERT_EQUALS(c[7],  34);
            TEST_ASSERT_EQUALS(c[8],  31);
            TEST_ASSERT_EQUALS(c[9],  87);
            TEST_ASSERT_EQUALS(c[10], -63);
            TEST_ASSERT_EQUALS(c[11], 27);
            TEST_ASSERT_EQUALS(c[12], 47);
            TEST_ASSERT_EQUALS(c[13], -94);
            TEST_ASSERT_EQUALS(c[14], 35);
            TEST_ASSERT_EQUALS(c[15], 32);
        }
        else
        {
            UEFI_LVV(("X86Feature::XMM4_1 not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("pmaxsb");
    {
        if (CPU::hasFlag(X86Feature::XMM4_1))
        {
            i8 a[16] = { 10, 64, 32, -46, -34, 97, -13, 64, 31, 97, -43, 37, 67, -24, 95, 32 };
            i8 b[16] = { 31, 13, 92, -16, -54, 27, -73, 34, 41, 87, -63, 27, 47, -94, 35, 62 };
            i8 c[16];

            testSse41Pmaxsb(a, b, c);

            TEST_ASSERT_EQUALS(a[0],  10);
            TEST_ASSERT_EQUALS(a[1],  64);
            TEST_ASSERT_EQUALS(a[2],  32);
            TEST_ASSERT_EQUALS(a[3],  -46);
            TEST_ASSERT_EQUALS(a[4],  -34);
            TEST_ASSERT_EQUALS(a[5],  97);
            TEST_ASSERT_EQUALS(a[6],  -13);
            TEST_ASSERT_EQUALS(a[7],  64);
            TEST_ASSERT_EQUALS(a[8],  31);
            TEST_ASSERT_EQUALS(a[9],  97);
            TEST_ASSERT_EQUALS(a[10], -43);
            TEST_ASSERT_EQUALS(a[11], 37);
            TEST_ASSERT_EQUALS(a[12], 67);
            TEST_ASSERT_EQUALS(a[13], -24);
            TEST_ASSERT_EQUALS(a[14], 95);
            TEST_ASSERT_EQUALS(a[15], 32);

            TEST_ASSERT_EQUALS(b[0],  31);
            TEST_ASSERT_EQUALS(b[1],  13);
            TEST_ASSERT_EQUALS(b[2],  92);
            TEST_ASSERT_EQUALS(b[3],  -16);
            TEST_ASSERT_EQUALS(b[4],  -54);
            TEST_ASSERT_EQUALS(b[5],  27);
            TEST_ASSERT_EQUALS(b[6],  -73);
            TEST_ASSERT_EQUALS(b[7],  34);
            TEST_ASSERT_EQUALS(b[8],  41);
            TEST_ASSERT_EQUALS(b[9],  87);
            TEST_ASSERT_EQUALS(b[10], -63);
            TEST_ASSERT_EQUALS(b[11], 27);
            TEST_ASSERT_EQUALS(b[12], 47);
            TEST_ASSERT_EQUALS(b[13], -94);
            TEST_ASSERT_EQUALS(b[14], 35);
            TEST_ASSERT_EQUALS(b[15], 62);

            TEST_ASSERT_EQUALS(c[0],  31);
            TEST_ASSERT_EQUALS(c[1],  64);
            TEST_ASSERT_EQUALS(c[2],  92);
            TEST_ASSERT_EQUALS(c[3],  -16);
            TEST_ASSERT_EQUALS(c[4],  -34);
            TEST_ASSERT_EQUALS(c[5],  97);
            TEST_ASSERT_EQUALS(c[6],  -13);
            TEST_ASSERT_EQUALS(c[7],  64);
            TEST_ASSERT_EQUALS(c[8],  41);
            TEST_ASSERT_EQUALS(c[9],  97);
            TEST_ASSERT_EQUALS(c[10], -43);
            TEST_ASSERT_EQUALS(c[11], 37);
            TEST_ASSERT_EQUALS(c[12], 67);
            TEST_ASSERT_EQUALS(c[13], -24);
            TEST_ASSERT_EQUALS(c[14], 95);
            TEST_ASSERT_EQUALS(c[15], 62);
        }
        else
        {
            UEFI_LVV(("X86Feature::XMM4_1 not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("pminsd");
    {
        if (CPU::hasFlag(X86Feature::XMM4_1))
        {
            i32 a[4] = { 10, 64, 32, -46 };
            i32 b[4] = { 31, 13, 92, -16 };
            i32 c[4];

            testSse41Pminsd(a, b, c);

            TEST_ASSERT_EQUALS(a[0], 10);
            TEST_ASSERT_EQUALS(a[1], 64);
            TEST_ASSERT_EQUALS(a[2], 32);
            TEST_ASSERT_EQUALS(a[3], -46);

            TEST_ASSERT_EQUALS(b[0], 31);
            TEST_ASSERT_EQUALS(b[1], 13);
            TEST_ASSERT_EQUALS(b[2], 92);
            TEST_ASSERT_EQUALS(b[3], -16);

            TEST_ASSERT_EQUALS(c[0], 10);
            TEST_ASSERT_EQUALS(c[1], 13);
            TEST_ASSERT_EQUALS(c[2], 32);
            TEST_ASSERT_EQUALS(c[3], -46);
        }
        else
        {
            UEFI_LVV(("X86Feature::XMM4_1 not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("pmaxsd");
    {
        if (CPU::hasFlag(X86Feature::XMM4_1))
        {
            i32 a[4] = { 10, 64, 32, -46 };
            i32 b[4] = { 31, 13, 92, -16 };
            i32 c[4];

            testSse41Pmaxsd(a, b, c);

            TEST_ASSERT_EQUALS(a[0], 10);
            TEST_ASSERT_EQUALS(a[1], 64);
            TEST_ASSERT_EQUALS(a[2], 32);
            TEST_ASSERT_EQUALS(a[3], -46);

            TEST_ASSERT_EQUALS(b[0], 31);
            TEST_ASSERT_EQUALS(b[1], 13);
            TEST_ASSERT_EQUALS(b[2], 92);
            TEST_ASSERT_EQUALS(b[3], -16);

            TEST_ASSERT_EQUALS(c[0], 31);
            TEST_ASSERT_EQUALS(c[1], 64);
            TEST_ASSERT_EQUALS(c[2], 92);
            TEST_ASSERT_EQUALS(c[3], -16);
        }
        else
        {
            UEFI_LVV(("X86Feature::XMM4_1 not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("pminud");
    {
        if (CPU::hasFlag(X86Feature::XMM4_1))
        {
            u32 a[4] = { 10, 64, 32, 46 };
            u32 b[4] = { 31, 13, 92, 16 };
            u32 c[4];

            testSse41Pminud(a, b, c);

            TEST_ASSERT_EQUALS(a[0], 10);
            TEST_ASSERT_EQUALS(a[1], 64);
            TEST_ASSERT_EQUALS(a[2], 32);
            TEST_ASSERT_EQUALS(a[3], 46);

            TEST_ASSERT_EQUALS(b[0], 31);
            TEST_ASSERT_EQUALS(b[1], 13);
            TEST_ASSERT_EQUALS(b[2], 92);
            TEST_ASSERT_EQUALS(b[3], 16);

            TEST_ASSERT_EQUALS(c[0], 10);
            TEST_ASSERT_EQUALS(c[1], 13);
            TEST_ASSERT_EQUALS(c[2], 32);
            TEST_ASSERT_EQUALS(c[3], 16);
        }
        else
        {
            UEFI_LVV(("X86Feature::XMM4_1 not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("pmaxud");
    {
        if (CPU::hasFlag(X86Feature::XMM4_1))
        {
            u32 a[4] = { 10, 64, 32, 46 };
            u32 b[4] = { 31, 13, 92, 16 };
            u32 c[4];

            testSse41Pmaxud(a, b, c);

            TEST_ASSERT_EQUALS(a[0], 10);
            TEST_ASSERT_EQUALS(a[1], 64);
            TEST_ASSERT_EQUALS(a[2], 32);
            TEST_ASSERT_EQUALS(a[3], 46);

            TEST_ASSERT_EQUALS(b[0], 31);
            TEST_ASSERT_EQUALS(b[1], 13);
            TEST_ASSERT_EQUALS(b[2], 92);
            TEST_ASSERT_EQUALS(b[3], 16);

            TEST_ASSERT_EQUALS(c[0], 31);
            TEST_ASSERT_EQUALS(c[1], 64);
            TEST_ASSERT_EQUALS(c[2], 92);
            TEST_ASSERT_EQUALS(c[3], 46);
        }
        else
        {
            UEFI_LVV(("X86Feature::XMM4_1 not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("pminuw");
    {
        if (CPU::hasFlag(X86Feature::XMM4_1))
        {
            u16 a[8] = { 10, 64, 32, 46, 34, 32, 97, 21 };
            u16 b[8] = { 31, 13, 92, 16, 35, 97, 32, 26 };
            u16 c[8];

            testSse41Pminuw(a, b, c);

            TEST_ASSERT_EQUALS(a[0], 10);
            TEST_ASSERT_EQUALS(a[1], 64);
            TEST_ASSERT_EQUALS(a[2], 32);
            TEST_ASSERT_EQUALS(a[3], 46);
            TEST_ASSERT_EQUALS(a[4], 34);
            TEST_ASSERT_EQUALS(a[5], 32);
            TEST_ASSERT_EQUALS(a[6], 97);
            TEST_ASSERT_EQUALS(a[7], 21);

            TEST_ASSERT_EQUALS(b[0], 31);
            TEST_ASSERT_EQUALS(b[1], 13);
            TEST_ASSERT_EQUALS(b[2], 92);
            TEST_ASSERT_EQUALS(b[3], 16);
            TEST_ASSERT_EQUALS(b[4], 35);
            TEST_ASSERT_EQUALS(b[5], 97);
            TEST_ASSERT_EQUALS(b[6], 32);
            TEST_ASSERT_EQUALS(b[7], 26);

            TEST_ASSERT_EQUALS(c[0], 10);
            TEST_ASSERT_EQUALS(c[1], 13);
            TEST_ASSERT_EQUALS(c[2], 32);
            TEST_ASSERT_EQUALS(c[3], 16);
            TEST_ASSERT_EQUALS(c[4], 34);
            TEST_ASSERT_EQUALS(c[5], 32);
            TEST_ASSERT_EQUALS(c[6], 32);
            TEST_ASSERT_EQUALS(c[7], 21);
        }
        else
        {
            UEFI_LVV(("X86Feature::XMM4_1 not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("pmaxuw");
    {
        if (CPU::hasFlag(X86Feature::XMM4_1))
        {
            u16 a[8] = { 10, 64, 32, 46, 34, 32, 97, 21 };
            u16 b[8] = { 31, 13, 92, 16, 35, 97, 32, 26 };
            u16 c[8];

            testSse41Pmaxuw(a, b, c);

            TEST_ASSERT_EQUALS(a[0], 10);
            TEST_ASSERT_EQUALS(a[1], 64);
            TEST_ASSERT_EQUALS(a[2], 32);
            TEST_ASSERT_EQUALS(a[3], 46);
            TEST_ASSERT_EQUALS(a[4], 34);
            TEST_ASSERT_EQUALS(a[5], 32);
            TEST_ASSERT_EQUALS(a[6], 97);
            TEST_ASSERT_EQUALS(a[7], 21);

            TEST_ASSERT_EQUALS(b[0], 31);
            TEST_ASSERT_EQUALS(b[1], 13);
            TEST_ASSERT_EQUALS(b[2], 92);
            TEST_ASSERT_EQUALS(b[3], 16);
            TEST_ASSERT_EQUALS(b[4], 35);
            TEST_ASSERT_EQUALS(b[5], 97);
            TEST_ASSERT_EQUALS(b[6], 32);
            TEST_ASSERT_EQUALS(b[7], 26);

            TEST_ASSERT_EQUALS(c[0], 31);
            TEST_ASSERT_EQUALS(c[1], 64);
            TEST_ASSERT_EQUALS(c[2], 92);
            TEST_ASSERT_EQUALS(c[3], 46);
            TEST_ASSERT_EQUALS(c[4], 35);
            TEST_ASSERT_EQUALS(c[5], 97);
            TEST_ASSERT_EQUALS(c[6], 97);
            TEST_ASSERT_EQUALS(c[7], 26);
        }
        else
        {
            UEFI_LVV(("X86Feature::XMM4_1 not supported"));
        }
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_SSE41_SSE41_H
