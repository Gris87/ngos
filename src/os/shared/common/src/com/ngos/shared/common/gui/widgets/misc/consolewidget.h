#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_CONSOLEWIDGET_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_CONSOLEWIDGET_H



#include <com/ngos/shared/common/gui/widgets/widget.h>



class ConsoleWidget: public Widget
{
public:
    ConsoleWidget(Image *panelImage, Widget *parent = 0); // TEST: NO
    ~ConsoleWidget(); // TEST: NO

    NgosStatus update(i64 positionX, i64 positionY, u64 width, u64 height) override; // TEST: NO
    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO

    Image* getPanelImage() const; // TEST: NO

private:
    Image *mPanelImage;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_CONSOLEWIDGET_H
