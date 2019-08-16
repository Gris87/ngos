#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_CONTROLS_BUTTON_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_CONTROLS_BUTTON_H



#include <common/src/bits64/gui/widgets/widget.h>



class Button: public Widget
{
public:
    Button(Image *normalImage, Image *hoverImage, Image *pressedImage, Image *focusedImage, Image *contentImage, Widget *parent = 0); // TEST: NO
    ~Button(); // TEST: NO

private:
    Image *mNormalImage;
    Image *mHoverImage;
    Image *mPressedImage;
    Image *mFocusedImage;
    Image *mContentImage;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_CONTROLS_BUTTON_H
