#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_BMP_LIB_BMPINFORMATIONHEADER_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_BMP_LIB_BMPINFORMATIONHEADER_H



#include <com/ngos/shared/common/graphics/bmp/lib/bmpcompressionmethod.h>
#include <com/ngos/shared/common/ngos/types.h>



struct BmpInformationHeader
{
    bad_uint32                  headerSize;
    bad_uint32                  width;
    bad_uint32                  height;
    bad_uint16                  numberOfPlanes;
    bad_uint16                  bitsPerPixel;
    BmpCompressionMethod compressionMethod;
    bad_uint32                  imageSize;         // The size of decompressed image
    bad_uint32                  xPixelsPerMeter;
    bad_uint32                  yPixelsPerMeter;
    bad_uint32                  numberOfColors;
    bad_uint32                  importantColors;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_BMP_LIB_BMPINFORMATIONHEADER_H
