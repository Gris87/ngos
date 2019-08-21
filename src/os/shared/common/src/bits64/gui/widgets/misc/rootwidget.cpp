#include "rootwidget.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



RootWidget::RootWidget()
    : Widget()
{
    COMMON_LT((""));
}

RootWidget::~RootWidget()
{
    COMMON_LT((""));



    ListElement<ScreenWidget *> *element = mScreens.getHead();

    while (element)
    {
        delete element->getData();

        element = element->getNext();
    }
}

NgosStatus RootWidget::addScreen(ScreenWidget *screen)
{
    COMMON_LT((" | screen = 0x%p", screen));

    COMMON_ASSERT(screen, "screen is null", NgosStatus::ASSERTION);



    mScreens.append(screen);



    return NgosStatus::OK;
}

NgosStatus RootWidget::updateRegion(i64 positionX, i64 positionY, u64 width, u64 height)
{
    COMMON_LT((" | positionX = %d, positionY = %d, width = %u, height = %u", positionX, positionY, width, height));

    COMMON_ASSERT(width > 0,  "width is zero",  NgosStatus::ASSERTION);
    COMMON_ASSERT(height > 0, "height is zero", NgosStatus::ASSERTION);



    ListElement<ScreenWidget *> *screen = mScreens.getHead();

    while (screen)
    {
        ScreenWidget *screenWidget = screen->getData();

        if (
            (i64)(positionX)          <  (i64)(screenWidget->mPositionX + screenWidget->mWidth)
            &&
            (i64)(positionX + width)  >= (i64)(screenWidget->mPositionX)
            &&
            (i64)(positionY)          <  (i64)(screenWidget->mPositionY + screenWidget->mHeight)
            &&
            (i64)(positionY + height) >= (i64)(screenWidget->mPositionY)
           )
        {
            screenWidget->updateRegion(positionX, positionY, width, height);
        }

        screen = screen->getNext();
    }



    ListElement<Widget *> *element = mChildren.getHead();

    while (element)
    {
        Widget *widget = element->getData();



        ListElement<ScreenWidget *> *screen = mScreens.getHead();

        while (screen)
        {
            ScreenWidget *screenWidget = screen->getData();

            if (
                (i64)(widget->mPositionX)                   <  (i64)(screenWidget->mPositionX + screenWidget->mWidth)
                &&
                (i64)(widget->mPositionX + widget->mWidth)  >= (i64)(screenWidget->mPositionX)
                &&
                (i64)(widget->mPositionY)                   <  (i64)(screenWidget->mPositionY + screenWidget->mHeight)
                &&
                (i64)(widget->mPositionY + widget->mHeight) >= (i64)(screenWidget->mPositionY)
               )
            {
                screenWidget->drawWidget(widget, widget->mPositionX - screenWidget->mPositionX, widget->mPositionY - screenWidget->mPositionY);
            }

            screen = screen->getNext();
        }



        element = element->getNext();
    }



    return NgosStatus::OK;
}

NgosStatus RootWidget::invalidate()
{
    COMMON_LT((""));



    COMMON_ASSERT_EXECUTION(Widget::invalidate(), NgosStatus::ASSERTION);



    ListElement<ScreenWidget *> *screen = mScreens.getHead();

    while (screen)
    {
        COMMON_ASSERT_EXECUTION(screen->getData()->invalidate(), NgosStatus::ASSERTION);

        screen = screen->getNext();
    }



    return NgosStatus::OK;
}

NgosStatus RootWidget::repaint()
{
    COMMON_LT((""));



    ListElement<ScreenWidget *> *screen = mScreens.getHead();

    while (screen)
    {
        COMMON_ASSERT_EXECUTION(screen->getData()->repaint(), NgosStatus::ASSERTION);

        screen = screen->getNext();
    }



    ListElement<Widget *> *element = mChildren.getHead();

    while (element)
    {
        Widget *widget = element->getData();

        COMMON_ASSERT_EXECUTION(widget->repaint(), NgosStatus::ASSERTION);



        ListElement<ScreenWidget *> *screen = mScreens.getHead();

        while (screen)
        {
            ScreenWidget *screenWidget = screen->getData();

            if (
                (i64)(widget->mPositionX)                   <  (i64)(screenWidget->mPositionX + screenWidget->mWidth)
                &&
                (i64)(widget->mPositionX + widget->mWidth)  >= (i64)(screenWidget->mPositionX)
                &&
                (i64)(widget->mPositionY)                   <  (i64)(screenWidget->mPositionY + screenWidget->mHeight)
                &&
                (i64)(widget->mPositionY + widget->mHeight) >= (i64)(screenWidget->mPositionY)
               )
            {
                screenWidget->drawWidget(widget, widget->mPositionX - screenWidget->mPositionX, widget->mPositionY - screenWidget->mPositionY);
            }

            screen = screen->getNext();
        }



        element = element->getNext();
    }



    return NgosStatus::OK;
}
