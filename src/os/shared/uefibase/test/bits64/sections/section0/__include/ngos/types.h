#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___INCLUDE_NGOS_TYPES_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___INCLUDE_NGOS_TYPES_H



#include <buildconfig.h>
#include <ngos/types.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __include_ngos_types);
{
    TEST_CASE("Size of general types");
    {
        TEST_ASSERT_EQUALS(sizeof(i8),  1);
        TEST_ASSERT_EQUALS(sizeof(i16), 2);
        TEST_ASSERT_EQUALS(sizeof(i32), 4);
        TEST_ASSERT_EQUALS(sizeof(i64), 8);

        TEST_ASSERT_EQUALS(sizeof(u8),  1);
        TEST_ASSERT_EQUALS(sizeof(u16), 2);
        TEST_ASSERT_EQUALS(sizeof(u32), 4);
        TEST_ASSERT_EQUALS(sizeof(u64), 8);
    }
    TEST_CASE_END();



    TEST_CASE("Values of general types");
    {
        TEST_ASSERT_EQUALS((i8)-1,   -1);
        TEST_ASSERT_EQUALS((i8)127,  127);
        TEST_ASSERT_EQUALS((i8)128,  -128);
        TEST_ASSERT_EQUALS((i8)-129, 127);

        TEST_ASSERT_EQUALS((i16)-1,     -1);
        TEST_ASSERT_EQUALS((i16)32767,  32767);
        TEST_ASSERT_EQUALS((i16)32768,  -32768);
        TEST_ASSERT_EQUALS((i16)-32769, 32767);

        TEST_ASSERT_EQUALS((i32)-1,          -1);
        TEST_ASSERT_EQUALS((i32)2147483647,  2147483647);
        TEST_ASSERT_EQUALS((i32)2147483648,  -2147483648);
        TEST_ASSERT_EQUALS((i32)-2147483649, 2147483647);

        TEST_ASSERT_EQUALS((i64)-1,                     -1);
        TEST_ASSERT_EQUALS((i64)9223372036854775807ULL, 9223372036854775807LL);

        TEST_ASSERT_EQUALS((u8)-1,  255);
        TEST_ASSERT_EQUALS((u16)-1, 65535);
        TEST_ASSERT_EQUALS((u32)-1, 4294967295);
        TEST_ASSERT_EQUALS((u64)-1, 18446744073709551615ULL);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___INCLUDE_NGOS_TYPES_H
