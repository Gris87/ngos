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
    , mBackgroundResizedImage(0)
{
    COMMON_LT((" | backgroundImage = 0x%p, frameBuffer = 0x%p, rootWidget = 0x%p", backgroundImage, frameBuffer, rootWidget));

    COMMON_ASSERT(backgroundImage, "backgroundImage is null");
    COMMON_ASSERT(frameBuffer,     "frameBuffer is null");
    COMMON_ASSERT(rootWidget,      "rootWidget is null");



    rootWidget->addScreen(this);
}

ScreenWidget::~ScreenWidget()
{
    COMMON_LT((""));



    if (mBackgroundResizedImage)
    {
        COMMON_ASSERT_EXECUTION(free(mBackgroundResizedImage));
    }
}

NgosStatus ScreenWidget::invalidate()
{
    COMMON_LT((""));



    COMMON_ASSERT_EXECUTION(Widget::invalidate(), NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mBackgroundResizedImage == 0, NgosStatus::ASSERTION);

    COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mBackgroundImage, mWidth, mHeight, &mBackgroundResizedImage), NgosStatus::ASSERTION);

    if (
        !mBackgroundResizedImage->hasAlpha
        ||
        !mBackgroundResizedImage->isOpaque
       )
    {
        Image *newImage;

        COMMON_ASSERT_EXECUTION(Graphics::makeOpaqueImage(mBackgroundResizedImage, &newImage), NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(free(mBackgroundResizedImage),                                 NgosStatus::ASSERTION);

        mBackgroundResizedImage = newImage;
    }



    return NgosStatus::OK;
}

NgosStatus ScreenWidget::repaint()
{
    COMMON_LT((""));



    COMMON_ASSERT_EXECUTION(Widget::repaint(), NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mBackgroundResizedImage != 0, NgosStatus::ASSERTION);

    memcpy(mFrameBuffer, mBackgroundResizedImage->data, mWidth * mHeight * sizeof(RgbaPixel));



    return NgosStatus::OK;
}

NgosStatus ScreenWidget::drawWidget(Widget *widget, i64 positionX, i64 positionY)
{
    COMMON_LT((" | widget = 0x%p, positionX = %d, positionX = %d", widget, positionX, positionX));

    COMMON_ASSERT(widget, "widget is null", NgosStatus::ASSERTION);



    Image *image = widget->mResultImage;

    COMMON_ASSERT_EXECUTION(Graphics::insertImageRaw(image->data, mFrameBuffer, image->width, image->height, mWidth, mHeight, image->hasAlpha ? sizeof(RgbaPixel) : sizeof(RgbPixel), sizeof(RgbaPixel), image->isOpaque, positionX, positionY), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
