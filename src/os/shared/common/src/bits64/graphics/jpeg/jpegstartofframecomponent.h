#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGSTARTOFFRAMECOMPONENT_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGSTARTOFFRAMECOMPONENT_H



#include <ngos/types.h>



struct JpegStartOfFrameComponent
{
    u8  id;
    u8  samplingFactorX: 4,
        samplingFactorY: 4;
    u8  quantizationTableId;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGSTARTOFFRAMECOMPONENT_H
