#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_PNGRENDERINGINTENT_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_PNGRENDERINGINTENT_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PngRenderingIntent: u8
{
    PERCEPTUAL            = 0,
    RELATIVE_COLORIMETRIC = 1,
    SATURATION            = 2,
    ABSOLUTE_COLORIMETRIC = 3
};



inline const char8* enumToString(PngRenderingIntent intent) // TEST: NO
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



inline const char8* enumToFullString(PngRenderingIntent intent) // TEST: NO
{
    // COMMON_LT((" | intent = %u", intent)); // Commented to avoid bad looking logs



    static char8 res[29];

    sprintf(res, "0x%02X (%s)", (u8)intent, enumToString(intent));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_PNGRENDERINGINTENT_H
