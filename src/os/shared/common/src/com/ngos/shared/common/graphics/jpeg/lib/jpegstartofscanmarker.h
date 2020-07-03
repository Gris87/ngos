#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGSTARTOFSCANMARKER_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGSTARTOFSCANMARKER_H



#include <common/src/com/ngos/shared/common/graphics/jpeg/lib/jpegmarkerheader.h>
#include <common/src/com/ngos/shared/common/graphics/jpeg/lib/jpegstartofscancomponent.h>



struct JpegStartOfScanMarker
{
    JpegMarkerHeader         header;
    u8                       numberOfComponents;
    JpegStartOfScanComponent components[0];
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGSTARTOFSCANMARKER_H
