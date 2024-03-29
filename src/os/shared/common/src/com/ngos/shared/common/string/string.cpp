#include "string.h"

#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/memory/malloc.h>
#include <com/ngos/shared/common/memory/memory.h>



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

    COMMON_ASSERT(str1, "str1 is null", nullptr);
    COMMON_ASSERT(str2, "str2 is null", nullptr);



    char8 *cur = str1;

    do
    {
        char8 ch = *str2;

        if (ch == 0)
        {
            break;
        }

        *cur = ch;

        ++cur;
        ++str2;
    } while(true);

    *cur = 0;



    return str1;
}

char16* strcpy(char16 *str1, const char16 *str2)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p", str1, str2));

    COMMON_ASSERT(str1, "str1 is null", nullptr);
    COMMON_ASSERT(str2, "str2 is null", nullptr);



    char16 *cur = str1;

    do
    {
        char16 ch = *str2;

        if (ch == 0)
        {
            break;
        }

        *cur = ch;

        ++cur;
        ++str2;
    } while(true);

    *cur = 0;



    return str1;
}

char8* strdup(const char8 *str)
{
    COMMON_LT((" | str = 0x%p", str));

    COMMON_ASSERT(str, "str is null", nullptr);



    u64 size = (strlen(str) + 1) * sizeof(char8);

    char8 *res = (char8 *)malloc(size);
    COMMON_TEST_ASSERT(res != nullptr, nullptr);

    memcpy(res, str, size);



    return res;
}

char16* strdup(const char16 *str)
{
    COMMON_LT((" | str = 0x%p", str));

    COMMON_ASSERT(str, "str is null", nullptr);



    u64 size = (strlen(str) + 1) * sizeof(char16);

    char16 *res = (char16 *)malloc(size);
    COMMON_TEST_ASSERT(res != nullptr, nullptr);

    memcpy(res, str, size);



    return res;
}

char8* strcat(char8 *str1, const char8 *str2)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p", str1, str2));

    COMMON_ASSERT(str1, "str1 is null", nullptr);
    COMMON_ASSERT(str2, "str2 is null", nullptr);



    char8 *cur = str1;

    while (*cur != 0)
    {
        ++cur;
    }



    do
    {
        char8 ch = *str2;

        if (ch == 0)
        {
            break;
        }

        *cur = ch;

        ++cur;
        ++str2;
    } while(true);

    *cur = 0;



    return str1;
}

char16* strcat(char16 *str1, const char16 *str2)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p", str1, str2));

    COMMON_ASSERT(str1, "str1 is null", nullptr);
    COMMON_ASSERT(str2, "str2 is null", nullptr);



    char16 *cur = str1;

    while (*cur != 0)
    {
        ++cur;
    }



    do
    {
        char16 ch = *str2;

        if (ch == 0)
        {
            break;
        }

        *cur = ch;

        ++cur;
        ++str2;
    } while(true);

    *cur = 0;



    return str1;
}

char8* strapp(char8 *str1, const char8 *str2)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p", str1, str2));

    COMMON_ASSERT(str1,       "str1 is null",    nullptr);
    COMMON_ASSERT(str2,       "str2 is null",    nullptr);
    COMMON_ASSERT(*str1 == 0, "str1 is invalid", nullptr);



    char8 *cur = str1;

    do
    {
        char8 ch = *str2;

        if (ch == 0)
        {
            break;
        }

        *cur = ch;

        ++cur;
        ++str2;
    } while(true);

    *cur = 0;



    return cur;
}

char16* strapp(char16 *str1, const char16 *str2)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p", str1, str2));

    COMMON_ASSERT(str1,       "str1 is null",    nullptr);
    COMMON_ASSERT(str2,       "str2 is null",    nullptr);
    COMMON_ASSERT(*str1 == 0, "str1 is invalid", nullptr);



    char16 *cur = str1;

    do
    {
        char16 ch = *str2;

        if (ch == 0)
        {
            break;
        }

        *cur = ch;

        ++cur;
        ++str2;
    } while(true);

    *cur = 0;



    return cur;
}

i64 strlen(const char8 *str)
{
    COMMON_LT((" | str = 0x%p", str));

    COMMON_ASSERT(str, "str is null", -1);



    const char8 *str2 = str;

    while (*str2 != 0)
    {
        ++str2;
    }

    return str2 - str;
}

