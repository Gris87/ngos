#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGQUANTIZATIONTABLE_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGQUANTIZATIONTABLE_H



#include <com/ngos/shared/common/graphics/jpeg/lib/jpegquantizationtableidandprecision.h>



#define JPEG_QUANTIZATION_TABLE_COUNT 4



struct JpegQuantizationTable
{
    JpegQuantizationTableIdAndPrecision idAndPrecision;
    u8                                  data8[0];
    u16                                 data16[0];
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGQUANTIZATIONTABLE_H
