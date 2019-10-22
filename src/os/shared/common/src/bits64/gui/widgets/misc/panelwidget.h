#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_PANELWIDGET_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_PANELWIDGET_H



#include <common/src/bits64/gui/widgets/widget.h>



class PanelWidget: public Widget
{
public:
    PanelWidget(Image *panelImage, Widget *parent = 0); // TEST: NO
    PanelWidget(Image *panelImage, Image *panelResizedImage, Widget *parent = 0); // TEST: NO
    ~PanelWidget(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO

private:
    Image *mPanelImage;
    bool   mPredefined;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_PANELWIDGET_H
