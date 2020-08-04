#ifndef COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_TABLEHEADERWIDGET_H
#define COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_TABLEHEADERWIDGET_H



#include <com/ngos/shared/common/gui/widgets/widget.h>

#include <com/ngos/shared/common/gui/widgets/misc/labelwidget.h>



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



#endif // COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_TABLEHEADERWIDGET_H
