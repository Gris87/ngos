#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_CHUNKS_PNGIMAGEHEADER_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_CHUNKS_PNGIMAGEHEADER_H



#include <common/src/com/ngos/shared/common/graphics/png/lib/pngcolortype.h>
#include <common/src/com/ngos/shared/common/graphics/png/lib/pngcompressionmethod.h>
#include <common/src/com/ngos/shared/common/graphics/png/lib/pngfiltermethod.h>
#include <common/src/com/ngos/shared/common/graphics/png/lib/pnginterlacemethod.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



struct PngImageHeader
{
    u32                  width;
    u32                  height;
    u8                   bitDepth;
    PngColorType         colorType;
    PngCompressionMethod compressionMethod;
    PngFilterMethod      filterMethod;
    PngInterlaceMethod   interlaceMethod;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_CHUNKS_PNGIMAGEHEADER_H
