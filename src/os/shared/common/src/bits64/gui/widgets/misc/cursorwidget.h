#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_CURSORWIDGET_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_CURSORWIDGET_H



#include <common/src/bits64/gui/widgets/widget.h>



class CursorWidget: public Widget
{
public:
    CursorWidget(Image *cursorImage, Image *pointerImage, Widget *parent = 0); // TEST: NO
    ~CursorWidget(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO

private:
    Image *mCursorImage;
    Image *mPointerImage;
    Image *mCursorResizedImage;
    Image *mPointerResizedImage;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_CURSORWIDGET_H
