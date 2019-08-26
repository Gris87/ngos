#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_GRAPHICS_STRETCHRANGE_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_GRAPHICS_STRETCHRANGE_H



#include <buildconfig.h>
#include <common/src/bits64/graphics/stretchrange.h>
#include <common/src/bits64/memory/memory.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_graphics_stretchrange);
{
    TEST_CASE("StretchRange()");
    {
        StretchRange temp(10, 20);
        StretchRange temp2(20, 30);

        TEST_ASSERT_EQUALS(temp.mFrom, 10);
        TEST_ASSERT_EQUALS(temp.mTo,   20);

        TEST_ASSERT_EQUALS(temp2.mFrom, 20);
        TEST_ASSERT_EQUALS(temp2.mTo,   30);
    }
    TEST_CASE_END();



    TEST_CASE("getSize()");
    {
        StretchRange temp(10, 20);
        StretchRange temp2(20, 50);

        TEST_ASSERT_EQUALS(temp.getSize(),  10);
        TEST_ASSERT_EQUALS(temp2.getSize(), 30);
    }
    TEST_CASE_END();



    TEST_CASE("getFrom()");
    {
        StretchRange temp(10, 20);
        StretchRange temp2(20, 30);

        TEST_ASSERT_EQUALS(temp.getFrom(),  10);
        TEST_ASSERT_EQUALS(temp2.getFrom(), 20);
    }
    TEST_CASE_END();



    TEST_CASE("getTo()");
    {
        StretchRange temp(10, 20);
        StretchRange temp2(20, 30);

        TEST_ASSERT_EQUALS(temp.getTo(),  20);
        TEST_ASSERT_EQUALS(temp2.getTo(), 30);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_GRAPHICS_STRETCHRANGE_H
