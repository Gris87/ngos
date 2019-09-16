#include "screenwidget.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/graphics/rgbapixel.h>
#include <common/src/bits64/graphics/rgbpixel.h>
#include <common/src/bits64/gui/widgets/misc/rootwidget.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/memory/memory.h>



ScreenWidget::ScreenWidget(Image *backgroundImage, UefiGraphicsOutputProtocol *screenGop, RootWidget *rootWidget)
    : Widget()
    , mBackgroundImage(backgroundImage)
    , mScreenGop(screenGop)
    , mRootWidget(rootWidget)
    , mBackgroundResizedImage(0)
    , mDoubleBuffer((RgbaPixel *)malloc(screenGop->mode->frameBufferSize))
    , mUpdateLeft(-1)
    , mUpdateTop(-1)
    , mUpdateRight(-1)
    , mUpdateBottom(-1)
{
    COMMON_LT((" | backgroundImage = 0x%p, screenGop = 0x%p, rootWidget = 0x%p", backgroundImage, screenGop, rootWidget));

    COMMON_ASSERT(backgroundImage, "backgroundImage is null");
    COMMON_ASSERT(screenGop,       "screenGop is null");
    COMMON_ASSERT(rootWidget,      "rootWidget is null");



    mRootWidget->addScreen(this);
}

ScreenWidget::~ScreenWidget()
{
    COMMON_LT((""));



    if (mBackgroundResizedImage)
    {
        delete mBackgroundResizedImage;
    }

    free(mDoubleBuffer);
}

NgosStatus ScreenWidget::updateRegion(i64 positionX, i64 positionY, u64 width, u64 height)
{
    COMMON_LT((" | positionX = %d, positionY = %d, width = %u, height = %u", positionX, positionY, width, height));

    COMMON_ASSERT(width > 0,  "width is zero",  NgosStatus::ASSERTION);
    COMMON_ASSERT(height > 0, "height is zero", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mBackgroundResizedImage != 0, NgosStatus::ASSERTION);

    COMMON_ASSERT_EXECUTION(Graphics::insertImageRaw(mBackgroundResizedImage->getBuffer(), (u8 *)mDoubleBuffer, mBackgroundResizedImage->getWidth(), mBackgroundResizedImage->getHeight(), mWidth, mHeight, mBackgroundResizedImage->getBytesPerPixel(), sizeof(RgbaPixel), true, 0, 0, positionX, positionY, positionX + width, positionY + height), NgosStatus::ASSERTION);



    if (mUpdateLeft < 0)
    {
        mUpdateLeft   = positionX;
        mUpdateTop    = positionY;
        mUpdateRight  = positionX + width;
        mUpdateBottom = positionY + height;
    }
    else
    {
        if (positionX < mUpdateLeft)
        {
            mUpdateLeft = positionX;
        }

        if (positionY < mUpdateTop)
        {
            mUpdateTop = positionY;
        }



        if ((i64)(positionX + width) > mUpdateRight)
        {
            mUpdateRight = positionX + width;
        }

        if ((i64)(positionY + height) > mUpdateBottom)
        {
            mUpdateBottom = positionY + height;
        }
    }



    drawWidget(mChildren.getHead()->getData(), positionX, positionY); // TODO: Think about



    return NgosStatus::OK;
}

NgosStatus ScreenWidget::applyUpdates()
{
    COMMON_LT((""));



    if (mUpdateLeft >= 0)
    {
        COMMON_ASSERT_EXECUTION(mScreenGop->blt(mScreenGop,
                                                (UefiGraphicsOutputBltPixel *)mDoubleBuffer,
                                                UefiGraphicsOutputBltOperation::BLT_BUFFER_TO_VIDEO,
                                                mUpdateLeft, mUpdateTop,
                                                mUpdateLeft, mUpdateTop,
                                                mUpdateRight - mUpdateLeft,
                                                mUpdateBottom - mUpdateTop,
                                                mWidth * sizeof(RgbaPixel)),
                                UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);

        mUpdateLeft   = -1;
        mUpdateTop    = -1;
        mUpdateRight  = -1;
        mUpdateBottom = -1;
    }



    return NgosStatus::OK;
}

NgosStatus ScreenWidget::update(i64 positionX, i64 positionY, u64 width, u64 height)
{
    COMMON_LT((" | positionX = %d, positionY = %d, width = %u, height = %u", positionX, positionY, width, height));

    COMMON_ASSERT(width > 0,  "width is zero",  NgosStatus::ASSERTION);
    COMMON_ASSERT(height > 0, "height is zero", NgosStatus::ASSERTION);



    return mRootWidget->update(mPositionX + positionX, mPositionY + positionY, width, height);
}

NgosStatus ScreenWidget::invalidate()
{
    COMMON_LT((""));



    COMMON_ASSERT_EXECUTION(Widget::invalidate(), NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mBackgroundResizedImage == 0, NgosStatus::ASSERTION);

    COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mBackgroundImage, mWidth, mHeight, &mBackgroundResizedImage), NgosStatus::ASSERTION);

    if (
        !mBackgroundResizedImage->isRgba()
        ||
        !mBackgroundResizedImage->isOpaque()
       )
    {
        Image *newImage;

        COMMON_ASSERT_EXECUTION(Graphics::makeOpaqueImage(mBackgroundResizedImage, &newImage), NgosStatus::ASSERTION);

        delete mBackgroundResizedImage;
        mBackgroundResizedImage = newImage;
    }



    return NgosStatus::OK;
}

NgosStatus ScreenWidget::repaint()
{
    COMMON_LT((""));



    COMMON_ASSERT_EXECUTION(Widget::repaint(), NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mBackgroundResizedImage != 0, NgosStatus::ASSERTION);

    memcpy(mDoubleBuffer, mBackgroundResizedImage->getBuffer(), mBackgroundResizedImage->getBufferSize());



    mUpdateLeft   = 0;
    mUpdateTop    = 0;
    mUpdateRight  = mWidth;
    mUpdateBottom = mHeight;



    return NgosStatus::OK;
}

NgosStatus ScreenWidget::drawWidget(Widget *widget, i64 positionX, i64 positionY)
{
    COMMON_LT((" | widget = 0x%p, positionX = %d, positionY = %d", widget, positionX, positionY));

    COMMON_ASSERT(widget, "widget is null", NgosStatus::ASSERTION);



    if (widget->isVisible())
    {
        Image *image = widget->getResultImage();

        COMMON_ASSERT_EXECUTION(Graphics::insertImageRaw(image->getBuffer(), (u8 *)mDoubleBuffer, image->getWidth(), image->getHeight(), mWidth, mHeight, image->getBytesPerPixel(), sizeof(RgbaPixel), image->isOpaque(), positionX, positionY), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}
