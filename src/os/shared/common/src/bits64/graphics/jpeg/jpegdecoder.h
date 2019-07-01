#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGDECODER_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGDECODER_H



#include <common/src/bits64/graphics/image.h>
#include <common/src/bits64/graphics/jpeg/jpegcomponent.h>
#include <common/src/bits64/graphics/jpeg/jpeghuffmantable.h>
#include <common/src/bits64/graphics/jpeg/jpegquantizationtable.h>
#include <common/src/bits64/graphics/jpeg/jpegstartofframemarker.h>
#include <common/src/bits64/graphics/jpeg/jpegstartofscanmarker.h>
#include <common/src/bits64/graphics/jpeg/jpegvlccode.h>
#include <ngos/types.h>



#define JPEG_NUMBER_OF_COMPONENTS 3



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
    JpegQuantizationTable*   quantizationTables[JPEG_QUANTIZATION_TABLE_COUNT];
    JpegVlcCode*             vlcDcTables[JPEG_HUFFMAN_TABLE_COUNT];
    JpegVlcCode*             vlcAcTables[JPEG_HUFFMAN_TABLE_COUNT];
    JpegComponent            components[JPEG_NUMBER_OF_COMPONENTS];
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGDECODER_H
