#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGHUFFMANTABLETYPE_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGHUFFMANTABLETYPE_H



#include <common/src/com/ngos/shared/common/log/assert.h>
#include <common/src/com/ngos/shared/common/log/log.h>
#include <common/src/com/ngos/shared/common/printf/printf.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



enum class JpegHuffmanTableType: u8
{
    DC = 0,
    AC = 1
};



inline const char8* enumToString(JpegHuffmanTableType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case JpegHuffmanTableType::DC: return "DC";
        case JpegHuffmanTableType::AC: return "AC";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(JpegHuffmanTableType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGHUFFMANTABLETYPE_H
