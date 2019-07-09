#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGCHUNK_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGCHUNK_H



#include <common/src/bits64/graphics/png/lib/pngchunktype.h>
#include <ngos/types.h>



struct PngChunk
{
    u32          length;
    PngChunkType type;
    u8           data[0];
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGCHUNK_H
