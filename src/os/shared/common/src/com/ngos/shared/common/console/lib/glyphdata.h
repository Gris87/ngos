#ifndef OS_SHARED_COMMON_SRC_BITS64_CONSOLE_LIB_GLYPHDATA_H
#define OS_SHARED_COMMON_SRC_BITS64_CONSOLE_LIB_GLYPHDATA_H



#include <common/src/com/ngos/shared/common/ngos/types.h>



struct GlyphData
{
    u8 width;
    i8 bitmapLeft;
    i8 bitmapTop;
    u8 bitmapWidth;
    u8 bitmapHeight;
    u8 bitmap[0];
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_CONSOLE_LIB_GLYPHDATA_H
