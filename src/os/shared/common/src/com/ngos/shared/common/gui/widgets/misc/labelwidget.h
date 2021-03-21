#ifndef COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_LABELWIDGET_H
#define COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_LABELWIDGET_H



#include <com/ngos/shared/common/gui/widgets/widget.h>

#include <com/ngos/shared/common/gui/other/horizontalalignment.h>
#include <com/ngos/shared/common/gui/other/verticalalignment.h>



class LabelWidget: public Widget
{
public:
    LabelWidget(const char8 *text, Widget *parent = nullptr); // TEST: NO
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
    i64 applyHorizontalAlignment(i64 fullWidth, i64 targetWidth); // TEST: NO
    i64 applyVerticalAlignment(i64 fullHeight, i64 targetHeight); // TEST: NO

    const char8         *mText;
    u16                 *mGlyphOffsets;
    RgbaPixel            mColor;
    HorizontalAlignment  mHorizontalAlignment;
    VerticalAlignment    mVerticalAlignment;
};



#endif // COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_LABELWIDGET_H
