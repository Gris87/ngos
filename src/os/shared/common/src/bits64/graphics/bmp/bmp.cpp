#include "bmp.h"

#include <common/src/bits64/graphics/bmp/bmpheader.h>
#include <common/src/bits64/graphics/bmp/bmpinformationheader.h>
#include <common/src/bits64/graphics/rgbpixel.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/memory/malloc.h>
#include <ngos/utils.h>



NgosStatus Bmp::loadImage(u8 *data, u64 size, Image **image)
{
    COMMON_LT((" | data = 0x%p, size = %u, image = 0x%p", data, size, image));

    COMMON_ASSERT(data,     "data is null",  NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0, "size is zero",  NgosStatus::ASSERTION);
    COMMON_ASSERT(image,    "image is null", NgosStatus::ASSERTION);

    COMMON_ASSERT(*((u16 *)&data[0]) == BMP_HEADER_SIGNATURE, "data is invalid", NgosStatus::ASSERTION);



    BmpHeader *bmpHeader = (BmpHeader *)data;

    if (
        size <= sizeof(BmpHeader) + sizeof(BmpInformationHeader)
        ||
        bmpHeader->signature != BMP_HEADER_SIGNATURE
       )
    {
        COMMON_LE(("Data is not a BMP image"));

        return NgosStatus::INVALID_DATA;
    }



    COMMON_LVVV(("bmpHeader->size        = %u", bmpHeader->size));
    COMMON_LVVV(("bmpHeader->imageOffset = %u", bmpHeader->imageOffset));



    u16 imageOffset = bmpHeader->imageOffset;



    if (bmpHeader->size != size)
    {
        COMMON_LE(("Invalid BMP image"));

        return NgosStatus::INVALID_DATA;
    }

    COMMON_TEST_ASSERT(imageOffset == sizeof(BmpHeader) + sizeof(BmpInformationHeader), NgosStatus::ASSERTION);



    BmpInformationHeader *bmpInfoHeader = (BmpInformationHeader *)((u64)bmpHeader + sizeof(BmpHeader));

    COMMON_LVVV(("bmpInfoHeader->headerSize        = %u", bmpInfoHeader->headerSize));
    COMMON_LVVV(("bmpInfoHeader->width             = %u", bmpInfoHeader->width));
    COMMON_LVVV(("bmpInfoHeader->height            = %u", bmpInfoHeader->height));
    COMMON_LVVV(("bmpInfoHeader->numberOfPlanes    = %u", bmpInfoHeader->numberOfPlanes));
    COMMON_LVVV(("bmpInfoHeader->bitsPerPixel      = %u", bmpInfoHeader->bitsPerPixel));
    COMMON_LVVV(("bmpInfoHeader->compressionMethod = %u (%s)", bmpInfoHeader->compressionMethod, bmpCompressionMethodToString(bmpInfoHeader->compressionMethod)));
    COMMON_LVVV(("bmpInfoHeader->imageSize         = %u", bmpInfoHeader->imageSize));
    COMMON_LVVV(("bmpInfoHeader->xPixelsPerMeter   = %u", bmpInfoHeader->xPixelsPerMeter));
    COMMON_LVVV(("bmpInfoHeader->yPixelsPerMeter   = %u", bmpInfoHeader->yPixelsPerMeter));
    COMMON_LVVV(("bmpInfoHeader->numberOfColors    = %u", bmpInfoHeader->numberOfColors));
    COMMON_LVVV(("bmpInfoHeader->importantColors   = %u", bmpInfoHeader->importantColors));



    COMMON_TEST_ASSERT(bmpInfoHeader->headerSize      == sizeof(BmpInformationHeader), NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(bmpInfoHeader->numberOfPlanes  == 1,                            NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(bmpInfoHeader->imageSize       == 0,                            NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(bmpInfoHeader->numberOfColors  == 0,                            NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(bmpInfoHeader->importantColors == 0,                            NgosStatus::ASSERTION);



    if (bmpInfoHeader->compressionMethod != BmpCompressionMethod::RGB)
    {
        COMMON_LE(("Unsupported BMP compression method %u (%s)", bmpInfoHeader->compressionMethod, bmpCompressionMethodToString(bmpInfoHeader->compressionMethod)));

        return NgosStatus::NOT_SUPPORTED;
    }



    u32 width        = bmpInfoHeader->width;
    u32 height       = bmpInfoHeader->height;
    u16 bitsPerPixel = bmpInfoHeader->bitsPerPixel;



    u64 stride;

    switch (bitsPerPixel)
    {
        case 1:  stride = DIV_UP(width, 8); break;
        case 4:  stride = DIV_UP(width, 2); break;
        case 8:  stride = width;            break;
        case 24: stride = width * 3;        break;

        default:
        {
            COMMON_LE(("Not supported BMP bits per pixel value: %u", bitsPerPixel));

            return NgosStatus::NOT_SUPPORTED;
        }
        break;
    }

    stride = ROUND_UP(stride, 4);



    if (imageOffset + stride * height > size)
    {
        COMMON_LE(("Invalid BMP image"));

        return NgosStatus::INVALID_DATA;
    }



    Image *newImage = (Image *)malloc(sizeof(Image) + width * height * sizeof(RgbPixel));

    if (!image)
    {
        COMMON_LE(("Failed to allocate space for raw image data. Out of space"));

        return NgosStatus::OUT_OF_MEMORY;
    }

    newImage->width    = width;
    newImage->height   = height;
    newImage->hasAlpha = false;



    *image = newImage;



    return NgosStatus::OK;
}
