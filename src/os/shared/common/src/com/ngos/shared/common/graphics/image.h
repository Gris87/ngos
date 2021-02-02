#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_IMAGE_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_IMAGE_H



#include <com/ngos/shared/common/graphics/ninepatch.h>
#include <com/ngos/shared/common/graphics/rgbapixel.h>
#include <com/ngos/shared/common/graphics/rgbpixel.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/ngos/types.h>



class Image
{
public:
    Image(bad_uint16 width, bad_uint16 height, bool hasAlpha, bool opaque);
    Image(const Image &image);
    ~Image(); // TEST: NO

    NgosStatus clearBuffer();
    NgosStatus fill(const RgbaPixel &color);

    NgosStatus createNinePatch();

    NgosStatus setOpaque(bool opaque);

    NinePatch* getNinePatch() const;
    bad_uint16 getWidth() const;
    bad_uint16 getHeight() const;
    bad_uint8 getBytesPerPixel() const;
    bool isRgba() const;
    bool isRgb() const;
    bool isOpaque() const;
    bad_uint16 getStride() const;
    bad_uint64 getBufferSize() const;
    bad_uint8* getBuffer() const;
    RgbPixel* getRgbBuffer() const;
    RgbaPixel* getRgbaBuffer() const;

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    NinePatch *mNinePatch;
    bad_uint16        mWidth;
    bad_uint16        mHeight;
    bad_uint8         mBytesPerPixel;
    bool       mIsOpaque;
    bad_uint16        mStride;
    bad_uint64        mBufferSize;
    bad_uint8        *mBuffer;
};



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_IMAGE_H
