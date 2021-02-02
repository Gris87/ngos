#ifndef COM_NGOS_SHARED_COMMON_GUI_WIDGETS_SPECIAL_SCREENWIDGET_H
#define COM_NGOS_SHARED_COMMON_GUI_WIDGETS_SPECIAL_SCREENWIDGET_H



#include <com/ngos/shared/common/gui/widgets/widget.h>

#include <com/ngos/shared/common/graphics/rgbapixel.h>
#include <com/ngos/shared/common/uefi/uefigraphicsoutputprotocol.h>



class RootWidget;



class ScreenWidget: public Widget
{
public:
    ScreenWidget(Image *backgroundImage, UefiGraphicsOutputProtocol *screenGop, RootWidget *rootWidget); // TEST: NO
    ~ScreenWidget(); // TEST: NO

    NgosStatus updateRegion(bad_int64 positionX, bad_int64 positionY, bad_uint64 width, bad_uint64 height); // TEST: NO
    NgosStatus applyUpdates(); // TEST: NO

    NgosStatus update(bad_int64 positionX, bad_int64 positionY, bad_uint64 width, bad_uint64 height) override; // TEST: NO
    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO

    UefiGraphicsOutputProtocol* getScreenGop() const; // TEST: NO

private:
    Image                      *mBackgroundImage;
    UefiGraphicsOutputProtocol *mScreenGop;
    RootWidget                 *mRootWidget;
    bad_int64                         mUpdateLeft;
    bad_int64                         mUpdateTop;
    bad_int64                         mUpdateRight;
    bad_int64                         mUpdateBottom;
};



#endif // COM_NGOS_SHARED_COMMON_GUI_WIDGETS_SPECIAL_SCREENWIDGET_H
