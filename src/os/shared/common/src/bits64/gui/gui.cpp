#include "gui.h"

#include <common/src/bits64/console/console.h>
#include <common/src/bits64/console/graphicalconsole.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



RootWidget   *GUI::sRootWidget;
ScreenWidget *GUI::sMainScreenWidget;
CursorWidget *GUI::sCursorWidget;



NgosStatus GUI::init(RootWidget *rootWidget, ScreenWidget *mainScreenWidget, CursorWidget *cursorWidget)
{
    COMMON_LT((" | rootWidget = 0x%p, mainScreenWidget = 0x%p, cursorWidget = 0x%p", rootWidget, mainScreenWidget, cursorWidget));

    COMMON_ASSERT(rootWidget,       "rootWidget is null",       NgosStatus::ASSERTION);
    COMMON_ASSERT(mainScreenWidget, "mainScreenWidget is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(cursorWidget,     "cursorWidget is null",     NgosStatus::ASSERTION);



    sRootWidget       = rootWidget;
    sMainScreenWidget = mainScreenWidget;
    sCursorWidget     = cursorWidget;



    COMMON_ASSERT_EXECUTION(sRootWidget->invalidate(),        NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(Console::noMorePrint(),           NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(sRootWidget->repaint(),           NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(GraphicalConsole::readyToPrint(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

ScreenWidget* GUI::getMainScreenWidget()
{
    COMMON_LT((""));



    return sMainScreenWidget;
}
