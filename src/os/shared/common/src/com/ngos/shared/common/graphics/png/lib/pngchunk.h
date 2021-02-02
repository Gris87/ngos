#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_PNGCHUNK_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_PNGCHUNK_H



#include <com/ngos/shared/common/graphics/png/lib/pngchunktype.h>
#include <com/ngos/shared/common/ngos/types.h>



struct PngChunk
{
    bad_uint32          length;
    PngChunkType type;
    bad_uint8           data[0];
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_PNGCHUNK_H
