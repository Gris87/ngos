#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGRENDERINGINTENT_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGRENDERINGINTENT_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/types.h>



enum class PngRenderingIntent: u8
{
    PERCEPTUAL            = 0,
    RELATIVE_COLORIMETRIC = 1,
    SATURATION            = 2,
    ABSOLUTE_COLORIMETRIC = 3
};



inline const char8* pngRenderingIntentToString(PngRenderingIntent intent) // TEST: NO
{
    // COMMON_LT((" | intent = %u", intent)); // Commented to avoid bad looking logs



    switch (intent)
    {
        case PngRenderingIntent::PERCEPTUAL:            return "PERCEPTUAL";
        case PngRenderingIntent::RELATIVE_COLORIMETRIC: return "RELATIVE_COLORIMETRIC";
        case PngRenderingIntent::SATURATION:            return "SATURATION";
        case PngRenderingIntent::ABSOLUTE_COLORIMETRIC: return "ABSOLUTE_COLORIMETRIC";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGRENDERINGINTENT_H
