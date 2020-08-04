#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_AVX512F_AVX512F_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_AVX512F_AVX512F_H



#include <buildconfig.h>
#include <com/ngos/shared/common/cpu/cpu.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/avx512f/asm_testavx512fvaddps.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/avx512f/asm_testavx512fvdivps.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/avx512f/asm_testavx512fvmaxps.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/avx512f/asm_testavx512fvminps.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/avx512f/asm_testavx512fvmulps.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/avx512f/asm_testavx512fvrcp14ps.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/avx512f/asm_testavx512fvrsqrt14ps.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/avx512f/asm_testavx512fvsqrtps.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/avx512f/asm_testavx512fvsubps.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_fpu_avx512f_avx512f);
{
    TEST_CASE("vaddps");
    {
        if (CPU::hasFlag(X86Feature::AVX512F))
        {
            float a[16] __attribute__((aligned(64))) = { 0.5, 0.4, 0.2, 0.1, 0.3, 0.7, 0.2, 0.1, 0.9, 0.4, 0.5, 0.7, 0.1, 0.3, 0.9, 0.3 };
            float b[16] __attribute__((aligned(64))) = { 0.8, 0.3, 0.8, 0.6, 0.9, 0.8, 0.7, 0.1, 0.6, 0.9, 0.4, 0.3, 0.7, 0.2, 0.8, 0.7 };
            float c[16] __attribute__((aligned(64)));

            testAvx512fVaddps(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0],  0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[1],  0.4);
            TEST_ASSERT_FLOAT_EQUALS(a[2],  0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[3],  0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[4],  0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[5],  0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[6],  0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[7],  0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[8],  0.9);
            TEST_ASSERT_FLOAT_EQUALS(a[9],  0.4);
            TEST_ASSERT_FLOAT_EQUALS(a[10], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[11], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[12], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[13], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[14], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(a[15], 0.3);

            TEST_ASSERT_FLOAT_EQUALS(b[0],  0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[1],  0.3);
            TEST_ASSERT_FLOAT_EQUALS(b[2],  0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[3],  0.6);
            TEST_ASSERT_FLOAT_EQUALS(b[4],  0.9);
            TEST_ASSERT_FLOAT_EQUALS(b[5],  0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[6],  0.7);
            TEST_ASSERT_FLOAT_EQUALS(b[7],  0.1);
            TEST_ASSERT_FLOAT_EQUALS(b[8],  0.6);
            TEST_ASSERT_FLOAT_EQUALS(b[9],  0.9);
            TEST_ASSERT_FLOAT_EQUALS(b[10], 0.4);
            TEST_ASSERT_FLOAT_EQUALS(b[11], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(b[12], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(b[13], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(b[14], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[15], 0.7);

            TEST_ASSERT_FLOAT_EQUALS(c[0],  1.3);
            TEST_ASSERT_FLOAT_EQUALS(c[1],  0.7);
            TEST_ASSERT_FLOAT_EQUALS(c[2],  1.0);
            TEST_ASSERT_FLOAT_EQUALS(c[3],  0.7);
            TEST_ASSERT_FLOAT_EQUALS(c[4],  1.2);
            TEST_ASSERT_FLOAT_EQUALS(c[5],  1.5);
            TEST_ASSERT_FLOAT_EQUALS(c[6],  0.9);
            TEST_ASSERT_FLOAT_EQUALS(c[7],  0.2);
            TEST_ASSERT_FLOAT_EQUALS(c[8],  1.5);
            TEST_ASSERT_FLOAT_EQUALS(c[9],  1.3);
            TEST_ASSERT_FLOAT_EQUALS(c[10], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(c[11], 1.0);
            TEST_ASSERT_FLOAT_EQUALS(c[12], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(c[13], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(c[14], 1.7);
            TEST_ASSERT_FLOAT_EQUALS(c[15], 1.0);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512F not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vsubps");
    {
        if (CPU::hasFlag(X86Feature::AVX512F))
        {
            float a[16] __attribute__((aligned(64))) = { 0.5, 0.4, 0.2, 0.1, 0.3, 0.7, 0.2, 0.1, 0.9, 0.4, 0.5, 0.7, 0.1, 0.3, 0.9, 0.3 };
            float b[16] __attribute__((aligned(64))) = { 0.8, 0.3, 0.8, 0.6, 0.9, 0.8, 0.7, 0.1, 0.6, 0.9, 0.4, 0.3, 0.7, 0.2, 0.8, 0.7 };
            float c[16] __attribute__((aligned(64)));

            testAvx512fVsubps(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0],  0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[1],  0.4);
            TEST_ASSERT_FLOAT_EQUALS(a[2],  0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[3],  0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[4],  0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[5],  0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[6],  0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[7],  0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[8],  0.9);
            TEST_ASSERT_FLOAT_EQUALS(a[9],  0.4);
            TEST_ASSERT_FLOAT_EQUALS(a[10], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[11], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[12], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[13], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[14], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(a[15], 0.3);

            TEST_ASSERT_FLOAT_EQUALS(b[0],  0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[1],  0.3);
            TEST_ASSERT_FLOAT_EQUALS(b[2],  0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[3],  0.6);
            TEST_ASSERT_FLOAT_EQUALS(b[4],  0.9);
            TEST_ASSERT_FLOAT_EQUALS(b[5],  0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[6],  0.7);
            TEST_ASSERT_FLOAT_EQUALS(b[7],  0.1);
            TEST_ASSERT_FLOAT_EQUALS(b[8],  0.6);
            TEST_ASSERT_FLOAT_EQUALS(b[9],  0.9);
            TEST_ASSERT_FLOAT_EQUALS(b[10], 0.4);
            TEST_ASSERT_FLOAT_EQUALS(b[11], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(b[12], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(b[13], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(b[14], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[15], 0.7);

            TEST_ASSERT_FLOAT_EQUALS(c[0],  -0.3);
            TEST_ASSERT_FLOAT_EQUALS(c[1],  0.1);
            TEST_ASSERT_FLOAT_EQUALS(c[2],  -0.6);
            TEST_ASSERT_FLOAT_EQUALS(c[3],  -0.5);
            TEST_ASSERT_FLOAT_EQUALS(c[4],  -0.6);
            TEST_ASSERT_FLOAT_EQUALS(c[5],  -0.1);
            TEST_ASSERT_FLOAT_EQUALS(c[6],  -0.5);
            TEST_ASSERT_FLOAT_EQUALS(c[7],  0.0);
            TEST_ASSERT_FLOAT_EQUALS(c[8],  0.3);
            TEST_ASSERT_FLOAT_EQUALS(c[9],  -0.5);
            TEST_ASSERT_FLOAT_EQUALS(c[10], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(c[11], 0.4);
            TEST_ASSERT_FLOAT_EQUALS(c[12], -0.6);
            TEST_ASSERT_FLOAT_EQUALS(c[13], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(c[14], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(c[15], -0.4);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512F not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vmulps");
    {
        if (CPU::hasFlag(X86Feature::AVX512F))
        {
            float a[16] __attribute__((aligned(64))) = { 0.5, 0.4, 0.2, 0.1, 0.3, 0.7, 0.2, 0.1, 0.9, 0.4, 0.5, 0.7, 0.1, 0.3, 0.9, 0.3 };
            float b[16] __attribute__((aligned(64))) = { 0.8, 0.3, 0.8, 0.6, 0.9, 0.8, 0.7, 0.1, 0.6, 0.9, 0.4, 0.3, 0.7, 0.2, 0.8, 0.7 };
            float c[16] __attribute__((aligned(64)));

            testAvx512fVmulps(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0],  0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[1],  0.4);
            TEST_ASSERT_FLOAT_EQUALS(a[2],  0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[3],  0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[4],  0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[5],  0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[6],  0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[7],  0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[8],  0.9);
            TEST_ASSERT_FLOAT_EQUALS(a[9],  0.4);
            TEST_ASSERT_FLOAT_EQUALS(a[10], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[11], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[12], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[13], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[14], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(a[15], 0.3);

            TEST_ASSERT_FLOAT_EQUALS(b[0],  0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[1],  0.3);
            TEST_ASSERT_FLOAT_EQUALS(b[2],  0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[3],  0.6);
            TEST_ASSERT_FLOAT_EQUALS(b[4],  0.9);
            TEST_ASSERT_FLOAT_EQUALS(b[5],  0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[6],  0.7);
            TEST_ASSERT_FLOAT_EQUALS(b[7],  0.1);
            TEST_ASSERT_FLOAT_EQUALS(b[8],  0.6);
            TEST_ASSERT_FLOAT_EQUALS(b[9],  0.9);
            TEST_ASSERT_FLOAT_EQUALS(b[10], 0.4);
            TEST_ASSERT_FLOAT_EQUALS(b[11], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(b[12], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(b[13], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(b[14], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[15], 0.7);

            TEST_ASSERT_FLOAT_EQUALS(c[0],  0.4);
            TEST_ASSERT_FLOAT_EQUALS(c[1],  0.12);
            TEST_ASSERT_FLOAT_EQUALS(c[2],  0.16);
            TEST_ASSERT_FLOAT_EQUALS(c[3],  0.06);
            TEST_ASSERT_FLOAT_EQUALS(c[4],  0.27);
            TEST_ASSERT_FLOAT_EQUALS(c[5],  0.56);
            TEST_ASSERT_FLOAT_EQUALS(c[6],  0.14);
            TEST_ASSERT_FLOAT_EQUALS(c[7],  0.01);
            TEST_ASSERT_FLOAT_EQUALS(c[8],  0.54);
            TEST_ASSERT_FLOAT_EQUALS(c[9],  0.36);
            TEST_ASSERT_FLOAT_EQUALS(c[10], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(c[11], 0.21);
            TEST_ASSERT_FLOAT_EQUALS(c[12], 0.07);
            TEST_ASSERT_FLOAT_EQUALS(c[13], 0.06);
            TEST_ASSERT_FLOAT_EQUALS(c[14], 0.72);
            TEST_ASSERT_FLOAT_EQUALS(c[15], 0.21);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512F not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vdivps");
    {
        if (CPU::hasFlag(X86Feature::AVX512F))
        {
            float a[16] __attribute__((aligned(64))) = { 0.5, 0.4, 0.2, 0.1, 0.3, 0.7, 0.2, 0.1, 0.9, 0.4, 0.5, 0.7, 0.1, 0.3, 0.9, 0.3 };
            float b[16] __attribute__((aligned(64))) = { 0.8, 0.3, 0.8, 0.6, 0.9, 0.8, 0.7, 0.1, 0.6, 0.9, 0.4, 0.3, 0.7, 0.2, 0.8, 0.7 };
            float c[16] __attribute__((aligned(64)));

            testAvx512fVdivps(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0],  0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[1],  0.4);
            TEST_ASSERT_FLOAT_EQUALS(a[2],  0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[3],  0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[4],  0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[5],  0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[6],  0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[7],  0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[8],  0.9);
            TEST_ASSERT_FLOAT_EQUALS(a[9],  0.4);
            TEST_ASSERT_FLOAT_EQUALS(a[10], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[11], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[12], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[13], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[14], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(a[15], 0.3);

            TEST_ASSERT_FLOAT_EQUALS(b[0],  0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[1],  0.3);
            TEST_ASSERT_FLOAT_EQUALS(b[2],  0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[3],  0.6);
            TEST_ASSERT_FLOAT_EQUALS(b[4],  0.9);
            TEST_ASSERT_FLOAT_EQUALS(b[5],  0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[6],  0.7);
            TEST_ASSERT_FLOAT_EQUALS(b[7],  0.1);
            TEST_ASSERT_FLOAT_EQUALS(b[8],  0.6);
            TEST_ASSERT_FLOAT_EQUALS(b[9],  0.9);
            TEST_ASSERT_FLOAT_EQUALS(b[10], 0.4);
            TEST_ASSERT_FLOAT_EQUALS(b[11], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(b[12], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(b[13], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(b[14], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[15], 0.7);

            TEST_ASSERT_FLOAT_EQUALS(c[0],  0.625);
            TEST_ASSERT_FLOAT_EQUALS(c[1],  1.333);
            TEST_ASSERT_FLOAT_EQUALS(c[2],  0.25);
            TEST_ASSERT_FLOAT_EQUALS(c[3],  0.166);
            TEST_ASSERT_FLOAT_EQUALS(c[4],  0.333);
            TEST_ASSERT_FLOAT_EQUALS(c[5],  0.875);
            TEST_ASSERT_FLOAT_EQUALS(c[6],  0.285);
            TEST_ASSERT_FLOAT_EQUALS(c[7],  1.0);
            TEST_ASSERT_FLOAT_EQUALS(c[8],  1.5);
            TEST_ASSERT_FLOAT_EQUALS(c[9],  0.444);
            TEST_ASSERT_FLOAT_EQUALS(c[10], 1.25);
            TEST_ASSERT_FLOAT_EQUALS(c[11], 2.333);
            TEST_ASSERT_FLOAT_EQUALS(c[12], 0.142);
            TEST_ASSERT_FLOAT_EQUALS(c[13], 1.5);
            TEST_ASSERT_FLOAT_EQUALS(c[14], 1.125);
            TEST_ASSERT_FLOAT_EQUALS(c[15], 0.428);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512F not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vsqrtps");
    {
        if (CPU::hasFlag(X86Feature::AVX512F))
        {
            float a[16] __attribute__((aligned(64))) = { 0.5, 0.4, 0.2, 0.1, 0.3, 0.7, 0.2, 0.1, 0.9, 0.4, 0.5, 0.7, 0.1, 0.3, 0.9, 0.3 };
            float b[16] __attribute__((aligned(64)));

            testAvx512fVsqrtps(a, b);

            TEST_ASSERT_FLOAT_EQUALS(a[0],  0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[1],  0.4);
            TEST_ASSERT_FLOAT_EQUALS(a[2],  0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[3],  0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[4],  0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[5],  0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[6],  0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[7],  0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[8],  0.9);
            TEST_ASSERT_FLOAT_EQUALS(a[9],  0.4);
            TEST_ASSERT_FLOAT_EQUALS(a[10], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[11], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[12], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[13], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[14], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(a[15], 0.3);

            TEST_ASSERT_FLOAT_EQUALS(b[0],  0.707);
            TEST_ASSERT_FLOAT_EQUALS(b[1],  0.632);
            TEST_ASSERT_FLOAT_EQUALS(b[2],  0.447);
            TEST_ASSERT_FLOAT_EQUALS(b[3],  0.316);
            TEST_ASSERT_FLOAT_EQUALS(b[4],  0.547);
            TEST_ASSERT_FLOAT_EQUALS(b[5],  0.836);
            TEST_ASSERT_FLOAT_EQUALS(b[6],  0.447);
            TEST_ASSERT_FLOAT_EQUALS(b[7],  0.316);
            TEST_ASSERT_FLOAT_EQUALS(b[8],  0.948);
            TEST_ASSERT_FLOAT_EQUALS(b[9],  0.632);
            TEST_ASSERT_FLOAT_EQUALS(b[10], 0.707);
            TEST_ASSERT_FLOAT_EQUALS(b[11], 0.836);
            TEST_ASSERT_FLOAT_EQUALS(b[12], 0.316);
            TEST_ASSERT_FLOAT_EQUALS(b[13], 0.547);
            TEST_ASSERT_FLOAT_EQUALS(b[14], 0.948);
            TEST_ASSERT_FLOAT_EQUALS(b[15], 0.547);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512F not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vrcp14ps");
    {
        if (CPU::hasFlag(X86Feature::AVX512F))
        {
            float a[16] __attribute__((aligned(64))) = { 0.5, 0.4, 0.2, 0.1, 0.3, 0.7, 0.2, 0.1, 0.9, 0.4, 0.5, 0.7, 0.1, 0.3, 0.9, 0.3 };
            float b[16] __attribute__((aligned(64)));

            testAvx512fVrcp14ps(a, b);

            TEST_ASSERT_FLOAT_EQUALS(a[0],  0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[1],  0.4);
            TEST_ASSERT_FLOAT_EQUALS(a[2],  0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[3],  0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[4],  0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[5],  0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[6],  0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[7],  0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[8],  0.9);
            TEST_ASSERT_FLOAT_EQUALS(a[9],  0.4);
            TEST_ASSERT_FLOAT_EQUALS(a[10], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[11], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[12], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[13], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[14], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(a[15], 0.3);

            TEST_ASSERT_FLOAT_EQUALS(b[0],  2.0);
            TEST_ASSERT_FLOAT_EQUALS(b[1],  2.5);
            TEST_ASSERT_FLOAT_EQUALS(b[2],  5.0);
            TEST_ASSERT_FLOAT_EQUALS(b[3],  10.0);
            TEST_ASSERT_FLOAT_EQUALS(b[4],  3.333);
            TEST_ASSERT_FLOAT_EQUALS(b[5],  1.428);
            TEST_ASSERT_FLOAT_EQUALS(b[6],  5.0);
            TEST_ASSERT_FLOAT_EQUALS(b[7],  10.0);
            TEST_ASSERT_FLOAT_EQUALS(b[8],  1.111);
            TEST_ASSERT_FLOAT_EQUALS(b[9],  2.5);
            TEST_ASSERT_FLOAT_EQUALS(b[10], 2.0);
            TEST_ASSERT_FLOAT_EQUALS(b[11], 1.428);
            TEST_ASSERT_FLOAT_EQUALS(b[12], 10.0);
            TEST_ASSERT_FLOAT_EQUALS(b[13], 3.333);
            TEST_ASSERT_FLOAT_EQUALS(b[14], 1.111);
            TEST_ASSERT_FLOAT_EQUALS(b[15], 3.333);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512F not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vrsqrt14ps");
    {
        if (CPU::hasFlag(X86Feature::AVX512F))
        {
            float a[16] __attribute__((aligned(64))) = { 0.5, 0.4, 0.2, 0.1, 0.3, 0.7, 0.2, 0.1, 0.9, 0.4, 0.5, 0.7, 0.1, 0.3, 0.9, 0.3 };
            float b[16] __attribute__((aligned(64)));

            testAvx512fVrsqrt14ps(a, b);

            TEST_ASSERT_FLOAT_EQUALS(a[0],  0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[1],  0.4);
            TEST_ASSERT_FLOAT_EQUALS(a[2],  0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[3],  0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[4],  0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[5],  0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[6],  0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[7],  0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[8],  0.9);
            TEST_ASSERT_FLOAT_EQUALS(a[9],  0.4);
            TEST_ASSERT_FLOAT_EQUALS(a[10], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[11], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[12], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[13], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[14], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(a[15], 0.3);

            TEST_ASSERT_FLOAT_EQUALS(b[0],  1.414);
            TEST_ASSERT_FLOAT_EQUALS(b[1],  1.581);
            TEST_ASSERT_FLOAT_EQUALS(b[2],  2.236);
            TEST_ASSERT_FLOAT_EQUALS(b[3],  3.162);
            TEST_ASSERT_FLOAT_EQUALS(b[4],  1.825);
            TEST_ASSERT_FLOAT_EQUALS(b[5],  1.195);
            TEST_ASSERT_FLOAT_EQUALS(b[6],  2.236);
            TEST_ASSERT_FLOAT_EQUALS(b[7],  3.162);
            TEST_ASSERT_FLOAT_EQUALS(b[8],  1.054);
            TEST_ASSERT_FLOAT_EQUALS(b[9],  1.581);
            TEST_ASSERT_FLOAT_EQUALS(b[10], 1.414);
            TEST_ASSERT_FLOAT_EQUALS(b[11], 1.195);
            TEST_ASSERT_FLOAT_EQUALS(b[12], 3.162);
            TEST_ASSERT_FLOAT_EQUALS(b[13], 1.825);
            TEST_ASSERT_FLOAT_EQUALS(b[14], 1.054);
            TEST_ASSERT_FLOAT_EQUALS(b[15], 1.825);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512F not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vmaxps");
    {
        if (CPU::hasFlag(X86Feature::AVX512F))
        {
            float a[16] __attribute__((aligned(64))) = { 0.5, 0.4, 0.2, 0.1, 0.3, 0.7, 0.2, 0.1, 0.9, 0.4, 0.5, 0.7, 0.1, 0.3, 0.9, 0.3 };
            float b[16] __attribute__((aligned(64))) = { 0.8, 0.3, 0.8, 0.6, 0.9, 0.8, 0.7, 0.1, 0.6, 0.9, 0.4, 0.3, 0.7, 0.2, 0.8, 0.7 };
            float c[16] __attribute__((aligned(64)));

            testAvx512fVmaxps(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0],  0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[1],  0.4);
            TEST_ASSERT_FLOAT_EQUALS(a[2],  0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[3],  0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[4],  0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[5],  0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[6],  0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[7],  0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[8],  0.9);
            TEST_ASSERT_FLOAT_EQUALS(a[9],  0.4);
            TEST_ASSERT_FLOAT_EQUALS(a[10], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[11], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[12], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[13], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[14], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(a[15], 0.3);

            TEST_ASSERT_FLOAT_EQUALS(b[0],  0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[1],  0.3);
            TEST_ASSERT_FLOAT_EQUALS(b[2],  0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[3],  0.6);
            TEST_ASSERT_FLOAT_EQUALS(b[4],  0.9);
            TEST_ASSERT_FLOAT_EQUALS(b[5],  0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[6],  0.7);
            TEST_ASSERT_FLOAT_EQUALS(b[7],  0.1);
            TEST_ASSERT_FLOAT_EQUALS(b[8],  0.6);
            TEST_ASSERT_FLOAT_EQUALS(b[9],  0.9);
            TEST_ASSERT_FLOAT_EQUALS(b[10], 0.4);
            TEST_ASSERT_FLOAT_EQUALS(b[11], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(b[12], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(b[13], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(b[14], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[15], 0.7);

            TEST_ASSERT_FLOAT_EQUALS(c[0],  0.8);
            TEST_ASSERT_FLOAT_EQUALS(c[1],  0.4);
            TEST_ASSERT_FLOAT_EQUALS(c[2],  0.8);
            TEST_ASSERT_FLOAT_EQUALS(c[3],  0.6);
            TEST_ASSERT_FLOAT_EQUALS(c[4],  0.9);
            TEST_ASSERT_FLOAT_EQUALS(c[5],  0.8);
            TEST_ASSERT_FLOAT_EQUALS(c[6],  0.7);
            TEST_ASSERT_FLOAT_EQUALS(c[7],  0.1);
            TEST_ASSERT_FLOAT_EQUALS(c[8],  0.9);
            TEST_ASSERT_FLOAT_EQUALS(c[9],  0.9);
            TEST_ASSERT_FLOAT_EQUALS(c[10], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(c[11], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(c[12], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(c[13], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(c[14], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(c[15], 0.7);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512F not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vminps");
    {
        if (CPU::hasFlag(X86Feature::AVX512F))
        {
            float a[16] __attribute__((aligned(64))) = { 0.5, 0.4, 0.2, 0.1, 0.3, 0.7, 0.2, 0.1, 0.9, 0.4, 0.5, 0.7, 0.1, 0.3, 0.9, 0.3 };
            float b[16] __attribute__((aligned(64))) = { 0.8, 0.3, 0.8, 0.6, 0.9, 0.8, 0.7, 0.1, 0.6, 0.9, 0.4, 0.3, 0.7, 0.2, 0.8, 0.7 };
            float c[16] __attribute__((aligned(64)));

            testAvx512fVminps(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0],  0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[1],  0.4);
            TEST_ASSERT_FLOAT_EQUALS(a[2],  0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[3],  0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[4],  0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[5],  0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[6],  0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[7],  0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[8],  0.9);
            TEST_ASSERT_FLOAT_EQUALS(a[9],  0.4);
            TEST_ASSERT_FLOAT_EQUALS(a[10], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[11], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[12], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[13], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[14], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(a[15], 0.3);

            TEST_ASSERT_FLOAT_EQUALS(b[0],  0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[1],  0.3);
            TEST_ASSERT_FLOAT_EQUALS(b[2],  0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[3],  0.6);
            TEST_ASSERT_FLOAT_EQUALS(b[4],  0.9);
            TEST_ASSERT_FLOAT_EQUALS(b[5],  0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[6],  0.7);
            TEST_ASSERT_FLOAT_EQUALS(b[7],  0.1);
            TEST_ASSERT_FLOAT_EQUALS(b[8],  0.6);
            TEST_ASSERT_FLOAT_EQUALS(b[9],  0.9);
            TEST_ASSERT_FLOAT_EQUALS(b[10], 0.4);
            TEST_ASSERT_FLOAT_EQUALS(b[11], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(b[12], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(b[13], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(b[14], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[15], 0.7);

            TEST_ASSERT_FLOAT_EQUALS(c[0],  0.5);
            TEST_ASSERT_FLOAT_EQUALS(c[1],  0.3);
            TEST_ASSERT_FLOAT_EQUALS(c[2],  0.2);
            TEST_ASSERT_FLOAT_EQUALS(c[3],  0.1);
            TEST_ASSERT_FLOAT_EQUALS(c[4],  0.3);
            TEST_ASSERT_FLOAT_EQUALS(c[5],  0.7);
            TEST_ASSERT_FLOAT_EQUALS(c[6],  0.2);
            TEST_ASSERT_FLOAT_EQUALS(c[7],  0.1);
            TEST_ASSERT_FLOAT_EQUALS(c[8],  0.6);
            TEST_ASSERT_FLOAT_EQUALS(c[9],  0.4);
            TEST_ASSERT_FLOAT_EQUALS(c[10], 0.4);
            TEST_ASSERT_FLOAT_EQUALS(c[11], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(c[12], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(c[13], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(c[14], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(c[15], 0.3);
        }
        else
        {
            UEFI_LVV(("X86Feature::AVX512F not supported"));
        }
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_AVX512F_AVX512F_H
