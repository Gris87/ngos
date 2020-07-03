#ifndef OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_FMA3_FMA3_H
#define OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_FMA3_FMA3_H



#include <buildconfig.h>
#include <com/ngos/shared/common/cpu/cpu.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/fma3/asm_testfma3vfmadd213pd.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/fma3/asm_testfma3vfmadd213ps.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/fma3/asm_testfma3vfmsub213pd.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/fma3/asm_testfma3vfmsub213ps.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_fpu_fma3_fma3);
{
    TEST_CASE("vfmadd213ps");
    {
        if (CPU::hasFlag(X86Feature::FMA))
        {
            float a[8] __attribute__((aligned(32))) = { 0.1, 0.9, 0.7, 0.5, 0.7, 0.3, 0.4, 0.9 };
            float b[8] __attribute__((aligned(32))) = { 0.8, 0.5, 0.3, 0.9, 0.9, 0.7, 0.5, 0.7 };
            float c[8] __attribute__((aligned(32))) = { 0.9, 0.7, 0.6, 0.8, 0.9, 0.6, 0.7, 0.8 };
            float d[8] __attribute__((aligned(32)));

            testFma3Vfmadd213ps(a, b, c, d);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(a[2], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[3], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[4], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[5], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[6], 0.4);
            TEST_ASSERT_FLOAT_EQUALS(a[7], 0.9);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(b[2], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(b[3], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(b[4], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(b[5], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(b[6], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(b[7], 0.7);

            TEST_ASSERT_FLOAT_EQUALS(c[0], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(c[1], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(c[2], 0.6);
            TEST_ASSERT_FLOAT_EQUALS(c[3], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(c[4], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(c[5], 0.6);
            TEST_ASSERT_FLOAT_EQUALS(c[6], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(c[7], 0.8);

            TEST_ASSERT_FLOAT_EQUALS(d[0], 0.98);
            TEST_ASSERT_FLOAT_EQUALS(d[1], 1.15);
            TEST_ASSERT_FLOAT_EQUALS(d[2], 0.81);
            TEST_ASSERT_FLOAT_EQUALS(d[3], 1.25);
            TEST_ASSERT_FLOAT_EQUALS(d[4], 1.53);
            TEST_ASSERT_FLOAT_EQUALS(d[5], 0.81);
            TEST_ASSERT_FLOAT_EQUALS(d[6], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(d[7], 1.43);
        }
        else
        {
            UEFI_LVV(("X86Feature::FMA not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vfmadd213pd");
    {
        if (CPU::hasFlag(X86Feature::FMA))
        {
            double a[4] __attribute__((aligned(32))) = { 0.1, 0.9, 0.7, 0.5 };
            double b[4] __attribute__((aligned(32))) = { 0.8, 0.5, 0.3, 0.9 };
            double c[4] __attribute__((aligned(32))) = { 0.9, 0.7, 0.6, 0.8 };
            double d[4] __attribute__((aligned(32)));

            testFma3Vfmadd213pd(a, b, c, d);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(a[2], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[3], 0.5);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(b[2], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(b[3], 0.9);

            TEST_ASSERT_FLOAT_EQUALS(c[0], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(c[1], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(c[2], 0.6);
            TEST_ASSERT_FLOAT_EQUALS(c[3], 0.8);

            TEST_ASSERT_FLOAT_EQUALS(d[0], 0.98);
            TEST_ASSERT_FLOAT_EQUALS(d[1], 1.15);
            TEST_ASSERT_FLOAT_EQUALS(d[2], 0.81);
            TEST_ASSERT_FLOAT_EQUALS(d[3], 1.25);
        }
        else
        {
            UEFI_LVV(("X86Feature::FMA not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vfmsub213ps");
    {
        if (CPU::hasFlag(X86Feature::FMA))
        {
            float a[8] __attribute__((aligned(32))) = { 0.1, 0.9, 0.7, 0.5, 0.7, 0.3, 0.4, 0.9 };
            float b[8] __attribute__((aligned(32))) = { 0.8, 0.5, 0.3, 0.9, 0.9, 0.7, 0.5, 0.7 };
            float c[8] __attribute__((aligned(32))) = { 0.9, 0.7, 0.6, 0.8, 0.9, 0.6, 0.7, 0.8 };
            float d[8] __attribute__((aligned(32)));

            testFma3Vfmsub213ps(a, b, c, d);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(a[2], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[3], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[4], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[5], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[6], 0.4);
            TEST_ASSERT_FLOAT_EQUALS(a[7], 0.9);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(b[2], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(b[3], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(b[4], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(b[5], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(b[6], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(b[7], 0.7);

            TEST_ASSERT_FLOAT_EQUALS(c[0], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(c[1], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(c[2], 0.6);
            TEST_ASSERT_FLOAT_EQUALS(c[3], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(c[4], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(c[5], 0.6);
            TEST_ASSERT_FLOAT_EQUALS(c[6], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(c[7], 0.8);

            TEST_ASSERT_FLOAT_EQUALS(d[0], -0.82);
            TEST_ASSERT_FLOAT_EQUALS(d[1], -0.25);
            TEST_ASSERT_FLOAT_EQUALS(d[2], -0.39);
            TEST_ASSERT_FLOAT_EQUALS(d[3], -0.35);
            TEST_ASSERT_FLOAT_EQUALS(d[4], -0.27);
            TEST_ASSERT_FLOAT_EQUALS(d[5], -0.39);
            TEST_ASSERT_FLOAT_EQUALS(d[6], -0.5);
            TEST_ASSERT_FLOAT_EQUALS(d[7], -0.17);
        }
        else
        {
            UEFI_LVV(("X86Feature::FMA not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("vfmsub213pd");
    {
        if (CPU::hasFlag(X86Feature::FMA))
        {
            double a[4] __attribute__((aligned(32))) = { 0.1, 0.9, 0.7, 0.5 };
            double b[4] __attribute__((aligned(32))) = { 0.8, 0.5, 0.3, 0.9 };
            double c[4] __attribute__((aligned(32))) = { 0.9, 0.7, 0.6, 0.8 };
            double d[4] __attribute__((aligned(32)));

            testFma3Vfmsub213pd(a, b, c, d);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(a[2], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[3], 0.5);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(b[2], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(b[3], 0.9);

            TEST_ASSERT_FLOAT_EQUALS(c[0], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(c[1], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(c[2], 0.6);
            TEST_ASSERT_FLOAT_EQUALS(c[3], 0.8);

            TEST_ASSERT_FLOAT_EQUALS(d[0], -0.82);
            TEST_ASSERT_FLOAT_EQUALS(d[1], -0.25);
            TEST_ASSERT_FLOAT_EQUALS(d[2], -0.39);
            TEST_ASSERT_FLOAT_EQUALS(d[3], -0.35);
        }
        else
        {
            UEFI_LVV(("X86Feature::FMA not supported"));
        }
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_FMA3_FMA3_H
