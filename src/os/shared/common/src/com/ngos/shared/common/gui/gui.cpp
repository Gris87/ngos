#include "gui.h"

#include <com/ngos/shared/common/console/console.h>
#include <com/ngos/shared/common/console/graphicalconsole.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>



#define MOUSE_BY_KEYBOARD_SPEED 20



RootWidget   *GUI::sRootWidget;
ScreenWidget *GUI::sMainScreenWidget;
CursorWidget *GUI::sCursorWidget;
Widget       *GUI::sHoveredWidget;
Widget       *GUI::sPressedWidget;
Widget       *GUI::sFocusedWidget;
bad_uint8            GUI::sUpdatesLocks;
bool          GUI::sMouseLeftButton;



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

NgosStatus GUI::processKeyboardEvent(const UefiInputKey &key)
{
    COMMON_LT((" | key = ..."));



    AVOID_UNUSED(key);



#if NGOS_BUILD_RELEASE == OPTION_NO // Ignore CppReleaseUsageVerifier
    switch (key.unicodeChar)
    {
        case 'w':
        case 'W':
        {
            UefiSimplePointerState state;

            state.relativeMovementX = 0;
            state.relativeMovementY = -MOUSE_BY_KEYBOARD_SPEED;
            state.relativeMovementZ = 0;
            state.leftButton        = false;
            state.rightButton       = false;



            COMMON_ASSERT_EXECUTION(processSimplePointerState(&state), NgosStatus::ASSERTION);



            return NgosStatus::OK;
        }
        break;

        case 's':
        case 'S':
        {
            UefiSimplePointerState state;

            state.relativeMovementX = 0;
            state.relativeMovementY = MOUSE_BY_KEYBOARD_SPEED;
            state.relativeMovementZ = 0;
            state.leftButton        = false;
            state.rightButton       = false;



            COMMON_ASSERT_EXECUTION(processSimplePointerState(&state), NgosStatus::ASSERTION);



            return NgosStatus::OK;
        }
        break;

        case 'a':
        case 'A':
        {
            UefiSimplePointerState state;

            state.relativeMovementX = -MOUSE_BY_KEYBOARD_SPEED;
            state.relativeMovementY = 0;
            state.relativeMovementZ = 0;
            state.leftButton        = false;
            state.rightButton       = false;



            COMMON_ASSERT_EXECUTION(processSimplePointerState(&state), NgosStatus::ASSERTION);



            return NgosStatus::OK;
        }
        break;

        case 'd':
        case 'D':
        {
            UefiSimplePointerState state;

            state.relativeMovementX = MOUSE_BY_KEYBOARD_SPEED;
            state.relativeMovementY = 0;
            state.relativeMovementZ = 0;
            state.leftButton        = false;
            state.rightButton       = false;



            COMMON_ASSERT_EXECUTION(processSimplePointerState(&state), NgosStatus::ASSERTION);



            return NgosStatus::OK;
        }
        break;

        case 'q':
        case 'Q':
        {
            UefiSimplePointerState state;

            state.relativeMovementX = 0;
            state.relativeMovementY = 0;
            state.relativeMovementZ = -1;
            state.leftButton        = false;
            state.rightButton       = false;



            COMMON_ASSERT_EXECUTION(processSimplePointerState(&state), NgosStatus::ASSERTION);



            return NgosStatus::OK;
        }
        break;

        case 'e':
        case 'E':
        {
            UefiSimplePointerState state;

            state.relativeMovementX = 0;
            state.relativeMovementY = 0;
            state.relativeMovementZ = 1;
            state.leftButton        = false;
            state.rightButton       = false;



            COMMON_ASSERT_EXECUTION(processSimplePointerState(&state), NgosStatus::ASSERTION);



            return NgosStatus::OK;
        }
        break;

        case KEY_SPACE:
        {
            UefiSimplePointerState state;

            state.relativeMovementX = 0;
            state.relativeMovementY = 0;
            state.relativeMovementZ = 0;
            state.leftButton        = true;
            state.rightButton       = false;



            COMMON_ASSERT_EXECUTION(processSimplePointerState(&state), NgosStatus::ASSERTION);



            state.leftButton = false;

            COMMON_ASSERT_EXECUTION(processSimplePointerState(&state), NgosStatus::ASSERTION);



            return NgosStatus::OK;
        }
        break;

        default:
        {
            // Nothing
        }
        break;
    }
#endif



    return NgosStatus::NO_EFFECT;
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
       )
    {
        bad_int64 cursorX = sCursorWidget->getPositionX() + state->relativeMovementX;
        bad_int64 cursorY = sCursorWidget->getPositionY() + state->relativeMovementY;



        if (cursorX < sRootWidget->getPositionX())
        {
            cursorX = sRootWidget->getPositionX();
        }

        if (cursorX > sRootWidget->getPositionX() + (bad_int64)sRootWidget->getWidth())
        {
            cursorX = sRootWidget->getPositionX() + (bad_int64)sRootWidget->getWidth();
        }

        if (cursorY < sRootWidget->getPositionY())
        {
            cursorY = sRootWidget->getPositionY();
        }

        if (cursorY > sRootWidget->getPositionY() + (bad_int64)sRootWidget->getHeight())
        {
            cursorY = sRootWidget->getPositionY() + (bad_int64)sRootWidget->getHeight();
        }



        COMMON_ASSERT_EXECUTION(sCursorWidget->setPosition(cursorX, cursorY), NgosStatus::ASSERTION);



        if (!sPressedWidget)
        {
            COMMON_ASSERT_EXECUTION(detectHoveredWidget(), NgosStatus::ASSERTION);
        }
    }



    if (
        state->relativeMovementZ != 0
        &&
        sHoveredWidget
       )
    {
        NgosStatus status = sHoveredWidget->onMouseScrollEvent(state->relativeMovementZ);

        COMMON_TEST_ASSERT(status == NgosStatus::OK
                            ||
                            status == NgosStatus::NO_EFFECT, NgosStatus::ASSERTION);

        if (status == NgosStatus::OK)
        {
            if (!sPressedWidget)
            {
                COMMON_ASSERT_EXECUTION(detectHoveredWidget(), NgosStatus::ASSERTION);
            }
        }
    }



    if (sPressedWidget)
    {
        if (
            !state->leftButton
            &&
            !state->rightButton
           )
        {
            COMMON_ASSERT_EXECUTION(detectHoveredWidget(), NgosStatus::ASSERTION);

            if (sMouseLeftButton)
            {
                sMouseLeftButton = false;

                if (sHoveredWidget == sPressedWidget)
                {
                    if (sPressedWidget->getPressEventHandler())
                    {
                        COMMON_ASSERT_EXECUTION(sPressedWidget->getPressEventHandler()(), NgosStatus::ASSERTION);
                    }
                    else
                    if (sPressedWidget->getPressEventHandlerObject())
                    {
                        COMMON_ASSERT_EXECUTION(sPressedWidget->getPressEventHandlerObject()->onWidgetPressed(sPressedWidget), NgosStatus::ASSERTION);
                    }
                }
            }

            COMMON_ASSERT_EXECUTION(setPressedWidget(nullptr), NgosStatus::ASSERTION);
        }
    }
    else
    {
        if (
            (
             state->leftButton
             ||
             state->rightButton
            )
            &&
            sHoveredWidget
           )
        {
            sMouseLeftButton = state->leftButton;

            COMMON_ASSERT_EXECUTION(setPressedWidget(sHoveredWidget), NgosStatus::ASSERTION);



            Widget *focusedWidget = sHoveredWidget;

            while (
                   focusedWidget
                   &&
                   !focusedWidget->isFocusable()
                  )
            {
                Widget *focusedWidgetOwner = focusedWidget->getOwnerWidget();

                if (focusedWidget == focusedWidgetOwner)
                {
                    focusedWidget = focusedWidget->getParent();
                }
                else
                {
                    focusedWidget = focusedWidgetOwner;
                }
            }

            COMMON_ASSERT_EXECUTION(setFocusedWidget(focusedWidget), NgosStatus::ASSERTION);
        }
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



    if (sPressedWidget)
    {
        if (!(state->activeButtons & FLAGS(UefiAbsolutePointerStateActiveButtonFlag::TOUCH_ACTIVE)))
        {
            COMMON_ASSERT_EXECUTION(detectHoveredWidget(), NgosStatus::ASSERTION);

            if (sHoveredWidget == sPressedWidget)
            {
                if (sPressedWidget->getPressEventHandler())
                {
                    COMMON_ASSERT_EXECUTION(sPressedWidget->getPressEventHandler()(), NgosStatus::ASSERTION);
                }
                else
                if (sPressedWidget->getPressEventHandlerObject())
                {
                    COMMON_ASSERT_EXECUTION(sPressedWidget->getPressEventHandlerObject()->onWidgetPressed(sPressedWidget), NgosStatus::ASSERTION);
                }
            }

            COMMON_ASSERT_EXECUTION(setPressedWidget(nullptr), NgosStatus::ASSERTION);
        }
    }
    else
    {
        COMMON_ASSERT_EXECUTION(detectHoveredWidget(), NgosStatus::ASSERTION);

        if (
            (state->activeButtons & FLAGS(UefiAbsolutePointerStateActiveButtonFlag::TOUCH_ACTIVE))
            &&
            sHoveredWidget
           )
        {
            COMMON_ASSERT_EXECUTION(setPressedWidget(sHoveredWidget), NgosStatus::ASSERTION);



            Widget *focusedWidget = sHoveredWidget;

            while (
                   focusedWidget
                   &&
                   !focusedWidget->isFocusable()
                  )
            {
                Widget *focusedWidgetOwner = focusedWidget->getOwnerWidget();

                if (focusedWidget == focusedWidgetOwner)
                {
                    focusedWidget = focusedWidget->getParent();
                }
                else
                {
                    focusedWidget = focusedWidgetOwner;
                }
            }

            COMMON_ASSERT_EXECUTION(setFocusedWidget(focusedWidget), NgosStatus::ASSERTION);
        }
    }



    COMMON_ASSERT_EXECUTION(unlockUpdates(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus GUI::detectHoveredWidget()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(sRootWidget,   NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sCursorWidget, NgosStatus::ASSERTION);



    Widget *hoveredWidget = sRootWidget->detectHoveredWidget(sCursorWidget->getPositionX(), sCursorWidget->getPositionY());

    if (hoveredWidget)
    {
        hoveredWidget = hoveredWidget->getOwnerWidget();
    }

    COMMON_ASSERT_EXECUTION(setHoveredWidget(hoveredWidget), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

RootWidget* GUI::getRootWidget()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return sRootWidget;
}

ScreenWidget* GUI::getMainScreenWidget()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return sMainScreenWidget;
}

bool GUI::isUpdatesEnabled()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



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
            if (sHoveredWidget != sPressedWidget)
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
        }

        sHoveredWidget = widget;

        if (sHoveredWidget)
        {
            if (sHoveredWidget != sPressedWidget)
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
        }

        COMMON_ASSERT_EXECUTION(unlockUpdates(), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

Widget* GUI::getHoveredWidget()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return sHoveredWidget;
}

NgosStatus GUI::setPressedWidget(Widget *widget)
{
    COMMON_LT((" | widget = 0x%p", widget));



    if (sPressedWidget != widget)
    {
        COMMON_ASSERT_EXECUTION(lockUpdates(), NgosStatus::ASSERTION);

        if (sPressedWidget)
        {
            if (sHoveredWidget == sPressedWidget)
            {
                if (sFocusedWidget == sHoveredWidget)
                {
                    sPressedWidget->setState(WidgetState::FOCUSED_HOVERED);
                }
                else
                {
                    sPressedWidget->setState(WidgetState::HOVERED);
                }
            }
            else
            if (sFocusedWidget == sPressedWidget)
            {
                sPressedWidget->setState(WidgetState::FOCUSED);
            }
            else
            {
                sPressedWidget->setState(WidgetState::NORMAL);
            }
        }

        sPressedWidget = widget;

        if (sPressedWidget)
        {
            sPressedWidget->setState(WidgetState::PRESSED);
        }

        COMMON_ASSERT_EXECUTION(unlockUpdates(), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

Widget* GUI::getPressedWidget()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return sPressedWidget;
}

NgosStatus GUI::setFocusedWidget(Widget *widget)
{
    COMMON_LT((" | widget = 0x%p", widget));



    if (sFocusedWidget != widget)
    {
        COMMON_ASSERT_EXECUTION(lockUpdates(), NgosStatus::ASSERTION);

        if (sFocusedWidget)
        {
            if (sFocusedWidget != sPressedWidget)
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
        }

        sFocusedWidget = widget;

        if (sFocusedWidget)
        {
            if (sFocusedWidget != sPressedWidget)
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
        }

        COMMON_ASSERT_EXECUTION(unlockUpdates(), NgosStatus::ASSERTION);
    }
    else
    {
        if (sFocusedWidget)
        {
            if (sFocusedWidget != sPressedWidget)
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
        }
    }



    return NgosStatus::OK;
}

Widget* GUI::getFocusedWidget()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return sFocusedWidget;
}
