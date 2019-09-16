#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_GUI_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_GUI_H



#include <common/src/bits64/gui/widgets/misc/cursorwidget.h>
#include <common/src/bits64/gui/widgets/misc/rootwidget.h>
#include <common/src/bits64/gui/widgets/misc/screenwidget.h>
#include <common/src/bits64/gui/widgets/widget.h>
#include <ngos/status.h>



class GUI
{
public:
    static NgosStatus init(RootWidget *rootWidget, ScreenWidget *mainScreenWidget, CursorWidget *cursorWidget); // TEST: NO

    static NgosStatus disableUpdates(); // TEST: NO
    static NgosStatus enableUpdates(); // TEST: NO

    static ScreenWidget* getMainScreenWidget(); // TEST: NO
    static bool isUpdatesEnabled(); // TEST: NO

private:
    static RootWidget   *sRootWidget;
    static ScreenWidget *sMainScreenWidget;
    static CursorWidget *sCursorWidget;
    static bool          sUpdatesEnabled;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_GUI_H
