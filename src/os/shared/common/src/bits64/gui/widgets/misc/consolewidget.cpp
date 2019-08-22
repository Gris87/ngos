#include "consolewidget.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



ConsoleWidget::ConsoleWidget(Image *image, Widget *parent)
    : Widget(parent)
    , mImage(image)
    , mResizedImage(0)
{
    COMMON_LT((" | image = 0x%p, parent = 0x%p", image, parent));

    COMMON_ASSERT(image, "image is null");
}

ConsoleWidget::~ConsoleWidget()
{
    COMMON_LT((""));



    if (mResizedImage)
    {
        COMMON_ASSERT_EXECUTION(free(mResizedImage));
    }

    if (mResultImage)
    {
        COMMON_ASSERT_EXECUTION(free(mResultImage));
    }
}

NgosStatus ConsoleWidget::invalidate()
{
    COMMON_LT((""));



    COMMON_ASSERT_EXECUTION(Widget::invalidate(), NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mResizedImage == 0, NgosStatus::ASSERTION);

    COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mImage, mWidth, mHeight, &mResizedImage), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus ConsoleWidget::repaint()
{
    COMMON_LT((""));



    COMMON_ASSERT_EXECUTION(Widget::repaint(), NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mResizedImage       != 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mChildren.getHead() == 0, NgosStatus::ASSERTION);



    if (mResultImage)
    {
        COMMON_ASSERT_EXECUTION(free(mResultImage), NgosStatus::ASSERTION);
    }



    COMMON_ASSERT_EXECUTION(Graphics::cloneImage(mResizedImage, &mResultImage), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

Image* ConsoleWidget::getResizedImage() const
{
    COMMON_LT((""));



    return mResizedImage;
}
