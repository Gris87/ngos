#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGSTARTOFFRAMEMARKER_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGSTARTOFFRAMEMARKER_H



#include <common/src/bits64/graphics/jpeg/lib/jpegmarkerheader.h>
#include <common/src/bits64/graphics/jpeg/lib/jpegstartofframecomponent.h>



#define JPEG_START_OF_FRAME_DEFAULT_PRECISION 8



struct JpegStartOfFrameMarker
{
    JpegMarkerHeader          header;
    u8                        dataPrecision;
    u16                       height;
    u16                       width;
    u8                        numberOfComponents;
    JpegStartOfFrameComponent components[0];
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGSTARTOFFRAMEMARKER_H
