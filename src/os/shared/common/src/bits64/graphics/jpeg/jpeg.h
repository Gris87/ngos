#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEG_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEG_H



#include <common/src/bits64/graphics/image.h>
#include <ngos/status.h>



class Jpeg
{
public:
    static NgosStatus loadImage(u8 *data, u64 size, Image **image);
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEG_H
