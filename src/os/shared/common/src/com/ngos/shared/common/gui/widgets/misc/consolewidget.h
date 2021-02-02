#ifndef COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_CONSOLEWIDGET_H
#define COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_CONSOLEWIDGET_H



#include <com/ngos/shared/common/gui/widgets/widget.h>



class ConsoleWidget: public Widget
{
public:
    ConsoleWidget(Image *panelImage, Widget *parent = 0); // TEST: NO
    ~ConsoleWidget(); // TEST: NO

    NgosStatus update(bad_int64 positionX, bad_int64 positionY, bad_uint64 width, bad_uint64 height) override; // TEST: NO
    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO

    Image* getPanelImage() const; // TEST: NO

private:
    Image *mPanelImage;
};



#endif // COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_CONSOLEWIDGET_H
