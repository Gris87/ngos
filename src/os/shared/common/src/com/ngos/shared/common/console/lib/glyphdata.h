#ifndef COM_NGOS_SHARED_COMMON_CONSOLE_LIB_GLYPHDATA_H
#define COM_NGOS_SHARED_COMMON_CONSOLE_LIB_GLYPHDATA_H



#include <com/ngos/shared/common/ngos/types.h>



struct GlyphData
{
    bad_uint8 width;
    bad_int8 bitmapLeft;
    bad_int8 bitmapTop;
    bad_uint8 bitmapWidth;
    bad_uint8 bitmapHeight;
    bad_uint8 bitmap[0];
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_CONSOLE_LIB_GLYPHDATA_H
