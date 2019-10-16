#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_CONTROLS_TABWIDGET_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_CONTROLS_TABWIDGET_H



#include <common/src/bits64/gui/widgets/widget.h>



class TabWidget: public Widget
{
public:
    TabWidget(Image *panelImage, Widget *parent = 0); // TEST: NO
    ~TabWidget(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO

private:
    Image *mPanelImage;
    Image *mPanelResizedImage;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_CONTROLS_TABWIDGET_H
