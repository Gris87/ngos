#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_PROGRESSBARWIDGET_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_PROGRESSBARWIDGET_H



#include <com/ngos/shared/common/gui/widgets/widget.h>

#include <com/ngos/shared/common/gui/widgets/misc/imagewidget.h>
#include <com/ngos/shared/common/gui/widgets/misc/labelwidget.h>
#include <com/ngos/shared/common/gui/widgets/misc/panelwidget.h>



class ProgressBarWidget: public Widget
{
public:
    ProgressBarWidget(Image *backgroundImage, Image *indicatorImage, Widget *parent = 0); // TEST: NO
    ~ProgressBarWidget(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO

    NgosStatus setColor(const RgbaPixel &color); // TEST: NO

    NgosStatus setMinimumValue(i64 minimumValue); // TEST: NO
    i64 getMinimumValue() const; // TEST: NO

    NgosStatus setMaximumValue(i64 maximumValue); // TEST: NO
    i64 getMaximumValue() const; // TEST: NO

    NgosStatus setValue(i64 value); // TEST: NO
    i64 getValue() const; // TEST: NO

private:
    NgosStatus updatePercents(); // TEST: NO

    PanelWidget *mPanelWidget;
    ImageWidget *mIndicatorImageWidget;
    LabelWidget *mLabelWidget;
    i64          mMinimumValue;
    i64          mMaximumValue;
    i64          mValue;
    i64          mProgressWidth;
    u8           mPercents;
    char8        mPercentsBuffer[6];
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_PROGRESSBARWIDGET_H
