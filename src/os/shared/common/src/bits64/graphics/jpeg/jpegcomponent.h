#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGCOMPONENT_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGCOMPONENT_H



#include <common/src/bits64/graphics/jpeg/jpegcomponentid.h>
#include <common/src/bits64/graphics/jpeg/jpeghuffmantable.h>
#include <common/src/bits64/graphics/jpeg/jpegquantizationtable.h>
#include <ngos/types.h>



struct JpegComponent
{
    JpegComponentId        id;
    u8                     samplingFactorX;
    u8                     samplingFactorY;
    u64                    width;
    u64                    height;
    u64                    stride;
    JpegQuantizationTable *quantizationTable;
    JpegHuffmanTable      *huffmanDcTable;
    JpegHuffmanTable      *huffmanAcTable;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGCOMPONENT_H
