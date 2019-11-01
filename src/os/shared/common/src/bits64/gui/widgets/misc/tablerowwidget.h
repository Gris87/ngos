#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_TABLEROWWIDGET_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_TABLEROWWIDGET_H



#include <common/src/bits64/gui/widgets/widget.h>



class TableRowWidget: public Widget
{
public:
    TableRowWidget(Widget *parent = 0); // TEST: NO
    ~TableRowWidget(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_TABLEROWWIDGET_H
