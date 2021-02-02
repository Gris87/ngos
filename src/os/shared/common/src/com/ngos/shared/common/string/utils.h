#ifndef COM_NGOS_SHARED_COMMON_STRING_UTILS_H
#define COM_NGOS_SHARED_COMMON_STRING_UTILS_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/generated/bytesdecimals.h>
#include <com/ngos/shared/common/string/generated/numberdecimals.h>
#include <com/ngos/shared/common/string/string.h>



inline NgosStatus bytesToString(bad_uint64 bytes, char8 *buffer, bad_int64 size)
{
    // COMMON_LT((" | bytes = %u, buffer = 0x%p, size = %d", bytes, buffer, size)); // Commented to avoid bad looking logs

    COMMON_ASSERT(buffer,     "buffer is null",    NgosStatus::ASSERTION);
    COMMON_ASSERT(size >= 11, "size is too small", NgosStatus::ASSERTION);



    AVOID_UNUSED(size);



    bad_uint8  level = 0;
    bad_uint16 tail  = 0;

    while (bytes >= 1024)
    {
        tail  =   bytes & 0x03FF;
        bytes >>= 10;

        ++level;
    }



    COMMON_TEST_ASSERT(level <= 6,    NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(tail  <  1024, NgosStatus::ASSERTION);



    if (tail >= ARRAY_COUNT(bytesDecimals))
    {
        tail = 0;
        ++bytes;

        if (bytes == 1024)
        {
            bytes = 1;
            ++level;
        }
    }



    bad_int64 length;

    switch (level)
    {
        case 0: length = sprintf(buffer, "%u B",      bytes);                      break;
        case 1: length = sprintf(buffer, "%u%.3s KB", bytes, bytesDecimals[tail]); break;
        case 2: length = sprintf(buffer, "%u%.3s MB", bytes, bytesDecimals[tail]); break;
        case 3: length = sprintf(buffer, "%u%.3s GB", bytes, bytesDecimals[tail]); break;
        case 4: length = sprintf(buffer, "%u%.3s TB", bytes, bytesDecimals[tail]); break;
        case 5: length = sprintf(buffer, "%u%.3s PB", bytes, bytesDecimals[tail]); break;
        case 6: length = sprintf(buffer, "%u%.3s EB", bytes, bytesDecimals[tail]); break;

        default: strcpy(buffer, "UNKNOWN"); length = 7; break;
    }

    COMMON_TEST_ASSERT(length < size, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

inline const char8* bytesToString(bad_uint64 bytes)
{
    // COMMON_LT((" | bytes = %u", bytes)); // Commented to avoid bad looking logs



    static char8 res[11];

    COMMON_ASSERT_EXECUTION(bytesToString(bytes, res, sizeof(res)), nullptr);



    return res;
}

inline const char8* hertzToString(bad_uint64 hertz)
{
    // COMMON_LT((" | hertz = %u", hertz)); // Commented to avoid bad looking logs



    bad_uint8  level = 0;
    bad_uint16 tail  = 0;

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

        if (hertz == 1000)
        {
            hertz = 1;
            ++level;
        }
    }



    static char8 res[11];
    bad_int64          length;

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

    COMMON_TEST_ASSERT(length < (bad_int64)sizeof(res), nullptr);



    return res;
}

inline const char8* boolToString(bool value)
{
    // COMMON_LT((" | value = %u", value)); // Commented to avoid bad looking logs



    return value ? "true" : "false";
}

inline const char8* stringToString(const char8 *str)
{
    // COMMON_LT((" | str = 0x%p", str)); // Commented to avoid bad looking logs



    return str != nullptr ? str : "null";
}



#endif // COM_NGOS_SHARED_COMMON_STRING_UTILS_H
