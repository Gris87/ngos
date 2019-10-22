#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_LABELWIDGET_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_LABELWIDGET_H



#include <common/src/bits64/gui/widgets/widget.h>



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

private:
    const char8 *mText;
    u16         *mGlyphOffsets;
    RgbaPixel    mColor;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_LABELWIDGET_H
