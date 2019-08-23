#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_STRING_STRING_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_STRING_STRING_H



#include <buildconfig.h>
#include <common/src/bits64/memory/memory.h>
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
        TEST_ASSERT_EQUALS(strlen(u""),         0);
        TEST_ASSERT_EQUALS(strlen(u"abcd"),     4);
        TEST_ASSERT_EQUALS(strlen(u"abcdefgh"), 8);
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
        TEST_ASSERT_EQUALS(strnlen(u"abcd", 0),  0);
        TEST_ASSERT_EQUALS(strnlen(u"abcd", 1),  1);
        TEST_ASSERT_EQUALS(strnlen(u"abcd", 5),  4);
        TEST_ASSERT_EQUALS(strnlen(u"abcd", -1), 4);

        TEST_ASSERT_EQUALS(strnlen(u"abcdefgh", 0),  0);
        TEST_ASSERT_EQUALS(strnlen(u"abcdefgh", 3),  3);
        TEST_ASSERT_EQUALS(strnlen(u"abcdefgh", 10), 8);
        TEST_ASSERT_EQUALS(strnlen(u"abcdefgh", -1), 8);
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



    TEST_CASE("strcmp()");
    {
        TEST_ASSERT_EQUALS(strcmp(u"aa", u"aa"), 0);
        TEST_ASSERT_EQUALS(strcmp(u"aa", u"ab"), -1);
        TEST_ASSERT_EQUALS(strcmp(u"ab", u"aa"), 1);

        TEST_ASSERT_EQUALS(strcmp(u"abcdef", u"abcdef"), 0);
        TEST_ASSERT_EQUALS(strcmp(u"abcdef", u"abcdeh"), -1);
        TEST_ASSERT_EQUALS(strcmp(u"abcdeh", u"abcdef"), 1);
        TEST_ASSERT_EQUALS(strcmp(u"abc",    u"abcdef"), -1);
        TEST_ASSERT_EQUALS(strcmp(u"abcdeg", u"abc"),    1);
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



    TEST_CASE("strncmp()");
    {
        TEST_ASSERT_EQUALS(strncmp(u"aa", u"aa", -1), 0);
        TEST_ASSERT_EQUALS(strncmp(u"aa", u"ab", -1), -1);
        TEST_ASSERT_EQUALS(strncmp(u"ab", u"aa", -1), 1);

        TEST_ASSERT_EQUALS(strncmp(u"abcdef", u"abcdef", -1), 0);
        TEST_ASSERT_EQUALS(strncmp(u"abcdef", u"abcdeh", -1), -1);
        TEST_ASSERT_EQUALS(strncmp(u"abcdeh", u"abcdef", -1), 1);
        TEST_ASSERT_EQUALS(strncmp(u"abc",    u"abcdef", -1), -1);
        TEST_ASSERT_EQUALS(strncmp(u"abcdeg", u"abc",    -1), 1);

        TEST_ASSERT_EQUALS(strncmp(u"abcdeg", u"abc",  3), 0);
        TEST_ASSERT_EQUALS(strncmp(u"abcdeg", u"abcf", 3), 0);
        TEST_ASSERT_EQUALS(strncmp(u"abcdeg", u"abd",  3), -1);
        TEST_ASSERT_EQUALS(strncmp(u"abcdeg", u"abb",  3), 1);
    }
    TEST_CASE_END();



    TEST_CASE("strcat()");
    {
        char8 temp[15];
        memzero(temp, sizeof(temp));

        TEST_ASSERT_EQUALS(strcat(temp, "aa"), temp);
        TEST_ASSERT_EQUALS(strcmp(temp, "aa"), 0);

        TEST_ASSERT_EQUALS(strcat(temp, "bbb"),   temp);
        TEST_ASSERT_EQUALS(strcmp(temp, "aabbb"), 0);

        TEST_ASSERT_EQUALS(strcat(temp, "cc"),      temp);
        TEST_ASSERT_EQUALS(strcmp(temp, "aabbbcc"), 0);

        TEST_ASSERT_EQUALS(strcat(temp, "dddd"),        temp);
        TEST_ASSERT_EQUALS(strcmp(temp, "aabbbccdddd"), 0);
    }
    TEST_CASE_END();



    TEST_CASE("strcat()");
    {
        char16 temp[15];
        memzero(temp, sizeof(temp));

        TEST_ASSERT_EQUALS(strcat(temp, u"aa"), temp);
        TEST_ASSERT_EQUALS(strcmp(temp, u"aa"), 0);

        TEST_ASSERT_EQUALS(strcat(temp, u"bbb"),   temp);
        TEST_ASSERT_EQUALS(strcmp(temp, u"aabbb"), 0);

        TEST_ASSERT_EQUALS(strcat(temp, u"cc"),      temp);
        TEST_ASSERT_EQUALS(strcmp(temp, u"aabbbcc"), 0);

        TEST_ASSERT_EQUALS(strcat(temp, u"dddd"),        temp);
        TEST_ASSERT_EQUALS(strcmp(temp, u"aabbbccdddd"), 0);
    }
    TEST_CASE_END();



    TEST_CASE("strapp()");
    {
        char8 temp[15];
        memzero(temp, sizeof(temp));

        char8 *cur = &temp[0];



        cur = strapp(cur, "aa");

        TEST_ASSERT_EQUALS(cur,                temp + 2);
        TEST_ASSERT_EQUALS(strcmp(temp, "aa"), 0);



        cur = strapp(cur, "bbb");

        TEST_ASSERT_EQUALS(cur,                   temp + 5);
        TEST_ASSERT_EQUALS(strcmp(temp, "aabbb"), 0);



        cur = strapp(cur, "cc");

        TEST_ASSERT_EQUALS(cur,                     temp + 7);
        TEST_ASSERT_EQUALS(strcmp(temp, "aabbbcc"), 0);



        cur = strapp(cur, "dddd");

        TEST_ASSERT_EQUALS(cur,                         temp + 11);
        TEST_ASSERT_EQUALS(strcmp(temp, "aabbbccdddd"), 0);
    }
    TEST_CASE_END();



    TEST_CASE("strapp()");
    {
        char16 temp[15];
        memzero(temp, sizeof(temp));

        char16 *cur = &temp[0];



        cur = strapp(cur, u"aa");

        TEST_ASSERT_EQUALS(cur,                 temp + 2);
        TEST_ASSERT_EQUALS(strcmp(temp, u"aa"), 0);



        cur = strapp(cur, u"bbb");

        TEST_ASSERT_EQUALS(cur,                    temp + 5);
        TEST_ASSERT_EQUALS(strcmp(temp, u"aabbb"), 0);



        cur = strapp(cur, u"cc");

        TEST_ASSERT_EQUALS(cur,                      temp + 7);
        TEST_ASSERT_EQUALS(strcmp(temp, u"aabbbcc"), 0);



        cur = strapp(cur, u"dddd");

        TEST_ASSERT_EQUALS(cur,                          temp + 11);
        TEST_ASSERT_EQUALS(strcmp(temp, u"aabbbccdddd"), 0);
    }
    TEST_CASE_END();



    TEST_CASE("strend()");
    {
        TEST_ASSERT_EQUALS(strend("abcaa", "aa"),      true);
        TEST_ASSERT_EQUALS(strend("abcaa", "ab"),      false);
        TEST_ASSERT_EQUALS(strend("abcaa", ""),        true);
        TEST_ASSERT_EQUALS(strend("abcaa", "dsfggaa"), false);
        TEST_ASSERT_EQUALS(strend("abcaa", "a"),       true);
        TEST_ASSERT_EQUALS(strend("abcaa", "caa"),     true);
        TEST_ASSERT_EQUALS(strend("abcaa", "cab"),     false);
        TEST_ASSERT_EQUALS(strend("abcaa", "abcaa"),   true);
    }
    TEST_CASE_END();



    TEST_CASE("strend()");
    {
        TEST_ASSERT_EQUALS(strend(u"abcaa", u"aa"),      true);
        TEST_ASSERT_EQUALS(strend(u"abcaa", u"ab"),      false);
        TEST_ASSERT_EQUALS(strend(u"abcaa", u""),        true);
        TEST_ASSERT_EQUALS(strend(u"abcaa", u"dsfggaa"), false);
        TEST_ASSERT_EQUALS(strend(u"abcaa", u"a"),       true);
        TEST_ASSERT_EQUALS(strend(u"abcaa", u"caa"),     true);
        TEST_ASSERT_EQUALS(strend(u"abcaa", u"cab"),     false);
        TEST_ASSERT_EQUALS(strend(u"abcaa", u"abcaa"),   true);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_STRING_STRING_H
