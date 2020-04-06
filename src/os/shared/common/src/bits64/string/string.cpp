#include "string.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/memory/malloc.h>
#include <common/src/bits64/memory/memory.h>



char8 toLower(char8 ch)
{
    COMMON_LT((" | ch = %c", ch));



    return ch >= 'A' && ch <= 'Z' ? (ch | 0x20) : ch;
}

char16 toLower(char16 ch)
{
    COMMON_LT((" | ch = %c", ch));



    return ch >= u'A' && ch <= u'Z' ? (ch | 0x0020) : ch;
}

char8 toUpper(char8 ch)
{
    COMMON_LT((" | ch = %c", ch));



    return ch >= 'a' && ch <= 'z' ? (ch & ~0x20) : ch;
}

char16 toUpper(char16 ch)
{
    COMMON_LT((" | ch = %c", ch));



    return ch >= u'a' && ch <= u'z' ? (ch & ~0x0020) : ch;
}

char8* strcpy(char8 *str1, const char8 *str2)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p", str1, str2));

    COMMON_ASSERT(str1, "str1 is null", 0);
    COMMON_ASSERT(str2, "str2 is null", 0);



    char8 *cur = str1;

    while (*str2) // *str2 != 0
    {
        *cur = *str2;

        ++cur;
        ++str2;
    }

    *cur = 0;



    return str1;
}

char16* strcpy(char16 *str1, const char16 *str2)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p", str1, str2));

    COMMON_ASSERT(str1, "str1 is null", 0);
    COMMON_ASSERT(str2, "str2 is null", 0);



    char16 *cur = str1;

    while (*str2) // *str2 != 0
    {
        *cur = *str2;

        ++cur;
        ++str2;
    }

    *cur = 0;



    return str1;
}

char8* strdup(const char8 *str)
{
    COMMON_LT((" | str = 0x%p", str));

    COMMON_ASSERT(str, "str is null", 0);



    u64 size = (strlen(str) + 1) * sizeof(char8);

    char8 *res = (char8 *)malloc(size);

    memcpy(res, str, size);



    return res;
}

char16* strdup(const char16 *str)
{
    COMMON_LT((" | str = 0x%p", str));

    COMMON_ASSERT(str, "str is null", 0);



    u64 size = (strlen(str) + 1) * sizeof(char16);

    char16 *res = (char16 *)malloc(size);

    memcpy(res, str, size);



    return res;
}

char8* strcat(char8 *str1, const char8 *str2)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p", str1, str2));

    COMMON_ASSERT(str1, "str1 is null", 0);
    COMMON_ASSERT(str2, "str2 is null", 0);



    char8 *cur = str1;

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

char8* strapp(char8 *str1, const char8 *str2)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p", str1, str2));

    COMMON_ASSERT(str1,       "str1 is null",    0);
    COMMON_ASSERT(str2,       "str2 is null",    0);
    COMMON_ASSERT(*str1 == 0, "str1 is invalid", 0);



    char8 *cur = str1;

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

i64 strlen(const char8 *str)
{
    COMMON_LT((" | str = 0x%p", str));

    COMMON_ASSERT(str, "str is null", 0);



    const char8 *str2 = str;

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

i64 strnlen(const char8 *str, i64 maxlen)
{
    // COMMON_LT((" | str = 0x%p, maxlen = %d", str, maxlen)); // Commented to avoid bad looking logs

    COMMON_ASSERT(str, "str is null", 0);



    const char8 *str2 = str;

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

i8 strcmp(const char8 *str1, const char8 *str2)
{
    // COMMON_LT((" | str1 = 0x%p, str2 = 0x%p", str1, str2)); // Commented to avoid too frequent logs

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

i8 strcmp(const char16 *str1, const char16 *str2)
{
    // COMMON_LT((" | str1 = 0x%p, str2 = 0x%p", str1, str2)); // Commented to avoid too frequent logs

    COMMON_ASSERT(str1, "str1 is null", 0);
    COMMON_ASSERT(str2, "str2 is null", 0);



    if (str1 == str2)
    {
        return 0;
    }



    do
    {
        u16 c1 = *str1;
        u16 c2 = *str2;

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

i8 strcmpi(const char8 *str1, const char8 *str2)
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
        u8 c1 = toLower(*str1);
        u8 c2 = toLower(*str2);

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

i8 strcmpi(const char16 *str1, const char16 *str2)
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
        u16 c1 = toLower(*str1);
        u16 c2 = toLower(*str2);

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

i8 strncmp(const char8 *str1, const char8 *str2, i64 length)
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

i8 strncmp(const char16 *str1, const char16 *str2, i64 length)
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
        u16 c1 = *str1;
        u16 c2 = *str2;

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

i8 strncmpi(const char8 *str1, const char8 *str2, i64 length)
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
        u8 c1 = toLower(*str1);
        u8 c2 = toLower(*str2);

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

i8 strncmpi(const char16 *str1, const char16 *str2, i64 length)
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
        u16 c1 = toLower(*str1);
        u16 c2 = toLower(*str2);

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

bool strend(const char8 *str1, const char8 *str2)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p", str1, str2));

    COMMON_ASSERT(str1, "str1 is null", 0);
    COMMON_ASSERT(str2, "str2 is null", 0);



    if (str1 == str2)
    {
        return true;
    }



    i64 len1 = strlen(str1);
    i64 len2 = strlen(str2);

    if (len2 > len1)
    {
        return false;
    }



    if (len2 > 0)
    {
        str1 = str1 + len1 - 1;
        str2 = str2 + len2 - 1;

        while (len2 > 0)
        {
            if (*str1 != *str2)
            {
                return false;
            }

            --str1;
            --str2;
            --len2;
        }
    }



    return true;
}

bool strend(const char16 *str1, const char16 *str2)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p", str1, str2));

    COMMON_ASSERT(str1, "str1 is null", 0);
    COMMON_ASSERT(str2, "str2 is null", 0);



    if (str1 == str2)
    {
        return true;
    }



    i64 len1 = strlen(str1);
    i64 len2 = strlen(str2);

    if (len2 > len1)
    {
        return false;
    }



    if (len2 > 0)
    {
        str1 = str1 + len1 - 1;
        str2 = str2 + len2 - 1;

        while (len2 > 0)
        {
            if (*str1 != *str2)
            {
                return false;
            }

            --str1;
            --str2;
            --len2;
        }
    }



    return true;
}

bool strendi(const char8 *str1, const char8 *str2)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p", str1, str2));

    COMMON_ASSERT(str1, "str1 is null", 0);
    COMMON_ASSERT(str2, "str2 is null", 0);



    if (str1 == str2)
    {
        return true;
    }



    i64 len1 = strlen(str1);
    i64 len2 = strlen(str2);

    if (len2 > len1)
    {
        return false;
    }



    if (len2 > 0)
    {
        str1 = str1 + len1 - 1;
        str2 = str2 + len2 - 1;

        while (len2 > 0)
        {
            if (toLower(*str1) != toLower(*str2))
            {
                return false;
            }

            --str1;
            --str2;
            --len2;
        }
    }



    return true;
}

bool strendi(const char16 *str1, const char16 *str2)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p", str1, str2));

    COMMON_ASSERT(str1, "str1 is null", 0);
    COMMON_ASSERT(str2, "str2 is null", 0);



    if (str1 == str2)
    {
        return true;
    }



    i64 len1 = strlen(str1);
    i64 len2 = strlen(str2);

    if (len2 > len1)
    {
        return false;
    }



    if (len2 > 0)
    {
        str1 = str1 + len1 - 1;
        str2 = str2 + len2 - 1;

        while (len2 > 0)
        {
            if (toLower(*str1) != toLower(*str2))
            {
                return false;
            }

            --str1;
            --str2;
            --len2;
        }
    }



    return true;
}
