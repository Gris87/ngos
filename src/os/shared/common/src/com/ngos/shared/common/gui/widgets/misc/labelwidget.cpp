#include "labelwidget.h"

#include <com/ngos/shared/common/assets/assets.h>
#include <com/ngos/shared/common/console/lib/glyphdata.h>
#include <com/ngos/shared/common/graphics/graphics.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>



#define CHAR_HEIGHT   41
#define SIDE_MARGIN   2
#define BOTTOM_MARGIN 15



LabelWidget::LabelWidget(const char8 *text, Widget *parent)
    : Widget(parent)
    , mText(text)
    , mGlyphOffsets(nullptr)
    , mColor(0xFFFFFFFF)
    , mHorizontalAlignment(HorizontalAlignment::CENTER)
    , mVerticalAlignment(VerticalAlignment::MIDDLE)
{
    COMMON_LT((" | text = 0x%p, parent = 0x%p", text, parent));

    COMMON_ASSERT(text,   "text is null");
    COMMON_ASSERT(parent, "parent is null");



    AssetEntry *asset = Assets::getAssetEntry("glyphs/gui.bin");
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



    COMMON_TEST_ASSERT(mText               != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mGlyphOffsets       != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mChildren.getHead() == nullptr, NgosStatus::ASSERTION);



    u16 targetWidth  = 0;
    u16 targetHeight = CHAR_HEIGHT + BOTTOM_MARGIN;
    u16 curX         = SIDE_MARGIN * 2;



    const char8 *str = mText;

    while (*str)
    {
        char8 ch = *str;

        if (ch == '\n')
        {
            curX         =  SIDE_MARGIN * 2;
            targetHeight += CHAR_HEIGHT;
        }
        else
        if (ch >= 0x20 && ch < 0x7F)
        {
            GlyphData *glyphData = (GlyphData *)((address_t)mGlyphOffsets + mGlyphOffsets[ch - 0x20]);

            curX += glyphData->width;

            if (curX > targetWidth)
            {
                targetWidth = curX;
            }
        }
        else
        {
            COMMON_LW(("Non-printable character found: 0x%02X", ch));

            return NgosStatus::UNEXPECTED_BEHAVIOUR;
        }



        ++str;
    }



    mOwnResultImage = new Image(mWidth, mHeight, true, false);
    COMMON_ASSERT_EXECUTION(mOwnResultImage->clearBuffer(), NgosStatus::ASSERTION);



    if (targetWidth > 0)
    {
        Image *fullImage = new Image(targetWidth, targetHeight, true, false);
        COMMON_ASSERT_EXECUTION(fullImage->clearBuffer(), NgosStatus::ASSERTION);

        Image *oneLineImage = new Image(targetWidth, CHAR_HEIGHT + BOTTOM_MARGIN, true, false);
        COMMON_ASSERT_EXECUTION(oneLineImage->clearBuffer(), NgosStatus::ASSERTION);



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
                                                applyHorizontalAlignment(targetWidth, curX),
                                                curY),
                                            NgosStatus::ASSERTION);

                    COMMON_ASSERT_EXECUTION(oneLineImage->clearBuffer(), NgosStatus::ASSERTION);

                    curX = SIDE_MARGIN;
                }

                curY += CHAR_HEIGHT;
            }
            else
            if (ch >= 0x20 && ch < 0x7F)
            {
                GlyphData *glyphData = (GlyphData *)((address_t)mGlyphOffsets + mGlyphOffsets[ch - 0x20]);



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

                        COMMON_TEST_ASSERT((address_t)pixel >= (address_t)oneLineImage->getBuffer()
                                            &&
                                            (address_t)pixel <= (address_t)oneLineImage->getBuffer() + oneLineImage->getBufferSize() - sizeof(RgbaPixel), NgosStatus::ASSERTION);



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
                                        applyHorizontalAlignment(targetWidth, curX),
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
                                    applyHorizontalAlignment(mOwnResultImage->getWidth(), resizedImage->getWidth()),
                                    applyVerticalAlignment(mOwnResultImage->getHeight(), resizedImage->getHeight())),
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

    if (
        mWidth > 0
        &&
        mHeight > 0
       )
    {
        COMMON_ASSERT_EXECUTION(repaint(), NgosStatus::ASSERTION);

        if (isVisible())
        {
            COMMON_ASSERT_EXECUTION(update(), NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

const char8* LabelWidget::getText() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mText;
}

NgosStatus LabelWidget::setColor(const RgbaPixel &color)
{
    COMMON_LT((" | color = ..."));



    mColor = color;

    if (
        mWidth > 0
        &&
        mHeight > 0
       )
    {
        COMMON_ASSERT_EXECUTION(repaint(), NgosStatus::ASSERTION);

        if (isVisible())
        {
            COMMON_ASSERT_EXECUTION(update(), NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

const RgbaPixel& LabelWidget::getColor() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mColor;
}

NgosStatus LabelWidget::setHorizontalAlignment(HorizontalAlignment alignment)
{
    COMMON_LT((" | alignment = %u", alignment));



    if (mHorizontalAlignment != alignment)
    {
        mHorizontalAlignment = alignment;

        if (
            mWidth > 0
            &&
            mHeight > 0
           )
        {
            COMMON_ASSERT_EXECUTION(repaint(), NgosStatus::ASSERTION);

            if (isVisible())
            {
                COMMON_ASSERT_EXECUTION(update(), NgosStatus::ASSERTION);
            }
        }
    }



    return NgosStatus::OK;
}

HorizontalAlignment LabelWidget::getHorizontalAlignment() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mHorizontalAlignment;
}

NgosStatus LabelWidget::setVerticalAlignment(VerticalAlignment alignment)
{
    COMMON_LT((" | alignment = %u", alignment));



    if (mVerticalAlignment != alignment)
    {
        mVerticalAlignment = alignment;

        if (
            mWidth > 0
            &&
            mHeight > 0
           )
        {
            COMMON_ASSERT_EXECUTION(repaint(), NgosStatus::ASSERTION);

            if (isVisible())
            {
                COMMON_ASSERT_EXECUTION(update(), NgosStatus::ASSERTION);
            }
        }
    }



    return NgosStatus::OK;
}

VerticalAlignment LabelWidget::getVerticalAlignment() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mVerticalAlignment;
}

i64 LabelWidget::applyHorizontalAlignment(i64 fullWidth, i64 targetWidth)
{
    COMMON_LT((" | fullWidth = %d, targetWidth = %d", fullWidth, targetWidth));



    switch (mHorizontalAlignment)
    {
        case HorizontalAlignment::LEFT_JUSTIFIED:  return 0;
        case HorizontalAlignment::CENTER:          return (fullWidth - targetWidth) / 2;
        case HorizontalAlignment::RIGHT_JUSTIFIED: return fullWidth - targetWidth;

        case HorizontalAlignment::NONE:
        {
            COMMON_LF(("Unexpected horizontal alignment %s, %s:%u", enumToFullString(mHorizontalAlignment), __FILE__, __LINE__));

            return 0;
        }
        break;

        default:
        {
            COMMON_LF(("Unknown horizontal alignment %s, %s:%u", enumToFullString(mHorizontalAlignment), __FILE__, __LINE__));

            return 0;
        }
        break;
    }



    return 0;
}

i64 LabelWidget::applyVerticalAlignment(i64 fullHeight, i64 targetHeight)
{
    COMMON_LT((" | fullHeight = %d, targetHeight = %d", fullHeight, targetHeight));



    switch (mVerticalAlignment)
    {
        case VerticalAlignment::TOP:    return 0;
        case VerticalAlignment::MIDDLE: return (fullHeight - targetHeight) / 2;
        case VerticalAlignment::BOTTOM: return fullHeight - targetHeight;

        case VerticalAlignment::NONE:
        {
            COMMON_LF(("Unexpected vertical alignment %s, %s:%u", enumToFullString(mVerticalAlignment), __FILE__, __LINE__));

            return 0;
        }
        break;

        default:
        {
            COMMON_LF(("Unknown vertical alignment %s, %s:%u", enumToFullString(mVerticalAlignment), __FILE__, __LINE__));

            return 0;
        }
        break;
    }



    return 0;
}
