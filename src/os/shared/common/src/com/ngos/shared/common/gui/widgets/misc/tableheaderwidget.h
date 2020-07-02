#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_TABLEHEADERWIDGET_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_TABLEHEADERWIDGET_H



#include <common/src/com/ngos/shared/common/gui/widgets/widget.h>

#include <common/src/com/ngos/shared/common/gui/widgets/misc/labelwidget.h>



class TableHeaderWidget: public Widget
{
public:
    TableHeaderWidget(Image *image, const char8* text, Widget *parent = 0); // TEST: NO
    ~TableHeaderWidget(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO

private:
    Image       *mImage;
    LabelWidget *mLabelWidget;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_TABLEHEADERWIDGET_H
