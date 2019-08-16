#include "graphics.h"

#include <common/src/bits64/graphics/bmp/bmp.h>
#include <common/src/bits64/graphics/bmp/lib/bmpheader.h>
#include <common/src/bits64/graphics/jpeg/jpeg.h>
#include <common/src/bits64/graphics/jpeg/lib/jpegmarkertype.h>
#include <common/src/bits64/graphics/png/lib/pngheader.h>
#include <common/src/bits64/graphics/png/png.h>
#include <common/src/bits64/graphics/rgbapixel.h>
#include <common/src/bits64/graphics/rgbpixel.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/memory/malloc.h>
#include <ngos/utils.h>



NgosStatus Graphics::loadImage(u8 *data, u64 size, Image **image)
{
    COMMON_LT((" | data = 0x%p, size = %u, image = 0x%p", data, size, image));

    COMMON_ASSERT(data,     "data is null",  NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0, "size is zero",  NgosStatus::ASSERTION);
    COMMON_ASSERT(image,    "image is null", NgosStatus::ASSERTION);



    if (size >= 8)
    {
        if (*((u64 *)&data[0]) == PNG_HEADER_SIGNATURE)
        {
            return Png::loadImage(data, size, image);
        }



        if (
            *((u16 *)&data[0])        == JPEG_START_OF_IMAGE_SIGNATURE
            &&
            *((u16 *)&data[size - 2]) == JPEG_END_OF_IMAGE_SIGNATURE
           )
        {
            return Jpeg::loadImage(data, size, image);
        }



        if (*((u16 *)&data[0]) == BMP_HEADER_SIGNATURE)
        {
            return Bmp::loadImage(data, size, image);
        }
    }



    COMMON_LC(("Failed to load image from not supported image format"));

    *image = 0;



    return NgosStatus::NOT_SUPPORTED;
}

NgosStatus Graphics::resizeImage(Image *image, u16 width, u16 height, Image **res)
{
    COMMON_LT((" | image = 0x%p, width = %u, height = %u, res = 0x%p", image, width, height, res));

    COMMON_ASSERT(image, "image is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(res,   "res is null",   NgosStatus::ASSERTION);



    if (
        width // width > 0
        &&
        height // height > 0
       )
    {
        u8  bytesPerPixel  = image->hasAlpha ? sizeof(RgbaPixel) : sizeof(RgbPixel);
        u64 originalStride = image->width * bytesPerPixel;
        u64 stride         = width * bytesPerPixel;



        Image *newImage = (Image *)malloc(sizeof(Image) + height * stride);

        if (!newImage)
        {
            COMMON_LE(("Failed to allocate space for raw image data. Out of space"));

            return NgosStatus::OUT_OF_MEMORY;
        }

        newImage->width    = width;
        newImage->height   = height;
        newImage->hasAlpha = image->hasAlpha;



        COMMON_ASSERT_EXECUTION(resizeImagePart(image->data, 0, 0, image->width, image->height, originalStride, newImage->data, 0, 0, width, height, stride, bytesPerPixel), NgosStatus::ASSERTION);



        *res = newImage;
    }
    else
    {
        *res = 0;
    }



    return NgosStatus::OK;
}

NgosStatus Graphics::resizeImageProportional(Image *image, u16 width, u16 height, Image **res)
{
    COMMON_LT((" | image = 0x%p, width = %u, height = %u, res = 0x%p", image, width, height, res));

    COMMON_ASSERT(image, "image is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(res,   "res is null",   NgosStatus::ASSERTION);



    u16 size = MIN(width, height);

    u16 newWidth;
    u16 newHeight;

    if (image->width > image->height)
    {
        newWidth  = size * image->height / image->width;
        newHeight = size * image->height / image->width;
    }
    else
    {
        newWidth  = size * image->width / image->height;
        newHeight = size * image->width / image->height;
    }



    return resizeImage(image, newWidth, newHeight, res);
}

NgosStatus Graphics::resizeImagePart(u8 *originalData, u16 originalPositionX, u16 originalPositionY, u16 originalWidth, u16 originalHeight, u64 originalStride, u8 *data, u16 positionX, u16 positionY, u16 width, u16 height, u64 stride, u8 bytesPerPixel)
{
    COMMON_LT((" | originalData = 0x%p, originalPositionX = %u, originalPositionY = %u, originalWidth = %u, originalHeight = %u, originalStride = %u, data = 0x%p, positionX = %u, positionY = %u, width = %u, height = %u, stride = %u, bytesPerPixel = %u", originalData, originalPositionX, originalPositionY, originalWidth, originalHeight, originalStride, data, positionX, positionY, width, height, stride, bytesPerPixel));

    COMMON_ASSERT(originalData,       "originalData is null",   NgosStatus::ASSERTION);
    COMMON_ASSERT(originalWidth > 0,  "originalWidth is zero",  NgosStatus::ASSERTION);
    COMMON_ASSERT(originalHeight > 0, "originalHeight is zero", NgosStatus::ASSERTION);
    COMMON_ASSERT(originalStride > 0, "originalStride is zero", NgosStatus::ASSERTION);
    COMMON_ASSERT(data,               "data is null",           NgosStatus::ASSERTION);
    COMMON_ASSERT(width > 0,          "width is zero",          NgosStatus::ASSERTION);
    COMMON_ASSERT(height > 0,         "height is zero",         NgosStatus::ASSERTION);
    COMMON_ASSERT(stride > 0,         "stride is zero",         NgosStatus::ASSERTION);
    COMMON_ASSERT(bytesPerPixel > 0,  "bytesPerPixel is zero",  NgosStatus::ASSERTION);



    for (i64 i = 0; i < height; ++i)
    {
        for (i64 j = 0; j < width; ++j)
        {
            i64 originalLeft   = j > 0 ? originalPositionX + (j - 1) * originalWidth  / width : originalPositionX;  // Ignore CppEqualAlignmentVerifier
            i64 originalRight  =         originalPositionX + (j + 1) * originalWidth  / width;                      // Ignore CppEqualAlignmentVerifier
            i64 originalTop    = i > 0 ? originalPositionY + (i - 1) * originalHeight / height : originalPositionY; // Ignore CppEqualAlignmentVerifier
            i64 originalBottom =         originalPositionY + (i + 1) * originalHeight / height;                     // Ignore CppEqualAlignmentVerifier



            u8 *targetData = &data[(positionY + i) * stride + (positionX + j) * bytesPerPixel];

            for (i64 k = 0; k < bytesPerPixel; ++k)
            {
                u64 sum   = 0;
                u64 total = 0;

                for (i64 g = originalTop; g < originalBottom; ++g)
                {
                    for (i64 h = originalLeft; h < originalRight; ++h)
                    {
                        sum += originalData[g * originalStride + h * bytesPerPixel + k];

                        ++total;
                    }
                }

                if (total) // total > 0
                {
                    targetData[k] = sum / total;
                }
                else
                {
                    targetData[k] = originalData[originalTop * originalStride + originalLeft * bytesPerPixel + k];
                }
            }
        }
    }



    return NgosStatus::OK;
}
