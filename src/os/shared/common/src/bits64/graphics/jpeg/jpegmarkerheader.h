#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGMARKERHEADER_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGMARKERHEADER_H



#include <common/src/bits64/graphics/jpeg/jpegmarkertype.h>
#include <ngos/status.h>



#define JPEG_MARKER_HEADER_SEPARATOR 0xFF



struct JpegMarkerHeader
{
    u8             separator;
    JpegMarkerType type;
    u16            length;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGMARKERHEADER_H
