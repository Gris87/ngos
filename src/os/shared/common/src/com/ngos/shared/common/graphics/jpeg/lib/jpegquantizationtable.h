#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGQUANTIZATIONTABLE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGQUANTIZATIONTABLE_H



#include <common/src/com/ngos/shared/common/ngos/types.h>



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



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGQUANTIZATIONTABLE_H
