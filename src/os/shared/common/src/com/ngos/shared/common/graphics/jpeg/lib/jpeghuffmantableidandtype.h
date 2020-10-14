#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGHUFFMANTABLEIDANDTYPE_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGHUFFMANTABLEIDANDTYPE_H



#include <com/ngos/shared/common/graphics/jpeg/lib/jpeghuffmantabletype.h>



struct JpegHuffmanTableIdAndType
{
    union
    {
        struct
        {
            u8 id:         4;
            u8 type:       1; // TODO: Use enum JpegHuffmanTableType
            u8 __reserved: 3;
        };

        u8 value8;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGHUFFMANTABLEIDANDTYPE_H
