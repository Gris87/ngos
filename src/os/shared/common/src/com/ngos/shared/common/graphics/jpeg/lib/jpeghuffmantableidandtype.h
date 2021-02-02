#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGHUFFMANTABLEIDANDTYPE_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGHUFFMANTABLEIDANDTYPE_H



#include <com/ngos/shared/common/graphics/jpeg/lib/jpeghuffmantabletype.h>



struct JpegHuffmanTableIdAndType
{
    union
    {
        struct
        {
            bad_uint8 id:         4;
            bad_uint8 type:       1; // TODO: Use enum JpegHuffmanTableType
            bad_uint8 __reserved: 3;
        };

        bad_uint8 value8;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGHUFFMANTABLEIDANDTYPE_H
