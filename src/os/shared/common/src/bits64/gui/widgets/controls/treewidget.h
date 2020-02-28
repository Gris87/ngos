#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_CONTROLS_TREEWIDGET_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_CONTROLS_TREEWIDGET_H



#include <common/src/bits64/gui/widgets/widget.h>

#include <common/src/bits64/gui/widgets/misc/wrapperwidget.h>
#include <common/src/bits64/gui/widgets/misc/treenodewidget.h>



class TreeWidget: public Widget
{
public:
    TreeWidget(Image *backgroundImage, Widget *parent = 0); // TEST: NO
    ~TreeWidget(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO

    bool isFocusable() override; // TEST: NO

    NgosStatus setRowHeight(u64 height); // TEST: NO
    u64 getRowHeight() const; // TEST: NO

    NgosStatus setRootNodeWidget(TreeNodeWidget *widget); // TEST: NO

private:
    Image         *mBackgroundImage;
    WrapperWidget *mWrapperWidget;
    u64            mRowHeight;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_CONTROLS_TREEWIDGET_H
