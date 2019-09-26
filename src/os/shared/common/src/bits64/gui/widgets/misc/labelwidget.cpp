#include "labelwidget.h"

#include <common/src/bits64/assets/assets.h>
#include <common/src/bits64/console/lib/glyphdata.h>
#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



#define CHAR_HEIGHT   20
#define BOTTOM_MARGIN 5



LabelWidget::LabelWidget(const char8 *text, Widget *parent)
    : Widget(parent)
    , mText(text)
    , mGlyphOffsets(0)
{
    COMMON_LT((" | text = 0x%p, parent = 0x%p", text, parent));

    COMMON_ASSERT(text, "text is null");



    AssetEntry *asset = Assets::getAssetEntry("glyphs/console.bin");
    COMMON_TEST_ASSERT(asset);

    mGlyphOffsets = (u16 *)asset->content;
}

LabelWidget::~LabelWidget()
{
    COMMON_LT((""));



    if (mResultImage)
    {
        delete mResultImage;
    }
}

NgosStatus LabelWidget::repaint()
{
    COMMON_LT((""));



    COMMON_ASSERT_EXECUTION(Widget::repaint(), NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mText               != 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mGlyphOffsets       != 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mChildren.getHead() == 0, NgosStatus::ASSERTION);



    u16 targetWidth  = 0;
    u16 targetHeight = CHAR_HEIGHT + BOTTOM_MARGIN;
    u16 curX         = 0;



    const char8 *str = mText;

    while (*str)
    {
        char8 ch = *str;

        if (ch == '\n')
        {
            curX         =  0;
            targetHeight += CHAR_HEIGHT;
        }
        else
        if (ch >= 0x20 && ch < 0x7F)
        {
            GlyphData *glyphData = (GlyphData *)((u64)mGlyphOffsets + mGlyphOffsets[ch - 0x20]);

            curX += glyphData->width;

            if (curX > targetWidth)
            {
                targetWidth = curX;
            }
        }
        else
        {
            COMMON_LW(("Non-printable character found: 0x%02X", (u8)ch));

            return NgosStatus::UNEXPECTED_BEHAVIOUR;
        }



        ++str;
    }



    if (mResultImage)
    {
        delete mResultImage;
    }

    mResultImage = new Image(mWidth, mHeight, true, false);
    mResultImage->clearBuffer();



    if (targetWidth) // targetWidth > 0
    {
        Image *fullImage = new Image(targetWidth, targetHeight, true, false);
        fullImage->clearBuffer();

        Image *oneLineImage = new Image(targetWidth, CHAR_HEIGHT + BOTTOM_MARGIN, true, false);
        oneLineImage->clearBuffer();



        u16 curX = 0;
        u16 curY = 0;

        const char8 *str = mText;

        while (*str)
        {
            char8 ch = *str;

            if (ch == '\n')
            {
                if (curX)
                {
                    COMMON_ASSERT_EXECUTION(Graphics::insertImageRaw(
                                                oneLineImage->getBuffer(),
                                                fullImage->getBuffer(),
                                                targetWidth,
                                                CHAR_HEIGHT + BOTTOM_MARGIN,
                                                targetWidth,
                                                targetHeight,
                                                oneLineImage->getBytesPerPixel(),
                                                fullImage->getBytesPerPixel(),
                                                false,
                                                (targetWidth - curX) >> 1,
                                                curY),
                                            NgosStatus::ASSERTION);

                    oneLineImage->clearBuffer();

                    curX = 0;
                }

                curY += CHAR_HEIGHT;
            }
            else
            if (ch >= 0x20 && ch < 0x7F)
            {
                GlyphData *glyphData = (GlyphData *)((u64)mGlyphOffsets + mGlyphOffsets[ch - 0x20]);



                i16  charPosX   = curX + glyphData->bitmapLeft;
                i16  charPosY   = CHAR_HEIGHT - glyphData->bitmapTop;
                u8  *bitmapByte = glyphData->bitmap;

                COMMON_TEST_ASSERT(charPosX + glyphData->bitmapWidth  <= targetWidth,                 NgosStatus::ASSERTION);
                COMMON_TEST_ASSERT(charPosY + glyphData->bitmapHeight <= CHAR_HEIGHT + BOTTOM_MARGIN, NgosStatus::ASSERTION);
                COMMON_TEST_ASSERT(glyphData->bitmapHeight            <= CHAR_HEIGHT,                 NgosStatus::ASSERTION);



                u8 bitmapLeft = charPosX < 0 ? (u8)(-charPosX) : 0;
                u8 bitmapTop  = charPosY < 0 ? (u8)(-charPosY) : 0;



                for (i64 i = bitmapTop; i < glyphData->bitmapHeight; ++i)
                {
                    for (i64 j = bitmapLeft; j < glyphData->bitmapWidth; ++j)
                    {
                        RgbaPixel *pixel = &oneLineImage->getRgbaBuffer()[(charPosY + i) * oneLineImage->getWidth() + charPosX + j];

                        COMMON_TEST_ASSERT((u64)pixel >= (u64)oneLineImage->getBuffer()
                                            &&
                                            (u64)pixel <= (u64)oneLineImage->getBuffer() + oneLineImage->getBufferSize() - sizeof(RgbaPixel), NgosStatus::ASSERTION);



                        pixel->red   = 0xFF;
                        pixel->green = 0xFF;
                        pixel->blue  = 0xFF;
                        pixel->alpha = *bitmapByte;

                        ++bitmapByte;
                    }
                }

                curX += glyphData->width;
            }



            ++str;
        }



        if (curX)
        {
            COMMON_ASSERT_EXECUTION(Graphics::insertImageRaw(
                                        oneLineImage->getBuffer(),
                                        fullImage->getBuffer(),
                                        targetWidth,
                                        CHAR_HEIGHT + BOTTOM_MARGIN,
                                        targetWidth,
                                        targetHeight,
                                        oneLineImage->getBytesPerPixel(),
                                        fullImage->getBytesPerPixel(),
                                        false,
                                        (targetWidth - curX) >> 1,
                                        curY),
                                    NgosStatus::ASSERTION);
        }



        Image *resizedImage;

        COMMON_ASSERT_EXECUTION(Graphics::resizeImageProportional(fullImage, mWidth, mHeight, &resizedImage), NgosStatus::ASSERTION);

        COMMON_ASSERT_EXECUTION(Graphics::insertImageRaw(
                                    resizedImage->getBuffer(),
                                    mResultImage->getBuffer(),
                                    resizedImage->getWidth(),
                                    resizedImage->getHeight(),
                                    mResultImage->getWidth(),
                                    mResultImage->getHeight(),
                                    resizedImage->getBytesPerPixel(),
                                    mResultImage->getBytesPerPixel(),
                                    true,
                                    (mResultImage->getWidth() - resizedImage->getWidth()) >> 1,
                                    (mResultImage->getHeight() - resizedImage->getHeight()) >> 1),
                                NgosStatus::ASSERTION);

        delete fullImage;
        delete oneLineImage;
        delete resizedImage;
    }



    return NgosStatus::OK;
}

NgosStatus LabelWidget::setText(const char8 *text)
{
    COMMON_LT((" | text = 0x%p", text));



    mText = text;



    return NgosStatus::OK;
}

const char8* LabelWidget::getText() const
{
    COMMON_LT((""));



    return mText;
}
