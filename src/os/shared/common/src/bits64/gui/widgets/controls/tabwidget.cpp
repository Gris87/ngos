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

NgosStatus TabWidget::addTabButton(Button *button)
{
    COMMON_LT((" | button = 0x%p", button));

    COMMON_ASSERT(button, "button is null", NgosStatus::ASSERTION);



    mTabButtons.append(button);



    return NgosStatus::OK;
}

NgosStatus TabWidget::addTabPage(Widget *page)
{
    COMMON_LT((" | page = 0x%p", page));

    COMMON_ASSERT(page, "page is null", NgosStatus::ASSERTION);



    mTabPages.append(page);



    return NgosStatus::OK;
}

NgosStatus TabWidget::invalidate()
{
    COMMON_LT((""));



    if (mPanelResizedImage)
    {
        delete mPanelResizedImage;
    }



    if (mTabButtons.getSize() > 0)
    {
        u64 maxTabButtonHeight = mTabButtons.at(0)->getHeight();

        for (i64 i = 1; i < (i64)mTabButtons.getSize(); ++i)
        {
            u64 buttonHeight = mTabButtons.at(i)->getHeight();

            if (buttonHeight > maxTabButtonHeight)
            {
                maxTabButtonHeight = buttonHeight;
            }
        }

        COMMON_TEST_ASSERT(maxTabButtonHeight < mHeight, NgosStatus::ASSERTION);



        mPanelResizedImage = new Image(mWidth, mHeight, true, false);
        mPanelResizedImage->clearBuffer();



        COMMON_ASSERT_EXECUTION(Graphics::insertImage(mPanelImage, mPanelResizedImage, 0, maxTabButtonHeight, mWidth, mHeight - maxTabButtonHeight), NgosStatus::ASSERTION);
    }
    else
    {
        COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mPanelImage, mWidth, mHeight, &mPanelResizedImage), NgosStatus::ASSERTION);
    }



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



    NinePatch *patch = mPanelImage->getNinePatch();

    u16 paddingLeft;
    u16 paddingTop;
    u16 paddingRight;

    if (patch)
    {
        paddingLeft  = patch->getPaddingLeft();
        paddingTop   = patch->getPaddingTop();
        paddingRight = patch->getPaddingRight();
    }
    else
    {
        paddingLeft  = 0;
        paddingTop   = 0;
        paddingRight = 0;
    }



    u64 buttonPositionX = paddingLeft;

    for (i64 i = 0; i < (i64)mTabButtons.getSize(); ++i)
    {
        Button *tabButton = mTabButtons.at(i);

        COMMON_TEST_ASSERT(buttonPositionX                         <= mWidth - paddingRight, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(buttonPositionX + tabButton->getWidth() <= mWidth - paddingRight, NgosStatus::ASSERTION);

        COMMON_ASSERT_EXECUTION(tabButton->lockUpdates(),                            NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(tabButton->setPosition(buttonPositionX, paddingTop), NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(tabButton->unlockUpdates(),                          NgosStatus::ASSERTION);

        buttonPositionX += tabButton->getWidth() * 95 / 100;
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
