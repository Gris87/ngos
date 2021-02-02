#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_NGOS_TYPES_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_NGOS_TYPES_H



#include <buildconfig.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_ngos_types);
{
    TEST_CASE("Size of general types");
    {
        TEST_ASSERT_EQUALS(sizeof(bad_int8),  1);
        TEST_ASSERT_EQUALS(sizeof(bad_int16), 2);
        TEST_ASSERT_EQUALS(sizeof(bad_int32), 4);
        TEST_ASSERT_EQUALS(sizeof(bad_int64), 8);

        TEST_ASSERT_EQUALS(sizeof(bad_uint8),  1);
        TEST_ASSERT_EQUALS(sizeof(bad_uint16), 2);
        TEST_ASSERT_EQUALS(sizeof(bad_uint32), 4);
        TEST_ASSERT_EQUALS(sizeof(bad_uint64), 8);

        TEST_ASSERT_EQUALS(sizeof(char8),  1);
        TEST_ASSERT_EQUALS(sizeof(char16), 2);

        TEST_ASSERT_EQUALS(sizeof(size_t), 8);
    }
    TEST_CASE_END();



    TEST_CASE("Values of general types");
    {
        TEST_ASSERT_EQUALS((bad_int8)-1,   -1);
        TEST_ASSERT_EQUALS((bad_int8)127,  127);
        TEST_ASSERT_EQUALS((bad_int8)128,  -128);
        TEST_ASSERT_EQUALS((bad_int8)-129, 127);

        TEST_ASSERT_EQUALS((bad_int16)-1,     -1);
        TEST_ASSERT_EQUALS((bad_int16)32767,  32767);
        TEST_ASSERT_EQUALS((bad_int16)32768,  -32768);
        TEST_ASSERT_EQUALS((bad_int16)-32769, 32767);

        TEST_ASSERT_EQUALS((bad_int32)-1,          -1);
        TEST_ASSERT_EQUALS((bad_int32)2147483647,  2147483647);
        TEST_ASSERT_EQUALS((bad_int32)2147483648,  -2147483648);
        TEST_ASSERT_EQUALS((bad_int32)-2147483649, 2147483647);

        bad_uint64 temp1 = 9223372036854775808ULL;
        bad_uint64 temp2 = 9223372036854775809ULL;

        TEST_ASSERT_EQUALS((bad_int64)-1,                     -1);
        TEST_ASSERT_EQUALS((bad_int64)9223372036854775807ULL, 9223372036854775807LL);
        TEST_ASSERT_EQUALS((bad_int64)temp1,                  (bad_int64)-temp1);
        TEST_ASSERT_EQUALS((bad_int64)-temp2,                 9223372036854775807LL);



        TEST_ASSERT_EQUALS((bad_uint8)-1,   255);
        TEST_ASSERT_EQUALS((bad_uint8)127,  127);
        TEST_ASSERT_EQUALS((bad_uint8)128,  128);
        TEST_ASSERT_EQUALS((bad_uint8)-129, 127);

        TEST_ASSERT_EQUALS((bad_uint16)-1,     65535);
        TEST_ASSERT_EQUALS((bad_uint16)32767,  32767);
        TEST_ASSERT_EQUALS((bad_uint16)32768,  32768);
        TEST_ASSERT_EQUALS((bad_uint16)-32769, 32767);

        TEST_ASSERT_EQUALS((bad_uint32)-1,          4294967295);
        TEST_ASSERT_EQUALS((bad_uint32)2147483647,  2147483647);
        TEST_ASSERT_EQUALS((bad_uint32)2147483648,  2147483648);
        TEST_ASSERT_EQUALS((bad_uint32)-2147483649, 2147483647);

        TEST_ASSERT_EQUALS((bad_uint64)-1,                     18446744073709551615ULL);
        TEST_ASSERT_EQUALS((bad_uint64)9223372036854775807ULL, 9223372036854775807ULL);
        TEST_ASSERT_EQUALS((bad_uint64)9223372036854775808ULL, 9223372036854775808ULL);
        TEST_ASSERT_EQUALS((bad_uint64)-temp2,                 9223372036854775807ULL);



        TEST_ASSERT_EQUALS((char8)-1,   -1);
        TEST_ASSERT_EQUALS((char8)127,  127);
        TEST_ASSERT_EQUALS((char8)128,  -128);
        TEST_ASSERT_EQUALS((char8)-129, 127);

        TEST_ASSERT_EQUALS((char16)-1,     65535);
        TEST_ASSERT_EQUALS((char16)32767,  32767);
        TEST_ASSERT_EQUALS((char16)32768,  32768);
        TEST_ASSERT_EQUALS((char16)-32769, 32767);



        TEST_ASSERT_EQUALS((size_t)-1,                     18446744073709551615ULL);
        TEST_ASSERT_EQUALS((size_t)9223372036854775807ULL, 9223372036854775807ULL);
        TEST_ASSERT_EQUALS((size_t)9223372036854775808ULL, 9223372036854775808ULL);
        TEST_ASSERT_EQUALS((size_t)-temp2,                 9223372036854775807ULL);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_NGOS_TYPES_H
