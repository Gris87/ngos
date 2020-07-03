#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_PNGCOMPRESSIONMETHOD_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_PNGCOMPRESSIONMETHOD_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/ngos/types.h>



enum class PngCompressionMethod: u8
{
    DEFLATE = 0
};



inline const char8* enumToString(PngCompressionMethod method) // TEST: NO
{
    // COMMON_LT((" | method = %u", method)); // Commented to avoid bad looking logs



    switch (method)
    {
        case PngCompressionMethod::DEFLATE: return "DEFLATE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PngCompressionMethod method) // TEST: NO
{
    // COMMON_LT((" | method = %u", method)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", method, enumToString(method));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_PNGCOMPRESSIONMETHOD_H
