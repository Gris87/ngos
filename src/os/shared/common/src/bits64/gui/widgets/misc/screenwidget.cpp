#include "screenwidget.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



ScreenWidget::ScreenWidget(Image *backgroundImage, u8 *frameBuffer, Widget *parent)
    : Widget(parent)
    , mBackgroundImage(backgroundImage)
    , mFrameBuffer(frameBuffer)
{
    COMMON_LT((" | backgroundImage = 0x%p, frameBuffer = 0x%p, parent = 0x%p", backgroundImage, frameBuffer, parent));

    COMMON_ASSERT(backgroundImage, "backgroundImage is null");
    COMMON_ASSERT(frameBuffer,     "frameBuffer is null");
}

ScreenWidget::~ScreenWidget()
{
    COMMON_LT((""));
}
