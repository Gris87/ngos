#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_STRING_STRING_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_STRING_STRING_H



#include <buildconfig.h>
#include <common/src/bits64/string/string.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_string_string);
{
    TEST_CASE("strlen()");
    {
        TEST_ASSERT_EQUALS(strlen(""),         0);
        TEST_ASSERT_EQUALS(strlen("abcd"),     4);
        TEST_ASSERT_EQUALS(strlen("abcdefgh"), 8);
    }
    TEST_CASE_END();



    TEST_CASE("strlen()");
    {
        TEST_ASSERT_EQUALS(strlen(L""),         0);
        TEST_ASSERT_EQUALS(strlen(L"abcd"),     4);
        TEST_ASSERT_EQUALS(strlen(L"abcdefgh"), 8);
    }
    TEST_CASE_END();



    TEST_CASE("strnlen()");
    {
        TEST_ASSERT_EQUALS(strnlen("abcd", 0),  0);
        TEST_ASSERT_EQUALS(strnlen("abcd", 1),  1);
        TEST_ASSERT_EQUALS(strnlen("abcd", 5),  4);
        TEST_ASSERT_EQUALS(strnlen("abcd", -1), 4);

        TEST_ASSERT_EQUALS(strnlen("abcdefgh", 0),  0);
        TEST_ASSERT_EQUALS(strnlen("abcdefgh", 3),  3);
        TEST_ASSERT_EQUALS(strnlen("abcdefgh", 10), 8);
        TEST_ASSERT_EQUALS(strnlen("abcdefgh", -1), 8);
    }
    TEST_CASE_END();



    TEST_CASE("strnlen()");
    {
        TEST_ASSERT_EQUALS(strnlen(L"abcd", 0),  0);
        TEST_ASSERT_EQUALS(strnlen(L"abcd", 1),  1);
        TEST_ASSERT_EQUALS(strnlen(L"abcd", 5),  4);
        TEST_ASSERT_EQUALS(strnlen(L"abcd", -1), 4);

        TEST_ASSERT_EQUALS(strnlen(L"abcdefgh", 0),  0);
        TEST_ASSERT_EQUALS(strnlen(L"abcdefgh", 3),  3);
        TEST_ASSERT_EQUALS(strnlen(L"abcdefgh", 10), 8);
        TEST_ASSERT_EQUALS(strnlen(L"abcdefgh", -1), 8);
    }
    TEST_CASE_END();



    TEST_CASE("strcmp()");
    {
        TEST_ASSERT_EQUALS(strcmp("aa", "aa"), 0);
        TEST_ASSERT_EQUALS(strcmp("aa", "ab"), -1);
        TEST_ASSERT_EQUALS(strcmp("ab", "aa"), 1);

        TEST_ASSERT_EQUALS(strcmp("abcdef", "abcdef"), 0);
        TEST_ASSERT_EQUALS(strcmp("abcdef", "abcdeh"), -1);
        TEST_ASSERT_EQUALS(strcmp("abcdeh", "abcdef"), 1);
        TEST_ASSERT_EQUALS(strcmp("abc",    "abcdef"), -1);
        TEST_ASSERT_EQUALS(strcmp("abcdeg", "abc"),    1);
    }
    TEST_CASE_END();



    TEST_CASE("strncmp()");
    {
        TEST_ASSERT_EQUALS(strncmp("aa", "aa", -1), 0);
        TEST_ASSERT_EQUALS(strncmp("aa", "ab", -1), -1);
        TEST_ASSERT_EQUALS(strncmp("ab", "aa", -1), 1);

        TEST_ASSERT_EQUALS(strncmp("abcdef", "abcdef", -1), 0);
        TEST_ASSERT_EQUALS(strncmp("abcdef", "abcdeh", -1), -1);
        TEST_ASSERT_EQUALS(strncmp("abcdeh", "abcdef", -1), 1);
        TEST_ASSERT_EQUALS(strncmp("abc",    "abcdef", -1), -1);
        TEST_ASSERT_EQUALS(strncmp("abcdeg", "abc",    -1), 1);

        TEST_ASSERT_EQUALS(strncmp("abcdeg", "abc",  3), 0);
        TEST_ASSERT_EQUALS(strncmp("abcdeg", "abcf", 3), 0);
        TEST_ASSERT_EQUALS(strncmp("abcdeg", "abd",  3), -1);
        TEST_ASSERT_EQUALS(strncmp("abcdeg", "abb",  3), 1);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_STRING_STRING_H
