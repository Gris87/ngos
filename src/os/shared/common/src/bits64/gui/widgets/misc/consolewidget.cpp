#include "consolewidget.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



ConsoleWidget::ConsoleWidget(Image *image, Widget *parent)
    : Widget(parent)
    , mImage(image)
    , mResizedImage(nullptr)
{
    COMMON_LT((" | image = 0x%p, parent = 0x%p", image, parent));

    COMMON_ASSERT(image, "image is null");
}

ConsoleWidget::~ConsoleWidget()
{
    COMMON_LT((""));



    if (mResizedImage)
    {
        delete mResizedImage;
    }

    if (mResultImage)
    {
        delete mResultImage;
    }
}

NgosStatus ConsoleWidget::update(i64 positionX, i64 positionY, u64 width, u64 height)
{
    COMMON_LT((" | positionX = %d, positionY = %d, width = %u, height = %u", positionX, positionY, width, height));

    COMMON_ASSERT(width > 0,  "width is zero",  NgosStatus::ASSERTION);
    COMMON_ASSERT(height > 0, "height is zero", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mParent, NgosStatus::ASSERTION);



    return mParent->update(mPositionX + positionX, mPositionY + positionY, width, height);
}

NgosStatus ConsoleWidget::invalidate()
{
    COMMON_LT((""));



    if (mResizedImage)
    {
        delete mResizedImage;
    }

    COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mImage, mWidth, mHeight, &mResizedImage), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus ConsoleWidget::repaint()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(mResizedImage       != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mChildren.getHead() == nullptr, NgosStatus::ASSERTION);



    if (mResultImage)
    {
        delete mResultImage;
    }

    mOwnResultImage = mResizedImage;
    mResultImage    = new Image(*mOwnResultImage);



    return NgosStatus::OK;
}
