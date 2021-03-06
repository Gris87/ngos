#ifndef COM_NGOS_SHARED_COMMON_GUI_WIDGETS_CONTROLS_BUTTON_H
#define COM_NGOS_SHARED_COMMON_GUI_WIDGETS_CONTROLS_BUTTON_H



#include <com/ngos/shared/common/gui/widgets/widget.h>

#include <com/ngos/shared/common/gui/widgets/misc/imagewidget.h>
#include <com/ngos/shared/common/gui/widgets/misc/labelwidget.h>



class Button: public Widget
{
public:
    Button(Image *normalImage, Image *hoverImage, Image *pressedImage, Image *focusedImage, Image *focusedHoverImage, Image *contentImage, Image *badgeImage, const char8 *text, Widget *parent = nullptr); // TEST: NO
    Button(Image *normalImage, Image *hoverImage, Image *pressedImage, Image *focusedImage, Image *focusedHoverImage, Image *normalResizedImage, Image *hoverResizedImage, Image *pressedResizedImage, Image *focusedResizedImage, Image *focusedHoverResizedImage, Image *contentImage, Image *badgeImage, const char8 *text, Widget *parent = nullptr); // TEST: NO
    Button(Image *normalImage, Image *hoverImage, Image *pressedImage, Image *focusedImage, Image *focusedHoverImage, Image *normalResizedImage, Image *hoverResizedImage, Image *pressedResizedImage, Image *focusedResizedImage, Image *focusedHoverResizedImage, Image *contentImage, Image *contentResizedImage, Image *badgeImage, const char8 *text, Widget *parent = nullptr); // TEST: NO
    ~Button(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO
    NgosStatus onKeyboardEvent(const UefiInputKey &key) override; // TEST: NO

    bool isAcceptMouseEvents() override; // TEST: NO
    bool isFocusable() override; // TEST: NO

    NgosStatus setContentImage(Image *contentImage); // TEST: NO

    NgosStatus setText(const char8 *text); // TEST: NO

    NgosStatus setColor(const RgbaPixel &color); // TEST: NO

    NgosStatus setPredefined(bool predefined); // TEST: NO

    NgosStatus setState(WidgetState state) override; // TEST: NO
    WidgetState getState() const override; // TEST: NO

    NgosStatus setKeyboardEventHandler(keyboard_event_handler handler) override; // TEST: NO
    keyboard_event_handler getKeyboardEventHandler() const override; // TEST: NO

    NgosStatus setPressEventHandler(press_event_handler handler) override; // TEST: NO
    press_event_handler getPressEventHandler() const override; // TEST: NO

    NgosStatus setPressEventHandlerObject(PressEventHandler *handler) override; // TEST: NO
    PressEventHandler* getPressEventHandlerObject() const override; // TEST: NO

private:
    Image                  *mNormalImage;
    Image                  *mHoverImage;
    Image                  *mPressedImage;
    Image                  *mFocusedImage;
    Image                  *mFocusedHoverImage;
    Image                  *mNormalResizedImage;
    Image                  *mHoverResizedImage;
    Image                  *mPressedResizedImage;
    Image                  *mFocusedResizedImage;
    Image                  *mFocusedHoverResizedImage;
    ImageWidget            *mImageWidget;
    ImageWidget            *mBadgeWidget;
    LabelWidget            *mLabelWidget;
    WidgetState             mState;
    bool                    mPredefined;
    keyboard_event_handler  mKeyboardEventHandler;
    press_event_handler     mPressEventHandler;
    PressEventHandler      *mPressEventHandlerObject;
};



#endif // COM_NGOS_SHARED_COMMON_GUI_WIDGETS_CONTROLS_BUTTON_H
