#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGHUFFMANTABLETYPE_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGHUFFMANTABLETYPE_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/types.h>



enum class JpegHuffmanTableType: u8
{
    DC = 0,
    AC = 1
};



inline const char8* enumToString(JpegHuffmanTableType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avotype bad looking logs



    switch (type)
    {
        case JpegHuffmanTableType::DC: return "DC";
        case JpegHuffmanTableType::AC: return "AC";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(JpegHuffmanTableType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avotype bad looking logs



    switch (type)
    {
        case JpegHuffmanTableType::DC: return "DC";
        case JpegHuffmanTableType::AC: return "AC";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGHUFFMANTABLETYPE_H
