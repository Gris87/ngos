#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_ROOTWIDGET_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_ROOTWIDGET_H



#include <common/src/bits64/gui/widgets/misc/screenwidget.h>



class RootWidget: public Widget
{
public:
    RootWidget(); // TEST: NO
    ~RootWidget(); // TEST: NO

    NgosStatus addScreen(ScreenWidget *screen); // TEST: NO

    NgosStatus updateRegion(i64 positionX, i64 positionY, u64 width, u64 height); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO

private:
    List<ScreenWidget *> mScreens;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_ROOTWIDGET_H
