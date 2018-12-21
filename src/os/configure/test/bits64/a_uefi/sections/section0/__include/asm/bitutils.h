#ifndef CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___INCLUDE_ASM_BITUTILS_H
#define CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___INCLUDE_ASM_BITUTILS_H



#include <asm/bitutils.h>
#include <buildconfig.h>

#include "test/bits64/a_uefi/testengine.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __include_asm_bitutils);
{
    TEST_CASE("test()");
    {

    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___INCLUDE_ASM_BITUTILS_H
