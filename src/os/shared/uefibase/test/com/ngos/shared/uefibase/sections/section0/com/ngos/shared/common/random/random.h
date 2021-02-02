#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_RANDOM_RANDOM_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_RANDOM_RANDOM_H



#include <buildconfig.h>
#include <com/ngos/shared/common/random/random.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_random_random);
{
    TEST_CASE("simpleRandom()");
    {
        bad_uint64 random1 = simpleRandom();
        bad_uint64 random2 = simpleRandom();
        bad_uint64 random3 = simpleRandom();
        bad_uint64 random4 = simpleRandom();

        TEST_ASSERT_NOT_EQUALS(random1, 0);
        TEST_ASSERT_NOT_EQUALS(random2, 0);
        TEST_ASSERT_NOT_EQUALS(random3, 0);
        TEST_ASSERT_NOT_EQUALS(random4, 0);

        TEST_ASSERT_NOT_EQUALS(random1, random2);
        TEST_ASSERT_NOT_EQUALS(random1, random3);
        TEST_ASSERT_NOT_EQUALS(random1, random4);
        TEST_ASSERT_NOT_EQUALS(random2, random3);
        TEST_ASSERT_NOT_EQUALS(random2, random4);
        TEST_ASSERT_NOT_EQUALS(random3, random4);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_RANDOM_RANDOM_H
