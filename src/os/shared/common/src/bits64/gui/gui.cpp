#include "gui.h"

#include <common/src/bits64/console/console.h>
#include <common/src/bits64/console/graphicalconsole.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



RootWidget   *GUI::sRootWidget;
ScreenWidget *GUI::sMainScreenWidget;
CursorWidget *GUI::sCursorWidget;
bool          GUI::sUpdatesEnabled;
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



    COMMON_ASSERT_EXECUTION(disableUpdates(),                 NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(sRootWidget->invalidate(),        NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(sRootWidget->repaint(),           NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(Console::noMorePrint(),           NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(enableUpdates(),                  NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(GraphicalConsole::readyToPrint(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus GUI::disableUpdates()
{
    COMMON_LT((""));



    sUpdatesEnabled = false;



    return NgosStatus::OK;
}

NgosStatus GUI::enableUpdates()
{
    COMMON_LT((""));



    if (!sUpdatesEnabled)
    {
        sUpdatesEnabled = true;

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



    return sUpdatesEnabled;
}

NgosStatus GUI::setHoveredWidget(Widget *widget)
{
    COMMON_LT((" | widget = 0x%p", widget));



    if (sHoveredWidget != widget)
    {
        if (sHoveredWidget)
        {
            sHoveredWidget->setState(WidgetState::NORMAL);
        }

        sHoveredWidget = widget;

        if (sHoveredWidget)
        {
            sHoveredWidget->setState(WidgetState::HOVERED);
        }
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
        if (sFocusedWidget)
        {
            sFocusedWidget->setState(WidgetState::NORMAL);
        }

        sFocusedWidget = widget;

        if (sFocusedWidget)
        {
            sFocusedWidget->setState(WidgetState::FOCUSED);
        }
    }



    return NgosStatus::OK;
}

Widget* GUI::getFocusedWidget()
{
    COMMON_LT((""));



    return sFocusedWidget;
}
