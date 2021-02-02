#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_PNGHEADER_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_PNGHEADER_H



#include <com/ngos/shared/common/graphics/png/lib/pngchunk.h>
#include <com/ngos/shared/common/ngos/types.h>



#define PNG_HEADER_SIGNATURE 0x0A1A0A0D474E5089 // "0x89 PNG 0x0D 0x0A 0x1A 0x0A"



struct PngHeader
{
    bad_uint64      signature;
    PngChunk imageHeaderChunk;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_PNGHEADER_H
