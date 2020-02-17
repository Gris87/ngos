#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_TREEWIDGET_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_TREEWIDGET_H



#include <common/src/bits64/gui/widgets/widget.h>



class TreeWidget: public Widget
{
public:
    TreeWidget(Widget *parent = 0); // TEST: NO
    ~TreeWidget(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_TREEWIDGET_H
