#ifndef COM_NGOS_SHARED_COMMON_GUI_WIDGETS_CONTROLS_TABLEWIDGET_H
#define COM_NGOS_SHARED_COMMON_GUI_WIDGETS_CONTROLS_TABLEWIDGET_H



#include <com/ngos/shared/common/gui/widgets/widget.h>

#include <com/ngos/shared/common/containers/arraylist.h>
#include <com/ngos/shared/common/gui/widgets/misc/tableheaderwidget.h>
#include <com/ngos/shared/common/gui/widgets/misc/tablerowwidget.h>
#include <com/ngos/shared/common/gui/widgets/misc/wrapperwidget.h>



class TableWidget: public Widget
{
public:
    TableWidget(Image *backgroundImage, Image *headerImage, Widget *parent = nullptr); // TEST: NO
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

    NgosStatus setRowHeight(i64 height); // TEST: NO
    i64 getRowHeight() const; // TEST: NO

    NgosStatus setColumnCount(i64 columns); // TEST: NO
    i64 getColumnCount() const; // TEST: NO

    NgosStatus setColumnWidth(i64 column, i64 width); // TEST: NO
    i64 getColumnWidth(i64 column) const; // TEST: NO

    NgosStatus setHeaderText(i64 column, const char8 *text); // TEST: NO

    NgosStatus setRowCount(i64 rows); // TEST: NO
    i64 getRowCount() const; // TEST: NO

    const ArrayList<TableRowWidget *>& getRows() const; // TEST: NO

    NgosStatus setCellWidget(i64 row, i64 column, Widget *widget); // TEST: NO
    Widget* getCellWidget(i64 row, i64 column) const; // TEST: NO

    NgosStatus setSelectedRow(i64 row); // TEST: NO
    i64 getSelectedRow() const; // TEST: NO

    NgosStatus setHighlightedRow(i64 row); // TEST: NO
    i64 getHighlightedRow() const; // TEST: NO

    NgosStatus setKeyboardEventHandler(keyboard_event_handler handler) override; // TEST: NO
    keyboard_event_handler getKeyboardEventHandler() const override; // TEST: NO

private:
    Image                          *mBackgroundImage;
    Image                          *mHeaderImage;
    WidgetState                     mState;
    i64                             mRowHeight;
    ArrayList<i64>                  mColumnWidth;
    i64                             mTotalColumnWidth;
    ArrayList<TableHeaderWidget *>  mHeaders;
    WrapperWidget                  *mContentWrapperWidget;
    WrapperWidget                  *mScrollWrapperWidget;
    ArrayList<TableRowWidget *>     mRows;
    i64                             mSelectedRow;
    i64                             mHighlightedRow;
    keyboard_event_handler          mKeyboardEventHandler;
};



#endif // COM_NGOS_SHARED_COMMON_GUI_WIDGETS_CONTROLS_TABLEWIDGET_H
