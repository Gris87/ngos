#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GUI_WIDGETS_CONTROLS_TABLEWIDGET_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GUI_WIDGETS_CONTROLS_TABLEWIDGET_H



#include <common/src/com/ngos/shared/common/gui/widgets/widget.h>

#include <common/src/com/ngos/shared/common/containers/arraylist.h>
#include <common/src/com/ngos/shared/common/gui/widgets/misc/tableheaderwidget.h>
#include <common/src/com/ngos/shared/common/gui/widgets/misc/tablerowwidget.h>
#include <common/src/com/ngos/shared/common/gui/widgets/misc/wrapperwidget.h>



class TableWidget: public Widget
{
public:
    TableWidget(Image *backgroundImage, Image *headerImage, Widget *parent = 0); // TEST: NO
    ~TableWidget(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO
    NgosStatus onKeyboardEvent(const UefiInputKey &key) override; // TEST: NO
    NgosStatus onMouseScrollEvent(i32 delta) override; // TEST: NO

    NgosStatus scrollToSelectedRow(); // TEST: NO
    NgosStatus pageUp(); // TEST: NO
    NgosStatus pageDown(); // TEST: NO

    bool isFocusable() override; // TEST: NO

    NgosStatus setState(WidgetState state) override; // TEST: NO
    WidgetState getState() const override; // TEST: NO

    NgosStatus setRowHeight(u64 height); // TEST: NO
    u64 getRowHeight() const; // TEST: NO

    NgosStatus setColumnCount(u64 columns); // TEST: NO
    u64 getColumnCount() const; // TEST: NO

    NgosStatus setColumnWidth(u64 column, u64 width); // TEST: NO
    u64 getColumnWidth(u64 column) const; // TEST: NO

    NgosStatus setHeaderText(u64 column, const char8 *text); // TEST: NO

    NgosStatus setRowCount(u64 rows); // TEST: NO
    u64 getRowCount() const; // TEST: NO

    const ArrayList<TableRowWidget *>& getRows() const; // TEST: NO

    NgosStatus setCellWidget(u64 row, u64 column, Widget *widget); // TEST: NO
    Widget* getCellWidget(u64 row, u64 column) const; // TEST: NO

    NgosStatus setSelectedRow(u64 row); // TEST: NO
    u64 getSelectedRow() const; // TEST: NO

    NgosStatus setHighlightedRow(u64 row); // TEST: NO
    u64 getHighlightedRow() const; // TEST: NO

    NgosStatus setKeyboardEventHandler(keyboard_event_handler handler) override; // TEST: NO
    keyboard_event_handler getKeyboardEventHandler() const override; // TEST: NO

private:
    Image                          *mBackgroundImage;
    Image                          *mHeaderImage;
    WidgetState                     mState;
    u64                             mRowHeight;
    ArrayList<u64>                  mColumnWidth;
    u64                             mTotalColumnWidth;
    ArrayList<TableHeaderWidget *>  mHeaders;
    WrapperWidget                  *mContentWrapperWidget;
    WrapperWidget                  *mScrollWrapperWidget;
    ArrayList<TableRowWidget *>     mRows;
    u64                             mSelectedRow;
    u64                             mHighlightedRow;
    keyboard_event_handler          mKeyboardEventHandler;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GUI_WIDGETS_CONTROLS_TABLEWIDGET_H
