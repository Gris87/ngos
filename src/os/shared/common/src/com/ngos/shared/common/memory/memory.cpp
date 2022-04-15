#include "memory.h"                                                                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/log/assert.h>                                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/log/log.h>                                                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
good_i8 memcmp(const void *str1, const void *str2, good_i64 length)                                                                                                                                                // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | str1 = 0x%p, str2 = 0x%p, length = %d", str1, str2, length));                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT(str1 != nullptr, "str1 is null", 0);                                                                                                                                                   // Colorize: green
    COMMON_ASSERT(str2 != nullptr, "str2 is null", 0);                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    if (str1 == str2)                                                                                                                                                                                    // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        return 0;                                                                                                                                                                                        // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Iterate over bytes from str1 and str2 and perform comparison                                                                                                                                      // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        const good_u8 *s1 = reinterpret_cast<const good_u8 *>(str1);                                                                                                                                               // Colorize: green
        const good_u8 *s2 = reinterpret_cast<const good_u8 *>(str2);                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        while (length > 0)                                                                                                                                                                               // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            good_u8 c1 = *s1;                                                                                                                                                                                 // Colorize: green
            good_u8 c2 = *s2;                                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (c1 != c2)                                                                                                                                                                                // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                return c1 < c2 ? -1 : 1;                                                                                                                                                                 // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            ++s1;                                                                                                                                                                                        // Colorize: green
            ++s2;                                                                                                                                                                                        // Colorize: green
            --length;                                                                                                                                                                                    // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return 0;                                                                                                                                                                                            // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
bool memempty(const void *src, good_i64 length)                                                                                                                                                               // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | src = 0x%p, length = %d", src, length));                                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT(src != nullptr, "src is null", false);                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Iterate over bytes and check that there are only zeros                                                                                                                                            // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        const good_u8 *s = reinterpret_cast<const good_u8 *>(src);                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        while (length > 0)                                                                                                                                                                               // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            --length;                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (s[length] != 0)                                                                                                                                                                          // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                return false;                                                                                                                                                                            // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return true;                                                                                                                                                                                         // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
void* memmove(void *dest, const void *src, good_i64 length)                                                                                                                                                   // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    COMMON_LT((" | dest = 0x%p, src = 0x%p, length = %d", dest, src, length));                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    COMMON_ASSERT(dest != nullptr, "dest is null", nullptr);                                                                                                                                             // Colorize: green
    COMMON_ASSERT(src  != nullptr, "src is null",  nullptr);                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    if (dest == src)                                                                                                                                                                                     // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        return dest;                                                                                                                                                                                     // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Use memcpy if it possible otherwise move data byte by byte                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        good_u8       *d = reinterpret_cast<good_u8       *>(dest);                                                                                                                                                // Colorize: green
        const good_u8 *s = reinterpret_cast<const good_u8 *>(src);                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (d >= s && d < s + length)                                                                                                                                                                    // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            while (length > 0)                                                                                                                                                                           // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                --length;                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                d[length] = s[length];                                                                                                                                                                   // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        else                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            return memcpy(dest, src, length);                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return dest;                                                                                                                                                                                         // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
