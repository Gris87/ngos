#include "labelwidget.h"

#include <common/src/bits64/assets/assets.h>
#include <common/src/bits64/console/lib/glyphdata.h>
#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



#define CHAR_HEIGHT   41
#define SIDE_MARGIN   2
#define BOTTOM_MARGIN 15



LabelWidget::LabelWidget(const char8 *text, Widget *parent)
    : Widget(parent)
    , mText(text)
    , mGlyphOffsets(nullptr)
    , mColor()
{
    COMMON_LT((" | text = 0x%p, parent = 0x%p", text, parent));

    COMMON_ASSERT(text,   "text is null");
    COMMON_ASSERT(parent, "parent is null");



    AssetEntry *asset = Assets::getAssetEntry("glyphs/gui.bin");
    COMMON_TEST_ASSERT(asset);

    mGlyphOffsets = (u16 *)asset->content;



    mColor.red   = 0xFF;
    mColor.green = 0xFF;
    mColor.blue  = 0xFF;
    mColor.alpha = 0xFF;
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



    COMMON_TEST_ASSERT(mText               != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mGlyphOffsets       != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mChildren.getHead() == nullptr, NgosStatus::ASSERTION);



    u16 targetWidth  = 0;
    u16 targetHeight = CHAR_HEIGHT + BOTTOM_MARGIN;
    u16 curX         = SIDE_MARGIN << 1; // "<< 1" == "* 2"



    const char8 *str = mText;

    while (*str)
    {
        char8 ch = *str;

        if (ch == '\n')
        {
            curX         =  SIDE_MARGIN << 1; // "<< 1" == "* 2"
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



    mOwnResultImage = new Image(mWidth, mHeight, true, false);
    mOwnResultImage->clearBuffer();



    if (targetWidth) // targetWidth > 0
    {
        Image *fullImage = new Image(targetWidth, targetHeight, true, false);
        fullImage->clearBuffer();

        Image *oneLineImage = new Image(targetWidth, CHAR_HEIGHT + BOTTOM_MARGIN, true, false);
        oneLineImage->clearBuffer();



        u16 curX = SIDE_MARGIN;
        u16 curY = 0;

        const char8 *str = mText;

        while (*str)
        {
            char8 ch = *str;

            if (ch == '\n')
            {
                if (curX > SIDE_MARGIN)
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

                    curX = SIDE_MARGIN;
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

                COMMON_TEST_ASSERT(charPosX                           >= 0,                           NgosStatus::ASSERTION);
                COMMON_TEST_ASSERT(charPosX + glyphData->bitmapWidth  <= targetWidth,                 NgosStatus::ASSERTION);
                COMMON_TEST_ASSERT(charPosY                           >= 0,                           NgosStatus::ASSERTION);
                COMMON_TEST_ASSERT(charPosY + glyphData->bitmapHeight <= CHAR_HEIGHT + BOTTOM_MARGIN, NgosStatus::ASSERTION);
                COMMON_TEST_ASSERT(glyphData->bitmapHeight            <= CHAR_HEIGHT,                 NgosStatus::ASSERTION);



                for (i64 i = 0; i < glyphData->bitmapHeight; ++i)
                {
                    for (i64 j = 0; j < glyphData->bitmapWidth; ++j)
                    {
                        RgbaPixel *pixel = &oneLineImage->getRgbaBuffer()[(charPosY + i) * targetWidth + charPosX + j];

                        COMMON_TEST_ASSERT((u64)pixel >= (u64)oneLineImage->getBuffer()
                                            &&
                                            (u64)pixel <= (u64)oneLineImage->getBuffer() + oneLineImage->getBufferSize() - sizeof(RgbaPixel), NgosStatus::ASSERTION);



                        pixel->red   = mColor.red;
                        pixel->green = mColor.green;
                        pixel->blue  = mColor.blue;
                        pixel->alpha = *bitmapByte * mColor.alpha / 0xFF;

                        ++bitmapByte;
                    }
                }

                curX += glyphData->width;
            }



            ++str;
        }



        if (curX > SIDE_MARGIN)
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
                                    mOwnResultImage->getBuffer(),
                                    resizedImage->getWidth(),
                                    resizedImage->getHeight(),
                                    mOwnResultImage->getWidth(),
                                    mOwnResultImage->getHeight(),
                                    resizedImage->getBytesPerPixel(),
                                    mOwnResultImage->getBytesPerPixel(),
                                    true,
                                    (mOwnResultImage->getWidth() - resizedImage->getWidth()) >> 1,
                                    (mOwnResultImage->getHeight() - resizedImage->getHeight()) >> 1),
                                NgosStatus::ASSERTION);

        delete fullImage;
        delete oneLineImage;
        delete resizedImage;
    }



    if (mResultImage)
    {
        delete mResultImage;
    }

    mResultImage = mOwnResultImage;



    return NgosStatus::OK;
}

NgosStatus LabelWidget::setText(const char8 *text)
{
    COMMON_LT((" | text = 0x%p", text));



    mText = text;

    COMMON_ASSERT_EXECUTION(repaint(), NgosStatus::ASSERTION);

    if (isVisible())
    {
        COMMON_ASSERT_EXECUTION(update(), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

const char8* LabelWidget::getText() const
{
    COMMON_LT((""));



    return mText;
}

NgosStatus LabelWidget::setColor(const RgbaPixel &color)
{
    COMMON_LT((""));



    mColor = color;

    COMMON_ASSERT_EXECUTION(repaint(), NgosStatus::ASSERTION);

    if (isVisible())
    {
        COMMON_ASSERT_EXECUTION(update(), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

const RgbaPixel& LabelWidget::getColor() const
{
    COMMON_LT((""));



    return mColor;
}
