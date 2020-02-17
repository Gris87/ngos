#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_TREEWIDGET_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_TREEWIDGET_H



#include <common/src/bits64/gui/widgets/widget.h>

#include <common/src/bits64/gui/widgets/misc/wrapperwidget.h>



class TreeWidget: public Widget
{
public:
    TreeWidget(Image *backgroundImage, Widget *parent = 0); // TEST: NO
    ~TreeWidget(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO

private:
    Image         *mBackgroundImage;
    WrapperWidget *mWrapperWidget;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_TREEWIDGET_H
