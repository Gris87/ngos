#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGSTARTOFSCANMARKER_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGSTARTOFSCANMARKER_H



#include <com/ngos/shared/common/graphics/jpeg/lib/jpegmarkerheader.h>
#include <com/ngos/shared/common/graphics/jpeg/lib/jpegstartofscancomponent.h>



struct JpegStartOfScanMarker
{
    JpegMarkerHeader         header;
    u8                       numberOfComponents;
    JpegStartOfScanComponent components[0];
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGSTARTOFSCANMARKER_H
