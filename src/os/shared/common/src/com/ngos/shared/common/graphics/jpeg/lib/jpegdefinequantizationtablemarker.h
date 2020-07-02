#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGDEFINEQUANTIZATIONTABLEMARKER_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGDEFINEQUANTIZATIONTABLEMARKER_H



#include <common/src/com/ngos/shared/common/graphics/jpeg/lib/jpegmarkerheader.h>
#include <common/src/com/ngos/shared/common/graphics/jpeg/lib/jpegquantizationtable.h>



struct JpegDefineQuantizationTableMarker
{
    JpegMarkerHeader      header;
    JpegQuantizationTable tables[0];
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGDEFINEQUANTIZATIONTABLEMARKER_H
