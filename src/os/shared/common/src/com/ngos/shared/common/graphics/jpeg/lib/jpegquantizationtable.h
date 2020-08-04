#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGQUANTIZATIONTABLE_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGQUANTIZATIONTABLE_H



#include <com/ngos/shared/common/ngos/types.h>



#define JPEG_QUANTIZATION_TABLE_COUNT 4



struct JpegQuantizationTable
{
    union
    {
        struct
        {
            u8 id:        4;
            u8 precision: 4;
        };

        u8 idAndPrecision;
    };

    u8  data8[0];
    u16 data16[0];
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGQUANTIZATIONTABLE_H
