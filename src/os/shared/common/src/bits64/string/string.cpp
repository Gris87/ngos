#include "string.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



i64 strlen(const char *str)
{
    COMMON_LT((" | str = 0x%p", str));

    COMMON_ASSERT(str, "str is null", 0);



    const char *str2 = str;

    while (*str2) // *str2 != 0
    {
        ++str2;
    }

    return str2 - str;
}

i64 strlen(const char16 *str)
{
    COMMON_LT((" | str = 0x%p", str));

    COMMON_ASSERT(str, "str is null", 0);



    const char16 *str2 = str;

    while (*str2) // *str2 != 0
    {
        ++str2;
    }

    return str2 - str;
}

i64 strnlen(const char *str, i64 maxlen)
{
    // COMMON_LT((" | str = 0x%p, maxlen = %d", str, maxlen)); // Commented to avoid bad looking logs

    COMMON_ASSERT(str, "str is null", 0);



    const char *str2 = str;

    while (*str2 && maxlen) // *str2 != 0 && maxlen != 0
    {
        ++str2;
        --maxlen;
    }

    return str2 - str;
}

i64 strnlen(const char16 *str, i64 maxlen)
{
    // COMMON_LT((" | str = 0x%p, maxlen = %d", str, maxlen)); // Commented to avoid bad looking logs

    COMMON_ASSERT(str, "str is null", 0);



    const char16 *str2 = str;

    while (*str2 && maxlen) // *str2 != 0 && maxlen != 0
    {
        ++str2;
        --maxlen;
    }

    return str2 - str;
}

i8 strcmp(const char *str1, const char *str2)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p", str1, str2));

    COMMON_ASSERT(str1, "str1 is null", 0);
    COMMON_ASSERT(str2, "str2 is null", 0);



    if (str1 == str2)
    {
        return 0;
    }



    do
    {
        u8 c1 = *str1;
        u8 c2 = *str2;

        if (c1 != c2)
        {
            return c1 < c2 ? -1 : 1;
        }

        if (!c1) // c1 == 0
        {
            break;
        }

        ++str1;
        ++str2;
    } while(true);

    return 0;
}

i8 strncmp(const char *str1, const char *str2, i64 length)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p, length = %d", str1, str2, length));

    COMMON_ASSERT(str1, "str1 is null", 0);
    COMMON_ASSERT(str2, "str2 is null", 0);



    if (str1 == str2)
    {
        return 0;
    }



    while (length) // length != 0
    {
        u8 c1 = *str1;
        u8 c2 = *str2;

        if (c1 != c2)
        {
            return c1 < c2 ? -1 : 1;
        }

        if (!c1) // c1 == 0
        {
            break;
        }

        ++str1;
        ++str2;
        --length;
    }

    return 0;
}

char* strcat(char *str1, const char *str2)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p", str1, str2));

    COMMON_ASSERT(str1, "str1 is null", 0);
    COMMON_ASSERT(str2, "str2 is null", 0);



    char *cur = str1;

    while (*cur) // *cur != 0
    {
        ++cur;
    }



    while (*str2) // *str2 != 0
    {
        *cur = *str2;

        ++cur;
        ++str2;
    }

    *cur = 0;



    return str1;
}

char16* strcat(char16 *str1, const char16 *str2)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p", str1, str2));

    COMMON_ASSERT(str1, "str1 is null", 0);
    COMMON_ASSERT(str2, "str2 is null", 0);



    char16 *cur = str1;

    while (*cur) // *cur != 0
    {
        ++cur;
    }



    while (*str2) // *str2 != 0
    {
        *cur = *str2;

        ++cur;
        ++str2;
    }

    *cur = 0;



    return str1;
}

char* strapp(char *str1, const char *str2)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p", str1, str2));

    COMMON_ASSERT(str1,       "str1 is null",    0);
    COMMON_ASSERT(str2,       "str2 is null",    0);
    COMMON_ASSERT(*str1 == 0, "str1 is invalid", 0);



    char *cur = str1;

    while (*str2) // *str2 != 0
    {
        *cur = *str2;

        ++cur;
        ++str2;
    }

    *cur = 0;



    return cur;
}

char16* strapp(char16 *str1, const char16 *str2)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p", str1, str2));

    COMMON_ASSERT(str1,       "str1 is null",    0);
    COMMON_ASSERT(str2,       "str2 is null",    0);
    COMMON_ASSERT(*str1 == 0, "str1 is invalid", 0);



    char16 *cur = str1;

    while (*str2) // *str2 != 0
    {
        *cur = *str2;

        ++cur;
        ++str2;
    }

    *cur = 0;



    return cur;
}
