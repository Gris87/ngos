#include "screenwidget.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/graphics/rgbapixel.h>
#include <common/src/bits64/graphics/rgbpixel.h>
#include <common/src/bits64/gui/widgets/misc/rootwidget.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/memory/memory.h>



ScreenWidget::ScreenWidget(Image *backgroundImage, u8 *frameBuffer, RootWidget *rootWidget)
    : Widget()
    , mBackgroundImage(backgroundImage)
    , mFrameBuffer(frameBuffer)
    , mRootWidget(rootWidget)
    , mBackgroundResizedImage(0)
{
    COMMON_LT((" | backgroundImage = 0x%p, frameBuffer = 0x%p, rootWidget = 0x%p", backgroundImage, frameBuffer, rootWidget));

    COMMON_ASSERT(backgroundImage, "backgroundImage is null");
    COMMON_ASSERT(frameBuffer,     "frameBuffer is null");
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
}

NgosStatus ScreenWidget::updateRegion(i64 positionX, i64 positionY, u64 width, u64 height)
{
    COMMON_LT((" | positionX = %d, positionY = %d, width = %u, height = %u", positionX, positionY, width, height));

    COMMON_ASSERT(width > 0,  "width is zero",  NgosStatus::ASSERTION);
    COMMON_ASSERT(height > 0, "height is zero", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mBackgroundResizedImage != 0, NgosStatus::ASSERTION);

    COMMON_ASSERT_EXECUTION(Graphics::insertImageRaw(mBackgroundResizedImage->getBuffer(), mFrameBuffer, mBackgroundResizedImage->getWidth(), mBackgroundResizedImage->getHeight(), mWidth, mHeight, mBackgroundResizedImage->getBytesPerPixel(), sizeof(RgbaPixel), true, 0, 0, positionX, positionY, positionX + width, positionY + height), NgosStatus::ASSERTION);



    drawWidget(mChildren.getHead()->getData(), positionX, positionY);



    return NgosStatus::OK;
}

NgosStatus ScreenWidget::update(i64 positionX, i64 positionY, u64 width, u64 height)
{
    COMMON_LT((" | positionX = %d, positionY = %d, width = %u, height = %u", positionX, positionY, width, height));

    COMMON_ASSERT(width > 0,  "width is zero",  NgosStatus::ASSERTION);
    COMMON_ASSERT(height > 0, "height is zero", NgosStatus::ASSERTION);



    if (mRootWidget)
    {
        return mRootWidget->update(mPositionX + positionX, mPositionY + positionY, width, height);
    }



    return NgosStatus::OK;
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

    memcpy(mFrameBuffer, mBackgroundResizedImage->getBuffer(), mBackgroundResizedImage->getBufferSize());



    return NgosStatus::OK;
}

NgosStatus ScreenWidget::drawWidget(Widget *widget, i64 positionX, i64 positionY)
{
    COMMON_LT((" | widget = 0x%p, positionX = %d, positionY = %d", widget, positionX, positionY));

    COMMON_ASSERT(widget, "widget is null", NgosStatus::ASSERTION);



    Image *image = widget->getResultImage();

    COMMON_ASSERT_EXECUTION(Graphics::insertImageRaw(image->getBuffer(), mFrameBuffer, image->getWidth(), image->getHeight(), mWidth, mHeight, image->getBytesPerPixel(), sizeof(RgbaPixel), image->isOpaque(), positionX, positionY), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
