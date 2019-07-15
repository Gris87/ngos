#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGHUFFMANTABLE_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGHUFFMANTABLE_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/types.h>



#define JPEG_HUFFMAN_TABLE_COUNT 4

#define JPEG_HUFFMAN_NUMBER_OF_SYMBOLS_COUNT 16

#define JPEG_HUFFMAN_TABLE_TYPE_DC 0
#define JPEG_HUFFMAN_TABLE_TYPE_AC 1



struct JpegHuffmanTable
{
    u8  id:         4,
        type:       1,
        __reserved: 3;

    u8  numberOfSymbols[JPEG_HUFFMAN_NUMBER_OF_SYMBOLS_COUNT];
    u8  symbols[0];
} __attribute__((packed));



inline const char* jpegHuffmanTableTypeToString(u8 type) 
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case JPEG_HUFFMAN_TABLE_TYPE_DC: return "DC";
        case JPEG_HUFFMAN_TABLE_TYPE_AC: return "AC";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGHUFFMANTABLE_H
