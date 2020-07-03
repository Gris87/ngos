#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_TABLEROWWIDGET_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_TABLEROWWIDGET_H



#include <common/src/com/ngos/shared/common/gui/widgets/widget.h>

#include <common/src/com/ngos/shared/common/containers/arraylist.h>
#include <common/src/com/ngos/shared/common/gui/widgets/misc/tablecellwidget.h>



class TableRowWidget: public Widget
{
public:
    TableRowWidget(Widget *parent = 0); // TEST: NO
    ~TableRowWidget(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO

    bool isAcceptMouseEvents() override; // TEST: NO

    Widget* getOwnerWidget() override; // TEST: NO

    NgosStatus setState(WidgetState state) override; // TEST: NO
    WidgetState getState() const override; // TEST: NO

    NgosStatus addCell(TableCellWidget *cell); // TEST: NO
    TableCellWidget* getCell(u64 column) const; // TEST: NO

private:
    ArrayList<TableCellWidget *> mCells;
    WidgetState                  mState;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_TABLEROWWIDGET_H
