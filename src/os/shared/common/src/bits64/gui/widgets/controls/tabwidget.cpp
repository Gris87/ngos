#include "tabwidget.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/gui/gui.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



TabWidget::TabWidget(Image *panelImage, Widget *parent)
    : Widget(parent)
    , mPanelImage(panelImage)
    , mPanelResizedImage(nullptr)
{
    COMMON_LT((" | panelImage = 0x%p, parent = 0x%p", panelImage, parent));

    COMMON_ASSERT(panelImage, "panelImage is null");
    COMMON_ASSERT(parent,     "parent is null");
}

TabWidget::~TabWidget()
{
    COMMON_LT((""));



    if (mPanelResizedImage)
    {
        delete mPanelResizedImage;
    }

    if (mResultImage)
    {
        delete mResultImage;
    }
}

NgosStatus TabWidget::invalidate()
{
    COMMON_LT((""));



    if (mPanelResizedImage)
    {
        delete mPanelResizedImage;
    }

    COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mPanelImage, mWidth, mHeight, &mPanelResizedImage), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus TabWidget::repaint()
{
    COMMON_LT((""));



    COMMON_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mPanelResizedImage != nullptr, NgosStatus::ASSERTION);



    mOwnResultImage = mPanelResizedImage;



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



    COMMON_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
