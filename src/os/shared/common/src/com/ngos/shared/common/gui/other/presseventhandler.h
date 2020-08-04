#ifndef COM_NGOS_SHARED_COMMON_GUI_OTHER_PRESSEVENTHANDLER_H
#define COM_NGOS_SHARED_COMMON_GUI_OTHER_PRESSEVENTHANDLER_H



#include <com/ngos/shared/common/ngos/status.h>



class Widget;



class PressEventHandler
{
public:
    virtual ~PressEventHandler(); // TEST: NO

    virtual NgosStatus onWidgetPressed(Widget *sender) = 0; // TEST: NO
};



#endif // COM_NGOS_SHARED_COMMON_GUI_OTHER_PRESSEVENTHANDLER_H
