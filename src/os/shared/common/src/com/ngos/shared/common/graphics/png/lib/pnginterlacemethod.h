#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGINTERLACEMETHOD_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGINTERLACEMETHOD_H



#include <common/src/com/ngos/shared/common/log/assert.h>
#include <common/src/com/ngos/shared/common/log/log.h>
#include <common/src/com/ngos/shared/common/printf/printf.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



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



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGINTERLACEMETHOD_H
