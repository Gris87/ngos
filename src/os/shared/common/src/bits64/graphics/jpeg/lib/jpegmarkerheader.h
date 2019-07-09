#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGMARKERHEADER_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGMARKERHEADER_H



#include <common/src/bits64/graphics/jpeg/lib/jpegmarkertype.h>
#include <ngos/status.h>



#define JPEG_MARKER_HEADER_SEPARATOR 0xFF



struct JpegMarkerHeader
{
    u8             separator;
    JpegMarkerType type;
    u16            length;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGMARKERHEADER_H
