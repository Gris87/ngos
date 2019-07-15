#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_CHUNKS_PNGSTANDARDRGBCOLORSPACE_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_CHUNKS_PNGSTANDARDRGBCOLORSPACE_H



#include <common/src/bits64/graphics/png/lib/pngrenderingintent.h>
#include <ngos/types.h>



struct PngStandardRgbColorSpace
{
    PngRenderingIntent renderingIntent;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_CHUNKS_PNGSTANDARDRGBCOLORSPACE_H