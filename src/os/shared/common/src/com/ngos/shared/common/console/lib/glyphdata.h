#ifndef COM_NGOS_SHARED_COMMON_CONSOLE_LIB_GLYPHDATA_H
#define COM_NGOS_SHARED_COMMON_CONSOLE_LIB_GLYPHDATA_H



#include <com/ngos/shared/common/ngos/types.h>



struct GlyphData
{
    u8 width;
    i8 bitmapLeft;
    i8 bitmapTop;
    u8 bitmapWidth;
    u8 bitmapHeight;
    u8 bitmap[0];
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_CONSOLE_LIB_GLYPHDATA_H
