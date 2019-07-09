#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_BMP_BMPINFORMATIONHEADER_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_BMP_BMPINFORMATIONHEADER_H



#include <common/src/bits64/graphics/bmp/bmpcompressionmethod.h>
#include <ngos/types.h>



struct BmpInformationHeader
{
    u32                  headerSize;
    u32                  width;
    u32                  height;
    u16                  numberOfPlanes;
    u16                  bitsPerPixel;
    BmpCompressionMethod compressionMethod;
    u32                  imageSize;         // The size of decompressed image
    u32                  xPixelsPerMeter;
    u32                  yPixelsPerMeter;
    u32                  numberOfColors;
    u32                  importantColors;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_BMP_BMPINFORMATIONHEADER_H
