#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_PNGCHUNK_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_PNGCHUNK_H



#include <common/src/com/ngos/shared/common/graphics/png/lib/pngchunktype.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



struct PngChunk
{
    u32          length;
    PngChunkType type;
    u8           data[0];
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_PNGCHUNK_H
