#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_TREENODEWIDGET_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_TREENODEWIDGET_H



#include <common/src/bits64/gui/widgets/widget.h>

#include <common/src/bits64/gui/widgets/misc/labelwidget.h>



class TreeNodeWidget: public Widget
{
public:
    TreeNodeWidget(Image *collapsedImage, Image *expandedImage, const char8* text, Widget *parent = 0); // TEST: NO
    ~TreeNodeWidget(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO

private:
    Image       *mCollapsedImage;
    Image       *mExpandedImage;
    LabelWidget *mLabelWidget;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_TREENODEWIDGET_H
