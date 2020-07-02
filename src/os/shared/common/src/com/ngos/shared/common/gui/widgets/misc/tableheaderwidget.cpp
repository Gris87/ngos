#include "tableheaderwidget.h"

#include <common/src/com/ngos/shared/common/graphics/graphics.h>
#include <common/src/com/ngos/shared/common/gui/gui.h>
#include <common/src/com/ngos/shared/common/log/assert.h>
#include <common/src/com/ngos/shared/common/log/log.h>



TableHeaderWidget::TableHeaderWidget(Image *image, const char8 *text, Widget *parent)
    : Widget(parent)
    , mImage(image)
    , mLabelWidget(nullptr)
{
    COMMON_LT((" | image = 0x%p, text = 0x%p, parent = 0x%p", image, text, parent));

    COMMON_ASSERT(image,  "image is null");
    COMMON_ASSERT(parent, "parent is null");



    if (text != nullptr && text[0] != 0)
    {
        mLabelWidget = new LabelWidget(text, this);
    }
}

TableHeaderWidget::~TableHeaderWidget()
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

NgosStatus TableHeaderWidget::invalidate()
{
    COMMON_LT((""));



    if (mOwnResultImage)
    {
        delete mOwnResultImage;
    }

    COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mImage, mWidth, mHeight, &mOwnResultImage), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus TableHeaderWidget::repaint()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(mOwnResultImage != nullptr, NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



    if (mResultImage)
    {
        delete mResultImage;
    }

    mResultImage = new Image(*mOwnResultImage);



    if (mLabelWidget)
    {
        NinePatch *patch = mImage->getNinePatch();

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



        COMMON_ASSERT_EXECUTION(mLabelWidget->lockUpdates(),                        NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(mLabelWidget->setPosition(paddingLeft, paddingTop), NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(mLabelWidget->setSize(allowedWidth, allowedHeight), NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(mLabelWidget->unlockUpdates(),                      NgosStatus::ASSERTION);
    }



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
