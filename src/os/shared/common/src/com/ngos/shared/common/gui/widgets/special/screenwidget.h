#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GUI_WIDGETS_SPECIAL_SCREENWIDGET_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GUI_WIDGETS_SPECIAL_SCREENWIDGET_H



#include <com/ngos/shared/common/gui/widgets/widget.h>

#include <com/ngos/shared/common/graphics/rgbapixel.h>
#include <com/ngos/shared/common/uefi/uefigraphicsoutputprotocol.h>



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

    UefiGraphicsOutputProtocol* getScreenGop() const; // TEST: NO

private:
    Image                      *mBackgroundImage;
    UefiGraphicsOutputProtocol *mScreenGop;
    RootWidget                 *mRootWidget;
    i64                         mUpdateLeft;
    i64                         mUpdateTop;
    i64                         mUpdateRight;
    i64                         mUpdateBottom;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GUI_WIDGETS_SPECIAL_SCREENWIDGET_H