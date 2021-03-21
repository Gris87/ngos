#ifndef COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_WRAPPERWIDGET_H
#define COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_WRAPPERWIDGET_H



#include <com/ngos/shared/common/gui/widgets/widget.h>



class WrapperWidget: public Widget
{
public:
    WrapperWidget(Widget *parent = nullptr); // TEST: NO
    ~WrapperWidget(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO
};



#endif // COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_WRAPPERWIDGET_H
