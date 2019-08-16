#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_GRAPHICS_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_GRAPHICS_H



#include <common/src/bits64/graphics/image.h>
#include <ngos/status.h>



class Graphics
{
public:
    static NgosStatus loadImage(u8 *data, u64 size, Image **image); // TEST: NO
    static NgosStatus resizeImage(Image *image, u16 width, u16 height, Image **res); // TEST: NO
    static NgosStatus resizeImageProportional(Image *image, u16 width, u16 height, Image **res); // TEST: NO

private:
    static NgosStatus resizeImagePart(u8 *originalData, u16 originalPositionX, u16 originalPositionY, u16 originalWidth, u16 originalHeight, u64 originalStride, u8 *data, u16 positionX, u16 positionY, u16 width, u16 height, u64 stride, u8 bytesPerPixel); // TEST: NO
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_GRAPHICS_H
