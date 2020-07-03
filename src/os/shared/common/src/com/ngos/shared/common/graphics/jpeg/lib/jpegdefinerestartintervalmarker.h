#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGDEFINERESTARTINTERVALMARKER_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGDEFINERESTARTINTERVALMARKER_H



#include <common/src/com/ngos/shared/common/graphics/jpeg/lib/jpegmarkerheader.h>



struct JpegDefineRestartIntervalMarker
{
    JpegMarkerHeader header;
    u16              restartInterval;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGDEFINERESTARTINTERVALMARKER_H