i64 strlen(const char16 *str)
{
    COMMON_LT((" | str = 0x%p", str));

    COMMON_ASSERT(str, "str is null", -1);



    const char16 *str2 = str;

    while (*str2 != 0)
    {
        ++str2;
    }

    return str2 - str;
}

i64 strnlen(const char8 *str, i64 maxlen)
{
    // COMMON_LT((" | str = 0x%p, maxlen = %d", str, maxlen)); // Commented to avoid bad looking logs

    COMMON_ASSERT(str, "str is null", -1);



    const char8 *str2 = str;

    while (*str2 != 0 && maxlen != 0)
    {
        ++str2;
        --maxlen;
    }

    return str2 - str;
}

i64 strnlen(const char16 *str, i64 maxlen)
{
    // COMMON_LT((" | str = 0x%p, maxlen = %d", str, maxlen)); // Commented to avoid bad looking logs

    COMMON_ASSERT(str, "str is null", -1);



    const char16 *str2 = str;

    while (*str2 != 0 && maxlen != 0)
    {
        ++str2;
        --maxlen;
    }

    return str2 - str;
}

i8 strcmp(const char8 *str1, const char8 *str2)
{
    // COMMON_LT((" | str1 = 0x%p, str2 = 0x%p", str1, str2)); // Commented to avoid too frequent logs

    COMMON_ASSERT(str1, "str1 is null", -1);
    COMMON_ASSERT(str2, "str2 is null", -1);



    if (str1 == str2)
    {
        return 0;
    }



    do
    {
        char8 c1 = *str1;
        char8 c2 = *str2;

        if (c1 != c2)
        {
            return c1 < c2 ? -1 : 1;
        }

        if (c1 == 0)
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

    COMMON_ASSERT(str1, "str1 is null", -1);
    COMMON_ASSERT(str2, "str2 is null", -1);



    if (str1 == str2)
    {
        return 0;
    }



    do
    {
        char16 c1 = *str1;
        char16 c2 = *str2;

        if (c1 != c2)
        {
            return c1 < c2 ? -1 : 1;
        }

        if (c1 == 0)
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

    COMMON_ASSERT(str1, "str1 is null", -1);
    COMMON_ASSERT(str2, "str2 is null", -1);



    if (str1 == str2)
    {
        return 0;
    }



    do
    {
        char8 c1 = *str1;
        char8 c2 = *str2;

        if (c1 != c2)
        {
            c1 = toLower(c1);
            c2 = toLower(c2);

            if (c1 != c2)
            {
                return c1 < c2 ? -1 : 1;
            }
        }

        if (c1 == 0)
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

    COMMON_ASSERT(str1, "str1 is null", -1);
    COMMON_ASSERT(str2, "str2 is null", -1);



    if (str1 == str2)
    {
        return 0;
    }



    do
    {
        char16 c1 = *str1;
        char16 c2 = *str2;

        if (c1 != c2)
        {
            c1 = toLower(c1);
            c2 = toLower(c2);

            if (c1 != c2)
            {
                return c1 < c2 ? -1 : 1;
            }
        }

        if (c1 == 0)
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

    COMMON_ASSERT(str1, "str1 is null", -1);
    COMMON_ASSERT(str2, "str2 is null", -1);



    if (str1 == str2)
    {
        return 0;
    }



    while (length != 0)
    {
        char8 c1 = *str1;
        char8 c2 = *str2;

        if (c1 != c2)
        {
            return c1 < c2 ? -1 : 1;
        }

        if (c1 == 0)
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

    COMMON_ASSERT(str1, "str1 is null", -1);
    COMMON_ASSERT(str2, "str2 is null", -1);



    if (str1 == str2)
    {
        return 0;
    }



    while (length != 0)
    {
        char16 c1 = *str1;
        char16 c2 = *str2;

        if (c1 != c2)
        {
            return c1 < c2 ? -1 : 1;
        }

        if (c1 == 0)
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

    COMMON_ASSERT(str1, "str1 is null", -1);
    COMMON_ASSERT(str2, "str2 is null", -1);



    if (str1 == str2)
    {
        return 0;
    }



    while (length != 0)
    {
        char8 c1 = *str1;
        char8 c2 = *str2;

        if (c1 != c2)
        {
            c1 = toLower(c1);
            c2 = toLower(c2);

            if (c1 != c2)
            {
                return c1 < c2 ? -1 : 1;
            }
        }

        if (c1 == 0)
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

    COMMON_ASSERT(str1, "str1 is null", -1);
    COMMON_ASSERT(str2, "str2 is null", -1);



    if (str1 == str2)
    {
        return 0;
    }



    while (length != 0)
    {
        char16 c1 = *str1;
        char16 c2 = *str2;

        if (c1 != c2)
        {
            c1 = toLower(c1);
            c2 = toLower(c2);

            if (c1 != c2)
            {
                return c1 < c2 ? -1 : 1;
            }
        }

        if (c1 == 0)
        {
            break;
        }

        ++str1;
        ++str2;
        --length;
    }



    return 0;
}

bool strequal(const char8 *str1, const char8 *str2)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p", str1, str2));

    COMMON_ASSERT(str1, "str1 is null", false);
    COMMON_ASSERT(str2, "str2 is null", false);



    return strcmp(str1, str2) == 0;
}

bool strequal(const char16 *str1, const char16 *str2)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p", str1, str2));

    COMMON_ASSERT(str1, "str1 is null", false);
    COMMON_ASSERT(str2, "str2 is null", false);



    return strcmp(str1, str2) == 0;
}

bool strequali(const char8 *str1, const char8 *str2)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p", str1, str2));

    COMMON_ASSERT(str1, "str1 is null", false);
    COMMON_ASSERT(str2, "str2 is null", false);



    return strcmpi(str1, str2) == 0;
}

bool strequali(const char16 *str1, const char16 *str2)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p", str1, str2));

    COMMON_ASSERT(str1, "str1 is null", false);
    COMMON_ASSERT(str2, "str2 is null", false);



    return strcmpi(str1, str2) == 0;
}

bool strnequal(const char8 *str1, const char8 *str2, i64 length)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p, length = %d", str1, str2, length));

    COMMON_ASSERT(str1, "str1 is null", 0);
    COMMON_ASSERT(str2, "str2 is null", 0);



    return strncmp(str1, str2, length) == 0;
}

bool strnequal(const char16 *str1, const char16 *str2, i64 length)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p, length = %d", str1, str2, length));

    COMMON_ASSERT(str1, "str1 is null", 0);
    COMMON_ASSERT(str2, "str2 is null", 0);



    return strncmp(str1, str2, length) == 0;
}

bool strnequali(const char8 *str1, const char8 *str2, i64 length)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p, length = %d", str1, str2, length));

    COMMON_ASSERT(str1, "str1 is null", 0);
    COMMON_ASSERT(str2, "str2 is null", 0);



    return strncmpi(str1, str2, length) == 0;
}

bool strnequali(const char16 *str1, const char16 *str2, i64 length)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p, length = %d", str1, str2, length));

    COMMON_ASSERT(str1, "str1 is null", 0);
    COMMON_ASSERT(str2, "str2 is null", 0);



    return strncmpi(str1, str2, length) == 0;
}

const char8* strstr(const char8 *str1, const char8 *str2)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p", str1, str2));

    COMMON_ASSERT(str1, "str1 is null", nullptr);
    COMMON_ASSERT(str2, "str2 is null", nullptr);



    if (str1 == str2)
    {
        return str1;
    }



    char8 c2 = *str2;

    if (c2 == 0)
    {
        return str1;
    }



    do
    {
        char8 c1 = *str1;

        if (c1 == 0)
        {
            return nullptr;
        }



        if (c1 == c2)
        {
            const char8 *cur1 = &str1[1];
            const char8 *cur2 = &str2[1];

            do
            {
                char8 ch2 = *cur2;

                if (ch2 == 0)
                {
                    return str1;
                }



                char8 ch1 = *cur1;

                if (ch1 == 0)
                {
                    return nullptr;
                }



                if (ch1 != ch2)
                {
                    break;
                }



                ++cur1;
                ++cur2;
            } while(true);
        }



        ++str1;
    } while(true);
}

