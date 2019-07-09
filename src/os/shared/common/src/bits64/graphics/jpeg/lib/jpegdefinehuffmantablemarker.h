#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGDEFINEHUFFMANTABLEMARKER_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGDEFINEHUFFMANTABLEMARKER_H



#include <common/src/bits64/graphics/jpeg/lib/jpeghuffmantable.h>
#include <common/src/bits64/graphics/jpeg/lib/jpegmarkerheader.h>



struct JpegDefineHuffmanTableMarker
{
    JpegMarkerHeader header;
    JpegHuffmanTable tables[0];
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGDEFINEHUFFMANTABLEMARKER_H
