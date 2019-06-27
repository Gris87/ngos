#ifndef JPEGQUANTIZATIONTABLE_H
#define JPEGQUANTIZATIONTABLE_H



#include <ngos/types.h>



#define JPEG_QUANTIZATION_TABLE_COUNT 4



struct JpegQuantizationTable
{
    u8 id;
    u8 data[8][8];
} __attribute__((packed));



#endif // JPEGQUANTIZATIONTABLE_H
