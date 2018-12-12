#ifndef CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_RANDOM_RANDOM_H
#define CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_RANDOM_RANDOM_H



#include <buildconfig.h>
#include <src/bits64/random/random.h>

#include "test/bits64/a_uefi/testengine.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __common_bits64_random_random);
{
    TEST_CASE("simpleRandom()");
    {
        u64 random1 = simpleRandom();
        u64 random2 = simpleRandom();
        u64 random3 = simpleRandom();
        u64 random4 = simpleRandom();

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



#endif // CONFIGURE_TEST_BITS64_A_UEFI_SECTIONS_SECTION0___COMMON_BITS64_RANDOM_RANDOM_H
