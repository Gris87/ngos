#ifndef OS_SHARED_COMMON_SRC_BITS64_ZLIB_ZLIBCOMPRESSIONLEVEL_H
#define OS_SHARED_COMMON_SRC_BITS64_ZLIB_ZLIBCOMPRESSIONLEVEL_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>



enum class ZLibCompressionLevel: u8
{
    FASTEST             = 0,
    FAST                = 1,
    DEFAULT             = 2,
    MAXIMUM_COMPRESSION = 3
};



inline const char8* enumToString(ZLibCompressionLevel level) // TEST: NO
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



inline const char8* enumToFullString(ZLibCompressionLevel level) // TEST: NO
{
    // COMMON_LT((" | level = %u", level)); // Commented to avoid bad looking logs



    static char8 res[27];

    sprintf(res, "0x%02X (%s)", level, enumToString(level));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_ZLIB_ZLIBCOMPRESSIONLEVEL_H
