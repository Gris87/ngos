#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGQUANTIZATIONTABLE_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGQUANTIZATIONTABLE_H



#include <ngos/types.h>



#define JPEG_QUANTIZATION_TABLE_COUNT 4



struct JpegQuantizationTable
{
    u8  id:        4;
    u8  precision: 4;

    u8  data8[0];
    u16 data16[0];
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGQUANTIZATIONTABLE_H
