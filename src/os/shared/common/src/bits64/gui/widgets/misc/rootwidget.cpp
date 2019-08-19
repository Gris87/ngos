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
        COMMON_ASSERT_EXECUTION(element->getData()->repaint(), NgosStatus::ASSERTION);

        element = element->getNext();
    }



    return NgosStatus::OK;
}
