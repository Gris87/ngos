#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGCHUNKTYPE_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGCHUNKTYPE_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/types.h>



enum class PngChunkType: u32 // Ignore CppEnumVerifier
{
    IHDR = 0x52444849,  // "IHDR"
    SRGB = 0x42475273,  // "sRGB"
    GAMA = 0x414D4167,  // "gAMA"
    PHYS = 0x73594870,  // "pHYs"
    TEXT = 0x74584574,  // "tEXt"
    IDAT = 0x54414449,  // "IDAT"
    IEND = 0x444E4549   // "IEND"
};



inline char* pngChunkTypeToString(PngChunkType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char res[5] __attribute__ ((section (".noinit")));

    *((u32 *)res) = (u32)type;
    COMMON_TEST_ASSERT(res[4] == 0, 0);

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGCHUNKTYPE_H
