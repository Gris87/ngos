#ifndef OS_SHARED_COMMON_SRC_BITS64_ZLIB_ZLIBCOMPRESSIONINFO_H
#define OS_SHARED_COMMON_SRC_BITS64_ZLIB_ZLIBCOMPRESSIONINFO_H



#include <common/src/com/ngos/shared/common/log/assert.h>
#include <common/src/com/ngos/shared/common/log/log.h>
#include <common/src/com/ngos/shared/common/printf/printf.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



enum class ZLibCompressionInfo: u8
{
    NONE       = 0,
    WINDOW_1K  = 2,
    WINDOW_2K  = 3,
    WINDOW_4K  = 4,
    WINDOW_8K  = 5,
    WINDOW_16K = 6,
    WINDOW_32K = 7
};



inline const char8* enumToString(ZLibCompressionInfo info) // TEST: NO
{
    // COMMON_LT((" | info = %u", info)); // Commented to avoid bad looking logs



    switch (info)
    {
        case ZLibCompressionInfo::NONE:       return "NONE";
        case ZLibCompressionInfo::WINDOW_1K:  return "WINDOW_1K";
        case ZLibCompressionInfo::WINDOW_2K:  return "WINDOW_2K";
        case ZLibCompressionInfo::WINDOW_4K:  return "WINDOW_4K";
        case ZLibCompressionInfo::WINDOW_8K:  return "WINDOW_8K";
        case ZLibCompressionInfo::WINDOW_16K: return "WINDOW_16K";
        case ZLibCompressionInfo::WINDOW_32K: return "WINDOW_32K";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(ZLibCompressionInfo info) // TEST: NO
{
    // COMMON_LT((" | info = %u", info)); // Commented to avoid bad looking logs



    static char8 res[18];

    sprintf(res, "0x%02X (%s)", info, enumToString(info));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_ZLIB_ZLIBCOMPRESSIONINFO_H