const char16* strstr(const char16 *str1, const char16 *str2)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p", str1, str2));

    COMMON_ASSERT(str1, "str1 is null", nullptr);
    COMMON_ASSERT(str2, "str2 is null", nullptr);



    if (str1 == str2)
    {
        return str1;
    }



    char16 c2 = *str2;

    if (c2 == 0)
    {
        return str1;
    }



    do
    {
        char16 c1 = *str1;

        if (c1 == 0)
        {
            return nullptr;
        }



        if (c1 == c2)
        {
            const char16 *cur1 = &str1[1];
            const char16 *cur2 = &str2[1];

            do
            {
                char16 ch2 = *cur2;

                if (ch2 == 0)
                {
                    return str1;
                }



                char16 ch1 = *cur1;

                if (ch1 == 0)
                {
                    return nullptr;
                }



                if (ch1 != ch2)
                {
                    break;
                }



                ++cur1;
                ++cur2;
            } while(true);
        }



        ++str1;
    } while(true);
}

const char8* strstri(const char8 *str1, const char8 *str2)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p", str1, str2));

    COMMON_ASSERT(str1, "str1 is null", nullptr);
    COMMON_ASSERT(str2, "str2 is null", nullptr);



    if (str1 == str2)
    {
        return str1;
    }



    char8 c2 = *str2;

    if (c2 == 0)
    {
        return str1;
    }

    c2 = toLower(c2);



    do
    {
        char8 c1 = *str1;

        if (c1 == 0)
        {
            return nullptr;
        }



        if (c1 != c2)
        {
            c1 = toLower(c1);
        }



        if (c1 == c2)
        {
            const char8 *cur1 = &str1[1];
            const char8 *cur2 = &str2[1];

            do
            {
                char8 ch2 = *cur2;

                if (ch2 == 0)
                {
                    return str1;
                }



                char8 ch1 = *cur1;

                if (ch1 == 0)
                {
                    return nullptr;
                }



                if (ch1 != ch2)
                {
                    ch1 = toLower(ch1);
                    ch2 = toLower(ch2);
                }

                if (ch1 != ch2)
                {
                    break;
                }



                ++cur1;
                ++cur2;
            } while(true);
        }



        ++str1;
    } while(true);
}

const char16* strstri(const char16 *str1, const char16 *str2)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p", str1, str2));

    COMMON_ASSERT(str1, "str1 is null", nullptr);
    COMMON_ASSERT(str2, "str2 is null", nullptr);



    if (str1 == str2)
    {
        return str1;
    }



    char16 c2 = *str2;

    if (c2 == 0)
    {
        return str1;
    }

    c2 = toLower(c2);



    do
    {
        char16 c1 = *str1;

        if (c1 == 0)
        {
            return nullptr;
        }



        if (c1 != c2)
        {
            c1 = toLower(c1);
        }



        if (c1 == c2)
        {
            const char16 *cur1 = &str1[1];
            const char16 *cur2 = &str2[1];

            do
            {
                char16 ch2 = *cur2;

                if (ch2 == 0)
                {
                    return str1;
                }



                char16 ch1 = *cur1;

                if (ch1 == 0)
                {
                    return nullptr;
                }



                if (ch1 != ch2)
                {
                    ch1 = toLower(ch1);
                    ch2 = toLower(ch2);
                }

                if (ch1 != ch2)
                {
                    break;
                }



                ++cur1;
                ++cur2;
            } while(true);
        }



        ++str1;
    } while(true);
}

bool strend(const char8 *str1, const char8 *str2)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p", str1, str2));

    COMMON_ASSERT(str1, "str1 is null", false);
    COMMON_ASSERT(str2, "str2 is null", false);



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

    COMMON_ASSERT(str1, "str1 is null", false);
    COMMON_ASSERT(str2, "str2 is null", false);



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

    COMMON_ASSERT(str1, "str1 is null", false);
    COMMON_ASSERT(str2, "str2 is null", false);



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
            char8 ch1 = *str1;
            char8 ch2 = *str2;

            if (
                ch1 != ch2
                &&
                toLower(ch1) != toLower(ch2)
               )
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

    COMMON_ASSERT(str1, "str1 is null", false);
    COMMON_ASSERT(str2, "str2 is null", false);



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
            char16 ch1 = *str1;
            char16 ch2 = *str2;

            if (
                ch1 != ch2
                &&
                toLower(ch1) != toLower(ch2)
               )
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
