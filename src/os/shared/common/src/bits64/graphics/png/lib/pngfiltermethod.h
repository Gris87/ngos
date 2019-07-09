#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGFILTERMETHOD_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGFILTERMETHOD_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/types.h>



enum class PngFilterMethod: u32
{
    ADAPTIVE = 0
};



inline char* pngFilterMethodToString(PngFilterMethod method) // TEST: NO
{
    // COMMON_LT((" | method = %u", method)); // Commented to avoid bad looking logs



    switch (method)
    {
        case PngFilterMethod::ADAPTIVE: return "ADAPTIVE";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGFILTERMETHOD_H