#ifndef OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_SSE42_SSE42_H
#define OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_SSE42_SSE42_H



#include <buildconfig.h>
#include <common/src/com/ngos/shared/common/cpu/cpu.h>
#include <uefibase/test/com/ngos/shared/uefibase/sections/section0/com/ngos/shared/common/fpu/sse42/asm_testsse42pcmpgtq.h>
#include <uefibase/test/com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_fpu_sse42_sse42);
{
    TEST_CASE("pcmpgtq");
    {
        if (CPU::hasFlag(X86Feature::XMM4_2))
        {
            i64 a[2] = { 1987965842, -1987077212 };
            i64 b[2] = { 1981132191, 1271329132 };
            i64 c[2];

            testSse42Pcmpgtq(a, b, c);

            TEST_ASSERT_EQUALS(a[0], 1987965842);
            TEST_ASSERT_EQUALS(a[1], -1987077212);

            TEST_ASSERT_EQUALS(b[0], 1981132191);
            TEST_ASSERT_EQUALS(b[1], 1271329132);

            TEST_ASSERT_EQUALS(c[0], -1);
            TEST_ASSERT_EQUALS(c[1], 0);
        }
        else
        {
            UEFI_LVV(("X86Feature::XMM4_2 not supported"));
        }
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_FPU_SSE42_SSE42_H
