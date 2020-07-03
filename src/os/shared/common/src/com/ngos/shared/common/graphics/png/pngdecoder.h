#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_PNGDECODER_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_PNGDECODER_H



#include <common/src/com/ngos/shared/common/graphics/image.h>
#include <common/src/com/ngos/shared/common/graphics/png/lib/chunks/pngembeddediccprofile.h>
#include <common/src/com/ngos/shared/common/graphics/png/lib/chunks/pngimagegamma.h>
#include <common/src/com/ngos/shared/common/graphics/png/lib/chunks/pngimageheader.h>
#include <common/src/com/ngos/shared/common/graphics/png/lib/chunks/pngimagelastmodificationtime.h>
#include <common/src/com/ngos/shared/common/graphics/png/lib/chunks/pngphysicalpixeldimensions.h>
#include <common/src/com/ngos/shared/common/graphics/png/lib/chunks/pngprimarychromaticities.h>
#include <common/src/com/ngos/shared/common/graphics/png/lib/chunks/pngsignificantbits.h>
#include <common/src/com/ngos/shared/common/graphics/png/lib/chunks/pngstandardrgbcolorspace.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



struct PngDecoder
{
    Image                        **image;
    PngImageHeader                *imageHeader;
    PngPrimaryChromaticities      *primaryChromaticities;
    PngImageGamma                 *imageGamma;
    PngEmbeddedIccProfile         *embeddedIccProfile;
    PngSignificantBits            *significantBits;
    PngStandardRgbColorSpace      *standardRgbColorSpace;
    PngPhysicalPixelDimensions    *physicalPixelDimensions;
    PngImageLastModificationTime  *imageLastModificationTime;
    u8                            *imageDataBuffer;
    u64                            imageDataSize;
    u64                            imageDataAllocatedSize;
    u8                            *rawImageBuffer;
    u8                             bitsPerPixel;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_PNGDECODER_H
