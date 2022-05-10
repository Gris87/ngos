#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_AVX512VL_AVX512VL_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_AVX512VL_AVX512VL_H



#include <buildconfig.h>
#include <com/ngos/shared/common/cpu/cpu.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/avx512vl/asm_testavx512vlvaddps.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/avx512vl/asm_testavx512vlvdivps.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/avx512vl/asm_testavx512vlvmaxps.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/avx512vl/asm_testavx512vlvminps.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/avx512vl/asm_testavx512vlvmulps.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/avx512vl/asm_testavx512vlvrcp14ps.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/avx512vl/asm_testavx512vlvrsqrt14ps.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/avx512vl/asm_testavx512vlvsqrtps.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/avx512vl/asm_testavx512vlvsubps.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_fpu_avx512vl_avx512vl);
{
    TEST_CASE("vaddps");
    {
        if (CPU::hasFeature(X86Feature::AVX512VL))
        {
            float a[8] __attribute__((aligned(64))) = { 0.5, 0.4, 0.2, 0.1, 0.3, 0.7, 0.2, 0.1 };
            float b[8] __attribute__((aligned(64))) = { 0.8, 0.3, 0.8, 0.6, 0.9, 0.8, 0.7, 0.1 };
            float c[8] __attribute__((aligned(64)));

            testAvx512vlVaddps(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.4);
            TEST_ASSERT_FLOAT_EQUALS(a[2], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[3], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[4], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[5], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[6], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[7], 0.1);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(b[2], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[3], 0.6);
            TEST_ASSERT_FLOAT_EQUALS(b[4], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(b[5], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[6], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(b[7], 0.1);

            TEST_ASSERT_FLOAT_EQUALS(c[0], 1.3);
            TEST_ASSERT_FLOAT_EQUALS(c[1], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(c[2], 1.0);
            TEST_ASSERT_FLOAT_EQUALS(c[3], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(c[4], 1.2);
            TEST_ASSERT_FLOAT_EQUALS(c[5], 1.5);
            TEST_ASSERT_FLOAT_EQUALS(c[6], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(c[7], 0.2);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512VL not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vsubps");
    {
        if (CPU::hasFeature(X86Feature::AVX512VL))
        {
            float a[8] __attribute__((aligned(64))) = { 0.5, 0.4, 0.2, 0.1, 0.3, 0.7, 0.2, 0.1 };
            float b[8] __attribute__((aligned(64))) = { 0.8, 0.3, 0.8, 0.6, 0.9, 0.8, 0.7, 0.1 };
            float c[8] __attribute__((aligned(64)));

            testAvx512vlVsubps(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.4);
            TEST_ASSERT_FLOAT_EQUALS(a[2], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[3], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[4], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[5], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[6], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[7], 0.1);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(b[2], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[3], 0.6);
            TEST_ASSERT_FLOAT_EQUALS(b[4], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(b[5], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[6], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(b[7], 0.1);

            TEST_ASSERT_FLOAT_EQUALS(c[0], -0.3);
            TEST_ASSERT_FLOAT_EQUALS(c[1], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(c[2], -0.6);
            TEST_ASSERT_FLOAT_EQUALS(c[3], -0.5);
            TEST_ASSERT_FLOAT_EQUALS(c[4], -0.6);
            TEST_ASSERT_FLOAT_EQUALS(c[5], -0.1);
            TEST_ASSERT_FLOAT_EQUALS(c[6], -0.5);
            TEST_ASSERT_FLOAT_EQUALS(c[7], 0.0);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512VL not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vmulps");
    {
        if (CPU::hasFeature(X86Feature::AVX512VL))
        {
            float a[8] __attribute__((aligned(64))) = { 0.5, 0.4, 0.2, 0.1, 0.3, 0.7, 0.2, 0.1 };
            float b[8] __attribute__((aligned(64))) = { 0.8, 0.3, 0.8, 0.6, 0.9, 0.8, 0.7, 0.1 };
            float c[8] __attribute__((aligned(64)));

            testAvx512vlVmulps(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.4);
            TEST_ASSERT_FLOAT_EQUALS(a[2], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[3], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[4], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[5], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[6], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[7], 0.1);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(b[2], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[3], 0.6);
            TEST_ASSERT_FLOAT_EQUALS(b[4], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(b[5], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[6], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(b[7], 0.1);

            TEST_ASSERT_FLOAT_EQUALS(c[0], 0.4);
            TEST_ASSERT_FLOAT_EQUALS(c[1], 0.12);
            TEST_ASSERT_FLOAT_EQUALS(c[2], 0.16);
            TEST_ASSERT_FLOAT_EQUALS(c[3], 0.06);
            TEST_ASSERT_FLOAT_EQUALS(c[4], 0.27);
            TEST_ASSERT_FLOAT_EQUALS(c[5], 0.56);
            TEST_ASSERT_FLOAT_EQUALS(c[6], 0.14);
            TEST_ASSERT_FLOAT_EQUALS(c[7], 0.01);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512VL not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vdivps");
    {
        if (CPU::hasFeature(X86Feature::AVX512VL))
        {
            float a[8] __attribute__((aligned(64))) = { 0.5, 0.4, 0.2, 0.1, 0.3, 0.7, 0.2, 0.1 };
            float b[8] __attribute__((aligned(64))) = { 0.8, 0.3, 0.8, 0.6, 0.9, 0.8, 0.7, 0.1 };
            float c[8] __attribute__((aligned(64)));

            testAvx512vlVdivps(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.4);
            TEST_ASSERT_FLOAT_EQUALS(a[2], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[3], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[4], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[5], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[6], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[7], 0.1);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(b[2], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[3], 0.6);
            TEST_ASSERT_FLOAT_EQUALS(b[4], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(b[5], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[6], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(b[7], 0.1);

            TEST_ASSERT_FLOAT_EQUALS(c[0], 0.625);
            TEST_ASSERT_FLOAT_EQUALS(c[1], 1.333);
            TEST_ASSERT_FLOAT_EQUALS(c[2], 0.25);
            TEST_ASSERT_FLOAT_EQUALS(c[3], 0.166);
            TEST_ASSERT_FLOAT_EQUALS(c[4], 0.333);
            TEST_ASSERT_FLOAT_EQUALS(c[5], 0.875);
            TEST_ASSERT_FLOAT_EQUALS(c[6], 0.285);
            TEST_ASSERT_FLOAT_EQUALS(c[7], 1.0);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512VL not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vsqrtps");
    {
        if (CPU::hasFeature(X86Feature::AVX512VL))
        {
            float a[8] __attribute__((aligned(64))) = { 1.0, 4.0, 9.0, 2.25, 0.3, 0.7, 0.2, 0.1 };
            float b[8] __attribute__((aligned(64)));

            testAvx512vlVsqrtps(a, b);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 1.0);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 4.0);
            TEST_ASSERT_FLOAT_EQUALS(a[2], 9.0);
            TEST_ASSERT_FLOAT_EQUALS(a[3], 2.25);
            TEST_ASSERT_FLOAT_EQUALS(a[4], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[5], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[6], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[7], 0.1);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 1.0);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 2.0);
            TEST_ASSERT_FLOAT_EQUALS(b[2], 3.0);
            TEST_ASSERT_FLOAT_EQUALS(b[3], 1.5);
            TEST_ASSERT_FLOAT_EQUALS(b[4], 0.547);
            TEST_ASSERT_FLOAT_EQUALS(b[5], 0.836);
            TEST_ASSERT_FLOAT_EQUALS(b[6], 0.447);
            TEST_ASSERT_FLOAT_EQUALS(b[7], 0.316);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512VL not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vrcp14ps");
    {
        if (CPU::hasFeature(X86Feature::AVX512VL))
        {
            float a[8] __attribute__((aligned(64))) = { 0.5, 0.4, 0.2, 0.1, 0.3, 0.7, 0.2, 0.1 };
            float b[8] __attribute__((aligned(64)));

            testAvx512vlVrcp14ps(a, b);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.4);
            TEST_ASSERT_FLOAT_EQUALS(a[2], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[3], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[4], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[5], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[6], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[7], 0.1);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 2.0);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 2.5);
            TEST_ASSERT_FLOAT_EQUALS(b[2], 5.0);
            TEST_ASSERT_FLOAT_EQUALS(b[3], 10.0);
            TEST_ASSERT_FLOAT_EQUALS(b[4], 3.333);
            TEST_ASSERT_FLOAT_EQUALS(b[5], 1.428);
            TEST_ASSERT_FLOAT_EQUALS(b[6], 5.0);
            TEST_ASSERT_FLOAT_EQUALS(b[7], 10.0);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512VL not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vrsqrt14ps");
    {
        if (CPU::hasFeature(X86Feature::AVX512VL))
        {
            float a[8] __attribute__((aligned(64))) = { 1.0, 4.0, 9.0, 2.25, 0.3, 0.7, 0.2, 0.1 };
            float b[8] __attribute__((aligned(64)));

            testAvx512vlVrsqrt14ps(a, b);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 1.0);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 4.0);
            TEST_ASSERT_FLOAT_EQUALS(a[2], 9.0);
            TEST_ASSERT_FLOAT_EQUALS(a[3], 2.25);
            TEST_ASSERT_FLOAT_EQUALS(a[4], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[5], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[6], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[7], 0.1);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 1.0);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(b[2], 0.333);
            TEST_ASSERT_FLOAT_EQUALS(b[3], 0.666);
            TEST_ASSERT_FLOAT_EQUALS(b[4], 1.825);
            TEST_ASSERT_FLOAT_EQUALS(b[5], 1.195);
            TEST_ASSERT_FLOAT_EQUALS(b[6], 2.236);
            TEST_ASSERT_FLOAT_EQUALS(b[7], 3.162);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512VL not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vmaxps");
    {
        if (CPU::hasFeature(X86Feature::AVX512VL))
        {
            float a[8] __attribute__((aligned(64))) = { 0.5, 0.4, 0.2, 0.1, 0.3, 0.7, 0.2, 0.1 };
            float b[8] __attribute__((aligned(64))) = { 0.8, 0.3, 0.8, 0.6, 0.9, 0.8, 0.7, 0.1 };
            float c[8] __attribute__((aligned(64)));

            testAvx512vlVmaxps(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.4);
            TEST_ASSERT_FLOAT_EQUALS(a[2], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[3], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[4], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[5], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[6], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[7], 0.1);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(b[2], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[3], 0.6);
            TEST_ASSERT_FLOAT_EQUALS(b[4], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(b[5], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[6], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(b[7], 0.1);

            TEST_ASSERT_FLOAT_EQUALS(c[0], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(c[1], 0.4);
            TEST_ASSERT_FLOAT_EQUALS(c[2], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(c[3], 0.6);
            TEST_ASSERT_FLOAT_EQUALS(c[4], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(c[5], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(c[6], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(c[7], 0.1);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512VL not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vminps");
    {
        if (CPU::hasFeature(X86Feature::AVX512VL))
        {
            float a[8] __attribute__((aligned(64))) = { 0.5, 0.4, 0.2, 0.1, 0.3, 0.7, 0.2, 0.1 };
            float b[8] __attribute__((aligned(64))) = { 0.8, 0.3, 0.8, 0.6, 0.9, 0.8, 0.7, 0.1 };
            float c[8] __attribute__((aligned(64)));

            testAvx512vlVminps(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.4);
            TEST_ASSERT_FLOAT_EQUALS(a[2], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[3], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[4], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[5], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[6], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[7], 0.1);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(b[2], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[3], 0.6);
            TEST_ASSERT_FLOAT_EQUALS(b[4], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(b[5], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[6], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(b[7], 0.1);

            TEST_ASSERT_FLOAT_EQUALS(c[0], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(c[1], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(c[2], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(c[3], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(c[4], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(c[5], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(c[6], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(c[7], 0.1);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512VL not supported"));
        }
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_AVX512VL_AVX512VL_H
