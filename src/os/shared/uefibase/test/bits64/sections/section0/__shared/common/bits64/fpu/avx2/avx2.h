#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_FPU_AVX2_AVX2_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_FPU_AVX2_AVX2_H



#include <buildconfig.h>
#include <common/src/bits64/cpu/cpu.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/fpu/avx2/asm_testavx2vphaddd.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/fpu/avx2/asm_testavx2vphaddw.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/fpu/avx2/asm_testavx2vphsubd.h>
#include <uefibase/test/bits64/sections/section0/__shared/common/bits64/fpu/avx2/asm_testavx2vphsubw.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_fpu_avx2_avx2);
{
    TEST_CASE("vphaddw");
    {
        if (CPU::hasFlag(X86Feature::AVX2))
        {
            u16 a[16] = { 10, 54, 34, 97, 31, 51, 33, 97, 19, 34, 27, 18, 74, 85, 36, 39 };
            u16 b[16] = { 91, 37, 21, 49, 37, 21, 37, 44, 67, 39, 26, 17, 34, 24, 86, 26 };
            u16 c[16];

            testAvx2Vphaddw(a, b, c);

            TEST_ASSERT_EQUALS(a[0],  10);
            TEST_ASSERT_EQUALS(a[1],  54);
            TEST_ASSERT_EQUALS(a[2],  34);
            TEST_ASSERT_EQUALS(a[3],  97);
            TEST_ASSERT_EQUALS(a[4],  31);
            TEST_ASSERT_EQUALS(a[5],  51);
            TEST_ASSERT_EQUALS(a[6],  33);
            TEST_ASSERT_EQUALS(a[7],  97);
            TEST_ASSERT_EQUALS(a[8],  19);
            TEST_ASSERT_EQUALS(a[9],  34);
            TEST_ASSERT_EQUALS(a[10], 27);
            TEST_ASSERT_EQUALS(a[11], 18);
            TEST_ASSERT_EQUALS(a[12], 74);
            TEST_ASSERT_EQUALS(a[13], 85);
            TEST_ASSERT_EQUALS(a[14], 36);
            TEST_ASSERT_EQUALS(a[15], 39);

            TEST_ASSERT_EQUALS(b[0],  91);
            TEST_ASSERT_EQUALS(b[1],  37);
            TEST_ASSERT_EQUALS(b[2],  21);
            TEST_ASSERT_EQUALS(b[3],  49);
            TEST_ASSERT_EQUALS(b[4],  37);
            TEST_ASSERT_EQUALS(b[5],  21);
            TEST_ASSERT_EQUALS(b[6],  37);
            TEST_ASSERT_EQUALS(b[7],  44);
            TEST_ASSERT_EQUALS(b[8],  67);
            TEST_ASSERT_EQUALS(b[9],  39);
            TEST_ASSERT_EQUALS(b[10], 26);
            TEST_ASSERT_EQUALS(b[11], 17);
            TEST_ASSERT_EQUALS(b[12], 34);
            TEST_ASSERT_EQUALS(b[13], 24);
            TEST_ASSERT_EQUALS(b[14], 86);
            TEST_ASSERT_EQUALS(b[15], 26);

            TEST_ASSERT_EQUALS(c[0],  64);
            TEST_ASSERT_EQUALS(c[1],  131);
            TEST_ASSERT_EQUALS(c[2],  82);
            TEST_ASSERT_EQUALS(c[3],  130);
            TEST_ASSERT_EQUALS(c[4],  128);
            TEST_ASSERT_EQUALS(c[5],  70);
            TEST_ASSERT_EQUALS(c[6],  58);
            TEST_ASSERT_EQUALS(c[7],  81);
            TEST_ASSERT_EQUALS(c[8],  53);
            TEST_ASSERT_EQUALS(c[9],  45);
            TEST_ASSERT_EQUALS(c[10], 159);
            TEST_ASSERT_EQUALS(c[11], 75);
            TEST_ASSERT_EQUALS(c[12], 106);
            TEST_ASSERT_EQUALS(c[13], 43);
            TEST_ASSERT_EQUALS(c[14], 58);
            TEST_ASSERT_EQUALS(c[15], 112);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX2 not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vphaddd");
    {
        if (CPU::hasFlag(X86Feature::AVX2))
        {
            u32 a[8] = { 10, 54, 34, 97, 31, 51, 33, 97 };
            u32 b[8] = { 91, 37, 21, 49, 37, 21, 37, 44 };
            u32 c[8];

            testAvx2Vphaddd(a, b, c);

            TEST_ASSERT_EQUALS(a[0], 10);
            TEST_ASSERT_EQUALS(a[1], 54);
            TEST_ASSERT_EQUALS(a[2], 34);
            TEST_ASSERT_EQUALS(a[3], 97);
            TEST_ASSERT_EQUALS(a[4], 31);
            TEST_ASSERT_EQUALS(a[5], 51);
            TEST_ASSERT_EQUALS(a[6], 33);
            TEST_ASSERT_EQUALS(a[7], 97);

            TEST_ASSERT_EQUALS(b[0], 91);
            TEST_ASSERT_EQUALS(b[1], 37);
            TEST_ASSERT_EQUALS(b[2], 21);
            TEST_ASSERT_EQUALS(b[3], 49);
            TEST_ASSERT_EQUALS(b[4], 37);
            TEST_ASSERT_EQUALS(b[5], 21);
            TEST_ASSERT_EQUALS(b[6], 37);
            TEST_ASSERT_EQUALS(b[7], 44);

            TEST_ASSERT_EQUALS(c[0], 64);
            TEST_ASSERT_EQUALS(c[1], 131);
            TEST_ASSERT_EQUALS(c[2], 128);
            TEST_ASSERT_EQUALS(c[3], 70);
            TEST_ASSERT_EQUALS(c[4], 82);
            TEST_ASSERT_EQUALS(c[5], 130);
            TEST_ASSERT_EQUALS(c[6], 58);
            TEST_ASSERT_EQUALS(c[7], 81);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX2 not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vphsubw");
    {
        if (CPU::hasFlag(X86Feature::AVX2))
        {
            u16 a[16] = { 10, 54, 34, 97, 31, 51, 33, 97, 19, 34, 27, 18, 74, 85, 36, 39 };
            u16 b[16] = { 91, 37, 21, 49, 37, 21, 37, 44, 67, 39, 26, 17, 34, 24, 86, 26 };
            u16 c[16];

            testAvx2Vphsubw(a, b, c);

            TEST_ASSERT_EQUALS(a[0],  10);
            TEST_ASSERT_EQUALS(a[1],  54);
            TEST_ASSERT_EQUALS(a[2],  34);
            TEST_ASSERT_EQUALS(a[3],  97);
            TEST_ASSERT_EQUALS(a[4],  31);
            TEST_ASSERT_EQUALS(a[5],  51);
            TEST_ASSERT_EQUALS(a[6],  33);
            TEST_ASSERT_EQUALS(a[7],  97);
            TEST_ASSERT_EQUALS(a[8],  19);
            TEST_ASSERT_EQUALS(a[9],  34);
            TEST_ASSERT_EQUALS(a[10], 27);
            TEST_ASSERT_EQUALS(a[11], 18);
            TEST_ASSERT_EQUALS(a[12], 74);
            TEST_ASSERT_EQUALS(a[13], 85);
            TEST_ASSERT_EQUALS(a[14], 36);
            TEST_ASSERT_EQUALS(a[15], 39);

            TEST_ASSERT_EQUALS(b[0],  91);
            TEST_ASSERT_EQUALS(b[1],  37);
            TEST_ASSERT_EQUALS(b[2],  21);
            TEST_ASSERT_EQUALS(b[3],  49);
            TEST_ASSERT_EQUALS(b[4],  37);
            TEST_ASSERT_EQUALS(b[5],  21);
            TEST_ASSERT_EQUALS(b[6],  37);
            TEST_ASSERT_EQUALS(b[7],  44);
            TEST_ASSERT_EQUALS(b[8],  67);
            TEST_ASSERT_EQUALS(b[9],  39);
            TEST_ASSERT_EQUALS(b[10], 26);
            TEST_ASSERT_EQUALS(b[11], 17);
            TEST_ASSERT_EQUALS(b[12], 34);
            TEST_ASSERT_EQUALS(b[13], 24);
            TEST_ASSERT_EQUALS(b[14], 86);
            TEST_ASSERT_EQUALS(b[15], 26);

            TEST_ASSERT_EQUALS(c[0],  65492);
            TEST_ASSERT_EQUALS(c[1],  65473);
            TEST_ASSERT_EQUALS(c[2],  65516);
            TEST_ASSERT_EQUALS(c[3],  65472);
            TEST_ASSERT_EQUALS(c[4],  54);
            TEST_ASSERT_EQUALS(c[5],  65508);
            TEST_ASSERT_EQUALS(c[6],  16);
            TEST_ASSERT_EQUALS(c[7],  65529);
            TEST_ASSERT_EQUALS(c[8],  65521);
            TEST_ASSERT_EQUALS(c[9],  9);
            TEST_ASSERT_EQUALS(c[10], 65525);
            TEST_ASSERT_EQUALS(c[11], 65533);
            TEST_ASSERT_EQUALS(c[12], 28);
            TEST_ASSERT_EQUALS(c[13], 9);
            TEST_ASSERT_EQUALS(c[14], 10);
            TEST_ASSERT_EQUALS(c[15], 60);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX2 not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vphsubd");
    {
        if (CPU::hasFlag(X86Feature::AVX2))
        {
            u32 a[8] = { 10, 54, 34, 97, 31, 51, 33, 97 };
            u32 b[8] = { 91, 37, 21, 49, 37, 21, 37, 44 };
            u32 c[8];

            testAvx2Vphsubd(a, b, c);

            TEST_ASSERT_EQUALS(a[0], 10);
            TEST_ASSERT_EQUALS(a[1], 54);
            TEST_ASSERT_EQUALS(a[2], 34);
            TEST_ASSERT_EQUALS(a[3], 97);
            TEST_ASSERT_EQUALS(a[4], 31);
            TEST_ASSERT_EQUALS(a[5], 51);
            TEST_ASSERT_EQUALS(a[6], 33);
            TEST_ASSERT_EQUALS(a[7], 97);

            TEST_ASSERT_EQUALS(b[0], 91);
            TEST_ASSERT_EQUALS(b[1], 37);
            TEST_ASSERT_EQUALS(b[2], 21);
            TEST_ASSERT_EQUALS(b[3], 49);
            TEST_ASSERT_EQUALS(b[4], 37);
            TEST_ASSERT_EQUALS(b[5], 21);
            TEST_ASSERT_EQUALS(b[6], 37);
            TEST_ASSERT_EQUALS(b[7], 44);

            TEST_ASSERT_EQUALS(c[0], 4294967252);
            TEST_ASSERT_EQUALS(c[1], 4294967233);
            TEST_ASSERT_EQUALS(c[2], 54);
            TEST_ASSERT_EQUALS(c[3], 4294967268);
            TEST_ASSERT_EQUALS(c[4], 4294967276);
            TEST_ASSERT_EQUALS(c[5], 4294967232);
            TEST_ASSERT_EQUALS(c[6], 16);
            TEST_ASSERT_EQUALS(c[7], 4294967289);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX2 not supported"));
        }
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_FPU_AVX2_AVX2_H