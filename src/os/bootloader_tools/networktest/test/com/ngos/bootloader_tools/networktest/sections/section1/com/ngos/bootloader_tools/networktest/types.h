#ifndef NETWORKTEST_TEST_BITS64_SECTIONS_SECTION1_BITS64_TYPES_H
#define NETWORKTEST_TEST_BITS64_SECTIONS_SECTION1_BITS64_TYPES_H



#include <buildconfig.h>
#include <uefibase/test/bits64/testengine.h>

#include "src/bits64/main/networktest.h"
#include "src/bits64/main/networktestgui.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section1, bits64_types);
{
    TEST_CASE("Size of structures");
    {
        TEST_ASSERT_EQUALS(sizeof(NetworkTest),    1);
        TEST_ASSERT_EQUALS(sizeof(NetworkTestGUI), 1);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // NETWORKTEST_TEST_BITS64_SECTIONS_SECTION1_BITS64_TYPES_H
