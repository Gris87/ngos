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

    static NgosStatus updateRegion(i64 positionX, i64 positionY, u64 width, u64 height); // TEST: NO

    static ScreenWidget* getMainScreenWidget(); // TEST: NO

private:
    static RootWidget   *sRootWidget;
    static ScreenWidget *sMainScreenWidget;
    static CursorWidget *sCursorWidget;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_GUI_H
