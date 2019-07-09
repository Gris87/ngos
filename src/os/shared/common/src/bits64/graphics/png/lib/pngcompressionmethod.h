#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGCOMPRESSIONMETHOD_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGCOMPRESSIONMETHOD_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/types.h>



enum class PngCompressionMethod: u8
{
    DEFLATE = 0
};



inline const char* pngCompressionMethodToString(PngCompressionMethod method) // TEST: NO
{
    // COMMON_LT((" | method = %u", method)); // Commented to avoid bad looking logs



    switch (method)
    {
        case PngCompressionMethod::DEFLATE: return "DEFLATE";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGCOMPRESSIONMETHOD_H
