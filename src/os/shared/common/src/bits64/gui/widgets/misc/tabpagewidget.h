#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_TABPAGEWIDGET_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_TABPAGEWIDGET_H



#include <common/src/bits64/gui/widgets/widget.h>



class TabPageWidget: public Widget
{
public:
    TabPageWidget(Widget *parent = 0); // TEST: NO
    ~TabPageWidget(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_TABPAGEWIDGET_H
