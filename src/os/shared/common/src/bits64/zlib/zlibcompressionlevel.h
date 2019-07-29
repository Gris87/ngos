#ifndef OS_SHARED_COMMON_SRC_BITS64_ZLIB_ZLIBCOMPRESSIONLEVEL_H
#define OS_SHARED_COMMON_SRC_BITS64_ZLIB_ZLIBCOMPRESSIONLEVEL_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/types.h>



enum class ZLibCompressionLevel: u8
{
    FASTEST             = 0,
    FAST                = 1,
    DEFAULT             = 2,
    MAXIMUM_COMPRESSION = 3
};



inline const char8* zLibCompressionLevelToString(ZLibCompressionLevel level) // TEST: NO
{
    // COMMON_LT((" | level = %u", level)); // Commented to avoid bad looking logs



    switch (level)
    {
        case ZLibCompressionLevel::FASTEST:             return "FASTEST";
        case ZLibCompressionLevel::FAST:                return "FAST";
        case ZLibCompressionLevel::DEFAULT:             return "DEFAULT";
        case ZLibCompressionLevel::MAXIMUM_COMPRESSION: return "MAXIMUM_COMPRESSION";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_ZLIB_ZLIBCOMPRESSIONLEVEL_H
