#ifndef OS_SHARED_COMMON_SRC_BITS64_ZLIB_ZLIBCOMPRESSIONMETHOD_H
#define OS_SHARED_COMMON_SRC_BITS64_ZLIB_ZLIBCOMPRESSIONMETHOD_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/types.h>



enum class ZLibCompressionMethod: u8
{
    NONE    = 0,
    DEFLATE = 8
};



inline const char8* zLibCompressionMethodToString(ZLibCompressionMethod method) // TEST: NO
{
    // COMMON_LT((" | method = %u", method)); // Commented to avoid bad looking logs



    switch (method)
    {
        case ZLibCompressionMethod::NONE:    return "NONE";
        case ZLibCompressionMethod::DEFLATE: return "DEFLATE";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_ZLIB_ZLIBCOMPRESSIONMETHOD_H
