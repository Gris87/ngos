#ifndef OS_SHARED_COMMON_SRC_BITS64_STRING_UTILS_H
#define OS_SHARED_COMMON_SRC_BITS64_STRING_UTILS_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/printf/printf.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



inline const char8* bytesToString(u64 bytes)
{
    // COMMON_LT((" | method = %u", method)); // Commented to avoid bad looking logs



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



    static char8 res[8];
    i64          length;

    AVOID_UNUSED(length);

    switch (level)
    {
        case 0: length = sprintf(res, "%u B",  bytes); break;
        case 1: length = sprintf(res, "%u KB", bytes); break;
        case 2: length = sprintf(res, "%u MB", bytes); break;
        case 3: length = sprintf(res, "%u GB", bytes); break;
        case 4: length = sprintf(res, "%u TB", bytes); break;
        case 5: length = sprintf(res, "%u PB", bytes); break;
        case 6: length = sprintf(res, "%u EB", bytes); break;

        default: return "UNKNOWN";
    }

    COMMON_TEST_ASSERT(length < (i64)sizeof(res), nullptr);



    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_STRING_UTILS_H
