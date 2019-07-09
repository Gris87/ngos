#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGDEFINERESTARTINTERVALMARKER_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGDEFINERESTARTINTERVALMARKER_H



#include <common/src/bits64/graphics/jpeg/jpegmarkerheader.h>



struct JpegDefineRestartIntervalMarker
{
    JpegMarkerHeader header;
    u16              restartInterval;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGDEFINERESTARTINTERVALMARKER_H
