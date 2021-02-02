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
    TableWidget(Image *backgroundImage, Image *headerImage, Widget *parent = 0); // TEST: NO
    ~TableWidget(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO
    NgosStatus onKeyboardEvent(const UefiInputKey &key) override; // TEST: NO
    NgosStatus onMouseScrollEvent(bad_int32 delta) override; // TEST: NO

    NgosStatus scrollToSelectedRow(); // TEST: NO
    NgosStatus pageUp(); // TEST: NO
    NgosStatus pageDown(); // TEST: NO

    bool isFocusable() override; // TEST: NO

    NgosStatus setState(WidgetState state) override; // TEST: NO
    WidgetState getState() const override; // TEST: NO

    NgosStatus setRowHeight(bad_uint64 height); // TEST: NO
    bad_uint64 getRowHeight() const; // TEST: NO

    NgosStatus setColumnCount(bad_uint64 columns); // TEST: NO
    bad_uint64 getColumnCount() const; // TEST: NO

    NgosStatus setColumnWidth(bad_uint64 column, bad_uint64 width); // TEST: NO
    bad_uint64 getColumnWidth(bad_uint64 column) const; // TEST: NO

    NgosStatus setHeaderText(bad_uint64 column, const char8 *text); // TEST: NO

    NgosStatus setRowCount(bad_uint64 rows); // TEST: NO
    bad_uint64 getRowCount() const; // TEST: NO

    const ArrayList<TableRowWidget *>& getRows() const; // TEST: NO

    NgosStatus setCellWidget(bad_uint64 row, bad_uint64 column, Widget *widget); // TEST: NO
    Widget* getCellWidget(bad_uint64 row, bad_uint64 column) const; // TEST: NO

    NgosStatus setSelectedRow(bad_uint64 row); // TEST: NO
    bad_uint64 getSelectedRow() const; // TEST: NO

    NgosStatus setHighlightedRow(bad_uint64 row); // TEST: NO
    bad_uint64 getHighlightedRow() const; // TEST: NO

    NgosStatus setKeyboardEventHandler(keyboard_event_handler handler) override; // TEST: NO
    keyboard_event_handler getKeyboardEventHandler() const override; // TEST: NO

private:
    Image                          *mBackgroundImage;
    Image                          *mHeaderImage;
    WidgetState                     mState;
    bad_uint64                             mRowHeight;
    ArrayList<bad_uint64>                  mColumnWidth;
    bad_uint64                             mTotalColumnWidth;
    ArrayList<TableHeaderWidget *>  mHeaders;
    WrapperWidget                  *mContentWrapperWidget;
    WrapperWidget                  *mScrollWrapperWidget;
    ArrayList<TableRowWidget *>     mRows;
    bad_uint64                             mSelectedRow;
    bad_uint64                             mHighlightedRow;
    keyboard_event_handler          mKeyboardEventHandler;
};



#endif // COM_NGOS_SHARED_COMMON_GUI_WIDGETS_CONTROLS_TABLEWIDGET_H
