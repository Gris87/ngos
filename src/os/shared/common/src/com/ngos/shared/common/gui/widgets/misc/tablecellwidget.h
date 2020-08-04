#ifndef COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_TABLECELLWIDGET_H
#define COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_TABLECELLWIDGET_H



#include <com/ngos/shared/common/gui/widgets/widget.h>



class TableCellWidget: public Widget
{
public:
    TableCellWidget(Widget *parent = 0); // TEST: NO
    ~TableCellWidget(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO
};



#endif // COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_TABLECELLWIDGET_H
