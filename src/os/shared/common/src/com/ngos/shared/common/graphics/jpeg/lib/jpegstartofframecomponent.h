#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGSTARTOFFRAMECOMPONENT_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGSTARTOFFRAMECOMPONENT_H



#include <com/ngos/shared/common/graphics/jpeg/lib/jpegcomponentid.h>
#include <com/ngos/shared/common/ngos/types.h>



struct JpegStartOfFrameComponent
{
    JpegComponentId id;

    union
    {
        struct
        {
            u8 samplingFactorY: 4;
            u8 samplingFactorX: 4;
        };

        u8 samplingFactor;
    };

    u8 quantizationTableId;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGSTARTOFFRAMECOMPONENT_H
