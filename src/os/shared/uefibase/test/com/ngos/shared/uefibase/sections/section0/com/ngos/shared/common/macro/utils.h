#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_MACRO_UTILS_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_MACRO_UTILS_H



#include <buildconfig.h>
#include <com/ngos/shared/common/macro/utils.h>
#include <com/ngos/shared/common/string/string.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_macro_utils);
{
    TEST_CASE("PP_JOIN()");
    {
        TEST_ASSERT_EQUALS(PP_JOIN(100, 500), 100500);
        TEST_ASSERT_EQUALS(PP_JOIN(123, 456), 123456);
        TEST_ASSERT_EQUALS(PP_JOIN(987, 123), 987123);

        TEST_ASSERT_EQUALS(PP_JOIN(PP_0(100, 500), 123),            100123);
        TEST_ASSERT_EQUALS(PP_JOIN(987,            PP_0(100, 500)), 987100);
        TEST_ASSERT_EQUALS(PP_JOIN(PP_0(100, 500), PP_0(987, 123)), 100987);
    }
    TEST_CASE_END();



    TEST_CASE("PP_STRINGIZE()");
    {
        TEST_ASSERT_EQUALS(strcmp(PP_STRINGIZE(100), "100"), 0);
        TEST_ASSERT_EQUALS(strcmp(PP_STRINGIZE(20),  "20"),  0);
        TEST_ASSERT_EQUALS(strcmp(PP_STRINGIZE(abc), "abc"), 0);
    }
    TEST_CASE_END();



    TEST_CASE("PP_0()");
    {
        TEST_ASSERT_EQUALS(PP_0(100, 500), 100);
        TEST_ASSERT_EQUALS(PP_0(123, 456), 123);
        TEST_ASSERT_EQUALS(PP_0(987, 123), 987);
    }
    TEST_CASE_END();



    TEST_CASE("PP_X()");
    {
        TEST_ASSERT_EQUALS(PP_0(PP_X(100, 500)), 500);
        TEST_ASSERT_EQUALS(PP_0(PP_X(123, 456)), 456);
        TEST_ASSERT_EQUALS(PP_0(PP_X(987, 123)), 123);
    }
    TEST_CASE_END();



    TEST_CASE("PP_NARG()");
    {
        TEST_ASSERT_EQUALS(PP_NARG(),                       1);
        TEST_ASSERT_EQUALS(PP_NARG(a),                      1);
        TEST_ASSERT_EQUALS(PP_NARG(a, b),                   2);
        TEST_ASSERT_EQUALS(PP_NARG(a, b, c),                3);
        TEST_ASSERT_EQUALS(PP_NARG(a, b, c, d),             4);
        TEST_ASSERT_EQUALS(PP_NARG(a, b, c, d, e),          5);
        TEST_ASSERT_EQUALS(PP_NARG(a, b, c, d, e, f),       6);
        TEST_ASSERT_EQUALS(PP_NARG(a, b, c, d, e, f, g),    7);
        TEST_ASSERT_EQUALS(PP_NARG(a, b, c, d, e, f, g, h), 8);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_MACRO_UTILS_H
