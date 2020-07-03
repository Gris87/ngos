#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGSTARTOFFRAMEMARKER_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGSTARTOFFRAMEMARKER_H



#include <common/src/com/ngos/shared/common/graphics/jpeg/lib/jpegmarkerheader.h>
#include <common/src/com/ngos/shared/common/graphics/jpeg/lib/jpegstartofframecomponent.h>



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



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGSTARTOFFRAMEMARKER_H
