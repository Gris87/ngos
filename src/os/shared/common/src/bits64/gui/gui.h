#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_GUI_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_GUI_H



#include <common/src/bits64/gui/widgets/misc/cursorwidget.h>
#include <common/src/bits64/gui/widgets/special/rootwidget.h>
#include <common/src/bits64/gui/widgets/special/screenwidget.h>
#include <common/src/bits64/gui/widgets/widget.h>
#include <ngos/status.h>
#include <uefi/uefiabsolutepointerprotocol.h>
#include <uefi/uefisimplepointerstate.h>



class GUI
{
public:
    static NgosStatus init(RootWidget *rootWidget, ScreenWidget *mainScreenWidget, CursorWidget *cursorWidget); // TEST: NO

    static NgosStatus lockUpdates(); // TEST: NO
    static NgosStatus unlockUpdates(); // TEST: NO

    static NgosStatus processSimplePointerState(UefiSimplePointerState *state); // TEST: NO
    static NgosStatus processAbsolutePointerState(UefiAbsolutePointerProtocol *pointer, UefiAbsolutePointerState *state); // TEST: NO

    static NgosStatus detectHoveredWidget(); // TEST: NO

    static RootWidget* getRootWidget(); // TEST: NO
    static ScreenWidget* getMainScreenWidget(); // TEST: NO

    static bool isUpdatesEnabled(); // TEST: NO

    static NgosStatus setHoveredWidget(Widget *widget); // TEST: NO
    static Widget* getHoveredWidget(); // TEST: NO

    static NgosStatus setPressedWidget(Widget *widget); // TEST: NO
    static Widget* getPressedWidget(); // TEST: NO

    static NgosStatus setFocusedWidget(Widget *widget); // TEST: NO
    static Widget* getFocusedWidget(); // TEST: NO

private:
    static RootWidget   *sRootWidget;
    static ScreenWidget *sMainScreenWidget;
    static CursorWidget *sCursorWidget;
    static Widget       *sHoveredWidget;
    static Widget       *sPressedWidget;
    static Widget       *sFocusedWidget;
    static u8            sUpdatesLocks;
    static bool          sMouseLeftButton;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_GUI_H
