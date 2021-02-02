#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_CHUNKS_PNGPHYSICALPIXELDIMENSIONS_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_CHUNKS_PNGPHYSICALPIXELDIMENSIONS_H



#include <com/ngos/shared/common/graphics/png/lib/pngunitspecifier.h>
#include <com/ngos/shared/common/ngos/types.h>



struct PngPhysicalPixelDimensions
{
    bad_uint32              pixelsPerUnitX;
    bad_uint32              pixelsPerUnitY;
    PngUnitSpecifier unitSpecifier;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_CHUNKS_PNGPHYSICALPIXELDIMENSIONS_H
