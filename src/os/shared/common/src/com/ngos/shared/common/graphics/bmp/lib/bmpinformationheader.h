#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_BMP_LIB_BMPINFORMATIONHEADER_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_BMP_LIB_BMPINFORMATIONHEADER_H



#include <com/ngos/shared/common/graphics/bmp/lib/bmpcompressionmethod.h>
#include <com/ngos/shared/common/ngos/types.h>



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



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_BMP_LIB_BMPINFORMATIONHEADER_H
