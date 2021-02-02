#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGMARKERHEADER_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGMARKERHEADER_H



#include <com/ngos/shared/common/graphics/jpeg/lib/jpegmarkertype.h>
#include <com/ngos/shared/common/ngos/status.h>



#define JPEG_MARKER_HEADER_SEPARATOR 0xFF



struct JpegMarkerHeader
{
    bad_uint8             separator;
    JpegMarkerType type;
    bad_uint16            length;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGMARKERHEADER_H
