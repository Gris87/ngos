#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_GRAPHICS_STRETCHRANGE_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_GRAPHICS_STRETCHRANGE_H



#include <buildconfig.h>
#include <com/ngos/shared/common/graphics/stretchrange.h>
#include <com/ngos/shared/common/memory/memory.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_graphics_stretchrange);
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



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_GRAPHICS_STRETCHRANGE_H
