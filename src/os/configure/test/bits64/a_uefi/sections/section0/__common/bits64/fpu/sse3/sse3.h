#ifndef CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_FPU_SSE3_SSE3_H
#define CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_FPU_SSE3_SSE3_H



#include <buildconfig.h>
#include <src/bits64/cpu/cpu.h>

#include "test/bits64/a_uefi/testengine.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse3/asm_testsse3addsubps.h"
#include "test/bits64/a_uefi/sections/section0/__common/bits64/fpu/sse3/asm_testsse3addsubpd.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __common_bits64_fpu_sse3_sse3);
{
    TEST_CASE("addsubps");
    {
        if (CPU::hasFlag(X86Feature::XMM3))
        {
        }
    }
    TEST_CASE_END();



    TEST_CASE("addsubpd");
    {
        if (CPU::hasFlag(X86Feature::XMM3))
        {
        }
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_FPU_SSE3_SSE3_H
