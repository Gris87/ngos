#include "treewidget.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/gui/gui.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



TreeWidget::TreeWidget(Image *backgroundImage, Widget *parent)
    : Widget(parent)
    , mBackgroundImage(backgroundImage)
    , mWrapperWidget(new WrapperWidget(this))
    , mRowHeight(0)
{
    COMMON_LT((" | backgroundImage = 0x%p, parent = 0x%p", backgroundImage, parent));

    COMMON_ASSERT(backgroundImage, "backgroundImage is null");
    COMMON_ASSERT(parent,          "parent is null");
}

TreeWidget::~TreeWidget()
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

NgosStatus TreeWidget::invalidate()
{
    COMMON_LT((""));



    if (mOwnResultImage)
    {
        delete mOwnResultImage;
    }

    COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mBackgroundImage, mWidth, mHeight, &mOwnResultImage), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus TreeWidget::repaint()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(mOwnResultImage != nullptr, NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



    if (mResultImage)
    {
        delete mResultImage;
    }

    mResultImage = new Image(*mOwnResultImage);



    NinePatch *patch = mBackgroundImage->getNinePatch();

    u16 paddingLeft;
    u16 paddingTop;
    u64 allowedWidth;
    u64 allowedHeight;

    if (patch)
    {
        paddingLeft = patch->getPaddingLeft();
        paddingTop  = patch->getPaddingTop();

        allowedWidth  = mWidth  - paddingLeft - patch->getPaddingRight();
        allowedHeight = mHeight - paddingTop  - patch->getPaddingBottom();
    }
    else
    {
        paddingLeft = 0;
        paddingTop  = 0;

        allowedWidth  = mWidth;
        allowedHeight = mHeight;
    }



    COMMON_ASSERT_EXECUTION(mWrapperWidget->lockUpdates(),                        NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(mWrapperWidget->setPosition(paddingLeft, paddingTop), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(mWrapperWidget->setSize(allowedWidth, allowedHeight), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(mWrapperWidget->unlockUpdates(),                      NgosStatus::ASSERTION);



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

bool TreeWidget::isFocusable()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return true;
}

NgosStatus TreeWidget::setRowHeight(u64 height)
{
    COMMON_LT((" | height = %u", height));

    COMMON_ASSERT(height > 0, "height is zero", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mRowHeight == 0, NgosStatus::ASSERTION);



    mRowHeight = height;



    return NgosStatus::OK;
}

u64 TreeWidget::getRowHeight() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mRowHeight;
}

NgosStatus TreeWidget::setRootNodeWidget(TreeNodeWidget *widget)
{
    COMMON_LT((" | widget = 0x%p", widget));

    COMMON_ASSERT(widget, "widget is null", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mRowHeight != 0, NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(widget->setParent(mWrapperWidget),                       NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(widget->setRowHeight(mRowHeight),                        NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(widget->setSize(mWrapperWidget->getWidth(), mRowHeight), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
