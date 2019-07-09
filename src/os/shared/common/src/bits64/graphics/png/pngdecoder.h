#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_PNGDECODER_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_PNGDECODER_H



#include <common/src/bits64/graphics/image.h>
#include <common/src/bits64/graphics/png/lib/chunks/pngimageheader.h>
#include <common/src/bits64/graphics/png/lib/chunks/pngstandardrgbcolorspace.h>
#include <ngos/types.h>



struct PngDecoder
{
    Image                    **image;
    PngImageHeader            *imageHeader;
    PngStandardRgbColorSpace  *standardRgbColorSpace;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_PNGDECODER_H
