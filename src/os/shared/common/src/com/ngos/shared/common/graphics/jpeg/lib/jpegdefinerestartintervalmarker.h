#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGDEFINERESTARTINTERVALMARKER_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGDEFINERESTARTINTERVALMARKER_H



#include <com/ngos/shared/common/graphics/jpeg/lib/jpegmarkerheader.h>



struct JpegDefineRestartIntervalMarker
{
    JpegMarkerHeader header;
    bad_uint16              restartInterval;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGDEFINERESTARTINTERVALMARKER_H
