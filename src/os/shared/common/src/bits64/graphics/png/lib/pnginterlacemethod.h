#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGINTERLACEMETHOD_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGINTERLACEMETHOD_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/types.h>



enum class PngInterlaceMethod: u8
{
    NONE   = 0,
    ADAM_7 = 1
};



inline const char* pngInterlaceMethodToString(PngInterlaceMethod method) // TEST: NO
{
    // COMMON_LT((" | method = %u", method)); // Commented to avoid bad looking logs



    switch (method)
    {
        case PngInterlaceMethod::NONE:   return "NONE";
        case PngInterlaceMethod::ADAM_7: return "ADAM_7";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGINTERLACEMETHOD_H
