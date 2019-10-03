#ifndef NETWORKTEST_TEST_BITS64_SECTIONS_SECTION1_TESTCASE_H
#define NETWORKTEST_TEST_BITS64_SECTIONS_SECTION1_TESTCASE_H



#include <buildconfig.h>
#include <uefibase/test/bits64/testengine.h>

#include "test/bits64/sections/section1/bits64/types.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



CPP_MAX_OPTIMIZATION
NgosStatus startTestSection1()
{
    UEFI_LT((""));



    INIT_TEST_SECTION();

    CALL_TEST_CASES(section1, bits64_types);

    SUMMARY_TEST_SECTION();
}



#endif



#endif // NETWORKTEST_TEST_BITS64_SECTIONS_SECTION1_TESTCASE_H