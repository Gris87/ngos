#include "progressbarwidget.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/gui/gui.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



ProgressBarWidget::ProgressBarWidget(Image *backgroundImage, Image *indicatorImage, Widget *parent)
    : Widget(parent)
    , mPanelWidget(nullptr)
    , mIndicatorImageWidget(nullptr)
    , mLabelWidget(nullptr)
    , mMinimumValue(0)
    , mMaximumValue(100)
    , mValue(0)
    , mPercentBuffer()
{
    COMMON_LT((" | backgroundImage = 0x%p, indicatorImage = 0x%p, parent = 0x%p", backgroundImage, indicatorImage, parent));

    COMMON_ASSERT(backgroundImage, "backgroundImage is null");
    COMMON_ASSERT(indicatorImage,  "indicatorImage is null");
    COMMON_ASSERT(parent,          "parent is null");



    mPanelWidget          = new PanelWidget(backgroundImage, this);
    mIndicatorImageWidget = new ImageWidget(indicatorImage,  mPanelWidget);
    mLabelWidget          = new LabelWidget(mPercentBuffer,  this);
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



    COMMON_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



    if (mResultImage)
    {
        delete mResultImage;
    }

    mResultImage = new Image(*mOwnResultImage);



    NinePatch *patch = mPanelWidget->getPanelImage()->getNinePatch();

    u16 paddingLeft;
    u16 paddingTop;
    u16 paddingRight;
    u16 paddingBottom;
    u64 allowedWidth;
    u64 allowedHeight;

    if (patch)
    {
        paddingLeft   = patch->getPaddingLeft();
        paddingTop    = patch->getPaddingTop();
        paddingRight  = patch->getPaddingRight();
        paddingBottom = patch->getPaddingBottom();

        allowedWidth  = mWidth  - paddingLeft - paddingRight;
        allowedHeight = mHeight - paddingTop  - paddingBottom;
    }
    else
    {
        paddingLeft   = 0;
        paddingTop    = 0;
        paddingRight  = 0;
        paddingBottom = 0;

        allowedWidth  = mWidth;
        allowedHeight = mHeight;
    }



    COMMON_ASSERT_EXECUTION(mPanelWidget->lockUpdates(), NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(mIndicatorImageWidget->lockUpdates(),                        NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(mIndicatorImageWidget->setPosition(paddingLeft, paddingTop), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(mIndicatorImageWidget->setSize(allowedWidth, allowedHeight), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(mIndicatorImageWidget->unlockUpdates(),                      NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(mPanelWidget->setPosition(0, 0),        NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(mPanelWidget->setSize(mWidth, mHeight), NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(mPanelWidget->unlockUpdates(), NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(mLabelWidget->lockUpdates(),            NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(mLabelWidget->setText("100 %"),         NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(mLabelWidget->setPosition(0, 0),        NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(mLabelWidget->setSize(mWidth, mHeight), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(mLabelWidget->unlockUpdates(),          NgosStatus::ASSERTION);



    ListElement<Widget *> *element = mChildren.getHead();

    while (element)
    {
        Widget *widget = element->getData();

        COMMON_ASSERT_EXECUTION(drawWidget(widget, widget->getPositionX(), widget->getPositionY()), NgosStatus::ASSERTION);

        element = element->getNext();
    }



    COMMON_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus ProgressBarWidget::setColor(const RgbaPixel &color)
{
    COMMON_LT((" | color = ..."));



    COMMON_TEST_ASSERT(mLabelWidget != nullptr, NgosStatus::ASSERTION);

    COMMON_ASSERT_EXECUTION(mLabelWidget->setColor(color), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
