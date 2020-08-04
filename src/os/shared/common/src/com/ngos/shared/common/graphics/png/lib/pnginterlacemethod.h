#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_PNGINTERLACEMETHOD_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_PNGINTERLACEMETHOD_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PngInterlaceMethod: u8
{
    NONE   = 0,
    ADAM_7 = 1
};



inline const char8* enumToString(PngInterlaceMethod method) // TEST: NO
{
    // COMMON_LT((" | method = %u", method)); // Commented to avoid bad looking logs



    switch (method)
    {
        case PngInterlaceMethod::NONE:   return "NONE";
        case PngInterlaceMethod::ADAM_7: return "ADAM_7";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PngInterlaceMethod method) // TEST: NO
{
    // COMMON_LT((" | method = %u", method)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", method, enumToString(method));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_PNGINTERLACEMETHOD_H
