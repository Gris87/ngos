#ifndef CPUTEST_TEST_BITS64_SECTIONS_SECTION1_BITS64_TYPES_H
#define CPUTEST_TEST_BITS64_SECTIONS_SECTION1_BITS64_TYPES_H



#include <buildconfig.h>
#include <uefibase/test/bits64/testengine.h>

#include "src/bits64/main/cputest.h"
#include "src/bits64/main/cputestgui.h"
#include "src/bits64/other/cacheinfo.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section1, bits64_types);
{
    TEST_CASE("Size of structures");
    {
        TEST_ASSERT_EQUALS(sizeof(CpuTest),    1);
        TEST_ASSERT_EQUALS(sizeof(CpuTestGUI), 1);
        TEST_ASSERT_EQUALS(sizeof(CacheInfo),  8);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // CPUTEST_TEST_BITS64_SECTIONS_SECTION1_BITS64_TYPES_H
