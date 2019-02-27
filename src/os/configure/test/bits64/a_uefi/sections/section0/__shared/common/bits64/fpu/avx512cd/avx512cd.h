#ifndef CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___SHARED_COMMON_BITS64_FPU_AVX512CD_AVX512CD_H
#define CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___SHARED_COMMON_BITS64_FPU_AVX512CD_AVX512CD_H



#include <buildconfig.h>
#include <common/src/bits64/cpu/cpu.h>

#include "test/bits64/a_uefi/sections/section0/__shared/common/bits64/fpu/avx512cd/asm_testavx512cdvpbroadcastmb2q.h"
#include "test/bits64/a_uefi/sections/section0/__shared/common/bits64/fpu/avx512cd/asm_testavx512cdvpbroadcastmw2d.h"
#include "test/bits64/a_uefi/sections/section0/__shared/common/bits64/fpu/avx512cd/asm_testavx512cdvplzcntd.h"
#include "test/bits64/a_uefi/sections/section0/__shared/common/bits64/fpu/avx512cd/asm_testavx512cdvplzcntq.h"
#include "test/bits64/a_uefi/testengine.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_fpu_avx512cd_avx512cd);
{
    TEST_CASE("vpbroadcastmb2q");
    {
        if (CPU::hasFlag(X86Feature::AVX512CD))
        {
            u64 a[8];

            testAvx512cdVpbroadcastmb2q(a, 100);

            TEST_ASSERT_EQUALS(a[0], 100);
            TEST_ASSERT_EQUALS(a[1], 100);
            TEST_ASSERT_EQUALS(a[2], 100);
            TEST_ASSERT_EQUALS(a[3], 100);
            TEST_ASSERT_EQUALS(a[4], 100);
            TEST_ASSERT_EQUALS(a[5], 100);
            TEST_ASSERT_EQUALS(a[6], 100);
            TEST_ASSERT_EQUALS(a[7], 100);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512CD not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vpbroadcastmw2d");
    {
        if (CPU::hasFlag(X86Feature::AVX512CD))
        {
            u32 a[16];

            testAvx512cdVpbroadcastmw2d(a, 1000);

            TEST_ASSERT_EQUALS(a[0],  1000);
            TEST_ASSERT_EQUALS(a[1],  1000);
            TEST_ASSERT_EQUALS(a[2],  1000);
            TEST_ASSERT_EQUALS(a[3],  1000);
            TEST_ASSERT_EQUALS(a[4],  1000);
            TEST_ASSERT_EQUALS(a[5],  1000);
            TEST_ASSERT_EQUALS(a[6],  1000);
            TEST_ASSERT_EQUALS(a[7],  1000);
            TEST_ASSERT_EQUALS(a[8],  1000);
            TEST_ASSERT_EQUALS(a[9],  1000);
            TEST_ASSERT_EQUALS(a[10], 1000);
            TEST_ASSERT_EQUALS(a[11], 1000);
            TEST_ASSERT_EQUALS(a[12], 1000);
            TEST_ASSERT_EQUALS(a[13], 1000);
            TEST_ASSERT_EQUALS(a[14], 1000);
            TEST_ASSERT_EQUALS(a[15], 1000);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512CD not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vplzcntd");
    {
        if (CPU::hasFlag(X86Feature::AVX512CD))
        {
            u32 a[16] = { 910, 154, 434, 397, 231, 151, 533, 697, 1109, 3234, 1227, 138, 704, 8485, 13636, 312019 };
            u32 b[16];

            testAvx512cdVplzcntd(a, b);

            TEST_ASSERT_EQUALS(a[0],  910);
            TEST_ASSERT_EQUALS(a[1],  154);
            TEST_ASSERT_EQUALS(a[2],  434);
            TEST_ASSERT_EQUALS(a[3],  397);
            TEST_ASSERT_EQUALS(a[4],  231);
            TEST_ASSERT_EQUALS(a[5],  151);
            TEST_ASSERT_EQUALS(a[6],  533);
            TEST_ASSERT_EQUALS(a[7],  697);
            TEST_ASSERT_EQUALS(a[8],  1109);
            TEST_ASSERT_EQUALS(a[9],  3234);
            TEST_ASSERT_EQUALS(a[10], 1227);
            TEST_ASSERT_EQUALS(a[11], 138);
            TEST_ASSERT_EQUALS(a[12], 704);
            TEST_ASSERT_EQUALS(a[13], 8485);
            TEST_ASSERT_EQUALS(a[14], 13636);
            TEST_ASSERT_EQUALS(a[15], 312019);

            TEST_ASSERT_EQUALS(b[0],  22);
            TEST_ASSERT_EQUALS(b[1],  24);
            TEST_ASSERT_EQUALS(b[2],  23);
            TEST_ASSERT_EQUALS(b[3],  23);
            TEST_ASSERT_EQUALS(b[4],  24);
            TEST_ASSERT_EQUALS(b[5],  24);
            TEST_ASSERT_EQUALS(b[6],  22);
            TEST_ASSERT_EQUALS(b[7],  22);
            TEST_ASSERT_EQUALS(b[8],  21);
            TEST_ASSERT_EQUALS(b[9],  20);
            TEST_ASSERT_EQUALS(b[10], 21);
            TEST_ASSERT_EQUALS(b[11], 24);
            TEST_ASSERT_EQUALS(b[12], 22);
            TEST_ASSERT_EQUALS(b[13], 18);
            TEST_ASSERT_EQUALS(b[14], 18);
            TEST_ASSERT_EQUALS(b[15], 13);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512CD not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vplzcntq");
    {
        if (CPU::hasFlag(X86Feature::AVX512CD))
        {
            u64 a[8] = { 910, 154, 434, 397, 231, 151, 533, 697 };
            u64 b[8];

            testAvx512cdVplzcntq(a, b);

            TEST_ASSERT_EQUALS(a[0], 910);
            TEST_ASSERT_EQUALS(a[1], 154);
            TEST_ASSERT_EQUALS(a[2], 434);
            TEST_ASSERT_EQUALS(a[3], 397);
            TEST_ASSERT_EQUALS(a[4], 231);
            TEST_ASSERT_EQUALS(a[5], 151);
            TEST_ASSERT_EQUALS(a[6], 533);
            TEST_ASSERT_EQUALS(a[7], 697);

            TEST_ASSERT_EQUALS(b[0], 54);
            TEST_ASSERT_EQUALS(b[1], 56);
            TEST_ASSERT_EQUALS(b[2], 55);
            TEST_ASSERT_EQUALS(b[3], 55);
            TEST_ASSERT_EQUALS(b[4], 56);
            TEST_ASSERT_EQUALS(b[5], 56);
            TEST_ASSERT_EQUALS(b[6], 54);
            TEST_ASSERT_EQUALS(b[7], 54);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512CD not supported"));
        }
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___SHARED_COMMON_BITS64_FPU_AVX512CD_AVX512CD_H
