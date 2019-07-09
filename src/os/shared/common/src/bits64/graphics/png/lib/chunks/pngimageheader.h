#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_PNGIMAGEHEADER_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_PNGIMAGEHEADER_H



#include <common/src/bits64/graphics/png/pngcolortype.h>
#include <common/src/bits64/graphics/png/pngcompressionmethod.h>
#include <common/src/bits64/graphics/png/pngfiltermethod.h>
#include <common/src/bits64/graphics/png/pnginterlacemethod.h>
#include <ngos/types.h>



struct PngImageHeader
{
    u32                  width;
    u32                  height;
    u8                   bitDepth;
    PngColorType         colorType;
    PngCompressionMethod compressionMethod;
    PngFilterMethod      filterMethod;
    PngInterlaceMethod   interlaceMethod;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_PNGIMAGEHEADER_H
