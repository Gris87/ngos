#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_PROGRESSBARWIDGET_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_PROGRESSBARWIDGET_H



#include <common/src/bits64/gui/widgets/widget.h>

#include <common/src/bits64/gui/widgets/misc/panelwidget.h>
#include <common/src/bits64/gui/widgets/misc/imagewidget.h>
#include <common/src/bits64/gui/widgets/misc/labelwidget.h>



class ProgressBarWidget: public Widget
{
public:
    ProgressBarWidget(Image *backgroundImage, Image *indicatorImage, Widget *parent = 0); // TEST: NO
    ~ProgressBarWidget(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO

private:
    PanelWidget *mPanelWidget;
    ImageWidget *mIndicatorImageWidget;
    LabelWidget *mLabelWidget;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_PROGRESSBARWIDGET_H
