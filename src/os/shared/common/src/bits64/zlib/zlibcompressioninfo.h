#ifndef OS_SHARED_COMMON_SRC_BITS64_ZLIB_ZLIBCOMPRESSIONINFO_H
#define OS_SHARED_COMMON_SRC_BITS64_ZLIB_ZLIBCOMPRESSIONINFO_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/types.h>



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



inline const char8* zLibCompressionInfoToString(ZLibCompressionInfo info) // TEST: NO
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



#endif // OS_SHARED_COMMON_SRC_BITS64_ZLIB_ZLIBCOMPRESSIONINFO_H
