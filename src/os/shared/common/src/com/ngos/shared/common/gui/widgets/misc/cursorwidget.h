#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_CURSORWIDGET_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_CURSORWIDGET_H



#include <common/src/com/ngos/shared/common/gui/widgets/widget.h>



class CursorWidget: public Widget
{
public:
    CursorWidget(Image *cursorImage, Widget *parent = 0); // TEST: NO
    ~CursorWidget(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO

private:
    Image *mCursorImage;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_CURSORWIDGET_H
