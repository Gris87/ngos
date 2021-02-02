#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGSTARTOFFRAMECOMPONENTSAMPLINGFACTOR_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGSTARTOFFRAMECOMPONENTSAMPLINGFACTOR_H



#include <com/ngos/shared/common/ngos/types.h>



struct JpegStartOfFrameComponentSamplingFactor
{
    union
    {
        struct
        {
            bad_uint8 y: 4;
            bad_uint8 x: 4;
        };

        bad_uint8 value8;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGSTARTOFFRAMECOMPONENTSAMPLINGFACTOR_H
