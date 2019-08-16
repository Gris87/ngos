#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_SCREENWIDGET_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_SCREENWIDGET_H



#include <common/src/bits64/gui/widgets/widget.h>



class ScreenWidget: public Widget
{
public:
    ScreenWidget(Image *backgroundImage, u8 *frameBuffer, Widget *parent = 0); // TEST: NO
    ~ScreenWidget(); // TEST: NO

private:
    Image *mBackgroundImage;
    u8    *mFrameBuffer;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_SCREENWIDGET_H
