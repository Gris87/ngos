#include "screenwidget.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



ScreenWidget::ScreenWidget(Image *backgroundImage, u8 *frameBuffer, Widget *parent)
    : Widget(parent)
    , mBackgroundImage(backgroundImage)
    , mFrameBuffer(frameBuffer)
    , mBackgroundResizedImage(0)
{
    COMMON_LT((" | backgroundImage = 0x%p, frameBuffer = 0x%p, parent = 0x%p", backgroundImage, frameBuffer, parent));

    COMMON_ASSERT(backgroundImage, "backgroundImage is null");
    COMMON_ASSERT(frameBuffer,     "frameBuffer is null");
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



    return NgosStatus::OK;
}
