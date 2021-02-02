#include "graphics.h"

#include <com/ngos/shared/common/assets/assets.h>
#include <com/ngos/shared/common/graphics/bmp/bmp.h>
#include <com/ngos/shared/common/graphics/bmp/lib/bmpheader.h>
#include <com/ngos/shared/common/graphics/jpeg/jpeg.h>
#include <com/ngos/shared/common/graphics/jpeg/lib/jpegmarkertype.h>
#include <com/ngos/shared/common/graphics/png/lib/pngheader.h>
#include <com/ngos/shared/common/graphics/png/png.h>
#include <com/ngos/shared/common/graphics/rgbapixel.h>
#include <com/ngos/shared/common/graphics/rgbpixel.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/memory/malloc.h>
#include <com/ngos/shared/common/memory/memory.h>
#include <com/ngos/shared/common/ngos/utils.h>
#include <com/ngos/shared/common/string/string.h>
#include <com/ngos/shared/common/string/utils.h>



#define GET_PIXEL_ADDRESS(baseAddress, posX, posY, stride, bytesPerPixel) ((baseAddress) + (posY) * (stride) + (posX) * (bytesPerPixel))



NgosStatus Graphics::loadImage(bad_uint8 *data, bad_uint64 size, bool withNinePatch, Image **image)
{
    COMMON_LT((" | data = 0x%p, size = %u, withNinePatch = %u, image = 0x%p", data, size, withNinePatch, image));

    COMMON_ASSERT(data,     "data is null",  NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0, "size is zero",  NgosStatus::ASSERTION);
    COMMON_ASSERT(image,    "image is null", NgosStatus::ASSERTION);



    if (size >= 8)
    {
        if (*(bad_uint64 *)&data[0] == PNG_HEADER_SIGNATURE)
        {
            return Png::loadImage(data, size, withNinePatch, image);
        }



        if (
            *(bad_uint16 *)&data[0]        == JPEG_START_OF_IMAGE_SIGNATURE
            &&
            *(bad_uint16 *)&data[size - 2] == JPEG_END_OF_IMAGE_SIGNATURE
           )
        {
            return Jpeg::loadImage(data, size, image);
        }



        if (*(bad_uint16 *)&data[0] == BMP_HEADER_SIGNATURE)
        {
            return Bmp::loadImage(data, size, image);
        }
    }



    COMMON_LC(("Failed to load image from not supported image format"));

    *image = 0;



    return NgosStatus::NOT_SUPPORTED;
}

