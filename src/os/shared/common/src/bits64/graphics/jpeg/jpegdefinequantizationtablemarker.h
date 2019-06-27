#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGDEFINEQUANTIZATIONTABLEMARKER_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGDEFINEQUANTIZATIONTABLEMARKER_H



#include <common/src/bits64/graphics/jpeg/jpegmarkerheader.h>
#include <common/src/bits64/graphics/jpeg/jpegquantizationtable.h>



struct JpegDefineQuantizationTableMarker
{
    JpegMarkerHeader      header;
    JpegQuantizationTable tables[0];
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGDEFINEQUANTIZATIONTABLEMARKER_H
