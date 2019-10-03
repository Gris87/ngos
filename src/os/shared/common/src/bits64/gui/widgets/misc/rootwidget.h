#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_ROOTWIDGET_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_ROOTWIDGET_H



#include <common/src/bits64/gui/widgets/misc/screenwidget.h>



class RootWidget: public Widget
{
public:
    RootWidget(); // TEST: NO
    ~RootWidget(); // TEST: NO

    NgosStatus addScreen(ScreenWidget *screen); // TEST: NO
    NgosStatus applyUpdates(); // TEST: NO

    NgosStatus update(i64 positionX, i64 positionY, u64 width, u64 height) override; // TEST: NO

    const List<ScreenWidget *>& getScreens() const; // TEST: NO

private:
    List<ScreenWidget *> mScreens;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_ROOTWIDGET_H
