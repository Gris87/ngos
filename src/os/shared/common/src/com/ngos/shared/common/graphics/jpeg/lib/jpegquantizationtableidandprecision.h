#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGQUANTIZATIONTABLEIDANDPRECISION_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGQUANTIZATIONTABLEIDANDPRECISION_H



#include <com/ngos/shared/common/ngos/types.h>



struct JpegQuantizationTableIdAndPrecision
{
    union
    {
        struct
        {
            u8 id:        4;
            u8 precision: 4;
        };

        u8 value8;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGQUANTIZATIONTABLEIDANDPRECISION_H
