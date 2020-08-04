#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGDEFINEQUANTIZATIONTABLEMARKER_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGDEFINEQUANTIZATIONTABLEMARKER_H



#include <com/ngos/shared/common/graphics/jpeg/lib/jpegmarkerheader.h>
#include <com/ngos/shared/common/graphics/jpeg/lib/jpegquantizationtable.h>



struct JpegDefineQuantizationTableMarker
{
    JpegMarkerHeader      header;
    JpegQuantizationTable tables[0];
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGDEFINEQUANTIZATIONTABLEMARKER_H
