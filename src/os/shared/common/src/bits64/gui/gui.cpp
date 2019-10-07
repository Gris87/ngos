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



    COMMON_ASSERT_EXECUTION(detectHoveredWidget(), NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(Console::noMorePrint(),           NgosStatus::ASSERTION);
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

NgosStatus GUI::processSimplePointerState(UefiSimplePointerState *state)
{
    COMMON_LT((" | state = 0x%p", state));

    COMMON_ASSERT(state, "state is null", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(sCursorWidget, NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(lockUpdates(), NgosStatus::ASSERTION);

    if (
        state->relativeMovementX
        ||
        state->relativeMovementY
        ||
        (
         !state->leftButton
         &&
         !state->rightButton
        )
       )
    {
        COMMON_ASSERT_EXECUTION(sCursorWidget->setPosition(sCursorWidget->getPositionX() + state->relativeMovementX, sCursorWidget->getPositionY() + state->relativeMovementY), NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(detectHoveredWidget(),                                                                                                                          NgosStatus::ASSERTION);
    }

    COMMON_ASSERT_EXECUTION(unlockUpdates(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus GUI::processAbsolutePointerState(UefiAbsolutePointerProtocol *pointer, UefiAbsolutePointerState *state)
{
    COMMON_LT((" | pointer = 0x%p, state = 0x%p", pointer, state));

    COMMON_ASSERT(pointer, "pointer is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(state,   "state is null",   NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(sCursorWidget, NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(lockUpdates(), NgosStatus::ASSERTION);

    COMMON_ASSERT_EXECUTION(sCursorWidget->setPosition(state->currentX * sMainScreenWidget->getWidth() / pointer->mode->absoluteMaxX,
                                                        state->currentY * sMainScreenWidget->getHeight() / pointer->mode->absoluteMaxY), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(detectHoveredWidget(),                                                                                       NgosStatus::ASSERTION);

    COMMON_ASSERT_EXECUTION(unlockUpdates(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus GUI::detectHoveredWidget()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(sRootWidget,   NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sCursorWidget, NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(setHoveredWidget(sRootWidget->detectHoveredWidget(sCursorWidget->getPositionX(), sCursorWidget->getPositionY())), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

RootWidget* GUI::getRootWidget()
{
    COMMON_LT((""));



    return sRootWidget;
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
            if (sFocusedWidget == sHoveredWidget)
            {
                sHoveredWidget->setState(WidgetState::FOCUSED);
            }
            else
            {
                sHoveredWidget->setState(WidgetState::NORMAL);
            }
        }

        sHoveredWidget = widget;

        if (sHoveredWidget)
        {
            if (sFocusedWidget == sHoveredWidget)
            {
                sHoveredWidget->setState(WidgetState::FOCUSED_HOVERED);
            }
            else
            {
                sHoveredWidget->setState(WidgetState::HOVERED);
            }
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
            if (sFocusedWidget == sHoveredWidget)
            {
                sFocusedWidget->setState(WidgetState::HOVERED);
            }
            else
            {
                sFocusedWidget->setState(WidgetState::NORMAL);
            }
        }

        sFocusedWidget = widget;

        if (sFocusedWidget)
        {
            if (sFocusedWidget == sHoveredWidget)
            {
                sFocusedWidget->setState(WidgetState::FOCUSED_HOVERED);
            }
            else
            {
                sFocusedWidget->setState(WidgetState::FOCUSED);
            }
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
