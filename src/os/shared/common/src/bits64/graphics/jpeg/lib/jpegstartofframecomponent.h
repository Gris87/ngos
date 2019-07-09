#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGSTARTOFFRAMECOMPONENT_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGSTARTOFFRAMECOMPONENT_H



#include <common/src/bits64/graphics/jpeg/jpegcomponentid.h>
#include <ngos/types.h>



struct JpegStartOfFrameComponent
{
    JpegComponentId id;
    u8              samplingFactorY: 4,
                    samplingFactorX: 4;
    u8              quantizationTableId;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGSTARTOFFRAMECOMPONENT_H
