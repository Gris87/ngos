#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGDECODER_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGDECODER_H



#include <common/src/bits64/graphics/image.h>
#include <common/src/bits64/graphics/jpeg/jpegcomponent.h>
#include <common/src/bits64/graphics/jpeg/jpeghuffmantable.h>
#include <common/src/bits64/graphics/jpeg/jpegquantizationtable.h>
#include <common/src/bits64/graphics/jpeg/jpegstartofframemarker.h>
#include <common/src/bits64/graphics/jpeg/jpegstartofscanmarker.h>
#include <ngos/types.h>



struct JpegDecoder
{
    u8                      *data;
    u64                      size;
    Image                  **image;
    JpegQuantizationTable*   quantizationTables[JPEG_QUANTIZATION_TABLE_COUNT];
    JpegStartOfFrameMarker  *startOfFrameMarker;
    JpegHuffmanTable*        huffmanDcTables[JPEG_HUFFMAN_TABLE_COUNT];
    JpegHuffmanTable*        huffmanAcTables[JPEG_HUFFMAN_TABLE_COUNT];
    u16                      restartInterval;
    JpegStartOfScanMarker   *startOfScanMarker;
    JpegComponent            components[3];
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGDECODER_H
