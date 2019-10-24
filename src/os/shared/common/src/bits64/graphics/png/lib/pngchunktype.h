#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGCHUNKTYPE_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGCHUNKTYPE_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/types.h>



enum class PngChunkType: u32 // Ignore CppEnumVerifier
{
    IHDR = 0x52444849,  // "IHDR"
    CHRM = 0x4D524863,  // "cHRM"
    GAMA = 0x414D4167,  // "gAMA"
    ICCP = 0x50434369,  // "iCCP"
    SBIT = 0x54494273,  // "sBIT"
    SRGB = 0x42475273,  // "sRGB"
    PLTE = 0x45544C50,  // "PLTE"
    BKGD = 0x44474B62,  // "bKGD"
    HIST = 0x54534968,  // "hIST"
    TRNS = 0x534E5274,  // "tRNS"
    PHYS = 0x73594870,  // "pHYs"
    SPLT = 0x544C5073,  // "sPLT"
    TIME = 0x454D4974,  // "tIME"
    ITXT = 0x74585469,  // "iTXt"
    TEXT = 0x74584574,  // "tEXt"
    ZTXT = 0x7458547A,  // "zTXt"
    IDAT = 0x54414449,  // "IDAT"
    IEND = 0x444E4549   // "IEND"
};



inline const char8* pngChunkTypeToString(PngChunkType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[5];

    *((u32 *)res) = (u32)type;
    COMMON_TEST_ASSERT(res[4] == 0, 0);

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGCHUNKTYPE_H