NgosStatus Graphics::loadImageFromAssets(const char8 *path, Image **image)
{
    COMMON_LT((" | path = %s, image = 0x%p", path, image));

    COMMON_ASSERT(path,  "path is null",  NgosStatus::ASSERTION);
    COMMON_ASSERT(image, "image is null", NgosStatus::ASSERTION);



    AssetEntry *asset = Assets::getAssetEntry(path);
    COMMON_TEST_ASSERT(asset, NgosStatus::ASSERTION);

    COMMON_ASSERT_EXECUTION(Graphics::loadImage(asset->content, asset->contentSize, strend(path, ".9.png"), image), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus Graphics::makeOpaqueImage(Image *image, bool hasAlpha, Image **res)
{
    COMMON_LT((" | image = 0x%p, hasAlpha = %u, res = 0x%p", image, hasAlpha, res));

    COMMON_ASSERT(image, "image is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(res,   "res is null",   NgosStatus::ASSERTION);



    if (
        !image->isOpaque()
        ||
        image->isRgba() != hasAlpha
       )
    {
        Image *newImage = new Image(image->getWidth(), image->getHeight(), hasAlpha, true);



        bad_int64  resolution    = image->getWidth() * image->getHeight();
        bad_uint8   bytesPerPixel = image->getBytesPerPixel();
        bad_uint8  *data          = image->getBuffer();



        if (hasAlpha)
        {
            RgbaPixel *pixel = newImage->getRgbaBuffer();

            for (bad_int64 i = 0; i < resolution; ++i)
            {
                RgbPixel *originalPixel = (RgbPixel *)data;

                pixel->red   = originalPixel->red;
                pixel->green = originalPixel->green;
                pixel->blue  = originalPixel->blue;
                pixel->alpha = 0xFF;

                data += bytesPerPixel;
                ++pixel;
            }
        }
        else
        {
            RgbPixel *pixel = newImage->getRgbBuffer();

            for (bad_int64 i = 0; i < resolution; ++i)
            {
                RgbPixel *originalPixel = (RgbPixel *)data;

                pixel->red   = originalPixel->red;
                pixel->green = originalPixel->green;
                pixel->blue  = originalPixel->blue;

                data += bytesPerPixel;
                ++pixel;
            }
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

NgosStatus Graphics::insertImage(Image *sourceImage, Image *destinationImage, bad_int64 positionX, bad_int64 positionY, bad_int64 width, bad_int64 height)
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



    COMMON_ASSERT_EXECUTION(insertImageRaw(
                                image->getBuffer(),
                                destinationImage->getBuffer(),
                                image->getWidth(),
                                image->getHeight(),
                                destinationImage->getWidth(),
                                destinationImage->getHeight(),
                                image->getBytesPerPixel(),
                                destinationImage->getBytesPerPixel(),
                                image->isOpaque() && destinationImage->isOpaque(),
                                positionX,
                                positionY),
                            NgosStatus::ASSERTION);



    if (image != sourceImage)
    {
        delete image;
    }



    return NgosStatus::OK;
}

NgosStatus Graphics::insertImageRaw(bad_uint8 *sourceData, bad_uint8 *destinationData, bad_uint16 sourceWidth, bad_uint16 sourceHeight, bad_uint16 destinationWidth, bad_uint16 destinationHeight, bad_uint8 sourceBytesPerPixel, bad_uint8 destinationBytesPerPixel, bool opaque, bad_int64 positionX, bad_int64 positionY)
{
    // COMMON_LT((" | sourceData = 0x%p, destinationData = 0x%p, sourceWidth = %u, sourceHeight = %u, destinationWidth = %u, destinationHeight = %u, sourceBytesPerPixel = %u, destinationBytesPerPixel = %u, opaque = %u, positionX = %d, positionY = %d", sourceData, destinationData, sourceWidth, sourceHeight, destinationWidth, destinationHeight, sourceBytesPerPixel, destinationBytesPerPixel, opaque, positionX, positionY)); // Commented to avoid too frequent logs

    COMMON_ASSERT(sourceData,                                                                                    "sourceData is null",                  NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationData,                                                                               "destinationData is null",             NgosStatus::ASSERTION);
    COMMON_ASSERT(sourceWidth > 0,                                                                               "sourceWidth is zero",                 NgosStatus::ASSERTION);
    COMMON_ASSERT(sourceHeight > 0,                                                                              "sourceHeight is zero",                NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationWidth > 0,                                                                          "destinationWidth is zero",            NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationHeight > 0,                                                                         "destinationHeight is zero",           NgosStatus::ASSERTION);
    COMMON_ASSERT(sourceBytesPerPixel == sizeof(RgbPixel) || sourceBytesPerPixel == sizeof(RgbaPixel),           "sourceBytesPerPixel is invalid",      NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationBytesPerPixel == sizeof(RgbPixel) || destinationBytesPerPixel == sizeof(RgbaPixel), "destinationBytesPerPixel is invalid", NgosStatus::ASSERTION);



    return insertImageRaw(sourceData,
                            destinationData,
                            sourceWidth,
                            sourceHeight,
                            destinationWidth,
                            destinationHeight,
                            sourceBytesPerPixel,
                            destinationBytesPerPixel,
                            opaque,
                            positionX,
                            positionY,
                            0, 0,
                            sourceWidth,
                            sourceHeight);
}

NgosStatus Graphics::insertImageRaw(bad_uint8 *sourceData, bad_uint8 *destinationData, bad_uint16 sourceWidth, bad_uint16 sourceHeight, bad_uint16 destinationWidth, bad_uint16 destinationHeight, bad_uint8 sourceBytesPerPixel, bad_uint8 destinationBytesPerPixel, bool opaque, bad_int64 positionX, bad_int64 positionY, bad_int64 left, bad_int64 top, bad_int64 right, bad_int64 bottom)
{
    // COMMON_LT((" | sourceData = 0x%p, destinationData = 0x%p, sourceWidth = %u, sourceHeight = %u, destinationWidth = %u, destinationHeight = %u, sourceBytesPerPixel = %u, destinationBytesPerPixel = %u, opaque = %u, positionX = %d, positionY = %d, left = %d, top = %d, right = %d, bottom = %d", sourceData, destinationData, sourceWidth, sourceHeight, destinationWidth, destinationHeight, sourceBytesPerPixel, destinationBytesPerPixel, opaque, positionX, positionY, left, top, right, bottom)); // Commented to avoid infinite loop

    COMMON_ASSERT(sourceData,                                                                                    "sourceData is null",                  NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationData,                                                                               "destinationData is null",             NgosStatus::ASSERTION);
    COMMON_ASSERT(sourceWidth > 0,                                                                               "sourceWidth is zero",                 NgosStatus::ASSERTION);
    COMMON_ASSERT(sourceHeight > 0,                                                                              "sourceHeight is zero",                NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationWidth > 0,                                                                          "destinationWidth is zero",            NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationHeight > 0,                                                                         "destinationHeight is zero",           NgosStatus::ASSERTION);
    COMMON_ASSERT(sourceBytesPerPixel == sizeof(RgbPixel) || sourceBytesPerPixel == sizeof(RgbaPixel),           "sourceBytesPerPixel is invalid",      NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationBytesPerPixel == sizeof(RgbPixel) || destinationBytesPerPixel == sizeof(RgbaPixel), "destinationBytesPerPixel is invalid", NgosStatus::ASSERTION);

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



    bad_uint64 sourceStride      = sourceWidth      * sourceBytesPerPixel;
    bad_uint64 destinationStride = destinationWidth * destinationBytesPerPixel;

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
    // COMMON_LVVV(("opaque                   = %s", boolToString(opaque)));      // Commented to avoid too frequent logs



    if (opaque)
    {
        // Insert source image to destination image without alpha blending
        {
            if (sourceBytesPerPixel == destinationBytesPerPixel)
            {
                // If both images are RGB or RGBA then just copy as is
                {
                    for (bad_int64 i = top; i < bottom; ++i)
                    {
                        bad_uint8 *sourcePixel      = GET_PIXEL_ADDRESS(sourceData,                  left,             i, sourceStride,      sourceBytesPerPixel);
                        bad_uint8 *destinationPixel = GET_PIXEL_ADDRESS(destinationData, positionX + left, positionY + i, destinationStride, destinationBytesPerPixel);

                        memcpy(destinationPixel, sourcePixel, (right - left) * sourceBytesPerPixel);
                    }
                }
            }
            else
            {
                // Types of images are different
                {
                    if (destinationBytesPerPixel == sizeof(RgbaPixel))
                    {
                        // Destination image is RGBA then source image should be RGB. Copy source image to destination and set alpha to 0xFF
                        {
                            COMMON_TEST_ASSERT(sourceBytesPerPixel == sizeof(RgbPixel), NgosStatus::ASSERTION);

                            for (bad_int64 i = top; i < bottom; ++i)
                            {
                                for (bad_int64 j = left; j < right; ++j)
                                {
                                    RgbPixel  *sourcePixel      = (RgbPixel  *)GET_PIXEL_ADDRESS(sourceData,                  j,             i, sourceStride,      sourceBytesPerPixel);
                                    RgbaPixel *destinationPixel = (RgbaPixel *)GET_PIXEL_ADDRESS(destinationData, positionX + j, positionY + i, destinationStride, destinationBytesPerPixel);

                                    destinationPixel->red   = sourcePixel->red;
                                    destinationPixel->green = sourcePixel->green;
                                    destinationPixel->blue  = sourcePixel->blue;
                                    destinationPixel->alpha = 0xFF;
                                }
                            }
                        }
                    }
                    else
                    {
                        // Destination image is RGB then source image should be RGBA. Copy source image to destination without taking alpha into account
                        {
                            COMMON_TEST_ASSERT(sourceBytesPerPixel == sizeof(RgbaPixel), NgosStatus::ASSERTION);

                            for (bad_int64 i = top; i < bottom; ++i)
                            {
                                for (bad_int64 j = left; j < right; ++j)
                                {
                                    RgbaPixel *sourcePixel      = (RgbaPixel *)GET_PIXEL_ADDRESS(sourceData,                  j,             i, sourceStride,      sourceBytesPerPixel);
                                    RgbPixel  *destinationPixel = (RgbPixel  *)GET_PIXEL_ADDRESS(destinationData, positionX + j, positionY + i, destinationStride, destinationBytesPerPixel);

                                    destinationPixel->red   = sourcePixel->red;
                                    destinationPixel->green = sourcePixel->green;
                                    destinationPixel->blue  = sourcePixel->blue;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        // Insert source image to destination image with alpha blending or without it. Need to check source image type
        {
            if (sourceBytesPerPixel == sizeof(RgbaPixel))
            {
                // Insert source image to destination image with alpha blending
                {
                    if (destinationBytesPerPixel == sizeof(RgbaPixel))
                    {
                        // Both images are RGBA. Composite images with two alpha channels
                        {
                            for (bad_int64 i = top; i < bottom; ++i)
                            {
                                for (bad_int64 j = left; j < right; ++j)
                                {
                                    RgbaPixel *sourcePixel      = (RgbaPixel *)GET_PIXEL_ADDRESS(sourceData,                  j,             i, sourceStride,      sourceBytesPerPixel);
                                    RgbaPixel *destinationPixel = (RgbaPixel *)GET_PIXEL_ADDRESS(destinationData, positionX + j, positionY + i, destinationStride, destinationBytesPerPixel);

                                    bad_uint8 srcAlpha = sourcePixel->alpha;
                                    bad_uint8 dstAlpha = destinationPixel->alpha;
                                    bad_uint8 notAlpha = ~srcAlpha;                                // ~srcAlpha == (0xFF - srcAlpha)
                                    bad_uint8 outAlpha = srcAlpha + (dstAlpha * notAlpha) / 0xFF;

                                    if (outAlpha != 0)
                                    {
                                        destinationPixel->red   = ((sourcePixel->red   * srcAlpha) + (destinationPixel->red   * dstAlpha * notAlpha) / 0xFF) / outAlpha;
                                        destinationPixel->green = ((sourcePixel->green * srcAlpha) + (destinationPixel->green * dstAlpha * notAlpha) / 0xFF) / outAlpha;
                                        destinationPixel->blue  = ((sourcePixel->blue  * srcAlpha) + (destinationPixel->blue  * dstAlpha * notAlpha) / 0xFF) / outAlpha;
                                        destinationPixel->alpha = outAlpha;
                                    }
                                    else
                                    {
                                        destinationPixel->value32 = 0;
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        // Source image is RGBA and destination image is RGB. Composite images without destination alpha channel
                        {
                            for (bad_int64 i = top; i < bottom; ++i)
                            {
                                for (bad_int64 j = left; j < right; ++j)
                                {
                                    RgbaPixel *sourcePixel      = (RgbaPixel *)GET_PIXEL_ADDRESS(sourceData,                  j,             i, sourceStride,      sourceBytesPerPixel);
                                    RgbPixel  *destinationPixel = (RgbPixel  *)GET_PIXEL_ADDRESS(destinationData, positionX + j, positionY + i, destinationStride, destinationBytesPerPixel);

                                    bad_uint8 alpha    = sourcePixel->alpha;
                                    bad_uint8 notAlpha = ~alpha;               // ~alpha == (0xFF - alpha)

                                    destinationPixel->red   = ((sourcePixel->red   * alpha) + (destinationPixel->red   * notAlpha)) / 0xFF;
                                    destinationPixel->green = ((sourcePixel->green * alpha) + (destinationPixel->green * notAlpha)) / 0xFF;
                                    destinationPixel->blue  = ((sourcePixel->blue  * alpha) + (destinationPixel->blue  * notAlpha)) / 0xFF;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                // Source image is RGB and destination image is non-opaque RGBA image. Copy source image to destination and set alpha to 0xFF
                {
                    COMMON_TEST_ASSERT(destinationBytesPerPixel == sizeof(RgbaPixel), NgosStatus::ASSERTION);

                    for (bad_int64 i = top; i < bottom; ++i)
                    {
                        for (bad_int64 j = left; j < right; ++j)
                        {
                            RgbPixel  *sourcePixel      = (RgbPixel  *)GET_PIXEL_ADDRESS(sourceData,                  j,             i, sourceStride,      sourceBytesPerPixel);
                            RgbaPixel *destinationPixel = (RgbaPixel *)GET_PIXEL_ADDRESS(destinationData, positionX + j, positionY + i, destinationStride, destinationBytesPerPixel);

                            destinationPixel->red   = sourcePixel->red;
                            destinationPixel->green = sourcePixel->green;
                            destinationPixel->blue  = sourcePixel->blue;
                            destinationPixel->alpha = 0xFF;
                        }
                    }
                }
            }
        }
    }



    return NgosStatus::OK;
}

NgosStatus Graphics::resizeImage(Image *image, bad_uint16 width, bad_uint16 height, Image **res)
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
                    bad_uint16 lastX = element->getData().getFrom();

                    if (lastX != 0)
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
                    bad_uint16 lastY = element->getData().getFrom();

                    if (lastY != 0)
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



            bad_uint16 totalStretchCountX = 0;
            bad_uint16 totalStretchCountY = 0;
            bad_uint16 totalFixedCountX   = 0;
            bad_uint16 totalFixedCountY   = 0;



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
                bad_uint16       totalWidth = 0;
                List<bad_uint16> sizes;

                if (width >= totalFixedCountX)
                {
                    bad_uint16 stretchableCount = width - totalFixedCountX;



                    bool                       isCurrentStretch = startWithStretchX;
                    ListElement<StretchRange> *element          = sourceRangesX.getHead();

                    while (element)
                    {
                        bad_uint16 size = element->getData().getSize();

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
                        bad_uint16 remain = width - totalWidth;

                        while (remain)
                        {
                            isCurrentStretch = startWithStretchX;

                            ListElement<bad_uint16> *sizeElement    = sizes.getHead();
                            ListElement<bad_uint16> *minSizeElement = 0;

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
                        bad_uint16 size;

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
                        bad_uint16 remain = width - totalWidth;

                        while (remain)
                        {
                            isCurrentStretch = startWithStretchX;

                            ListElement<bad_uint16> *sizeElement    = sizes.getHead();
                            ListElement<bad_uint16> *minSizeElement = 0;

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

                ListElement<bad_uint16> *sizeElement = sizes.getHead();

                while (sizeElement)
                {
                    bad_uint16 to = totalWidth + sizeElement->getData();

                    destinationRangesX.append(StretchRange(totalWidth, to));
                    totalWidth = to;

                    sizeElement = sizeElement->getNext();
                }

                COMMON_TEST_ASSERT(totalWidth == width, NgosStatus::ASSERTION);
            }



            // Get destinationRangesY
            {
                bad_uint16       totalHeight = 0;
                List<bad_uint16> sizes;

                if (height >= totalFixedCountY)
                {
                    bad_uint16 stretchableCount = height - totalFixedCountY;



                    bool                       isCurrentStretch = startWithStretchY;
                    ListElement<StretchRange> *element          = sourceRangesY.getHead();

                    while (element)
                    {
                        bad_uint16 size = element->getData().getSize();

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
                        bad_uint16 remain = height - totalHeight;

                        while (remain)
                        {
                            isCurrentStretch = startWithStretchY;

                            ListElement<bad_uint16> *sizeElement    = sizes.getHead();
                            ListElement<bad_uint16> *minSizeElement = 0;

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
                        bad_uint16 size;

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
                        bad_uint16 remain = height - totalHeight;

                        while (remain)
                        {
                            isCurrentStretch = startWithStretchY;

                            ListElement<bad_uint16> *sizeElement    = sizes.getHead();
                            ListElement<bad_uint16> *minSizeElement = 0;

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

                ListElement<bad_uint16> *sizeElement = sizes.getHead();

                while (sizeElement)
                {
                    bad_uint16 to = totalHeight + sizeElement->getData();

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



                        bad_uint16 sourceSizeX      = sourceRangeX->getData().getSize();
                        bad_uint16 sourceSizeY      = sourceRangeY->getData().getSize();
                        bad_uint16 destinationSizeX = destinationRangeX->getData().getSize();
                        bad_uint16 destinationSizeY = destinationRangeY->getData().getSize();

                        COMMON_TEST_ASSERT(sourceSizeX > 0, NgosStatus::ASSERTION);
                        COMMON_TEST_ASSERT(sourceSizeY > 0, NgosStatus::ASSERTION);



                        if (
                            destinationSizeX // destinationSizeX > 0
                            &&
                            destinationSizeY // destinationSizeY > 0
                           )
                        {
                            COMMON_ASSERT_EXECUTION(resizeImageRaw(
                                                        image->getBuffer(),
                                                        newImage->getBuffer(),
                                                        sourceRangeX->getData().getFrom(),
                                                        sourceRangeY->getData().getFrom(),
                                                        destinationRangeX->getData().getFrom(),
                                                        destinationRangeY->getData().getFrom(),
                                                        sourceSizeX,
                                                        sourceSizeY,
                                                        destinationSizeX,
                                                        destinationSizeY,
                                                        image->getStride(),
                                                        newImage->getStride(),
                                                        newImage->getBytesPerPixel()),
                                                    NgosStatus::ASSERTION);
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
            COMMON_ASSERT_EXECUTION(resizeImageRaw(
                                        image->getBuffer(),
                                        newImage->getBuffer(),
                                        0, 0,
                                        0, 0,
                                        image->getWidth(),
                                        image->getHeight(),
                                        newImage->getWidth(),
                                        newImage->getHeight(),
                                        image->getStride(),
                                        newImage->getStride(),
                                        newImage->getBytesPerPixel()),
                                    NgosStatus::ASSERTION);
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

NgosStatus Graphics::resizeImageProportional(Image *image, bad_uint16 width, bad_uint16 height, Image **res)
{
    COMMON_LT((" | image = 0x%p, width = %u, height = %u, res = 0x%p", image, width, height, res));

    COMMON_ASSERT(image,      "image is null",  NgosStatus::ASSERTION);
    COMMON_ASSERT(width > 0,  "width is zero",  NgosStatus::ASSERTION);
    COMMON_ASSERT(height > 0, "height is zero", NgosStatus::ASSERTION);
    COMMON_ASSERT(res,        "res is null",    NgosStatus::ASSERTION);



    float scaleX = (float)width  / image->getWidth();
    float scaleY = (float)height / image->getHeight();

    float scale = MIN(scaleX, scaleY);

    bad_uint16 newWidth  = image->getWidth()  * scale;
    bad_uint16 newHeight = image->getHeight() * scale;



    return resizeImage(image, newWidth, newHeight, res);
}

NgosStatus Graphics::resizeImageRaw(bad_uint8 *sourceData, bad_uint8 *destinationData, bad_uint16 sourcePositionX, bad_uint16 sourcePositionY, bad_uint16 destinationPositionX, bad_uint16 destinationPositionY, bad_uint16 sourceWidth, bad_uint16 sourceHeight, bad_uint16 destinationWidth, bad_uint16 destinationHeight, bad_uint64 sourceStride, bad_uint64 destinationStride, bad_uint8 bytesPerPixel)
{
    // COMMON_LT((" | sourceData = 0x%p, destinationData = 0x%p, sourcePositionX = %u, sourcePositionY = %u, destinationPositionX = %u, destinationPositionY = %u, sourceWidth = %u, sourceHeight = %u, destinationWidth = %u, destinationHeight = %u, sourceStride = %u, destinationStride = %u, bytesPerPixel = %u", sourceData, destinationData, sourcePositionX, sourcePositionY, destinationPositionX, destinationPositionY, sourceWidth, sourceHeight, destinationWidth, destinationHeight, sourceStride, destinationStride, bytesPerPixel)); // Commented to avoid too frequent logs

    COMMON_ASSERT(sourceData,                                                              "sourceData is null",           NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationData,                                                         "destinationData is null",      NgosStatus::ASSERTION);
    COMMON_ASSERT(sourceWidth > 0,                                                         "sourceWidth is zero",          NgosStatus::ASSERTION);
    COMMON_ASSERT(sourceHeight > 0,                                                        "sourceHeight is zero",         NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationWidth > 0,                                                    "destinationWidth is zero",     NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationHeight > 0,                                                   "destinationHeight is zero",    NgosStatus::ASSERTION);
    COMMON_ASSERT(sourceStride > 0,                                                        "sourceStride is zero",         NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationStride > 0,                                                   "destinationStride is zero",    NgosStatus::ASSERTION);
    COMMON_ASSERT(bytesPerPixel == sizeof(RgbPixel) || bytesPerPixel == sizeof(RgbaPixel), "bytesPerPixel is invalid",     NgosStatus::ASSERTION);
    COMMON_ASSERT(sourceStride % bytesPerPixel == 0,                                       "sourceStride is invalid",      NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationStride % bytesPerPixel == 0,                                  "destinationStride is invalid", NgosStatus::ASSERTION);



    if (sourceWidth == destinationWidth)
    {
        if (sourceHeight == destinationHeight)
        {
            // If same size then just copy as is
            {
                for (bad_int64 i = 0; i < destinationHeight; ++i)
                {
                    bad_uint8 *sourcePixel      = GET_PIXEL_ADDRESS(sourceData,      sourcePositionX,      sourcePositionY      + i, sourceStride,      bytesPerPixel);
                    bad_uint8 *destinationPixel = GET_PIXEL_ADDRESS(destinationData, destinationPositionX, destinationPositionY + i, destinationStride, bytesPerPixel);

                    memcpy(destinationPixel, sourcePixel, sourceWidth * bytesPerPixel);
                }
            }
        }
        else
        {
            // Width is the same, but height is different
            {
                bad_int64 sourceBottom = sourcePositionY + sourceHeight;

                if (bytesPerPixel == sizeof(RgbaPixel))
                {
                    for (bad_int64 i = 0; i < destinationHeight; ++i)
                    {
                        bad_int64 top    = i > 0 ? sourcePositionY + (i - 1) * sourceHeight / destinationHeight : sourcePositionY; // Ignore CppEqualAlignmentVerifier
                        bad_int64 bottom =         sourcePositionY + (i + 1) * sourceHeight / destinationHeight;                   // Ignore CppEqualAlignmentVerifier

                        if (bottom >= sourceBottom)
                        {
                            if (top >= sourceBottom)
                            {
                                top = sourceBottom - 1;
                            }

                            bottom = sourceBottom - 1;
                        }

                        COMMON_TEST_ASSERT(bottom >= top, NgosStatus::ASSERTION);



                        for (bad_int64 j = 0; j < destinationWidth; ++j)
                        {
                            RgbaPixel *destinationPixel = (RgbaPixel *)GET_PIXEL_ADDRESS(destinationData, destinationPositionX + j, destinationPositionY + i, destinationStride, bytesPerPixel);

                            bad_uint64 totalRed   = 0;
                            bad_uint64 totalGreen = 0;
                            bad_uint64 totalBlue  = 0;
                            bad_uint64 totalAlpha = 0;



                            for (bad_int64 k = top; k <= bottom; ++k)
                            {
                                RgbaPixel *sourcePixel = (RgbaPixel *)GET_PIXEL_ADDRESS(sourceData, sourcePositionX + j, k, sourceStride, bytesPerPixel);

                                totalRed   += sourcePixel->alpha * sourcePixel->red;
                                totalGreen += sourcePixel->alpha * sourcePixel->green;
                                totalBlue  += sourcePixel->alpha * sourcePixel->blue;
                                totalAlpha += sourcePixel->alpha;
                            }



                            if (totalAlpha > 0)
                            {
                                bad_uint64 count = bottom - top + 1;

                                COMMON_TEST_ASSERT(count > 0, NgosStatus::ASSERTION);

                                destinationPixel->red   = totalRed   / totalAlpha;
                                destinationPixel->green = totalGreen / totalAlpha;
                                destinationPixel->blue  = totalBlue  / totalAlpha;
                                destinationPixel->alpha = totalAlpha / count;
                            }
                            else
                            {
                                destinationPixel->value32 = 0;
                            }
                        }
                    }
                }
                else
                {
                    for (bad_int64 i = 0; i < destinationHeight; ++i)
                    {
                        bad_int64 top    = i > 0 ? sourcePositionY + (i - 1) * sourceHeight / destinationHeight : sourcePositionY; // Ignore CppEqualAlignmentVerifier
                        bad_int64 bottom =         sourcePositionY + (i + 1) * sourceHeight / destinationHeight;                   // Ignore CppEqualAlignmentVerifier

                        if (bottom >= sourceBottom)
                        {
                            if (top >= sourceBottom)
                            {
                                top = sourceBottom - 1;
                            }

                            bottom = sourceBottom - 1;
                        }

                        COMMON_TEST_ASSERT(bottom >= top, NgosStatus::ASSERTION);



                        for (bad_int64 j = 0; j < destinationWidth; ++j)
                        {
                            RgbPixel *destinationPixel = (RgbPixel *)GET_PIXEL_ADDRESS(destinationData, destinationPositionX + j, destinationPositionY + i, destinationStride, bytesPerPixel);

                            bad_uint64 totalRed   = 0;
                            bad_uint64 totalGreen = 0;
                            bad_uint64 totalBlue  = 0;



                            for (bad_int64 k = top; k <= bottom; ++k)
                            {
                                RgbPixel *sourcePixel = (RgbPixel *)GET_PIXEL_ADDRESS(sourceData, sourcePositionX + j, k, sourceStride, bytesPerPixel);

                                totalRed   += sourcePixel->red;
                                totalGreen += sourcePixel->green;
                                totalBlue  += sourcePixel->blue;
                            }



                            bad_uint64 count = bottom - top + 1;

                            COMMON_TEST_ASSERT(count > 0, NgosStatus::ASSERTION);

                            destinationPixel->red   = totalRed   / count;
                            destinationPixel->green = totalGreen / count;
                            destinationPixel->blue  = totalBlue  / count;
                        }
                    }
                }
            }
        }
    }
    else
    {
        if (sourceHeight == destinationHeight)
        {
            // Height is the same, but width is different
            {
                bad_int64 sourceRight = sourcePositionX + sourceWidth;

                if (bytesPerPixel == sizeof(RgbaPixel))
                {
                    for (bad_int64 j = 0; j < destinationWidth; ++j)
                    {
                        bad_int64 left  = j > 0 ? sourcePositionX + (j - 1) * sourceWidth / destinationWidth : sourcePositionX; // Ignore CppEqualAlignmentVerifier
                        bad_int64 right =         sourcePositionX + (j + 1) * sourceWidth / destinationWidth;                   // Ignore CppEqualAlignmentVerifier

                        if (right >= sourceRight)
                        {
                            if (left >= sourceRight)
                            {
                                left = sourceRight - 1;
                            }

                            right = sourceRight - 1;
                        }

                        COMMON_TEST_ASSERT(right >= left, NgosStatus::ASSERTION);



                        for (bad_int64 i = 0; i < destinationHeight; ++i)
                        {
                            RgbaPixel *destinationPixel = (RgbaPixel *)GET_PIXEL_ADDRESS(destinationData, destinationPositionX + j, destinationPositionY + i, destinationStride, bytesPerPixel);

                            bad_uint64 totalRed   = 0;
                            bad_uint64 totalGreen = 0;
                            bad_uint64 totalBlue  = 0;
                            bad_uint64 totalAlpha = 0;



                            for (bad_int64 k = left; k <= right; ++k)
                            {
                                RgbaPixel *sourcePixel = (RgbaPixel *)GET_PIXEL_ADDRESS(sourceData, k, sourcePositionY + i, sourceStride, bytesPerPixel);

                                totalRed   += sourcePixel->alpha * sourcePixel->red;
                                totalGreen += sourcePixel->alpha * sourcePixel->green;
                                totalBlue  += sourcePixel->alpha * sourcePixel->blue;
                                totalAlpha += sourcePixel->alpha;
                            }



                            if (totalAlpha > 0)
                            {
                                bad_uint64 count = right - left + 1;

                                COMMON_TEST_ASSERT(count > 0, NgosStatus::ASSERTION);

                                destinationPixel->red   = totalRed   / totalAlpha;
                                destinationPixel->green = totalGreen / totalAlpha;
                                destinationPixel->blue  = totalBlue  / totalAlpha;
                                destinationPixel->alpha = totalAlpha / count;
                            }
                            else
                            {
                                destinationPixel->value32 = 0;
                            }
                        }
                    }
                }
                else
                {
                    for (bad_int64 j = 0; j < destinationWidth; ++j)
                    {
                        bad_int64 left  = j > 0 ? sourcePositionX + (j - 1) * sourceWidth / destinationWidth : sourcePositionX; // Ignore CppEqualAlignmentVerifier
                        bad_int64 right =         sourcePositionX + (j + 1) * sourceWidth / destinationWidth;                   // Ignore CppEqualAlignmentVerifier

                        if (right >= sourceRight)
                        {
                            if (left >= sourceRight)
                            {
                                left = sourceRight - 1;
                            }

                            right = sourceRight - 1;
                        }

                        COMMON_TEST_ASSERT(right >= left, NgosStatus::ASSERTION);



                        for (bad_int64 i = 0; i < destinationHeight; ++i)
                        {
                            RgbPixel *destinationPixel = (RgbPixel *)GET_PIXEL_ADDRESS(destinationData, destinationPositionX + j, destinationPositionY + i, destinationStride, bytesPerPixel);

                            bad_uint64 totalRed   = 0;
                            bad_uint64 totalGreen = 0;
                            bad_uint64 totalBlue  = 0;



                            for (bad_int64 k = left; k <= right; ++k)
                            {
                                RgbPixel *sourcePixel = (RgbPixel *)GET_PIXEL_ADDRESS(sourceData, k, sourcePositionY + i, sourceStride, bytesPerPixel);

                                totalRed   += sourcePixel->red;
                                totalGreen += sourcePixel->green;
                                totalBlue  += sourcePixel->blue;
                            }



                            bad_uint64 count = right - left + 1;

                            COMMON_TEST_ASSERT(count > 0, NgosStatus::ASSERTION);

                            destinationPixel->red   = totalRed   / count;
                            destinationPixel->green = totalGreen / count;
                            destinationPixel->blue  = totalBlue  / count;
                        }
                    }
                }
            }
        }
        else
        {
            // The size is different
            {
                bad_int64 sourceRight  = sourcePositionX + sourceWidth;
                bad_int64 sourceBottom = sourcePositionY + sourceHeight;

                if (bytesPerPixel == sizeof(RgbaPixel))
                {
                    for (bad_int64 i = 0; i < destinationHeight; ++i)
                    {
                        bad_int64 top    = i > 0 ? sourcePositionY + (i - 1) * sourceHeight / destinationHeight : sourcePositionY; // Ignore CppEqualAlignmentVerifier
                        bad_int64 bottom =         sourcePositionY + (i + 1) * sourceHeight / destinationHeight;                   // Ignore CppEqualAlignmentVerifier

                        if (bottom >= sourceBottom)
                        {
                            if (top >= sourceBottom)
                            {
                                top = sourceBottom - 1;
                            }

                            bottom = sourceBottom - 1;
                        }

                        COMMON_TEST_ASSERT(bottom >= top, NgosStatus::ASSERTION);



                        for (bad_int64 j = 0; j < destinationWidth; ++j)
                        {
                            bad_int64 left   = j > 0 ? sourcePositionX + (j - 1) * sourceWidth  / destinationWidth : sourcePositionX;  // Ignore CppEqualAlignmentVerifier
                            bad_int64 right  =         sourcePositionX + (j + 1) * sourceWidth  / destinationWidth;                    // Ignore CppEqualAlignmentVerifier

                            if (right >= sourceRight)
                            {
                                if (left >= sourceRight)
                                {
                                    left = sourceRight - 1;
                                }

                                right = sourceRight - 1;
                            }

                            COMMON_TEST_ASSERT(right >= left, NgosStatus::ASSERTION);



                            RgbaPixel *destinationPixel = (RgbaPixel *)GET_PIXEL_ADDRESS(destinationData, destinationPositionX + j, destinationPositionY + i, destinationStride, bytesPerPixel);

                            bad_uint64 totalRed   = 0;
                            bad_uint64 totalGreen = 0;
                            bad_uint64 totalBlue  = 0;
                            bad_uint64 totalAlpha = 0;



                            for (bad_int64 k = top; k <= bottom; ++k)
                            {
                                for (bad_int64 g = left; g <= right; ++g)
                                {
                                    RgbaPixel *sourcePixel = (RgbaPixel *)GET_PIXEL_ADDRESS(sourceData, g, k, sourceStride, bytesPerPixel);

                                    totalRed   += sourcePixel->alpha * sourcePixel->red;
                                    totalGreen += sourcePixel->alpha * sourcePixel->green;
                                    totalBlue  += sourcePixel->alpha * sourcePixel->blue;
                                    totalAlpha += sourcePixel->alpha;
                                }
                            }



                            if (totalAlpha > 0)
                            {
                                bad_uint64 count = (bottom - top + 1) * (right - left + 1);

                                COMMON_TEST_ASSERT(count > 0, NgosStatus::ASSERTION);

                                destinationPixel->red   = totalRed   / totalAlpha;
                                destinationPixel->green = totalGreen / totalAlpha;
                                destinationPixel->blue  = totalBlue  / totalAlpha;
                                destinationPixel->alpha = totalAlpha / count;
                            }
                            else
                            {
                                destinationPixel->value32 = 0;
                            }
                        }
                    }
                }
                else
                {
                    for (bad_int64 i = 0; i < destinationHeight; ++i)
                    {
                        bad_int64 top    = i > 0 ? sourcePositionY + (i - 1) * sourceHeight / destinationHeight : sourcePositionY; // Ignore CppEqualAlignmentVerifier
                        bad_int64 bottom =         sourcePositionY + (i + 1) * sourceHeight / destinationHeight;                   // Ignore CppEqualAlignmentVerifier

                        if (bottom >= sourceBottom)
                        {
                            if (top >= sourceBottom)
                            {
                                top = sourceBottom - 1;
                            }

                            bottom = sourceBottom - 1;
                        }

                        COMMON_TEST_ASSERT(bottom >= top, NgosStatus::ASSERTION);



                        for (bad_int64 j = 0; j < destinationWidth; ++j)
                        {
                            bad_int64 left   = j > 0 ? sourcePositionX + (j - 1) * sourceWidth  / destinationWidth : sourcePositionX;  // Ignore CppEqualAlignmentVerifier
                            bad_int64 right  =         sourcePositionX + (j + 1) * sourceWidth  / destinationWidth;                    // Ignore CppEqualAlignmentVerifier

                            if (right >= sourceRight)
                            {
                                if (left >= sourceRight)
                                {
                                    left = sourceRight - 1;
                                }

                                right = sourceRight - 1;
                            }

                            COMMON_TEST_ASSERT(right >= left, NgosStatus::ASSERTION);



                            RgbPixel *destinationPixel = (RgbPixel *)GET_PIXEL_ADDRESS(destinationData, destinationPositionX + j, destinationPositionY + i, destinationStride, bytesPerPixel);

                            bad_uint64 totalRed   = 0;
                            bad_uint64 totalGreen = 0;
                            bad_uint64 totalBlue  = 0;



                            for (bad_int64 k = top; k <= bottom; ++k)
                            {
                                for (bad_int64 g = left; g <= right; ++g)
                                {
                                    RgbPixel *sourcePixel = (RgbPixel *)GET_PIXEL_ADDRESS(sourceData, g, k, sourceStride, bytesPerPixel);

                                    totalRed   += sourcePixel->red;
                                    totalGreen += sourcePixel->green;
                                    totalBlue  += sourcePixel->blue;
                                }
                            }



                            bad_uint64 count = (bottom - top + 1) * (right - left + 1);

                            COMMON_TEST_ASSERT(count > 0, NgosStatus::ASSERTION);

                            destinationPixel->red   = totalRed   / count;
                            destinationPixel->green = totalGreen / count;
                            destinationPixel->blue  = totalBlue  / count;
                        }
                    }
                }
            }
        }
    }



    return NgosStatus::OK;
}
