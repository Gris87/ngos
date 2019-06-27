#ifndef JPEGSTARTOFFRAMEBASELINEDCTMARKER_H
#define JPEGSTARTOFFRAMEBASELINEDCTMARKER_H



#include <common/src/bits64/graphics/jpeg/jpegmarkerheader.h>
#include <common/src/bits64/graphics/jpeg/jpegstartofframebaselinedctcomponent.h>



#define JPEG_START_OF_FRAME_DEFAULT_PRECISION 8



struct JpegStartOfFrameBaselineDctMarker
{
    JpegMarkerHeader                     header;
    u8                                   dataPrecision;
    u16                                  height;
    u16                                  width;
    u8                                   numberOfComponents;
    JpegStartOfFrameBaselineDctComponent components[0];
} __attribute__((packed));



#endif // JPEGSTARTOFFRAMEBASELINEDCTMARKER_H
