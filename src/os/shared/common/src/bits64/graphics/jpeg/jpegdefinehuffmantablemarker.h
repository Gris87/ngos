#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGDEFINEHUFFMANTABLEMARKER_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGDEFINEHUFFMANTABLEMARKER_H



#include <common/src/bits64/graphics/jpeg/jpegmarkerheader.h>
#include <common/src/bits64/graphics/jpeg/jpeghuffmantable.h>



struct JpegDefineHuffmanTableMarker
{
    JpegMarkerHeader header;
    JpegHuffmanTable tables[0];
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGDEFINEHUFFMANTABLEMARKER_H
