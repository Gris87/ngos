#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_SCREENWIDGET_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_SCREENWIDGET_H



#include <common/src/bits64/graphics/rgbapixel.h>
#include <common/src/bits64/gui/widgets/widget.h>
#include <uefi/uefigraphicsoutputprotocol.h>



class RootWidget;



class ScreenWidget: public Widget
{
public:
    ScreenWidget(Image *backgroundImage, UefiGraphicsOutputProtocol *screenGop, RootWidget *rootWidget); // TEST: NO
    ~ScreenWidget(); // TEST: NO

    NgosStatus updateRegion(i64 positionX, i64 positionY, u64 width, u64 height); // TEST: NO
    NgosStatus applyUpdates(); // TEST: NO

    NgosStatus update(i64 positionX, i64 positionY, u64 width, u64 height) override; // TEST: NO
    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO

    NgosStatus drawWidget(Widget *widget, i64 positionX, i64 positionY); // TEST: NO
    NgosStatus drawWidget(Widget *widget, i64 positionX, i64 positionY, i64 left, i64 top, i64 right, i64 bottom); // TEST: NO

private:
    Image                      *mBackgroundImage;
    UefiGraphicsOutputProtocol *mScreenGop;
    RootWidget                 *mRootWidget;
    Image                      *mBackgroundResizedImage;
    RgbaPixel                  *mDoubleBuffer;
    i64                         mUpdateLeft;
    i64                         mUpdateTop;
    i64                         mUpdateRight;
    i64                         mUpdateBottom;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_SCREENWIDGET_H
