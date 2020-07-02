#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_TABLECELLWIDGET_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_TABLECELLWIDGET_H



#include <common/src/com/ngos/shared/common/gui/widgets/widget.h>



class TableCellWidget: public Widget
{
public:
    TableCellWidget(Widget *parent = 0); // TEST: NO
    ~TableCellWidget(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_TABLECELLWIDGET_H
