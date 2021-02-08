#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGSTARTOFSCANCOMPONENTHUFFMANTABLEIDS_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGSTARTOFSCANCOMPONENTHUFFMANTABLEIDS_H



#include <com/ngos/shared/common/ngos/types.h>



struct JpegStartOfScanComponentHuffmanTableIds
{
    union
    {
        struct
        {
            u8 ac: 4;
            u8 dc: 4;
        };

        u8 value8;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGSTARTOFSCANCOMPONENTHUFFMANTABLEIDS_H
