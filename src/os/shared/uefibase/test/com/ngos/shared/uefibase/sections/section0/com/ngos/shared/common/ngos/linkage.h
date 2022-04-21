#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_NGOS_LINKAGE_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_NGOS_LINKAGE_H



#include <buildconfig.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_ngos_linkage);
{
    TEST_CASE("IS_CONSTANT()");
    {
        u64 temp = 0;

        for (good_I64 i = 0; i < 10; ++i)
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



    TEST_CASE("ARRAY_COUNT()");
    {
        u8     a[5];
        u16    b[6];
        u32    c[7];
        u64    d[8];
        char8  e[9];
        char16 f[3];

        TEST_ASSERT_EQUALS(ARRAY_COUNT(a), 5);
        TEST_ASSERT_EQUALS(ARRAY_COUNT(b), 6);
        TEST_ASSERT_EQUALS(ARRAY_COUNT(c), 7);
        TEST_ASSERT_EQUALS(ARRAY_COUNT(d), 8);
        TEST_ASSERT_EQUALS(ARRAY_COUNT(e), 9);
        TEST_ASSERT_EQUALS(ARRAY_COUNT(f), 3);
    }
    TEST_CASE_END();



    TEST_CASE("FLAGS()");
    {
        TEST_ASSERT_EQUALS(FLAGS(1),          1);
        TEST_ASSERT_EQUALS(FLAGS(1, 2),       3);
        TEST_ASSERT_EQUALS(FLAGS(1, 4),       5);
        TEST_ASSERT_EQUALS(FLAGS(1, 2, 4),    7);
        TEST_ASSERT_EQUALS(FLAGS(1, 2, 4, 8), 15);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_NGOS_LINKAGE_H
