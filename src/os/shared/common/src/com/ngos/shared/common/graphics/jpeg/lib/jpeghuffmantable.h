#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGHUFFMANTABLE_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGHUFFMANTABLE_H



#include <com/ngos/shared/common/graphics/jpeg/lib/jpeghuffmantableidandtype.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>



#define JPEG_HUFFMAN_TABLE_COUNT 4

#define JPEG_HUFFMAN_NUMBER_OF_SYMBOLS_COUNT 16



struct JpegHuffmanTable
{
    JpegHuffmanTableIdAndType idAndType;
    bad_uint8                        numberOfSymbols[JPEG_HUFFMAN_NUMBER_OF_SYMBOLS_COUNT];
    bad_uint8                        symbols[0];
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGHUFFMANTABLE_H
