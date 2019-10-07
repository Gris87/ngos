#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_GRAPHICS_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_GRAPHICS_H



#include <common/src/bits64/graphics/image.h>
#include <ngos/status.h>



class Graphics
{
public:
    static NgosStatus loadImage(u8 *data, u64 size, bool withNinePatch, Image **image); // TEST: NO
    static NgosStatus loadImageFromAssets(const char8 *path, Image **image); // TEST: NO
    static NgosStatus makeOpaqueImage(Image *image, Image **res); // TEST: NO
    static NgosStatus insertImage(Image *sourceImage, Image *destinationImage, i64 positionX, i64 positionY, i64 width = 0, i64 height = 0); // TEST: NO
    static NgosStatus insertImageRaw(u8 *sourceData, u8 *destinationData, u16 sourceWidth, u16 sourceHeight, u16 destinationWidth, u16 destinationHeight, u8 sourceBytesPerPixel, u8 destinationBytesPerPixel, bool opaque, i64 positionX, i64 positionY); // TEST: NO
    static NgosStatus insertImageRaw(u8 *sourceData, u8 *destinationData, u16 sourceWidth, u16 sourceHeight, u16 destinationWidth, u16 destinationHeight, u8 sourceBytesPerPixel, u8 destinationBytesPerPixel, bool opaque, i64 positionX, i64 positionY, i64 left, i64 top, i64 right, i64 bottom); // TEST: NO
    static NgosStatus resizeImage(Image *image, u16 width, u16 height, Image **res); // TEST: NO
    static NgosStatus resizeImageProportional(Image *image, u16 width, u16 height, Image **res); // TEST: NO

private:
    static NgosStatus resizeImageRaw(u8 *sourceData, u8 *destinationData, u16 sourcePositionX, u16 sourcePositionY, u16 destinationPositionX, u16 destinationPositionY, u16 sourceWidth, u16 sourceHeight, u16 destinationWidth, u16 destinationHeight, u64 sourceStride, u64 destinationStride, u8 bytesPerPixel); // TEST: NO
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_GRAPHICS_H
