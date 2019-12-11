#include "bmp.h"

#include <common/src/bits64/graphics/bmp/lib/bmpcolormap.h>
#include <common/src/bits64/graphics/bmp/lib/bmpheader.h>
#include <common/src/bits64/graphics/bmp/lib/bmpinformationheader.h>
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

    COMMON_ASSERT(*(u16 *)&data[0] == BMP_HEADER_SIGNATURE, "data is invalid", NgosStatus::ASSERTION);



    *image = 0;



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



    if (bmpHeader->size != size)
    {
        COMMON_LE(("Invalid BMP image"));

        return NgosStatus::INVALID_DATA;
    }



    BmpInformationHeader *bmpInfoHeader = (BmpInformationHeader *)((u64)bmpHeader + sizeof(BmpHeader));

    COMMON_LVVV(("bmpInfoHeader->headerSize        = %u", bmpInfoHeader->headerSize));
    COMMON_LVVV(("bmpInfoHeader->width             = %u", bmpInfoHeader->width));
    COMMON_LVVV(("bmpInfoHeader->height            = %u", bmpInfoHeader->height));
    COMMON_LVVV(("bmpInfoHeader->numberOfPlanes    = %u", bmpInfoHeader->numberOfPlanes));
    COMMON_LVVV(("bmpInfoHeader->bitsPerPixel      = %u", bmpInfoHeader->bitsPerPixel));
    COMMON_LVVV(("bmpInfoHeader->compressionMethod = %s", enumToFullString(bmpInfoHeader->compressionMethod)));
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
        COMMON_LE(("Unsupported BMP compression method %s", enumToFullString(bmpInfoHeader->compressionMethod)));

        return NgosStatus::NOT_SUPPORTED;
    }



    u16 imageOffset  = bmpHeader->imageOffset;
    u32 width        = bmpInfoHeader->width;
    u32 height       = bmpInfoHeader->height;
    u16 bitsPerPixel = bmpInfoHeader->bitsPerPixel;



    if (
        !width // width == 0
        ||
        !height // height == 0
        ||
        width > 0xFFFF
        ||
        height > 0xFFFF
       )
    {
        COMMON_LE(("BMP image has invalid size %u x %u", width, height));

        return NgosStatus::INVALID_DATA;
    }



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

    COMMON_LVVV(("stride = %u", stride));



    if (imageOffset + stride * height > size)
    {
        COMMON_LE(("Invalid BMP image"));

        return NgosStatus::INVALID_DATA;
    }



    *image = new Image(width, height, false, true);



    BmpColorMap *colorMap  = (BmpColorMap *)((u64)bmpInfoHeader + sizeof(BmpInformationHeader));
    u8          *imageData = (u8 *)((u64)bmpHeader + imageOffset);
    RgbPixel    *pixelData = (*image)->getRgbBuffer();
    u8           byteValue = 0;

    for (i64 y = height - 1; y >= 0; --y)
    {
        u8 *imageByte =  imageData;
        imageData     += stride;

        RgbPixel *pixel = pixelData + y * width;

        switch (bitsPerPixel)
        {
            case 1:
            {
                for (i64 x = 0; x < width; ++x)
                {
                    u8 index = x & 0x07;

                    if (!index) // index == 0
                    {
                        byteValue = *imageByte;
                        ++imageByte;
                    }

                    index = (byteValue >> (7 - index)) & 0x01;



                    pixel->red   = colorMap[index].red;
                    pixel->green = colorMap[index].green;
                    pixel->blue  = colorMap[index].blue;

                    ++pixel;
                }
            }
            break;

            case 4:
            {
                for (i64 x = 0; x <= width - 2; x += 2)
                {
                    byteValue = *imageByte;
                    ++imageByte;

                    u8 index  = byteValue >> 4;
                    u8 index2 = byteValue & 0x0F;



                    pixel->red   = colorMap[index].red;
                    pixel->green = colorMap[index].green;
                    pixel->blue  = colorMap[index].blue;

                    ++pixel;



                    pixel->red   = colorMap[index2].red;
                    pixel->green = colorMap[index2].green;
                    pixel->blue  = colorMap[index2].blue;

                    ++pixel;
                }

                if (width & 0x01)
                {
                    byteValue = *imageByte;
                    ++imageByte;

                    u8 index = byteValue >> 4;



                    pixel->red   = colorMap[index].red;
                    pixel->green = colorMap[index].green;
                    pixel->blue  = colorMap[index].blue;

                    ++pixel;
                }
            }
            break;

            case 8:
            {
                for (i64 x = 0; x < width; ++x)
                {
                    u8 index = *imageByte;
                    ++imageByte;



                    pixel->red   = colorMap[index].red;
                    pixel->green = colorMap[index].green;
                    pixel->blue  = colorMap[index].blue;

                    ++pixel;
                }
            }
            break;

            case 24:
            {
                for (i64 x = 0; x < width; ++x)
                {
                    pixel->blue  = *imageByte;  ++imageByte;
                    pixel->green = *imageByte;  ++imageByte;
                    pixel->red   = *imageByte;  ++imageByte;

                    ++pixel;
                }
            }
            break;

            default:
            {
                COMMON_LE(("Not supported BMP bits per pixel value: %u", bitsPerPixel));

                return NgosStatus::NOT_SUPPORTED;
            }
            break;
        }
    }



    return NgosStatus::OK;
}
