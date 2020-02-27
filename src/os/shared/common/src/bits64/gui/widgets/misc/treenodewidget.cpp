#include "treenodewidget.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/gui/gui.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



TreeNodeWidget::TreeNodeWidget(Image *collapsedImage, Image *expandedImage, Image *image, const char8 *text, Widget *parent)
    : Widget(parent)
    , mCollapsedImage(collapsedImage)
    , mExpandedImage(expandedImage)
    , mImage(image)
    , mLabelWidget(nullptr)
{
    COMMON_LT((" | collapsedImage = 0x%p, expandedImage = 0x%p, image = 0x%p, text = 0x%p, parent = 0x%p", collapsedImage, expandedImage, image, text, parent));

    COMMON_ASSERT(collapsedImage, "collapsedImage is null");
    COMMON_ASSERT(expandedImage,  "expandedImage is null");
    COMMON_ASSERT(image,          "image is null");
    COMMON_ASSERT(parent,         "parent is null");



    if (text && *text)
    {
        mLabelWidget = new LabelWidget(text, this);
    }
}

TreeNodeWidget::~TreeNodeWidget()
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

NgosStatus TreeNodeWidget::invalidate()
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

NgosStatus TreeNodeWidget::repaint()
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
        COMMON_ASSERT_EXECUTION(mLabelWidget->lockUpdates(),            NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(mLabelWidget->setPosition(0, 0),        NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(mLabelWidget->setSize(mWidth, mHeight), NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(mLabelWidget->unlockUpdates(),          NgosStatus::ASSERTION);
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
