#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_CONTROLS_BUTTON_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_CONTROLS_BUTTON_H



#include <common/src/bits64/gui/widgets/widget.h>
#include <common/src/bits64/gui/widgets/misc/imagewidget.h>
#include <common/src/bits64/gui/widgets/misc/labelwidget.h>



class Button: public Widget
{
public:
    Button(Image *normalImage, Image *hoverImage, Image *pressedImage, Image *focusedImage, Image *contentImage, const char8 *text, Widget *parent = 0); // TEST: NO
    ~Button(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO
    NgosStatus onKeyboardEvent(const UefiInputKey &key) override; // TEST: NO

    NgosStatus setState(WidgetState state) override; // TEST: NO
    WidgetState getState() const override; // TEST: NO

    NgosStatus setKeyboardEventHandler(keyboard_event_handler handler) override; // TEST: NO
    keyboard_event_handler getKeyboardEventHandler() const override; // TEST: NO

    NgosStatus setPressEventHandler(press_event_handler handler) override; // TEST: NO
    press_event_handler getPressEventHandler() const override; // TEST: NO

private:
    Image                  *mNormalImage;
    Image                  *mHoverImage;
    Image                  *mPressedImage;
    Image                  *mFocusedImage;
    Image                  *mNormalResizedImage;
    Image                  *mHoverResizedImage;
    Image                  *mPressedResizedImage;
    Image                  *mFocusedResizedImage;
    ImageWidget            *mImageWidget;
    LabelWidget            *mLabelWidget;
    WidgetState             mState;
    keyboard_event_handler  mKeyboardEventHandler;
    press_event_handler     mPressEventHandler;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_CONTROLS_BUTTON_H
