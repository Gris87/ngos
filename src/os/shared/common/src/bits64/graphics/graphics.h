#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_GRAPHICS_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_GRAPHICS_H



#include <common/src/bits64/graphics/image.h>
#include <ngos/status.h>



class Graphics
{
public:
    static NgosStatus loadImage(u8 *data, u64 size, Image **image); // TEST: NO
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_GRAPHICS_H
