#ifndef JPEGSTARTOFFRAMEBASELINEDCTCOMPONENT_H
#define JPEGSTARTOFFRAMEBASELINEDCTCOMPONENT_H



#include <ngos/types.h>



struct JpegStartOfFrameBaselineDctComponent
{
    u8 id;
    u8 samplingFactors;
    u8 quantizationTableId;
} __attribute__((packed));



#endif // JPEGSTARTOFFRAMEBASELINEDCTCOMPONENT_H
