#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_LABELWIDGET_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_LABELWIDGET_H



#include <common/src/com/ngos/shared/common/gui/widgets/widget.h>

#include <common/src/com/ngos/shared/common/gui/other/horizontalalignment.h>
#include <common/src/com/ngos/shared/common/gui/other/verticalalignment.h>



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
    i64 applyHorizontalAlignment(i64 fullWidth, i64 targetWidth); // TEST: NO
    i64 applyVerticalAlignment(i64 fullHeight, i64 targetHeight); // TEST: NO

    const char8         *mText;
    u16                 *mGlyphOffsets;
    RgbaPixel            mColor;
    HorizontalAlignment  mHorizontalAlignment;
    VerticalAlignment    mVerticalAlignment;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_LABELWIDGET_H
