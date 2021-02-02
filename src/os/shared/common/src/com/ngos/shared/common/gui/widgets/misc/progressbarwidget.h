#ifndef COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_PROGRESSBARWIDGET_H
#define COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_PROGRESSBARWIDGET_H



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

    NgosStatus setMinimumValue(bad_int64 minimumValue); // TEST: NO
    bad_int64 getMinimumValue() const; // TEST: NO

    NgosStatus setMaximumValue(bad_int64 maximumValue); // TEST: NO
    bad_int64 getMaximumValue() const; // TEST: NO

    NgosStatus setValue(bad_int64 value); // TEST: NO
    bad_int64 getValue() const; // TEST: NO

private:
    NgosStatus updatePercents(); // TEST: NO

    PanelWidget *mPanelWidget;
    ImageWidget *mIndicatorImageWidget;
    LabelWidget *mLabelWidget;
    bad_int64          mMinimumValue;
    bad_int64          mMaximumValue;
    bad_int64          mValue;
    bad_int64          mProgressWidth;
    bad_uint8           mPercents;
    char8        mPercentsBuffer[6];
};



#endif // COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_PROGRESSBARWIDGET_H
