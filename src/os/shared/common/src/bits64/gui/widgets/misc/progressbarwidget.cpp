#include "progressbarwidget.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



ProgressBarWidget::ProgressBarWidget(Image *backgroundImage, Image *indicatorImage, Widget *parent)
    : Widget(parent)
    , mPanelWidget(nullptr)
    , mIndicatorImageWidget(nullptr)
    , mLabelWidget(nullptr)
{
    COMMON_LT((" | backgroundImage = 0x%p, indicatorImage = 0x%p, parent = 0x%p", backgroundImage, indicatorImage, parent));

    COMMON_ASSERT(backgroundImage, "backgroundImage is null");
    COMMON_ASSERT(indicatorImage,  "indicatorImage is null");
    COMMON_ASSERT(parent,          "parent is null");
}

ProgressBarWidget::~ProgressBarWidget()
{
    COMMON_LT((""));



    if (mOwnResultImage)
    {
        delete mOwnResultImage;
    }

    if (mResultImage)
    {
        delete mResultImage;
    }
}

NgosStatus ProgressBarWidget::invalidate()
{
    COMMON_LT((""));



    if (mOwnResultImage)
    {
        delete mOwnResultImage;
    }

    mOwnResultImage = new Image(mWidth, mHeight, true, false);
    COMMON_ASSERT_EXECUTION(mOwnResultImage->clearBuffer(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus ProgressBarWidget::repaint()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(mOwnResultImage != nullptr, NgosStatus::ASSERTION);



    if (mResultImage)
    {
        delete mResultImage;
    }

    mResultImage = new Image(*mOwnResultImage);



    ListElement<Widget *> *element = mChildren.getHead();

    while (element)
    {
        Widget *widget = element->getData();

        COMMON_ASSERT_EXECUTION(drawWidget(widget, widget->getPositionX(), widget->getPositionY()), NgosStatus::ASSERTION);

        element = element->getNext();
    }



    return NgosStatus::OK;
}
