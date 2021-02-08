#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGSTARTOFFRAMECOMPONENT_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGSTARTOFFRAMECOMPONENT_H



#include <com/ngos/shared/common/graphics/jpeg/lib/jpegcomponentid.h>
#include <com/ngos/shared/common/graphics/jpeg/lib/jpegstartofframecomponentsamplingfactor.h>



struct JpegStartOfFrameComponent
{
    JpegComponentId                         id;
    JpegStartOfFrameComponentSamplingFactor samplingFactor;
    u8                                      quantizationTableId;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGSTARTOFFRAMECOMPONENT_H
