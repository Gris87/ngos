#ifndef CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___SHARED_COMMON_BITS64_FPU_AVX512DQ_AVX512DQ_H
#define CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___SHARED_COMMON_BITS64_FPU_AVX512DQ_AVX512DQ_H



#include <buildconfig.h>
#include <common/src/bits64/cpu/cpu.h>

#include "test/bits64/a_uefi/sections/section0/__shared/common/bits64/fpu/avx512dq/asm_testavx512dqvcvtpd2qq.h"
#include "test/bits64/a_uefi/sections/section0/__shared/common/bits64/fpu/avx512dq/asm_testavx512dqvcvtps2qq.h"
#include "test/bits64/a_uefi/sections/section0/__shared/common/bits64/fpu/avx512dq/asm_testavx512dqvcvtqq2pd.h"
#include "test/bits64/a_uefi/sections/section0/__shared/common/bits64/fpu/avx512dq/asm_testavx512dqvcvtqq2ps.h"
#include "test/bits64/a_uefi/sections/section0/__shared/common/bits64/fpu/avx512dq/asm_testavx512dqvpmullq.h"
#include "test/bits64/a_uefi/testengine.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_fpu_avx512dq_avx512dq);
{
    TEST_CASE("vcvtpd2qq");
    {
        if (CPU::hasFlag(X86Feature::AVX512DQ))
        {
            double a[8] = { 0.1, 0.9, 12378.4, 12389.6, 1234879.15, 1232134513216.9, 832198789.0, 321983217.98 };
            u64    b[8];

            testAvx512dqVcvtpd2qq(a, b);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(a[2], 12378.4);
            TEST_ASSERT_FLOAT_EQUALS(a[3], 12389.6);
            TEST_ASSERT_FLOAT_EQUALS(a[4], 1234879.15);
            TEST_ASSERT_FLOAT_EQUALS(a[5], 1232134513216.9);
            TEST_ASSERT_FLOAT_EQUALS(a[6], 832198789.0);
            TEST_ASSERT_FLOAT_EQUALS(a[7], 321983217.98);

            TEST_ASSERT_EQUALS(b[0], 0);
            TEST_ASSERT_EQUALS(b[1], 1);
            TEST_ASSERT_EQUALS(b[2], 12378);
            TEST_ASSERT_EQUALS(b[3], 12390);
            TEST_ASSERT_EQUALS(b[4], 1234879);
            TEST_ASSERT_EQUALS(b[5], 1232134513217);
            TEST_ASSERT_EQUALS(b[6], 832198789);
            TEST_ASSERT_EQUALS(b[7], 321983218);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512DQ not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vcvtps2qq");
    {
        if (CPU::hasFlag(X86Feature::AVX512DQ))
        {
            float a[16] = { 0.1, 0.9, 12378.4, 12389.6, 24879.15, 21216.9, 18789.0, 23217.98, 0, 0, 0, 0, 0, 0, 0, 0 };
            u64   b[8];

            testAvx512dqVcvtps2qq(a, b);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(a[2], 12378.4);
            TEST_ASSERT_FLOAT_EQUALS(a[3], 12389.6);
            TEST_ASSERT_FLOAT_EQUALS(a[4], 24879.15);
            TEST_ASSERT_FLOAT_EQUALS(a[5], 21216.9);
            TEST_ASSERT_FLOAT_EQUALS(a[6], 18789.0);
            TEST_ASSERT_FLOAT_EQUALS(a[7], 23217.98);

            TEST_ASSERT_EQUALS(b[0], 0);
            TEST_ASSERT_EQUALS(b[1], 1);
            TEST_ASSERT_EQUALS(b[2], 12378);
            TEST_ASSERT_EQUALS(b[3], 12390);
            TEST_ASSERT_EQUALS(b[4], 24879);
            TEST_ASSERT_EQUALS(b[5], 21217);
            TEST_ASSERT_EQUALS(b[6], 18789);
            TEST_ASSERT_EQUALS(b[7], 23218);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512DQ not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vcvtqq2pd");
    {
        if (CPU::hasFlag(X86Feature::AVX512DQ))
        {
            u64    a[8] = { 298321398, 798321398, 199873167, 632197312, 598798321, 413246489, 832198789, 321983217 };
            double b[8];

            testAvx512dqVcvtqq2pd(a, b);

            TEST_ASSERT_EQUALS(a[0], 298321398);
            TEST_ASSERT_EQUALS(a[1], 798321398);
            TEST_ASSERT_EQUALS(a[2], 199873167);
            TEST_ASSERT_EQUALS(a[3], 632197312);
            TEST_ASSERT_EQUALS(a[4], 598798321);
            TEST_ASSERT_EQUALS(a[5], 413246489);
            TEST_ASSERT_EQUALS(a[6], 832198789);
            TEST_ASSERT_EQUALS(a[7], 321983217);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 298321398.0);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 798321398.0);
            TEST_ASSERT_FLOAT_EQUALS(a[2], 199873167.0);
            TEST_ASSERT_FLOAT_EQUALS(a[3], 632197312.0);
            TEST_ASSERT_FLOAT_EQUALS(a[4], 598798321.0);
            TEST_ASSERT_FLOAT_EQUALS(a[5], 413246489.0);
            TEST_ASSERT_FLOAT_EQUALS(a[6], 832198789.0);
            TEST_ASSERT_FLOAT_EQUALS(a[7], 321983217.0);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512DQ not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vcvtqq2ps");
    {
        if (CPU::hasFlag(X86Feature::AVX512DQ))
        {
            u64   a[8] = { 298321398, 798321398, 199873167, 632197312, 598798321, 413246489, 832198789, 321983217 };
            float b[16];

            testAvx512dqVcvtqq2ps(a, b);

            TEST_ASSERT_EQUALS(a[0], 298321398);
            TEST_ASSERT_EQUALS(a[1], 798321398);
            TEST_ASSERT_EQUALS(a[2], 199873167);
            TEST_ASSERT_EQUALS(a[3], 632197312);
            TEST_ASSERT_EQUALS(a[4], 598798321);
            TEST_ASSERT_EQUALS(a[5], 413246489);
            TEST_ASSERT_EQUALS(a[6], 832198789);
            TEST_ASSERT_EQUALS(a[7], 321983217);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 298321398.0);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 798321398.0);
            TEST_ASSERT_FLOAT_EQUALS(a[2], 199873167.0);
            TEST_ASSERT_FLOAT_EQUALS(a[3], 632197312.0);
            TEST_ASSERT_FLOAT_EQUALS(a[4], 598798321.0);
            TEST_ASSERT_FLOAT_EQUALS(a[5], 413246489.0);
            TEST_ASSERT_FLOAT_EQUALS(a[6], 832198789.0);
            TEST_ASSERT_FLOAT_EQUALS(a[7], 321983217.0);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512DQ not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vpmullq");
    {
        if (CPU::hasFlag(X86Feature::AVX512DQ))
        {
            u64 a[8] = { 298321398, 798321398, 199873167, 632197312, 598798321, 413246489, 832198789, 321983217 };
            u64 b[8] = { 598798321, 413246489, 832198789, 321983217, 632197312, 199873167, 798321398, 298321398 };
            u64 c[8];

            testAvx512dqVpmullq(a, b, c);

            TEST_ASSERT_EQUALS(a[0], 298321398);
            TEST_ASSERT_EQUALS(a[1], 798321398);
            TEST_ASSERT_EQUALS(a[2], 199873167);
            TEST_ASSERT_EQUALS(a[3], 632197312);
            TEST_ASSERT_EQUALS(a[4], 598798321);
            TEST_ASSERT_EQUALS(a[5], 413246489);
            TEST_ASSERT_EQUALS(a[6], 832198789);
            TEST_ASSERT_EQUALS(a[7], 321983217);

            TEST_ASSERT_EQUALS(b[0], 598798321);
            TEST_ASSERT_EQUALS(b[1], 413246489);
            TEST_ASSERT_EQUALS(b[2], 832198789);
            TEST_ASSERT_EQUALS(b[3], 321983217);
            TEST_ASSERT_EQUALS(b[4], 632197312);
            TEST_ASSERT_EQUALS(b[5], 199873167);
            TEST_ASSERT_EQUALS(b[6], 798321398);
            TEST_ASSERT_EQUALS(b[7], 298321398);

            TEST_ASSERT_EQUALS(c[0], 178634352240772758);
            TEST_ASSERT_EQUALS(c[1], 329903514817071622);
            TEST_ASSERT_EQUALS(c[2], 166334207530994763);
            TEST_ASSERT_EQUALS(c[3], 203556924296512704);
            TEST_ASSERT_EQUALS(c[4], 378558688966313152);
            TEST_ASSERT_EQUALS(c[5], 82596884508060663);
            TEST_ASSERT_EQUALS(c[6], 664362100648387022);
            TEST_ASSERT_EQUALS(c[7], 96054483427977366);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512DQ not supported"));
        }
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___SHARED_COMMON_BITS64_FPU_AVX512DQ_AVX512DQ_H
