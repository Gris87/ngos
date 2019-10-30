#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_CONTROLS_TABLEWIDGET_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_CONTROLS_TABLEWIDGET_H



#include <common/src/bits64/gui/widgets/widget.h>

#include <common/src/bits64/containers/arraylist.h>



class TableWidget: public Widget
{
public:
    TableWidget(Image *headerImage, Image *cellNormalImage, Image *cellHoverImage, Image *cellInactiveImage, Image *cellFocusedImage, Image *cellFocusedHoverImage, Widget *parent = 0); // TEST: NO
    ~TableWidget(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO

    NgosStatus setRowHeight(u64 height); // TEST: NO
    u64 getRowHeight() const; // TEST: NO

    NgosStatus setColumnCount(u64 columns); // TEST: NO
    u64 getColumnCount() const; // TEST: NO

    NgosStatus setColumnWidth(u64 column, u64 width); // TEST: NO
    u64 getColumnWidth(u64 column) const; // TEST: NO

private:
    Image          *mHeaderImage;
    Image          *mCellNormalImage;
    Image          *mCellHoverImage;
    Image          *mCellInactiveImage;
    Image          *mCellFocusedImage;
    Image          *mCellFocusedHoverImage;
    u64             mRowHeight;
    ArrayList<u64>  mColumnWidth;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_CONTROLS_TABLEWIDGET_H
