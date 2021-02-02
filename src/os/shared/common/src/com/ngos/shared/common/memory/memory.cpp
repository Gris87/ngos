#include "memory.h"

#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>



bad_int8 memcmp(const void *str1, const void *str2, bad_int64 length)
{
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p, length = %d", str1, str2, length));

    COMMON_ASSERT(str1, "str1 is null", 0);
    COMMON_ASSERT(str2, "str2 is null", 0);



    if (str1 == str2)
    {
        return 0;
    }



    bad_uint8 *s1 = (bad_uint8 *)str1;
    bad_uint8 *s2 = (bad_uint8 *)str2;

    while (length > 0)
    {
        bad_uint8 c1 = *s1;
        bad_uint8 c2 = *s2;

        if (c1 != c2)
        {
            return c1 < c2 ? -1 : 1;
        }

        ++s1;
        ++s2;
        --length;
    }

    return 0;
}

bool memempty(const void *src, bad_int64 length)
{
    COMMON_LT((" | src = 0x%p, length = %d", src, length));

    COMMON_ASSERT(src, "src is null", false);



    bad_uint8 *s = (bad_uint8 *)src;

    while (length > 0)
    {
        --length;

        if (s[length] != 0)
        {
            return false;
        }
    }

    return true;
}

void* memmove(void *dest, const void *src, bad_int64 length)
{
    COMMON_LT((" | dest = 0x%p, src = 0x%p, length = %d", dest, src, length));

    COMMON_ASSERT(dest, "dest is null", 0);
    COMMON_ASSERT(src,  "src is null",  0);



    if (dest == src)
    {
        return dest;
    }



    bad_uint8 *d = (bad_uint8 *)dest;
    bad_uint8 *s = (bad_uint8 *)src;

    if (d <= s || d - s >= length)
    {
        return memcpy(dest, src, length);
    }

    while (length > 0)
    {
        --length;

        d[length] = s[length];
    }

    return dest;
}
