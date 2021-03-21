#ifndef COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_PANELWIDGET_H
#define COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_PANELWIDGET_H



#include <com/ngos/shared/common/gui/widgets/widget.h>



class PanelWidget: public Widget
{
public:
    PanelWidget(Image *panelImage, Widget *parent = nullptr); // TEST: NO
    PanelWidget(Image *panelImage, Image *panelResizedImage, Widget *parent = nullptr); // TEST: NO
    ~PanelWidget(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO

    Image* getPanelImage() const; // TEST: NO

private:
    Image *mPanelImage;
    bool   mPredefined;
};



#endif // COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_PANELWIDGET_H
