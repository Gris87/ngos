#ifndef COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_CURSORWIDGET_H
#define COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_CURSORWIDGET_H



#include <com/ngos/shared/common/gui/widgets/widget.h>



class CursorWidget: public Widget
{
public:
    CursorWidget(Image *cursorImage, Widget *parent = nullptr); // TEST: NO
    ~CursorWidget(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO

private:
    Image *mCursorImage;
};



#endif // COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_CURSORWIDGET_H
