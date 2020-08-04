#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGDEFINEHUFFMANTABLEMARKER_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGDEFINEHUFFMANTABLEMARKER_H



#include <com/ngos/shared/common/graphics/jpeg/lib/jpeghuffmantable.h>
#include <com/ngos/shared/common/graphics/jpeg/lib/jpegmarkerheader.h>



struct JpegDefineHuffmanTableMarker
{
    JpegMarkerHeader header;
    JpegHuffmanTable tables[0];
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGDEFINEHUFFMANTABLEMARKER_H
