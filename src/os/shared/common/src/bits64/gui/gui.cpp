#include "gui.h"

#include <common/src/bits64/console/console.h>
#include <common/src/bits64/console/graphicalconsole.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



RootWidget   *GUI::sRootWidget;
ScreenWidget *GUI::sMainScreenWidget;
CursorWidget *GUI::sCursorWidget;
u8            GUI::sUpdatesLocks;
Widget       *GUI::sHoveredWidget;
Widget       *GUI::sFocusedWidget;



NgosStatus GUI::init(RootWidget *rootWidget, ScreenWidget *mainScreenWidget, CursorWidget *cursorWidget)
{
    COMMON_LT((" | rootWidget = 0x%p, mainScreenWidget = 0x%p, cursorWidget = 0x%p", rootWidget, mainScreenWidget, cursorWidget));

    COMMON_ASSERT(rootWidget,       "rootWidget is null",       NgosStatus::ASSERTION);
    COMMON_ASSERT(mainScreenWidget, "mainScreenWidget is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(cursorWidget,     "cursorWidget is null",     NgosStatus::ASSERTION);



    sRootWidget       = rootWidget;
    sMainScreenWidget = mainScreenWidget;
    sCursorWidget     = cursorWidget;



    COMMON_ASSERT_EXECUTION(lockUpdates(),                    NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(sRootWidget->invalidate(),        NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(sRootWidget->repaint(),           NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(Console::noMorePrint(),           NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(unlockUpdates(),                  NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(GraphicalConsole::readyToPrint(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus GUI::lockUpdates()
{
    COMMON_LT((""));



    ++sUpdatesLocks;

    COMMON_TEST_ASSERT(!isUpdatesEnabled(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus GUI::unlockUpdates()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(!isUpdatesEnabled(), NgosStatus::ASSERTION);

    --sUpdatesLocks;

    if (isUpdatesEnabled())
    {
        COMMON_ASSERT(sRootWidget, "sRootWidget is null", NgosStatus::ASSERTION);

        COMMON_ASSERT_EXECUTION(sRootWidget->applyUpdates(), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

ScreenWidget* GUI::getMainScreenWidget()
{
    COMMON_LT((""));



    return sMainScreenWidget;
}

bool GUI::isUpdatesEnabled()
{
    COMMON_LT((""));



    return !sUpdatesLocks; // sUpdatesLocks == 0
}

NgosStatus GUI::setHoveredWidget(Widget *widget)
{
    COMMON_LT((" | widget = 0x%p", widget));



    if (sHoveredWidget != widget)
    {
        COMMON_ASSERT_EXECUTION(lockUpdates(), NgosStatus::ASSERTION);

        if (sHoveredWidget)
        {
            sHoveredWidget->setState(WidgetState::NORMAL);
        }

        sHoveredWidget = widget;

        if (sHoveredWidget)
        {
            sHoveredWidget->setState(WidgetState::HOVERED);
        }

        COMMON_ASSERT_EXECUTION(unlockUpdates(), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

Widget* GUI::getHoveredWidget()
{
    COMMON_LT((""));



    return sHoveredWidget;
}

NgosStatus GUI::setFocusedWidget(Widget *widget)
{
    COMMON_LT((" | widget = 0x%p", widget));



    if (sFocusedWidget != widget)
    {
        COMMON_ASSERT_EXECUTION(lockUpdates(), NgosStatus::ASSERTION);

        if (sFocusedWidget)
        {
            sFocusedWidget->setState(WidgetState::NORMAL);
        }

        sFocusedWidget = widget;

        if (sFocusedWidget)
        {
            sFocusedWidget->setState(WidgetState::FOCUSED);
        }

        COMMON_ASSERT_EXECUTION(unlockUpdates(), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

Widget* GUI::getFocusedWidget()
{
    COMMON_LT((""));



    return sFocusedWidget;
}
