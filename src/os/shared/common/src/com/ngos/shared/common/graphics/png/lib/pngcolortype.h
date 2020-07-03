#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_PNGCOLORTYPE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_PNGCOLORTYPE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/ngos/types.h>



enum class PngColorType: u8
{
    GREYSCALE           = 0,
    RGB                 = 2,
    PALETTE             = 3,
    GREYSCALE_AND_ALPHA = 4,
    RGBA                = 6
};



inline const char8* enumToString(PngColorType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case PngColorType::GREYSCALE:           return "GREYSCALE";
        case PngColorType::RGB:                 return "RGB";
        case PngColorType::PALETTE:             return "PALETTE";
        case PngColorType::GREYSCALE_AND_ALPHA: return "GREYSCALE_AND_ALPHA";
        case PngColorType::RGBA:                return "RGBA";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PngColorType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[27];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_PNGCOLORTYPE_H
