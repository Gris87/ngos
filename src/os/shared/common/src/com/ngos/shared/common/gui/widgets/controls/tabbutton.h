#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_CONTROLS_TABBUTTON_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_CONTROLS_TABBUTTON_H



#include <common/src/com/ngos/shared/common/gui/widgets/widget.h>

#include <common/src/com/ngos/shared/common/gui/widgets/misc/imagewidget.h>
#include <common/src/com/ngos/shared/common/gui/widgets/misc/labelwidget.h>



class TabButton: public Widget
{
public:
    TabButton(Image *normalImage, Image *hoverImage, Image *pressedImage, Image *focusedImage, Image *focusedHoverImage, Image *selectedNormalImage, Image *selectedHoverImage, Image *selectedPressedImage, Image *selectedFocusedImage, Image *selectedFocusedHoverImage, Image *contentImage, Image *badgeImage, const char8 *text, Widget *parent = 0); // TEST: NO
    TabButton(Image *normalImage, Image *hoverImage, Image *pressedImage, Image *focusedImage, Image *focusedHoverImage, Image *selectedNormalImage, Image *selectedHoverImage, Image *selectedPressedImage, Image *selectedFocusedImage, Image *selectedFocusedHoverImage, Image *normalResizedImage, Image *hoverResizedImage, Image *pressedResizedImage, Image *focusedResizedImage, Image *focusedHoverResizedImage, Image *selectedNormalResizedImage, Image *selectedHoverResizedImage, Image *selectedPressedResizedImage, Image *selectedFocusedResizedImage, Image *selectedFocusedHoverResizedImage, Image *contentImage, Image *badgeImage, const char8 *text, Widget *parent = 0); // TEST: NO
    ~TabButton(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO
    NgosStatus onKeyboardEvent(const UefiInputKey &key) override; // TEST: NO

    bool isAcceptMouseEvents() override; // TEST: NO
    bool isFocusable() override; // TEST: NO

    NgosStatus setState(WidgetState state) override; // TEST: NO
    WidgetState getState() const override; // TEST: NO

    NgosStatus setSelected(bool selected); // TEST: NO
    bool isSelected() const; // TEST: NO

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
    Image                  *mSelectedNormalImage;
    Image                  *mSelectedHoverImage;
    Image                  *mSelectedPressedImage;
    Image                  *mSelectedFocusedImage;
    Image                  *mSelectedFocusedHoverImage;
    Image                  *mNormalResizedImage;
    Image                  *mHoverResizedImage;
    Image                  *mPressedResizedImage;
    Image                  *mFocusedResizedImage;
    Image                  *mFocusedHoverResizedImage;
    Image                  *mSelectedNormalResizedImage;
    Image                  *mSelectedHoverResizedImage;
    Image                  *mSelectedPressedResizedImage;
    Image                  *mSelectedFocusedResizedImage;
    Image                  *mSelectedFocusedHoverResizedImage;
    ImageWidget            *mImageWidget;
    ImageWidget            *mBadgeWidget;
    LabelWidget            *mLabelWidget;
    WidgetState             mState;
    bool                    mSelected;
    bool                    mPredefined;
    keyboard_event_handler  mKeyboardEventHandler;
    press_event_handler     mPressEventHandler;
    PressEventHandler      *mPressEventHandlerObject;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_CONTROLS_TABBUTTON_H
