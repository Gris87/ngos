#ifndef OS_SHARED_COMMON_SRC_BITS64_STRING_UTILS_H
#define OS_SHARED_COMMON_SRC_BITS64_STRING_UTILS_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/generated/bytesdecimals.h>
#include <common/src/bits64/string/generated/numberdecimals.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



inline const char8* bytesToString(u64 bytes)
{
    // COMMON_LT((" | bytes = %u", bytes)); // Commented to avoid bad looking logs



    u8  level = 0;
    u16 tail  = 0;

    while (bytes >= 1024)
    {
        tail  =   bytes & 0x03FF;
        bytes >>= 10;

        ++level;
    }



    COMMON_TEST_ASSERT(level <= 6,    nullptr);
    COMMON_TEST_ASSERT(tail  <  1024, nullptr);



    if (tail >= ARRAY_COUNT(bytesDecimals))
    {
        tail = 0;
        ++bytes;

        if (bytes >= 1024)
        {
            bytes >>= 10;
            ++level;
        }
    }



    static char8 res[11];
    i64          length;

    AVOID_UNUSED(length);

    switch (level)
    {
        case 0: length = sprintf(res, "%u B",      bytes);                      break;
        case 1: length = sprintf(res, "%u%.3s KB", bytes, bytesDecimals[tail]); break;
        case 2: length = sprintf(res, "%u%.3s MB", bytes, bytesDecimals[tail]); break;
        case 3: length = sprintf(res, "%u%.3s GB", bytes, bytesDecimals[tail]); break;
        case 4: length = sprintf(res, "%u%.3s TB", bytes, bytesDecimals[tail]); break;
        case 5: length = sprintf(res, "%u%.3s PB", bytes, bytesDecimals[tail]); break;
        case 6: length = sprintf(res, "%u%.3s EB", bytes, bytesDecimals[tail]); break;

        default: return "UNKNOWN";
    }

    COMMON_TEST_ASSERT(length < (i64)sizeof(res), nullptr);



    return res;
}

inline const char8* hertzToString(u64 hertz)
{
    // COMMON_LT((" | hertz = %u", hertz)); // Commented to avoid bad looking logs



    u8  level = 0;
    u16 tail  = 0;

    while (hertz >= 1000)
    {
        tail  =  hertz % 1000;
        hertz /= 1000;

        ++level;
    }



    COMMON_TEST_ASSERT(level <= 6,    nullptr);
    COMMON_TEST_ASSERT(tail  <  1000, nullptr);



    if (tail >= ARRAY_COUNT(numberDecimals))
    {
        tail = 0;
        ++hertz;

        if (hertz >= 1000)
        {
            hertz /= 1000;
            ++level;
        }
    }



    static char8 res[11];
    i64          length;

    AVOID_UNUSED(length);

    switch (level)
    {
        case 0: length = sprintf(res, "%u Hz",      hertz);                       break;
        case 1: length = sprintf(res, "%u%.3s KHz", hertz, numberDecimals[tail]); break;
        case 2: length = sprintf(res, "%u%.3s MHz", hertz, numberDecimals[tail]); break;
        case 3: length = sprintf(res, "%u%.3s GHz", hertz, numberDecimals[tail]); break;
        case 4: length = sprintf(res, "%u%.3s THz", hertz, numberDecimals[tail]); break;
        case 5: length = sprintf(res, "%u%.3s PHz", hertz, numberDecimals[tail]); break;
        case 6: length = sprintf(res, "%u%.3s EHz", hertz, numberDecimals[tail]); break;

        default: return "UNKNOWN";
    }

    COMMON_TEST_ASSERT(length < (i64)sizeof(res), nullptr);



    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_STRING_UTILS_H
