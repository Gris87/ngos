#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_IMAGE_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_IMAGE_H



#include <common/src/bits64/graphics/ninepatch.h>
#include <common/src/bits64/graphics/rgbapixel.h>
#include <common/src/bits64/graphics/rgbpixel.h>
#include <ngos/status.h>
#include <ngos/types.h>



class Image
{
public:
    Image(u16 width, u16 height, bool hasAlpha, bool opaque);
    Image(const Image &image);
    ~Image(); // TEST: NO

    NgosStatus clearBuffer();
    NgosStatus fill(const RgbaPixel &color);

    NgosStatus createNinePatch();

    NgosStatus setOpaque(bool opaque);

    NinePatch* getNinePatch() const;
    u16 getWidth() const;
    u16 getHeight() const;
    u8 getBytesPerPixel() const;
    bool isRgba() const;
    bool isRgb() const;
    bool isOpaque() const;
    u16 getStride() const;
    u64 getBufferSize() const;
    u8* getBuffer() const;
    RgbPixel* getRgbBuffer() const;
    RgbaPixel* getRgbaBuffer() const;

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    NinePatch *mNinePatch;
    u16        mWidth;
    u16        mHeight;
    u8         mBytesPerPixel;
    bool       mIsOpaque;
    u16        mStride;
    u64        mBufferSize;
    u8        *mBuffer;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_IMAGE_H
