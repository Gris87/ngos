#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_SSE_SSE_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_SSE_SSE_H



#include <buildconfig.h>
#include <com/ngos/shared/common/cpu/cpu.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/sse/asm_testsseaddps.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/sse/asm_testssedivps.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/sse/asm_testssemaxps.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/sse/asm_testsseminps.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/sse/asm_testssemulps.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/sse/asm_testssercpps.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/sse/asm_testssersqrtps.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/sse/asm_testssesqrtps.h>
#include <com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/sse/asm_testssesubps.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_fpu_sse_sse);
{
    TEST_CASE("addps");
    {
        if (CPU::hasFeature(X86Feature::SSE))
        {
            float a[4] = { 0.5, 0.4, 0.2, 0.1 };
            float b[4] = { 0.8, 0.3, 0.8, 0.6 };
            float c[4];

            testSseAddps(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.4);
            TEST_ASSERT_FLOAT_EQUALS(a[2], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[3], 0.1);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(b[2], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[3], 0.6);

            TEST_ASSERT_FLOAT_EQUALS(c[0], 1.3);
            TEST_ASSERT_FLOAT_EQUALS(c[1], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(c[2], 1.0);
            TEST_ASSERT_FLOAT_EQUALS(c[3], 0.7);
        }
        else
        {
            UEFI_LVV(("X86Feature::SSE not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("subps");
    {
        if (CPU::hasFeature(X86Feature::SSE))
        {
            float a[4] = { 0.1, 0.5, 0.6, 0.3 };
            float b[4] = { 0.7, 0.3, 0.2, 0.6 };
            float c[4];

            testSseSubps(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[2], 0.6);
            TEST_ASSERT_FLOAT_EQUALS(a[3], 0.3);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(b[2], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(b[3], 0.6);

            TEST_ASSERT_FLOAT_EQUALS(c[0], -0.6);
            TEST_ASSERT_FLOAT_EQUALS(c[1], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(c[2], 0.4);
            TEST_ASSERT_FLOAT_EQUALS(c[3], -0.3);
        }
        else
        {
            UEFI_LVV(("X86Feature::SSE not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("mulps");
    {
        if (CPU::hasFeature(X86Feature::SSE))
        {
            float a[4] = { 0.3, 0.5, 0.7, 0.9 };
            float b[4] = { 0.4, 0.6, 0.8, 0.2 };
            float c[4];

            testSseMulps(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[2], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[3], 0.9);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 0.4);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.6);
            TEST_ASSERT_FLOAT_EQUALS(b[2], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(b[3], 0.2);

            TEST_ASSERT_FLOAT_EQUALS(c[0], 0.12);
            TEST_ASSERT_FLOAT_EQUALS(c[1], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(c[2], 0.56);
            TEST_ASSERT_FLOAT_EQUALS(c[3], 0.18);
        }
        else
        {
            UEFI_LVV(("X86Feature::SSE not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("divps");
    {
        if (CPU::hasFeature(X86Feature::SSE))
        {
            float a[4] = { 0.8, 0.2, 0.5, 0.6 };
            float b[4] = { 0.3, 0.1, 0.7, 0.4 };
            float c[4];

            testSseDivps(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.8);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[2], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(a[3], 0.6);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(b[2], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(b[3], 0.4);

            TEST_ASSERT_FLOAT_EQUALS(c[0], 2.666);
            TEST_ASSERT_FLOAT_EQUALS(c[1], 2.0);
            TEST_ASSERT_FLOAT_EQUALS(c[2], 0.714);
            TEST_ASSERT_FLOAT_EQUALS(c[3], 1.5);
        }
        else
        {
            UEFI_LVV(("X86Feature::SSE not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("sqrtps");
    {
        if (CPU::hasFeature(X86Feature::SSE))
        {
            float a[4] = { 1.0, 4.0, 3.14, 0.09 };
            float b[4];

            testSseSqrtps(a, b);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 1.0);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 4.0);
            TEST_ASSERT_FLOAT_EQUALS(a[2], 3.14);
            TEST_ASSERT_FLOAT_EQUALS(a[3], 0.09);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 1.0);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 2.0);
            TEST_ASSERT_FLOAT_EQUALS(b[2], 1.772);
            TEST_ASSERT_FLOAT_EQUALS(b[3], 0.3);
        }
        else
        {
            UEFI_LVV(("X86Feature::SSE not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("rcpps");
    {
        if (CPU::hasFeature(X86Feature::SSE))
        {
            float a[4] = { 0.1, 0.3, 0.2, 0.5 };
            float b[4];

            testSseRcpps(a, b);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[2], 0.2);
            TEST_ASSERT_FLOAT_EQUALS(a[3], 0.5);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 10.0);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 3.333);
            TEST_ASSERT_FLOAT_EQUALS(b[2], 5.0);
            TEST_ASSERT_FLOAT_EQUALS(b[3], 2.0);
        }
        else
        {
            UEFI_LVV(("X86Feature::SSE not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("rsqrtps");
    {
        if (CPU::hasFeature(X86Feature::SSE))
        {
            float a[4] = { 1.0, 4.0, 9.0, 3.14 };
            float b[4];

            testSseRsqrtps(a, b);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 1.0);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 4.0);
            TEST_ASSERT_FLOAT_EQUALS(a[2], 9.0);
            TEST_ASSERT_FLOAT_EQUALS(a[3], 3.14);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 1.0);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(b[2], 0.333);
            TEST_ASSERT_FLOAT_EQUALS(b[3], 0.564);
        }
        else
        {
            UEFI_LVV(("X86Feature::SSE not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("maxps");
    {
        if (CPU::hasFeature(X86Feature::SSE))
        {
            float a[4] = { 0.9, 0.3, 0.7, 0.4 };
            float b[4] = { 0.1, 0.5, 0.7, 0.2 };
            float c[4];

            testSseMaxps(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[2], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[3], 0.4);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(b[2], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(b[3], 0.2);

            TEST_ASSERT_FLOAT_EQUALS(c[0], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(c[1], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(c[2], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(c[3], 0.4);
        }
        else
        {
            UEFI_LVV(("X86Feature::SSE not supported"));
        }
    }
    TEST_CASE_END();



    TEST_CASE("minps");
    {
        if (CPU::hasFeature(X86Feature::SSE))
        {
            float a[4] = { 0.9, 0.3, 0.7, 0.4 };
            float b[4] = { 0.1, 0.5, 0.7, 0.2 };
            float c[4];

            testSseMinps(a, b, c);

            TEST_ASSERT_FLOAT_EQUALS(a[0], 0.9);
            TEST_ASSERT_FLOAT_EQUALS(a[1], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(a[2], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(a[3], 0.4);

            TEST_ASSERT_FLOAT_EQUALS(b[0], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(b[1], 0.5);
            TEST_ASSERT_FLOAT_EQUALS(b[2], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(b[3], 0.2);

            TEST_ASSERT_FLOAT_EQUALS(c[0], 0.1);
            TEST_ASSERT_FLOAT_EQUALS(c[1], 0.3);
            TEST_ASSERT_FLOAT_EQUALS(c[2], 0.7);
            TEST_ASSERT_FLOAT_EQUALS(c[3], 0.2);
        }
        else
        {
            UEFI_LVV(("X86Feature::SSE not supported"));
        }
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_SSE_SSE_H
