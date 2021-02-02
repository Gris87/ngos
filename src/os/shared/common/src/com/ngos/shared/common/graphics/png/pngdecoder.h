#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_PNGDECODER_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_PNGDECODER_H



#include <com/ngos/shared/common/graphics/image.h>
#include <com/ngos/shared/common/graphics/png/lib/chunks/pngembeddediccprofile.h>
#include <com/ngos/shared/common/graphics/png/lib/chunks/pngimagegamma.h>
#include <com/ngos/shared/common/graphics/png/lib/chunks/pngimageheader.h>
#include <com/ngos/shared/common/graphics/png/lib/chunks/pngimagelastmodificationtime.h>
#include <com/ngos/shared/common/graphics/png/lib/chunks/pngphysicalpixeldimensions.h>
#include <com/ngos/shared/common/graphics/png/lib/chunks/pngprimarychromaticities.h>
#include <com/ngos/shared/common/graphics/png/lib/chunks/pngsignificantbits.h>
#include <com/ngos/shared/common/graphics/png/lib/chunks/pngstandardrgbcolorspace.h>
#include <com/ngos/shared/common/ngos/types.h>



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
    bad_uint8                            *imageDataBuffer;
    bad_uint64                            imageDataSize;
    bad_uint64                            imageDataAllocatedSize;
    bad_uint8                            *rawImageBuffer;
    bad_uint8                             bitsPerPixel;
};



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_PNGDECODER_H
