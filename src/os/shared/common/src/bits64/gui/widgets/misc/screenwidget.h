#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_SCREENWIDGET_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_SCREENWIDGET_H



#include <common/src/bits64/gui/widgets/widget.h>



class RootWidget;



class ScreenWidget: public Widget
{
public:
    ScreenWidget(Image *backgroundImage, u8 *frameBuffer, RootWidget *rootWidget); // TEST: NO
    ~ScreenWidget(); // TEST: NO

    NgosStatus updateRegion(i64 positionX, i64 positionY, u64 width, u64 height); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO

    NgosStatus drawWidget(Widget *widget, i64 positionX, i64 positionY); // TEST: NO

private:
    Image *mBackgroundImage;
    u8    *mFrameBuffer;
    Image *mBackgroundResizedImage;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_SCREENWIDGET_H
