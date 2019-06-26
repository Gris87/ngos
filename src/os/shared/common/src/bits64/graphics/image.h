#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_IMAGE_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_IMAGE_H



#include <ngos/types.h>



struct Image
{
    u16  width;
    u16  height;
    bool hasAlpha;
    u8   data[0];
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_IMAGE_H
