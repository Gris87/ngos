#include "gui.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



Widget       *GUI::sRootWidget;
CursorWidget *GUI::sCursorWidget;



NgosStatus GUI::init(Widget *rootWidget, CursorWidget *cursorWidget)
{
    COMMON_LT((" | rootWidget = 0x%p, cursorWidget = 0x%p", rootWidget, cursorWidget));

    COMMON_ASSERT(rootWidget,   "rootWidget is null",   NgosStatus::ASSERTION);
    COMMON_ASSERT(cursorWidget, "cursorWidget is null", NgosStatus::ASSERTION);



    sRootWidget   = rootWidget;
    sCursorWidget = cursorWidget;



    return NgosStatus::OK;
}
