#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_OTHER_PRESSEVENTHANDLER_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_OTHER_PRESSEVENTHANDLER_H



#include <ngos/status.h>



class Widget;



class PressEventHandler
{
public:
    virtual NgosStatus onWidgetPressed(Widget *sender) = 0; // TEST: NO
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_OTHER_PRESSEVENTHANDLER_H
