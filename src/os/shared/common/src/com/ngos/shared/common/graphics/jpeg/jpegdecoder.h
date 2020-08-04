#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_JPEGDECODER_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_JPEGDECODER_H



#include <com/ngos/shared/common/graphics/image.h>
#include <com/ngos/shared/common/graphics/jpeg/jpegcomponent.h>
#include <com/ngos/shared/common/graphics/jpeg/jpegvlccode.h>
#include <com/ngos/shared/common/graphics/jpeg/lib/jpeghuffmantable.h>
#include <com/ngos/shared/common/graphics/jpeg/lib/jpegquantizationtable.h>
#include <com/ngos/shared/common/graphics/jpeg/lib/jpegstartofframemarker.h>
#include <com/ngos/shared/common/graphics/jpeg/lib/jpegstartofscanmarker.h>
#include <com/ngos/shared/common/ngos/types.h>



#define JPEG_NUMBER_OF_COMPONENTS    3
#define JPEG_QUANTIZATION_TABLE_SIZE 64



struct JpegDecoder
{
    u8                      *data;
    u64                      size;
    Image                  **image;
    JpegStartOfFrameMarker  *startOfFrameMarker;
    JpegStartOfScanMarker   *startOfScanMarker;
    u16                      restartInterval;
    u16                      mcuBlockCountX;
    u16                      mcuBlockCountY;
    u64                      bitBuffer;
    u8                       bitsAvailable;
    u16                      quantizationTables[JPEG_QUANTIZATION_TABLE_COUNT][JPEG_QUANTIZATION_TABLE_SIZE];
    JpegVlcCode*             vlcDcTables[JPEG_HUFFMAN_TABLE_COUNT];
    JpegVlcCode*             vlcAcTables[JPEG_HUFFMAN_TABLE_COUNT];
    JpegComponent            components[JPEG_NUMBER_OF_COMPONENTS];
};



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_JPEGDECODER_H
