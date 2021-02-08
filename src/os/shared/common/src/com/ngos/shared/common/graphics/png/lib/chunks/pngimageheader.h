#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_CHUNKS_PNGIMAGEHEADER_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_CHUNKS_PNGIMAGEHEADER_H



#include <com/ngos/shared/common/graphics/png/lib/pngcolortype.h>
#include <com/ngos/shared/common/graphics/png/lib/pngcompressionmethod.h>
#include <com/ngos/shared/common/graphics/png/lib/pngfiltermethod.h>
#include <com/ngos/shared/common/graphics/png/lib/pnginterlacemethod.h>
#include <com/ngos/shared/common/ngos/types.h>



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



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_CHUNKS_PNGIMAGEHEADER_H
