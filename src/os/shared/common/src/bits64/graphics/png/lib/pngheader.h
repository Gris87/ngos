#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_PNGHEADER_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_PNGHEADER_H



#include <common/src/bits64/graphics/png/pngchunk.h>
#include <ngos/types.h>



#define PNG_HEADER_SIGNATURE 0x0A1A0A0D474E5089 // "0x89 PNG 0x0D 0x0A 0x1A 0x0A"



struct PngHeader
{
    u64      signature;
    PngChunk chunk;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_PNGHEADER_H
