#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_PNGFILTERMETHOD_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_PNGFILTERMETHOD_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PngFilterMethod: u8
{
    ADAPTIVE = 0
};



inline const char8* enumToString(PngFilterMethod method) // TEST: NO
{
    // COMMON_LT((" | method = %u", method)); // Commented to avoid bad looking logs



    switch (method)
    {
        case PngFilterMethod::ADAPTIVE: return "ADAPTIVE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PngFilterMethod method) // TEST: NO
{
    // COMMON_LT((" | method = %u", method)); // Commented to avoid bad looking logs



    static char8 res[16];

    sprintf(res, "0x%02X (%s)", (u8)method, enumToString(method));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_PNGFILTERMETHOD_H
