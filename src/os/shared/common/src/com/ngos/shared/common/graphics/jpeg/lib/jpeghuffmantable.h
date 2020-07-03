#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGHUFFMANTABLE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGHUFFMANTABLE_H



#include <com/ngos/shared/common/graphics/jpeg/lib/jpeghuffmantabletype.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>



#define JPEG_HUFFMAN_TABLE_COUNT 4

#define JPEG_HUFFMAN_NUMBER_OF_SYMBOLS_COUNT 16



struct JpegHuffmanTable
{
    union
    {
        struct
        {
            u8 id:         4;
            u8 type:       1; // TODO: Use enum JpegHuffmanTableType
            u8 __reserved: 3;
        };

        u8 idAndType;
    };

    u8 numberOfSymbols[JPEG_HUFFMAN_NUMBER_OF_SYMBOLS_COUNT];
    u8 symbols[0];
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGHUFFMANTABLE_H
