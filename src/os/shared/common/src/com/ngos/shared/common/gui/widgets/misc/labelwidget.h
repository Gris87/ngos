#ifndef COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_LABELWIDGET_H
#define COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_LABELWIDGET_H



#include <com/ngos/shared/common/gui/widgets/widget.h>

#include <com/ngos/shared/common/gui/other/horizontalalignment.h>
#include <com/ngos/shared/common/gui/other/verticalalignment.h>



class LabelWidget: public Widget
{
public:
    LabelWidget(const char8 *text, Widget *parent = 0); // TEST: NO
    ~LabelWidget(); // TEST: NO

    NgosStatus repaint() override; // TEST: NO

    NgosStatus setText(const char8 *text); // TEST: NO
    const char8* getText() const; // TEST: NO

    NgosStatus setColor(const RgbaPixel &color); // TEST: NO
    const RgbaPixel& getColor() const; // TEST: NO

    NgosStatus setHorizontalAlignment(HorizontalAlignment alignment); // TEST: NO
    HorizontalAlignment getHorizontalAlignment() const; // TEST: NO

    NgosStatus setVerticalAlignment(VerticalAlignment alignment); // TEST: NO
    VerticalAlignment getVerticalAlignment() const; // TEST: NO

private:
    bad_int64 applyHorizontalAlignment(bad_int64 fullWidth, bad_int64 targetWidth); // TEST: NO
    bad_int64 applyVerticalAlignment(bad_int64 fullHeight, bad_int64 targetHeight); // TEST: NO

    const char8         *mText;
    bad_uint16                 *mGlyphOffsets;
    RgbaPixel            mColor;
    HorizontalAlignment  mHorizontalAlignment;
    VerticalAlignment    mVerticalAlignment;
};



#endif // COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_LABELWIDGET_H
