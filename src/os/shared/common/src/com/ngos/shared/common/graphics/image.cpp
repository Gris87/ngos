#include "image.h"

#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/memory/memory.h>



Image::Image(u16 width, u16 height, bool hasAlpha, bool opaque)
    : mNinePatch(nullptr)
    , mWidth(width)
    , mHeight(height)
    , mBytesPerPixel(hasAlpha ? sizeof(RgbaPixel) : sizeof(RgbPixel))
    , mIsOpaque(opaque)
    , mStride(mWidth * mBytesPerPixel)
    , mBufferSize(mHeight * mStride)
    , mBuffer(new u8[mBufferSize])
{
    COMMON_LT((" | width = %u, height = %u, hasAlpha = %d, opaque = %d", width, height, hasAlpha, opaque));

    COMMON_ASSERT(width > 0,  "width is zero");
    COMMON_ASSERT(height > 0, "height is zero");



    COMMON_TEST_ASSERT(hasAlpha || opaque);
}

Image::Image(const Image &image)
    : mNinePatch(image.mNinePatch ? new NinePatch(*image.mNinePatch) : nullptr)
    , mWidth(image.mWidth)
    , mHeight(image.mHeight)
    , mBytesPerPixel(image.mBytesPerPixel)
    , mIsOpaque(image.mIsOpaque)
    , mStride(image.mStride)
    , mBufferSize(image.mBufferSize)
    , mBuffer(new u8[mBufferSize])
{
    COMMON_LT((" | image = ..."));



    memcpy(mBuffer, image.mBuffer, mBufferSize);
}

Image::~Image()
{
    COMMON_LT((""));



    if (mNinePatch)
    {
        delete mNinePatch;
    }

    delete[] mBuffer;
}

NgosStatus Image::clearBuffer()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    memzero(mBuffer, mBufferSize);



    return NgosStatus::OK;
}

NgosStatus Image::fill(const RgbaPixel &color)
{
    COMMON_LT((" | color = ..."));



    i64 resolution = mWidth * mHeight;

    if (isRgba())
    {
        RgbaPixel *buffer = getRgbaBuffer();

        for (good_I64 i = 0; i < resolution; ++i)
        {
            buffer[i].value32 = color.value32;
        }
    }
    else
    {
        RgbPixel *buffer = getRgbBuffer();

        for (good_I64 i = 0; i < resolution; ++i)
        {
            buffer[i].red   = color.red;
            buffer[i].green = color.green;
            buffer[i].blue  = color.blue;
        }
    }



    return NgosStatus::OK;
}

NgosStatus Image::createNinePatch()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(!mNinePatch, NgosStatus::ASSERTION);

    if (mNinePatch)
    {
        delete mNinePatch;
    }

    mNinePatch = new NinePatch();



    return NgosStatus::OK;
}

NgosStatus Image::setOpaque(bool opaque)
{
    COMMON_LT((" | opaque = %d", opaque));



    mIsOpaque = opaque;



    return NgosStatus::OK;
}

NinePatch* Image::getNinePatch() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mNinePatch;
}

u16 Image::getWidth() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mWidth;
}

u16 Image::getHeight() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mHeight;
}

u8 Image::getBytesPerPixel() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mBytesPerPixel;
}

bool Image::isRgba() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mBytesPerPixel == sizeof(RgbaPixel);
}

bool Image::isRgb() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mBytesPerPixel == sizeof(RgbPixel);
}

bool Image::isOpaque() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mIsOpaque;
}

u16 Image::getStride() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mStride;
}

u64 Image::getBufferSize() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mBufferSize;
}

u8* Image::getBuffer() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mBuffer;
}

RgbPixel* Image::getRgbBuffer() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs

    COMMON_ASSERT(isRgb(), "Image is not RGB", nullptr);



    return (RgbPixel *)mBuffer;
}

RgbaPixel* Image::getRgbaBuffer() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs

    COMMON_ASSERT(isRgba(), "Image is not RGBA", nullptr);



    return (RgbaPixel *)mBuffer;
}
