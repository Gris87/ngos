#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_CHUNKS_PNGPHYSICALPIXELDIMENSIONS_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_CHUNKS_PNGPHYSICALPIXELDIMENSIONS_H



#include <common/src/com/ngos/shared/common/graphics/png/lib/pngunitspecifier.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



struct PngPhysicalPixelDimensions
{
    u32              pixelsPerUnitX;
    u32              pixelsPerUnitY;
    PngUnitSpecifier unitSpecifier;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_CHUNKS_PNGPHYSICALPIXELDIMENSIONS_H
