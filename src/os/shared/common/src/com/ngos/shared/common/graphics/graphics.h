#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_GRAPHICS_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_GRAPHICS_H



#include <com/ngos/shared/common/graphics/image.h>
#include <com/ngos/shared/common/ngos/status.h>



class Graphics
{
public:
    static NgosStatus loadImage(bad_uint8 *data, bad_uint64 size, bool withNinePatch, Image **image); // TEST: NO
    static NgosStatus loadImageFromAssets(const char8 *path, Image **image); // TEST: NO
    static NgosStatus makeOpaqueImage(Image *image, bool hasAlpha, Image **res); // TEST: NO
    static NgosStatus insertImage(Image *sourceImage, Image *destinationImage, bad_int64 positionX, bad_int64 positionY, bad_int64 width = 0, bad_int64 height = 0); // TEST: NO
    static NgosStatus insertImageRaw(bad_uint8 *sourceData, bad_uint8 *destinationData, bad_uint16 sourceWidth, bad_uint16 sourceHeight, bad_uint16 destinationWidth, bad_uint16 destinationHeight, bad_uint8 sourceBytesPerPixel, bad_uint8 destinationBytesPerPixel, bool opaque, bad_int64 positionX, bad_int64 positionY); // TEST: NO
    static NgosStatus insertImageRaw(bad_uint8 *sourceData, bad_uint8 *destinationData, bad_uint16 sourceWidth, bad_uint16 sourceHeight, bad_uint16 destinationWidth, bad_uint16 destinationHeight, bad_uint8 sourceBytesPerPixel, bad_uint8 destinationBytesPerPixel, bool opaque, bad_int64 positionX, bad_int64 positionY, bad_int64 left, bad_int64 top, bad_int64 right, bad_int64 bottom); // TEST: NO
    static NgosStatus resizeImage(Image *image, bad_uint16 width, bad_uint16 height, Image **res); // TEST: NO
    static NgosStatus resizeImageProportional(Image *image, bad_uint16 width, bad_uint16 height, Image **res); // TEST: NO

private:
    static NgosStatus resizeImageRaw(bad_uint8 *sourceData, bad_uint8 *destinationData, bad_uint16 sourcePositionX, bad_uint16 sourcePositionY, bad_uint16 destinationPositionX, bad_uint16 destinationPositionY, bad_uint16 sourceWidth, bad_uint16 sourceHeight, bad_uint16 destinationWidth, bad_uint16 destinationHeight, bad_uint64 sourceStride, bad_uint64 destinationStride, bad_uint8 bytesPerPixel); // TEST: NO
};



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_GRAPHICS_H
