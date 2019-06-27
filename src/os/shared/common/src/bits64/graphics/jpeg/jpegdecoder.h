#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGDECODER_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGDECODER_H



#include <common/src/bits64/graphics/image.h>
#include <common/src/bits64/graphics/jpeg/jpegquantizationtable.h>
#include <common/src/bits64/graphics/jpeg/jpegstartofframemarker.h>
#include <ngos/types.h>



struct JpegDecoder
{
    u8                      *data;
    u64                      size;
    Image                  **image;
    JpegQuantizationTable*   quantizationTables[JPEG_QUANTIZATION_TABLE_COUNT];
    JpegStartOfFrameMarker  *startOfFrameMarker;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGDECODER_H
