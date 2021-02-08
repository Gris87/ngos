#include "tabwidget.h"

#include <com/ngos/shared/common/graphics/graphics.h>
#include <com/ngos/shared/common/gui/gui.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>



TabWidget::TabWidget(Image *panelImage, Widget *parent)
    : Widget(parent)
    , mPanelImage(panelImage)
    , mTabButtons()
    , mTabPages()
    , mCurrentPage(-1)
{
    COMMON_LT((" | panelImage = 0x%p, parent = 0x%p", panelImage, parent));

    COMMON_ASSERT(panelImage, "panelImage is null");
    COMMON_ASSERT(parent,     "parent is null");
}

TabWidget::~TabWidget()
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

NgosStatus TabWidget::addTabButton(TabButton *button)
{
    COMMON_LT((" | button = 0x%p", button));

    COMMON_ASSERT(button, "button is null", NgosStatus::ASSERTION);



    mTabButtons.append(button);



    return NgosStatus::OK;
}

NgosStatus TabWidget::addTabPage(TabPageWidget *page)
{
    COMMON_LT((" | page = 0x%p", page));

    COMMON_ASSERT(page, "page is null", NgosStatus::ASSERTION);



    mTabPages.append(page);



    return NgosStatus::OK;
}

NgosStatus TabWidget::invalidate()
{
    COMMON_LT((""));



    if (mOwnResultImage)
    {
        delete mOwnResultImage;
    }



    if (mTabButtons.getSize() > 0)
    {
        u64 tabButtonHeight = mTabButtons.first()->getHeight();

        COMMON_TEST_ASSERT(tabButtonHeight < mHeight, NgosStatus::ASSERTION);



        mOwnResultImage = new Image(mWidth, mHeight, true, false);
        COMMON_ASSERT_EXECUTION(mOwnResultImage->clearBuffer(), NgosStatus::ASSERTION);



        COMMON_ASSERT_EXECUTION(Graphics::insertImage(mPanelImage, mOwnResultImage, 0, tabButtonHeight, mWidth, mHeight - tabButtonHeight), NgosStatus::ASSERTION);
    }
    else
    {
        COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mPanelImage, mWidth, mHeight, &mOwnResultImage), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus TabWidget::repaint()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(mOwnResultImage != nullptr, NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



    if (mResultImage)
    {
        delete mResultImage;
    }

    mResultImage = new Image(*mOwnResultImage);



    NinePatch *patch = mPanelImage->getNinePatch();

    u16 paddingLeft;
    u16 paddingRight;

    AVOID_UNUSED(paddingRight);

    if (patch)
    {
        paddingLeft  = patch->getPaddingLeft();
        paddingRight = patch->getPaddingRight();
    }
    else
    {
        paddingLeft  = 0;
        paddingRight = 0;
    }



    u64 buttonPositionX = paddingLeft;

    for (i64 i = 0; i < mTabButtons.getSize(); ++i)
    {
        TabButton *tabButton = mTabButtons.at(i);

        COMMON_TEST_ASSERT(i == 0 || tabButton->getHeight() == mTabButtons.at(i - 1)->getHeight(), NgosStatus::ASSERTION);

        COMMON_TEST_ASSERT(buttonPositionX                         <= mWidth - paddingRight, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(buttonPositionX + tabButton->getWidth() <= mWidth - paddingRight, NgosStatus::ASSERTION);

        COMMON_ASSERT_EXECUTION(tabButton->lockUpdates(),                   NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(tabButton->setPosition(buttonPositionX, 0), NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(tabButton->unlockUpdates(),                 NgosStatus::ASSERTION);

        buttonPositionX += tabButton->getWidth();
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

NgosStatus TabWidget::setSize(u64 width, u64 height)
{
    COMMON_LT((" | width = %u, height = %u", width, height));



    if (
        mWidth != width
        ||
        mHeight != height
       )
    {
        COMMON_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



        NinePatch *patch = mPanelImage->getNinePatch();

        u16 paddingLeft;
        u16 paddingTop;
        u16 paddingRight;
        u16 paddingBottom;

        paddingTop = mTabButtons.first()->getHeight();

        if (patch)
        {
            paddingLeft   =  patch->getPaddingLeft();
            paddingTop    += patch->getPaddingTop();
            paddingRight  =  patch->getPaddingRight();
            paddingBottom =  patch->getPaddingBottom();
        }
        else
        {
            paddingLeft   = 0;
            paddingRight  = 0;
            paddingBottom = 0;
        }



        for (i64 i = 0; i < mTabPages.getSize(); ++i)
        {
            TabPageWidget *page = mTabPages.at(i);

            COMMON_ASSERT_EXECUTION(page->lockUpdates(),                                                                    NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(page->setPosition(paddingLeft, paddingTop),                                             NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(page->setSize(width - paddingLeft - paddingRight, height - paddingTop - paddingBottom), NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(page->unlockUpdates(),                                                                  NgosStatus::ASSERTION);
        }



        COMMON_ASSERT_EXECUTION(Widget::setSize(width, height), NgosStatus::ASSERTION);



        COMMON_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus TabWidget::setCurrentPage(i64 page)
{
    COMMON_LT((" | page = %d", page));

    COMMON_ASSERT(page >= 0 && page < mTabPages.getSize(),      "page is invalid",      NgosStatus::ASSERTION);
    COMMON_ASSERT(mTabPages.getSize() == mTabButtons.getSize(), "mTabPages is invalid", NgosStatus::ASSERTION);



    if (mCurrentPage != page)
    {
        COMMON_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



        if (mCurrentPage >= 0)
        {
            TabPageWidget *page = mTabPages.at(mCurrentPage);

            COMMON_ASSERT_EXECUTION(page->lockUpdates(),     NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(page->setVisible(false), NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(page->unlockUpdates(),   NgosStatus::ASSERTION);

            COMMON_ASSERT_EXECUTION(mTabButtons.at(mCurrentPage)->setSelected(false), NgosStatus::ASSERTION);
        }

        mCurrentPage = page;

        COMMON_ASSERT_EXECUTION(mTabPages.at(mCurrentPage)->setVisible(true),    NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(mTabButtons.at(mCurrentPage)->setSelected(true), NgosStatus::ASSERTION);



        COMMON_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

i64 TabWidget::getCurrentPage()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mCurrentPage;
}
