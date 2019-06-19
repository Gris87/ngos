#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___INCLUDE_NGOS_LINKAGE_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___INCLUDE_NGOS_LINKAGE_H



#include <buildconfig.h>
#include <ngos/linkage.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __include_ngos_linkage);
{
    TEST_CASE("IS_CONSTANT()");
    {
        u64 temp = 0;

        for (i64 i = 0; i < 100; ++i)
        {
            temp += temp + 1;
        }



        TEST_ASSERT_EQUALS(IS_CONSTANT(0),       true);
        TEST_ASSERT_EQUALS(IS_CONSTANT(200),     true);
        TEST_ASSERT_EQUALS(IS_CONSTANT(1000),    true);
        TEST_ASSERT_EQUALS(IS_CONSTANT(100000),  true);
        TEST_ASSERT_EQUALS(IS_CONSTANT(-5),      true);
        TEST_ASSERT_EQUALS(IS_CONSTANT(-1000),   true);
        TEST_ASSERT_EQUALS(IS_CONSTANT(-100000), true);
        TEST_ASSERT_EQUALS(IS_CONSTANT(temp),    false);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___INCLUDE_NGOS_LINKAGE_H
