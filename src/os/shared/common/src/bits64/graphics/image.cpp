#include "image.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/memory/memory.h>



Image::Image(u16 width, u16 height, bool hasAlpha, bool opaque)
    : mNinePatch(0)
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
    : mNinePatch(image.mNinePatch ? new NinePatch(*image.mNinePatch) : 0)
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
    COMMON_LT((""));



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

        for (i64 i = 0; i < resolution; ++i)
        {
            buffer[i].red   = color.red;
            buffer[i].green = color.green;
            buffer[i].blue  = color.blue;
            buffer[i].alpha = color.alpha;
        }
    }
    else
    {
        RgbPixel *buffer = getRgbBuffer();

        for (i64 i = 0; i < resolution; ++i)
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
    COMMON_LT((""));



    return mNinePatch;
}

u16 Image::getWidth() const
{
    COMMON_LT((""));



    return mWidth;
}

u16 Image::getHeight() const
{
    COMMON_LT((""));



    return mHeight;
}

u8 Image::getBytesPerPixel() const
{
    COMMON_LT((""));



    return mBytesPerPixel;
}

bool Image::isRgba() const
{
    COMMON_LT((""));



    return mBytesPerPixel == sizeof(RgbaPixel);
}

bool Image::isOpaque() const
{
    COMMON_LT((""));



    return mIsOpaque;
}

u16 Image::getStride() const
{
    COMMON_LT((""));



    return mStride;
}

u64 Image::getBufferSize() const
{
    COMMON_LT((""));



    return mBufferSize;
}

u8* Image::getBuffer() const
{
    COMMON_LT((""));



    return mBuffer;
}

RgbPixel* Image::getRgbBuffer() const
{
    COMMON_LT((""));

    COMMON_ASSERT(!isRgba(), "Image is RGBA", 0);



    return (RgbPixel *)mBuffer;
}

RgbaPixel* Image::getRgbaBuffer() const
{
    COMMON_LT((""));

    COMMON_ASSERT(isRgba(), "Image is RGB", 0);



    return (RgbaPixel *)mBuffer;
}
