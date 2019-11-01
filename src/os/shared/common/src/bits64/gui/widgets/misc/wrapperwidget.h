#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_WRAPPERWIDGET_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_WRAPPERWIDGET_H



#include <common/src/bits64/gui/widgets/widget.h>



class WrapperWidget: public Widget
{
public:
    WrapperWidget(Widget *parent = 0); // TEST: NO
    ~WrapperWidget(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_WRAPPERWIDGET_H
