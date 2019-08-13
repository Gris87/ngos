#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_WIDGET_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_WIDGET_H



#include <common/src/bits64/containers/list.h>



class Widget
{
public:
    Widget(Widget *parent = 0); // TEST: NO
    virtual ~Widget(); // TEST: NO

private:
    Widget         *mParent;
    List<Widget *>  mChildren;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_WIDGET_H
