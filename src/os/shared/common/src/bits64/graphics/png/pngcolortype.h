#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_PNGCOLORTYPE_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_PNGCOLORTYPE_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/types.h>



enum class PngColorType: u32
{
    GREYSCALE           = 0,
    RGB                 = 2,
    PALETTE             = 3,
    GREYSCALE_AND_ALPHA = 4,
    RGBA                = 6
};



inline char* pngColorTypeToString(PngColorType type) // TEST: NO
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



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_PNGCOLORTYPE_H
