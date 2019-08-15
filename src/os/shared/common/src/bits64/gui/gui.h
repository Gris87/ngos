#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_GUI_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_GUI_H



#include <common/src/bits64/gui/widgets/widget.h>
#include <common/src/bits64/gui/widgets/misc/cursorwidget.h>
#include <ngos/status.h>



class GUI
{
public:
    static NgosStatus init(Widget *rootWidget, CursorWidget *cursorWidget); // TEST: NO

private:
    static Widget       *sRootWidget;
    static CursorWidget *sCursorWidget;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_GUI_H
