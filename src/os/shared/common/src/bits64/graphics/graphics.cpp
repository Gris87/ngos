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
#include <common/src/bits64/memory/memory.h>
#include <ngos/utils.h>



NgosStatus Graphics::loadImage(u8 *data, u64 size, bool withNinePatch, Image **image)
{
    COMMON_LT((" | data = 0x%p, size = %u, withNinePatch = %u, image = 0x%p", data, size, withNinePatch, image));

    COMMON_ASSERT(data,     "data is null",  NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0, "size is zero",  NgosStatus::ASSERTION);
    COMMON_ASSERT(image,    "image is null", NgosStatus::ASSERTION);



    if (size >= 8)
    {
        if (*((u64 *)&data[0]) == PNG_HEADER_SIGNATURE)
        {
            return Png::loadImage(data, size, withNinePatch, image);
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

NgosStatus Graphics::makeOpaqueImage(Image *image, Image **res)
{
    COMMON_LT((" | image = 0x%p, res = 0x%p", image, res));

    COMMON_ASSERT(image, "image is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(res,   "res is null",   NgosStatus::ASSERTION);



    if (
        !image->isRgba()
        ||
        !image->isOpaque()
       )
    {
        i64    resolution    = image->getWidth() * image->getHeight();
        u8     bytesPerPixel = image->getBytesPerPixel();
        Image *newImage      = new Image(image->getWidth(), image->getHeight(), true, true);



        u8        *data  = image->getBuffer();
        RgbaPixel *pixel = newImage->getRgbaBuffer();

        for (i64 i = 0; i < resolution; ++i)
        {
            RgbPixel *originalPixel = (RgbPixel *)data;

            pixel->red   = originalPixel->red;
            pixel->green = originalPixel->green;
            pixel->blue  = originalPixel->blue;
            pixel->alpha = 0xFF;

            data += bytesPerPixel;
            ++pixel;
        }



        *res = newImage;
    }
    else
    {
        *res = image;

        return NgosStatus::NO_EFFECT;
    }



    return NgosStatus::OK;
}

NgosStatus Graphics::insertImage(Image *sourceImage, Image *destinationImage, i64 positionX, i64 positionY, i64 width, i64 height)
{
    COMMON_LT((" | sourceImage = 0x%p, destinationImage = 0x%p, positionX = %d, positionY = %d, width = %d, height = %d", sourceImage, destinationImage, positionX, positionY, width, height));

    COMMON_ASSERT(sourceImage,      "sourceImage is null",      NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationImage, "destinationImage is null", NgosStatus::ASSERTION);



    Image *image;

    if (
        width > 0
        &&
        height > 0
        &&
        (
         width != sourceImage->getWidth()
         ||
         height != sourceImage->getHeight()
        )
       )
    {
        COMMON_ASSERT_EXECUTION(resizeImage(sourceImage, width, height, &image), NgosStatus::ASSERTION);
    }
    else
    {
        image = sourceImage;
    }



    COMMON_ASSERT_EXECUTION(insertImageRaw(image->getBuffer(), destinationImage->getBuffer(), image->getWidth(), image->getHeight(), destinationImage->getWidth(), destinationImage->getHeight(), image->getBytesPerPixel(), destinationImage->getBytesPerPixel(), image->isOpaque() && destinationImage->isOpaque(), positionX, positionY), NgosStatus::ASSERTION);



    if (image != sourceImage)
    {
        delete image;
    }



    return NgosStatus::OK;
}

NgosStatus Graphics::insertImageRaw(u8 *sourceData, u8 *destinationData, u16 sourceWidth, u16 sourceHeight, u16 destinationWidth, u16 destinationHeight, u8 sourceBytesPerPixel, u8 destinationBytesPerPixel, bool opaque, i64 positionX, i64 positionY)
{
    COMMON_LT((" | sourceData = 0x%p, destinationData = 0x%p, sourceWidth = %u, sourceHeight = %u, destinationWidth = %u, destinationHeight = %u, sourceBytesPerPixel = %u, destinationBytesPerPixel = %u, opaque = %u, positionX = %d, positionY = %d", sourceData, destinationData, sourceWidth, sourceHeight, destinationWidth, destinationHeight, sourceBytesPerPixel, destinationBytesPerPixel, opaque, positionX, positionY));

    COMMON_ASSERT(sourceData,                   "sourceData is null",               NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationData,              "destinationData is null",          NgosStatus::ASSERTION);
    COMMON_ASSERT(sourceWidth > 0,              "sourceWidth is zero",              NgosStatus::ASSERTION);
    COMMON_ASSERT(sourceHeight > 0,             "sourceHeight is zero",             NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationWidth > 0,         "destinationWidth is zero",         NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationHeight > 0,        "destinationHeight is zero",        NgosStatus::ASSERTION);
    COMMON_ASSERT(sourceBytesPerPixel > 0,      "sourceBytesPerPixel is zero",      NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationBytesPerPixel > 0, "destinationBytesPerPixel is zero", NgosStatus::ASSERTION);



    return insertImageRaw(sourceData, destinationData, sourceWidth, sourceHeight, destinationWidth, destinationHeight, sourceBytesPerPixel, destinationBytesPerPixel, opaque, positionX, positionY, 0, 0, sourceWidth, sourceHeight);
}

NgosStatus Graphics::insertImageRaw(u8 *sourceData, u8 *destinationData, u16 sourceWidth, u16 sourceHeight, u16 destinationWidth, u16 destinationHeight, u8 sourceBytesPerPixel, u8 destinationBytesPerPixel, bool opaque, i64 positionX, i64 positionY, i64 left, i64 top, i64 right, i64 bottom)
{
    COMMON_LT((" | sourceData = 0x%p, destinationData = 0x%p, sourceWidth = %u, sourceHeight = %u, destinationWidth = %u, destinationHeight = %u, sourceBytesPerPixel = %u, destinationBytesPerPixel = %u, opaque = %u, positionX = %d, positionY = %d, left = %d, top = %d, right = %d, bottom = %d", sourceData, destinationData, sourceWidth, sourceHeight, destinationWidth, destinationHeight, sourceBytesPerPixel, destinationBytesPerPixel, opaque, positionX, positionY, left, top, right, bottom));

    COMMON_ASSERT(sourceData,                   "sourceData is null",               NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationData,              "destinationData is null",          NgosStatus::ASSERTION);
    COMMON_ASSERT(sourceWidth > 0,              "sourceWidth is zero",              NgosStatus::ASSERTION);
    COMMON_ASSERT(sourceHeight > 0,             "sourceHeight is zero",             NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationWidth > 0,         "destinationWidth is zero",         NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationHeight > 0,        "destinationHeight is zero",        NgosStatus::ASSERTION);
    COMMON_ASSERT(sourceBytesPerPixel > 0,      "sourceBytesPerPixel is zero",      NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationBytesPerPixel > 0, "destinationBytesPerPixel is zero", NgosStatus::ASSERTION);
    COMMON_ASSERT(right > left,                 "right is invalid",                 NgosStatus::ASSERTION);
    COMMON_ASSERT(bottom > top,                 "bottom is invalid",                NgosStatus::ASSERTION);

    AVOID_UNUSED(sourceHeight);



    if (positionX + left < 0)
    {
        left = -positionX;
    }

    if (positionX + right > destinationWidth)
    {
        right = destinationWidth - positionX;
    }

    if (positionY + top < 0)
    {
        top = -positionY;
    }

    if (positionY + bottom > destinationHeight)
    {
        bottom = destinationHeight - positionY;
    }



    u64 sourceStride      = sourceWidth      * sourceBytesPerPixel;
    u64 destinationStride = destinationWidth * destinationBytesPerPixel;

    // COMMON_LVVV(("left                     = %d", left));                      // Commented to avoid too frequent logs
    // COMMON_LVVV(("right                    = %d", right));                     // Commented to avoid too frequent logs
    // COMMON_LVVV(("top                      = %d", top));                       // Commented to avoid too frequent logs
    // COMMON_LVVV(("bottom                   = %d", bottom));                    // Commented to avoid too frequent logs
    // COMMON_LVVV(("sourceWidth              = %u", sourceWidth));               // Commented to avoid too frequent logs
    // COMMON_LVVV(("sourceHeight             = %u", sourceHeight));              // Commented to avoid too frequent logs
    // COMMON_LVVV(("destinationWidth         = %u", destinationWidth));          // Commented to avoid too frequent logs
    // COMMON_LVVV(("destinationHeight        = %u", destinationHeight));         // Commented to avoid too frequent logs
    // COMMON_LVVV(("sourceBytesPerPixel      = %u", sourceBytesPerPixel));       // Commented to avoid too frequent logs
    // COMMON_LVVV(("destinationBytesPerPixel = %u", destinationBytesPerPixel));  // Commented to avoid too frequent logs
    // COMMON_LVVV(("sourceStride             = %u", sourceStride));              // Commented to avoid too frequent logs
    // COMMON_LVVV(("destinationStride        = %u", destinationStride));         // Commented to avoid too frequent logs
    // COMMON_LVVV(("positionX                = %d", positionX));                 // Commented to avoid too frequent logs
    // COMMON_LVVV(("positionY                = %d", positionY));                 // Commented to avoid too frequent logs
    // COMMON_LVVV(("opaque                   = %s", opaque ? "true" : "false")); // Commented to avoid too frequent logs



    if (opaque)
    {
        if (sourceBytesPerPixel == destinationBytesPerPixel)
        {
            for (i64 i = top; i < bottom; ++i)
            {
                RgbPixel *sourcePixel      = (RgbPixel *)(sourceData      + i               * sourceStride      + left               * sourceBytesPerPixel);
                RgbPixel *destinationPixel = (RgbPixel *)(destinationData + (positionY + i) * destinationStride + (positionX + left) * destinationBytesPerPixel);

                memcpy(destinationPixel, sourcePixel, (right - left) * sourceBytesPerPixel);
            }
        }
        else
        {
            for (i64 i = top; i < bottom; ++i)
            {
                for (i64 j = left; j < right; ++j)
                {
                    RgbPixel *sourcePixel      = (RgbPixel *)(sourceData      + i               * sourceStride      + j               * sourceBytesPerPixel);
                    RgbPixel *destinationPixel = (RgbPixel *)(destinationData + (positionY + i) * destinationStride + (positionX + j) * destinationBytesPerPixel);

                    destinationPixel->red   = sourcePixel->red;
                    destinationPixel->green = sourcePixel->green;
                    destinationPixel->blue  = sourcePixel->blue;
                }
            }
        }
    }
    else
    {
        if (sourceBytesPerPixel == sizeof(RgbaPixel))
        {
            if (destinationBytesPerPixel == sizeof(RgbaPixel))
            {
                for (i64 i = top; i < bottom; ++i)
                {
                    for (i64 j = left; j < right; ++j)
                    {
                        RgbaPixel *sourcePixel      = (RgbaPixel *)(sourceData      + i               * sourceStride      + j               * sourceBytesPerPixel);
                        RgbaPixel *destinationPixel = (RgbaPixel *)(destinationData + (positionY + i) * destinationStride + (positionX + j) * destinationBytesPerPixel);

                        u8 alpha    = sourcePixel->alpha;
                        u8 notAlpha = ~alpha;

                        // Ignore CppAlignmentVerifier [BEGIN]
                        destinationPixel->red   = (destinationPixel->red   * notAlpha + sourcePixel->red      * alpha) / 0xFF;
                        destinationPixel->green = (destinationPixel->green * notAlpha + sourcePixel->green    * alpha) / 0xFF;
                        destinationPixel->blue  = (destinationPixel->blue  * notAlpha + sourcePixel->blue     * alpha) / 0xFF;
                        destinationPixel->alpha = destinationPixel->alpha  + (0xFF - destinationPixel->alpha) * alpha  / 0xFF;
                        // Ignore CppAlignmentVerifier [END]
                    }
                }
            }
            else
            {
                for (i64 i = top; i < bottom; ++i)
                {
                    for (i64 j = left; j < right; ++j)
                    {
                        RgbaPixel *sourcePixel      = (RgbaPixel *)(sourceData     + i               * sourceStride      + j               * sourceBytesPerPixel);
                        RgbPixel  *destinationPixel = (RgbPixel *)(destinationData + (positionY + i) * destinationStride + (positionX + j) * destinationBytesPerPixel);

                        u8 alpha    = sourcePixel->alpha;
                        u8 notAlpha = ~alpha;

                        destinationPixel->red   = (destinationPixel->red   * notAlpha + sourcePixel->red   * alpha) / 0xFF;
                        destinationPixel->green = (destinationPixel->green * notAlpha + sourcePixel->green * alpha) / 0xFF;
                        destinationPixel->blue  = (destinationPixel->blue  * notAlpha + sourcePixel->blue  * alpha) / 0xFF;
                    }
                }
            }
        }
        else
        {
            for (i64 i = top; i < bottom; ++i)
            {
                for (i64 j = left; j < right; ++j)
                {
                    RgbPixel  *sourcePixel      = (RgbPixel *)(sourceData       + i               * sourceStride      + j               * sourceBytesPerPixel);
                    RgbaPixel *destinationPixel = (RgbaPixel *)(destinationData + (positionY + i) * destinationStride + (positionX + j) * destinationBytesPerPixel);

                    destinationPixel->red   = sourcePixel->red;
                    destinationPixel->green = sourcePixel->green;
                    destinationPixel->blue  = sourcePixel->blue;
                    destinationPixel->alpha = 0xFF;
                }
            }
        }
    }



    return NgosStatus::OK;
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
        Image *newImage = new Image(width, height, image->isRgba(), image->isOpaque());



        NinePatch *patch = image->getNinePatch();

        if (patch)
        {
            List<StretchRange> sourceRangesX;
            List<StretchRange> sourceRangesY;
            List<StretchRange> destinationRangesX;
            List<StretchRange> destinationRangesY;

            bool startWithStretchX;
            bool startWithStretchY;



            // Get sourceRangesX and startWithStretchX
            {
                ListElement<StretchRange> *element = patch->getStretchRangesX().getHead();

                if (element)
                {
                    u16 lastX = element->getData().getFrom();

                    if (lastX) // lastX != 0
                    {
                        startWithStretchX = false;

                        sourceRangesX.append(StretchRange(0, lastX));
                    }
                    else
                    {
                        startWithStretchX = true;
                    }



                    while (element)
                    {
                        sourceRangesX.append(StretchRange(lastX, element->getData().getTo()));
                        lastX = element->getData().getTo();

                        element = element->getNext();

                        if (element)
                        {
                            sourceRangesX.append(StretchRange(lastX, element->getData().getFrom()));
                            lastX = element->getData().getFrom();
                        }
                    }



                    if (lastX != image->getWidth())
                    {
                        sourceRangesX.append(StretchRange(lastX, image->getWidth()));
                    }
                }
                else
                {
                    startWithStretchX = true;

                    sourceRangesX.append(StretchRange(0, image->getWidth()));
                }
            }



            // Get sourceRangesY and startWithStretchY
            {
                ListElement<StretchRange> *element = patch->getStretchRangesY().getHead();

                if (element)
                {
                    u16 lastY = element->getData().getFrom();

                    if (lastY) // lastY != 0
                    {
                        startWithStretchY = false;

                        sourceRangesY.append(StretchRange(0, lastY));
                    }
                    else
                    {
                        startWithStretchY = true;
                    }



                    while (element)
                    {
                        sourceRangesY.append(StretchRange(lastY, element->getData().getTo()));
                        lastY = element->getData().getTo();

                        element = element->getNext();

                        if (element)
                        {
                            sourceRangesY.append(StretchRange(lastY, element->getData().getFrom()));
                            lastY = element->getData().getFrom();
                        }
                    }



                    if (lastY != image->getHeight())
                    {
                        sourceRangesY.append(StretchRange(lastY, image->getHeight()));
                    }
                }
                else
                {
                    startWithStretchY = true;

                    sourceRangesY.append(StretchRange(0, image->getHeight()));
                }
            }



            u16 totalStretchCountX = 0;
            u16 totalStretchCountY = 0;
            u16 totalFixedCountX   = 0;
            u16 totalFixedCountY   = 0;



            // Get totalStretchCountX and totalFixedCountX
            {
                bool                       isCurrentStretch = startWithStretchX;
                ListElement<StretchRange> *element          = sourceRangesX.getHead();

                while (element)
                {
                    if (isCurrentStretch)
                    {
                        totalStretchCountX += element->getData().getSize();
                    }
                    else
                    {
                        totalFixedCountX += element->getData().getSize();
                    }



                    isCurrentStretch = !isCurrentStretch;

                    element = element->getNext();
                }
            }



            // Get totalStretchCountY and totalFixedCountY
            {
                bool                       isCurrentStretch = startWithStretchY;
                ListElement<StretchRange> *element          = sourceRangesY.getHead();

                while (element)
                {
                    if (isCurrentStretch)
                    {
                        totalStretchCountY += element->getData().getSize();
                    }
                    else
                    {
                        totalFixedCountY += element->getData().getSize();
                    }



                    isCurrentStretch = !isCurrentStretch;

                    element = element->getNext();
                }
            }



            // Get destinationRangesX
            {
                u16       totalWidth = 0;
                List<u16> sizes;

                if (width >= totalFixedCountX)
                {
                    u16 stretchableCount = width - totalFixedCountX;



                    bool                       isCurrentStretch = startWithStretchX;
                    ListElement<StretchRange> *element          = sourceRangesX.getHead();

                    while (element)
                    {
                        u16 size = element->getData().getSize();

                        if (isCurrentStretch)
                        {
                            size = stretchableCount * size / totalStretchCountX;
                        }

                        totalWidth += size;
                        sizes.append(size);



                        isCurrentStretch = !isCurrentStretch;

                        element = element->getNext();
                    }



                    COMMON_TEST_ASSERT(totalWidth <= width, NgosStatus::ASSERTION);

                    if (totalWidth < width)
                    {
                        u16 remain = width - totalWidth;

                        while (remain)
                        {
                            isCurrentStretch = startWithStretchX;

                            ListElement<u16> *sizeElement    = sizes.getHead();
                            ListElement<u16> *minSizeElement = 0;

                            while (sizeElement)
                            {
                                if (isCurrentStretch)
                                {
                                    if (!minSizeElement || sizeElement->getData() < minSizeElement->getData())
                                    {
                                        minSizeElement = sizeElement;
                                    }
                                }

                                isCurrentStretch = !isCurrentStretch;

                                sizeElement = sizeElement->getNext();
                            }



                            COMMON_TEST_ASSERT(minSizeElement, NgosStatus::ASSERTION);

                            minSizeElement->setData(minSizeElement->getData() + 1);



                            --remain;
                        }
                    }
                }
                else
                {
                    bool                       isCurrentStretch = startWithStretchX;
                    ListElement<StretchRange> *element          = sourceRangesX.getHead();

                    while (element)
                    {
                        u16 size;

                        if (isCurrentStretch)
                        {
                            size = 0;
                        }
                        else
                        {
                            size = width * element->getData().getSize() / totalFixedCountX;

                            totalWidth += size;
                        }

                        sizes.append(size);



                        isCurrentStretch = !isCurrentStretch;

                        element = element->getNext();
                    }



                    COMMON_TEST_ASSERT(totalWidth <= width, NgosStatus::ASSERTION);

                    if (totalWidth < width)
                    {
                        u16 remain = width - totalWidth;

                        while (remain)
                        {
                            isCurrentStretch = startWithStretchX;

                            ListElement<u16> *sizeElement    = sizes.getHead();
                            ListElement<u16> *minSizeElement = 0;

                            while (sizeElement)
                            {
                                if (!isCurrentStretch)
                                {
                                    if (!minSizeElement || sizeElement->getData() < minSizeElement->getData())
                                    {
                                        minSizeElement = sizeElement;
                                    }
                                }

                                isCurrentStretch = !isCurrentStretch;

                                sizeElement = sizeElement->getNext();
                            }



                            COMMON_TEST_ASSERT(minSizeElement, NgosStatus::ASSERTION);

                            minSizeElement->setData(minSizeElement->getData() + 1);



                            --remain;
                        }
                    }
                }



                totalWidth = 0;

                ListElement<u16> *sizeElement = sizes.getHead();

                while (sizeElement)
                {
                    u16 to = totalWidth + sizeElement->getData();

                    destinationRangesX.append(StretchRange(totalWidth, to));
                    totalWidth = to;

                    sizeElement = sizeElement->getNext();
                }

                COMMON_TEST_ASSERT(totalWidth == width, NgosStatus::ASSERTION);
            }



            // Get destinationRangesY
            {
                u16       totalHeight = 0;
                List<u16> sizes;

                if (height >= totalFixedCountY)
                {
                    u16 stretchableCount = height - totalFixedCountY;



                    bool                       isCurrentStretch = startWithStretchY;
                    ListElement<StretchRange> *element          = sourceRangesY.getHead();

                    while (element)
                    {
                        u16 size = element->getData().getSize();

                        if (isCurrentStretch)
                        {
                            size = stretchableCount * size / totalStretchCountY;
                        }

                        totalHeight += size;
                        sizes.append(size);



                        isCurrentStretch = !isCurrentStretch;

                        element = element->getNext();
                    }



                    COMMON_TEST_ASSERT(totalHeight <= height, NgosStatus::ASSERTION);

                    if (totalHeight < height)
                    {
                        u16 remain = height - totalHeight;

                        while (remain)
                        {
                            isCurrentStretch = startWithStretchY;

                            ListElement<u16> *sizeElement    = sizes.getHead();
                            ListElement<u16> *minSizeElement = 0;

                            while (sizeElement)
                            {
                                if (isCurrentStretch)
                                {
                                    if (!minSizeElement || sizeElement->getData() < minSizeElement->getData())
                                    {
                                        minSizeElement = sizeElement;
                                    }
                                }

                                isCurrentStretch = !isCurrentStretch;

                                sizeElement = sizeElement->getNext();
                            }



                            COMMON_TEST_ASSERT(minSizeElement, NgosStatus::ASSERTION);

                            minSizeElement->setData(minSizeElement->getData() + 1);



                            --remain;
                        }
                    }
                }
                else
                {
                    bool                       isCurrentStretch = startWithStretchY;
                    ListElement<StretchRange> *element          = sourceRangesY.getHead();

                    while (element)
                    {
                        u16 size;

                        if (isCurrentStretch)
                        {
                            size = 0;
                        }
                        else
                        {
                            size = height * element->getData().getSize() / totalFixedCountY;

                            totalHeight += size;
                        }

                        sizes.append(size);



                        isCurrentStretch = !isCurrentStretch;

                        element = element->getNext();
                    }



                    COMMON_TEST_ASSERT(totalHeight <= height, NgosStatus::ASSERTION);

                    if (totalHeight < height)
                    {
                        u16 remain = height - totalHeight;

                        while (remain)
                        {
                            isCurrentStretch = startWithStretchY;

                            ListElement<u16> *sizeElement    = sizes.getHead();
                            ListElement<u16> *minSizeElement = 0;

                            while (sizeElement)
                            {
                                if (!isCurrentStretch)
                                {
                                    if (!minSizeElement || sizeElement->getData() < minSizeElement->getData())
                                    {
                                        minSizeElement = sizeElement;
                                    }
                                }

                                isCurrentStretch = !isCurrentStretch;

                                sizeElement = sizeElement->getNext();
                            }



                            COMMON_TEST_ASSERT(minSizeElement, NgosStatus::ASSERTION);

                            minSizeElement->setData(minSizeElement->getData() + 1);



                            --remain;
                        }
                    }
                }



                totalHeight = 0;

                ListElement<u16> *sizeElement = sizes.getHead();

                while (sizeElement)
                {
                    u16 to = totalHeight + sizeElement->getData();

                    destinationRangesY.append(StretchRange(totalHeight, to));
                    totalHeight = to;

                    sizeElement = sizeElement->getNext();
                }

                COMMON_TEST_ASSERT(totalHeight == height, NgosStatus::ASSERTION);
            }



            // Resize source ranges to destination ranges
            {
                ListElement<StretchRange> *sourceRangeY      = sourceRangesY.getHead();
                ListElement<StretchRange> *destinationRangeY = destinationRangesY.getHead();

                while (sourceRangeY)
                {
                    COMMON_TEST_ASSERT(destinationRangeY, NgosStatus::ASSERTION);



                    ListElement<StretchRange> *sourceRangeX      = sourceRangesX.getHead();
                    ListElement<StretchRange> *destinationRangeX = destinationRangesX.getHead();

                    while (sourceRangeX)
                    {
                        COMMON_TEST_ASSERT(destinationRangeX, NgosStatus::ASSERTION);



                        u16 sourceSizeX      = sourceRangeX->getData().getSize();
                        u16 sourceSizeY      = sourceRangeY->getData().getSize();
                        u16 destinationSizeX = destinationRangeX->getData().getSize();
                        u16 destinationSizeY = destinationRangeY->getData().getSize();

                        if (
                            sourceSizeX == destinationSizeX
                            &&
                            sourceSizeY == destinationSizeY
                           )
                        {
                            COMMON_ASSERT_EXECUTION(insertImageRaw(image->getBuffer(), newImage->getBuffer(), image->getWidth(), image->getHeight(), newImage->getWidth(), newImage->getHeight(), image->getBytesPerPixel(), newImage->getBytesPerPixel(), true, destinationRangeX->getData().getFrom() - sourceRangeX->getData().getFrom(), destinationRangeY->getData().getFrom() - sourceRangeY->getData().getFrom(), sourceRangeX->getData().getFrom(), sourceRangeY->getData().getFrom(), sourceRangeX->getData().getTo(), sourceRangeY->getData().getTo()), NgosStatus::ASSERTION);
                        }
                        else
                        {
                            COMMON_ASSERT_EXECUTION(resizeImageRaw(image->getBuffer(), sourceRangeX->getData().getFrom(), sourceRangeY->getData().getFrom(), sourceSizeX, sourceSizeY, image->getStride(), newImage->getBuffer(), destinationRangeX->getData().getFrom(), destinationRangeY->getData().getFrom(), destinationSizeX, destinationSizeY, newImage->getStride(), newImage->getBytesPerPixel()), NgosStatus::ASSERTION);
                        }



                        sourceRangeX      = sourceRangeX->getNext();
                        destinationRangeX = destinationRangeX->getNext();
                    }

                    COMMON_TEST_ASSERT(!destinationRangeX, NgosStatus::ASSERTION);



                    sourceRangeY      = sourceRangeY->getNext();
                    destinationRangeY = destinationRangeY->getNext();
                }

                COMMON_TEST_ASSERT(!destinationRangeY, NgosStatus::ASSERTION);
            }
        }
        else
        {
            COMMON_ASSERT_EXECUTION(resizeImageRaw(image->getBuffer(), 0, 0, image->getWidth(), image->getHeight(), image->getStride(), newImage->getBuffer(), 0, 0, newImage->getWidth(), newImage->getHeight(), newImage->getStride(), newImage->getBytesPerPixel()), NgosStatus::ASSERTION);
        }



        *res = newImage;
    }
    else
    {
        *res = 0;

        return NgosStatus::INVALID_DATA;
    }



    return NgosStatus::OK;
}

NgosStatus Graphics::resizeImageProportional(Image *image, u16 width, u16 height, Image **res)
{
    COMMON_LT((" | image = 0x%p, width = %u, height = %u, res = 0x%p", image, width, height, res));

    COMMON_ASSERT(image,      "image is null",  NgosStatus::ASSERTION);
    COMMON_ASSERT(width > 0,  "width is zero",  NgosStatus::ASSERTION);
    COMMON_ASSERT(height > 0, "height is zero", NgosStatus::ASSERTION);
    COMMON_ASSERT(res,        "res is null",    NgosStatus::ASSERTION);



    float scaleX = (float)width  / image->getWidth();
    float scaleY = (float)height / image->getHeight();

    float scale = MIN(scaleX, scaleY);

    u16 newWidth  = image->getWidth()  * scale;
    u16 newHeight = image->getHeight() * scale;



    return resizeImage(image, newWidth, newHeight, res);
}

NgosStatus Graphics::resizeImageRaw(u8 *originalData, u16 originalPositionX, u16 originalPositionY, u16 originalWidth, u16 originalHeight, u64 originalStride, u8 *data, u16 positionX, u16 positionY, u16 width, u16 height, u64 stride, u8 bytesPerPixel)
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
