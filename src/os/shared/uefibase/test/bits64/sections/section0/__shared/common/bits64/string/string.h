#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_STRING_STRING_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_STRING_STRING_H



#include <buildconfig.h>
#include <common/src/bits64/memory/memory.h>
#include <common/src/bits64/string/string.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_string_string);
{
    TEST_CASE("toLower()");
    {
        TEST_ASSERT_EQUALS(toLower('A'), 'a');
        TEST_ASSERT_EQUALS(toLower('a'), 'a');
        TEST_ASSERT_EQUALS(toLower('Z'), 'z');
        TEST_ASSERT_EQUALS(toLower('z'), 'z');
        TEST_ASSERT_EQUALS(toLower('G'), 'g');
        TEST_ASSERT_EQUALS(toLower('g'), 'g');
    }
    TEST_CASE_END();



    TEST_CASE("toLower()");
    {
        TEST_ASSERT_EQUALS(toLower(u'A'), u'a');
        TEST_ASSERT_EQUALS(toLower(u'a'), u'a');
        TEST_ASSERT_EQUALS(toLower(u'Z'), u'z');
        TEST_ASSERT_EQUALS(toLower(u'z'), u'z');
        TEST_ASSERT_EQUALS(toLower(u'G'), u'g');
        TEST_ASSERT_EQUALS(toLower(u'g'), u'g');
    }
    TEST_CASE_END();



    TEST_CASE("toUpper()");
    {
        TEST_ASSERT_EQUALS(toUpper('A'), 'A');
        TEST_ASSERT_EQUALS(toUpper('a'), 'A');
        TEST_ASSERT_EQUALS(toUpper('Z'), 'Z');
        TEST_ASSERT_EQUALS(toUpper('z'), 'Z');
        TEST_ASSERT_EQUALS(toUpper('G'), 'G');
        TEST_ASSERT_EQUALS(toUpper('g'), 'G');
    }
    TEST_CASE_END();



    TEST_CASE("toUpper()");
    {
        TEST_ASSERT_EQUALS(toUpper(u'A'), u'A');
        TEST_ASSERT_EQUALS(toUpper(u'a'), u'A');
        TEST_ASSERT_EQUALS(toUpper(u'Z'), u'Z');
        TEST_ASSERT_EQUALS(toUpper(u'z'), u'Z');
        TEST_ASSERT_EQUALS(toUpper(u'G'), u'G');
        TEST_ASSERT_EQUALS(toUpper(u'g'), u'G');
    }
    TEST_CASE_END();



    TEST_CASE("strcpy()");
    {
        char8 temp[15];
        memzero(temp, sizeof(temp));

        TEST_ASSERT_EQUALS(strcpy(temp, "aa"), temp);
        TEST_ASSERT_EQUALS(strcmp(temp, "aa"), 0);

        TEST_ASSERT_EQUALS(strcpy(temp, "bbb"), temp);
        TEST_ASSERT_EQUALS(strcmp(temp, "bbb"), 0);

        TEST_ASSERT_EQUALS(strcpy(temp, "cc"), temp);
        TEST_ASSERT_EQUALS(strcmp(temp, "cc"), 0);

        TEST_ASSERT_EQUALS(strcpy(temp, "dddd"), temp);
        TEST_ASSERT_EQUALS(strcmp(temp, "dddd"), 0);
    }
    TEST_CASE_END();



    TEST_CASE("strcpy()");
    {
        char16 temp[15];
        memzero(temp, sizeof(temp));

        TEST_ASSERT_EQUALS(strcpy(temp, u"aa"), temp);
        TEST_ASSERT_EQUALS(strcmp(temp, u"aa"), 0);

        TEST_ASSERT_EQUALS(strcpy(temp, u"bbb"), temp);
        TEST_ASSERT_EQUALS(strcmp(temp, u"bbb"), 0);

        TEST_ASSERT_EQUALS(strcpy(temp, u"cc"), temp);
        TEST_ASSERT_EQUALS(strcmp(temp, u"cc"), 0);

        TEST_ASSERT_EQUALS(strcpy(temp, u"dddd"), temp);
        TEST_ASSERT_EQUALS(strcmp(temp, u"dddd"), 0);
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

        TEST_ASSERT_EQUALS(cur,                &temp[2]);
        TEST_ASSERT_EQUALS(strcmp(temp, "aa"),  0);



        cur = strapp(cur, "bbb");

        TEST_ASSERT_EQUALS(cur,                   &temp[5]);
        TEST_ASSERT_EQUALS(strcmp(temp, "aabbb"),  0);



        cur = strapp(cur, "cc");

        TEST_ASSERT_EQUALS(cur,                     &temp[7]);
        TEST_ASSERT_EQUALS(strcmp(temp, "aabbbcc"),  0);



        cur = strapp(cur, "dddd");

        TEST_ASSERT_EQUALS(cur,                         &temp[11]);
        TEST_ASSERT_EQUALS(strcmp(temp, "aabbbccdddd"),  0);
    }
    TEST_CASE_END();



    TEST_CASE("strapp()");
    {
        char16 temp[15];
        memzero(temp, sizeof(temp));

        char16 *cur = &temp[0];



        cur = strapp(cur, u"aa");

        TEST_ASSERT_EQUALS(cur,                 &temp[2]);
        TEST_ASSERT_EQUALS(strcmp(temp, u"aa"),  0);



        cur = strapp(cur, u"bbb");

        TEST_ASSERT_EQUALS(cur,                    &temp[5]);
        TEST_ASSERT_EQUALS(strcmp(temp, u"aabbb"),  0);



        cur = strapp(cur, u"cc");

        TEST_ASSERT_EQUALS(cur,                      &temp[7]);
        TEST_ASSERT_EQUALS(strcmp(temp, u"aabbbcc"),  0);



        cur = strapp(cur, u"dddd");

        TEST_ASSERT_EQUALS(cur,                          &temp[11]);
        TEST_ASSERT_EQUALS(strcmp(temp, u"aabbbccdddd"),  0);
    }
    TEST_CASE_END();



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
        TEST_ASSERT_EQUALS(strcmp("abcdef", "abc"),    1);
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
        TEST_ASSERT_EQUALS(strcmp(u"abcdef", u"abc"),    1);
    }
    TEST_CASE_END();



    TEST_CASE("strcmpi()");
    {
        TEST_ASSERT_EQUALS(strcmpi("Aa", "aA"), 0);
        TEST_ASSERT_EQUALS(strcmpi("aA", "ab"), -1);
        TEST_ASSERT_EQUALS(strcmpi("ab", "aA"), 1);

        TEST_ASSERT_EQUALS(strcmpi("AbCdEf", "abcdef"), 0);
        TEST_ASSERT_EQUALS(strcmpi("AbCdEf", "abcdeh"), -1);
        TEST_ASSERT_EQUALS(strcmpi("abcdeh", "AbCdEf"), 1);
        TEST_ASSERT_EQUALS(strcmpi("abc",    "AbCdEf"), -1);
        TEST_ASSERT_EQUALS(strcmpi("AbCdEf", "abc"),    1);
    }
    TEST_CASE_END();



    TEST_CASE("strcmpi()");
    {
        TEST_ASSERT_EQUALS(strcmpi(u"Aa", u"aA"), 0);
        TEST_ASSERT_EQUALS(strcmpi(u"aA", u"ab"), -1);
        TEST_ASSERT_EQUALS(strcmpi(u"ab", u"aA"), 1);

        TEST_ASSERT_EQUALS(strcmpi(u"AbCdEf", u"abcdef"), 0);
        TEST_ASSERT_EQUALS(strcmpi(u"AbCdEf", u"abcdeh"), -1);
        TEST_ASSERT_EQUALS(strcmpi(u"abcdeh", u"AbCdEf"), 1);
        TEST_ASSERT_EQUALS(strcmpi(u"abc",    u"AbCdEf"), -1);
        TEST_ASSERT_EQUALS(strcmpi(u"AbCdEf", u"abc"),    1);
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
        TEST_ASSERT_EQUALS(strncmp("abcdef", "abc",    -1), 1);

        TEST_ASSERT_EQUALS(strncmp("abcdef", "abc",  3), 0);
        TEST_ASSERT_EQUALS(strncmp("abcdef", "abcf", 3), 0);
        TEST_ASSERT_EQUALS(strncmp("abcdef", "abd",  3), -1);
        TEST_ASSERT_EQUALS(strncmp("abcdef", "abb",  3), 1);
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
        TEST_ASSERT_EQUALS(strncmp(u"abcdef", u"abc",    -1), 1);

        TEST_ASSERT_EQUALS(strncmp(u"abcdef", u"abc",  3), 0);
        TEST_ASSERT_EQUALS(strncmp(u"abcdef", u"abcf", 3), 0);
        TEST_ASSERT_EQUALS(strncmp(u"abcdef", u"abd",  3), -1);
        TEST_ASSERT_EQUALS(strncmp(u"abcdef", u"abb",  3), 1);
    }
    TEST_CASE_END();



    TEST_CASE("strncmpi()");
    {
        TEST_ASSERT_EQUALS(strncmpi("Aa", "aA", -1), 0);
        TEST_ASSERT_EQUALS(strncmpi("aA", "ab", -1), -1);
        TEST_ASSERT_EQUALS(strncmpi("ab", "aA", -1), 1);

        TEST_ASSERT_EQUALS(strncmpi("AbCdEf", "abcdef", -1), 0);
        TEST_ASSERT_EQUALS(strncmpi("AbCdEf", "abcdeh", -1), -1);
        TEST_ASSERT_EQUALS(strncmpi("abcdeh", "AbCdEf", -1), 1);
        TEST_ASSERT_EQUALS(strncmpi("abc",    "AbCdEf", -1), -1);
        TEST_ASSERT_EQUALS(strncmpi("AbCdEf", "abc",    -1), 1);

        TEST_ASSERT_EQUALS(strncmpi("AbCdEf", "abc",  3), 0);
        TEST_ASSERT_EQUALS(strncmpi("AbCdEf", "abcf", 3), 0);
        TEST_ASSERT_EQUALS(strncmpi("AbCdEf", "abd",  3), -1);
        TEST_ASSERT_EQUALS(strncmpi("AbCdEf", "abb",  3), 1);
    }
    TEST_CASE_END();



    TEST_CASE("strncmpi()");
    {
        TEST_ASSERT_EQUALS(strncmpi(u"Aa", u"aA", -1), 0);
        TEST_ASSERT_EQUALS(strncmpi(u"aA", u"ab", -1), -1);
        TEST_ASSERT_EQUALS(strncmpi(u"ab", u"aA", -1), 1);

        TEST_ASSERT_EQUALS(strncmpi(u"AbCdEf", u"abcdef", -1), 0);
        TEST_ASSERT_EQUALS(strncmpi(u"AbCdEf", u"abcdeh", -1), -1);
        TEST_ASSERT_EQUALS(strncmpi(u"abcdeh", u"AbCdEf", -1), 1);
        TEST_ASSERT_EQUALS(strncmpi(u"abc",    u"AbCdEf", -1), -1);
        TEST_ASSERT_EQUALS(strncmpi(u"AbCdEf", u"abc",    -1), 1);

        TEST_ASSERT_EQUALS(strncmpi(u"AbCdEf", u"abc",  3), 0);
        TEST_ASSERT_EQUALS(strncmpi(u"AbCdEf", u"abcf", 3), 0);
        TEST_ASSERT_EQUALS(strncmpi(u"AbCdEf", u"abd",  3), -1);
        TEST_ASSERT_EQUALS(strncmpi(u"abcdeg", u"abb",  3), 1);
    }
    TEST_CASE_END();



    TEST_CASE("strstr()");
    {
        const char8 *str = "aaabbcd";

        TEST_ASSERT_EQUALS(strstr(str, "aaabbcd"), &str[0]);
        TEST_ASSERT_EQUALS(strstr(str, ""),        &str[0]);
        TEST_ASSERT_EQUALS(strstr(str, "aa"),      &str[0]);
        TEST_ASSERT_EQUALS(strstr(str, "aab"),     &str[1]);
        TEST_ASSERT_EQUALS(strstr(str, "ab"),      &str[2]);
        TEST_ASSERT_EQUALS(strstr(str, "dsfggaa"),  nullptr);
        TEST_ASSERT_EQUALS(strstr(str, "bc"),      &str[4]);
    }
    TEST_CASE_END();



    TEST_CASE("strstr()");
    {
        const char16 *str = u"aaabbcd";

        TEST_ASSERT_EQUALS(strstr(str, u"aaabbcd"), &str[0]);
        TEST_ASSERT_EQUALS(strstr(str, u""),        &str[0]);
        TEST_ASSERT_EQUALS(strstr(str, u"aa"),      &str[0]);
        TEST_ASSERT_EQUALS(strstr(str, u"aab"),     &str[1]);
        TEST_ASSERT_EQUALS(strstr(str, u"ab"),      &str[2]);
        TEST_ASSERT_EQUALS(strstr(str, u"dsfggaa"),  nullptr);
        TEST_ASSERT_EQUALS(strstr(str, u"bc"),      &str[4]);
    }
    TEST_CASE_END();



    TEST_CASE("strstri()");
    {
        const char8 *str = "aAaBBCd";

        TEST_ASSERT_EQUALS(strstri(str, "aAaBBCd"), &str[0]);
        TEST_ASSERT_EQUALS(strstri(str, "aaabbcd"), &str[0]);
        TEST_ASSERT_EQUALS(strstri(str, ""),        &str[0]);
        TEST_ASSERT_EQUALS(strstri(str, "aA"),      &str[0]);
        TEST_ASSERT_EQUALS(strstri(str, "aAb"),     &str[1]);
        TEST_ASSERT_EQUALS(strstri(str, "Ab"),      &str[2]);
        TEST_ASSERT_EQUALS(strstri(str, "dsfggaa"),  nullptr);
        TEST_ASSERT_EQUALS(strstri(str, "bc"),      &str[4]);
    }
    TEST_CASE_END();



    TEST_CASE("strstri()");
    {
        const char16 *str = u"aAaBBCd";

        TEST_ASSERT_EQUALS(strstri(str, u"aAaBBCd"), &str[0]);
        TEST_ASSERT_EQUALS(strstri(str, u"aaabbcd"), &str[0]);
        TEST_ASSERT_EQUALS(strstri(str, u""),        &str[0]);
        TEST_ASSERT_EQUALS(strstri(str, u"aA"),      &str[0]);
        TEST_ASSERT_EQUALS(strstri(str, u"aAb"),     &str[1]);
        TEST_ASSERT_EQUALS(strstri(str, u"Ab"),      &str[2]);
        TEST_ASSERT_EQUALS(strstri(str, u"dsfggaa"),  nullptr);
        TEST_ASSERT_EQUALS(strstri(str, u"bc"),      &str[4]);
    }
    TEST_CASE_END();



    TEST_CASE("strend()");
    {
        TEST_ASSERT_EQUALS(strend("abcaa", "abcaa"),   true);
        TEST_ASSERT_EQUALS(strend("abcaa", ""),        true);
        TEST_ASSERT_EQUALS(strend("abcaa", "dsfggaa"), false);
        TEST_ASSERT_EQUALS(strend("abcaa", "aa"),      true);
        TEST_ASSERT_EQUALS(strend("abcaa", "ab"),      false);
        TEST_ASSERT_EQUALS(strend("abcaa", "a"),       true); // Ignore CppSingleCharVerifier
        TEST_ASSERT_EQUALS(strend("abcaa", "caa"),     true);
        TEST_ASSERT_EQUALS(strend("abcaa", "cab"),     false);
    }
    TEST_CASE_END();



    TEST_CASE("strend()");
    {
        TEST_ASSERT_EQUALS(strend(u"abcaa", u"abcaa"),   true);
        TEST_ASSERT_EQUALS(strend(u"abcaa", u""),        true);
        TEST_ASSERT_EQUALS(strend(u"abcaa", u"dsfggaa"), false);
        TEST_ASSERT_EQUALS(strend(u"abcaa", u"aa"),      true);
        TEST_ASSERT_EQUALS(strend(u"abcaa", u"ab"),      false);
        TEST_ASSERT_EQUALS(strend(u"abcaa", u"a"),       true); // Ignore CppSingleCharVerifier
        TEST_ASSERT_EQUALS(strend(u"abcaa", u"caa"),     true);
        TEST_ASSERT_EQUALS(strend(u"abcaa", u"cab"),     false);
    }
    TEST_CASE_END();



    TEST_CASE("strendi()");
    {
        TEST_ASSERT_EQUALS(strendi("AbCaA", "AbCaA"),   true);
        TEST_ASSERT_EQUALS(strendi("AbCaA", "abcaa"),   true);
        TEST_ASSERT_EQUALS(strendi("AbCaA", ""),        true);
        TEST_ASSERT_EQUALS(strendi("AbCaA", "dsfggaa"), false);
        TEST_ASSERT_EQUALS(strendi("AbCaA", "Aa"),      true);
        TEST_ASSERT_EQUALS(strendi("AbCaA", "aB"),      false);
        TEST_ASSERT_EQUALS(strendi("AbCaA", "a"),       true); // Ignore CppSingleCharVerifier
        TEST_ASSERT_EQUALS(strendi("AbCaA", "CAa"),     true);
        TEST_ASSERT_EQUALS(strendi("AbCaA", "caB"),     false);
    }
    TEST_CASE_END();



    TEST_CASE("strendi()");
    {
        TEST_ASSERT_EQUALS(strendi(u"AbCaA", u"AbCaA"),   true);
        TEST_ASSERT_EQUALS(strendi(u"AbCaA", u"abcaa"),   true);
        TEST_ASSERT_EQUALS(strendi(u"AbCaA", u""),        true);
        TEST_ASSERT_EQUALS(strendi(u"AbCaA", u"dsfggaa"), false);
        TEST_ASSERT_EQUALS(strendi(u"AbCaA", u"Aa"),      true);
        TEST_ASSERT_EQUALS(strendi(u"AbCaA", u"aB"),      false);
        TEST_ASSERT_EQUALS(strendi(u"AbCaA", u"a"),       true); // Ignore CppSingleCharVerifier
        TEST_ASSERT_EQUALS(strendi(u"AbCaA", u"CAa"),     true);
        TEST_ASSERT_EQUALS(strendi(u"AbCaA", u"caB"),     false);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_STRING_STRING_H
