#include "tabbutton.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/gui/gui.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/utils.h>



TabButton::TabButton(Image *normalImage, Image *hoverImage, Image *pressedImage, Image *focusedImage, Image *focusedHoverImage, Image *selectedNormalImage, Image *selectedHoverImage, Image *selectedPressedImage, Image *selectedFocusedImage, Image *selectedFocusedHoverImage, Image *contentImage, Image *badgeImage, const char8 *text, Widget *parent)
    : Widget(parent)
    , mNormalImage(normalImage)
    , mHoverImage(hoverImage)
    , mPressedImage(pressedImage)
    , mFocusedImage(focusedImage)
    , mFocusedHoverImage(focusedHoverImage)
    , mSelectedNormalImage(selectedNormalImage)
    , mSelectedHoverImage(selectedHoverImage)
    , mSelectedPressedImage(selectedPressedImage)
    , mSelectedFocusedImage(selectedFocusedImage)
    , mSelectedFocusedHoverImage(selectedFocusedHoverImage)
    , mNormalResizedImage(nullptr)
    , mHoverResizedImage(nullptr)
    , mPressedResizedImage(nullptr)
    , mFocusedResizedImage(nullptr)
    , mFocusedHoverResizedImage(nullptr)
    , mSelectedNormalResizedImage(nullptr)
    , mSelectedHoverResizedImage(nullptr)
    , mSelectedPressedResizedImage(nullptr)
    , mSelectedFocusedResizedImage(nullptr)
    , mSelectedFocusedHoverResizedImage(nullptr)
    , mImageWidget(new ImageWidget(contentImage, this))
    , mBadgeWidget(nullptr)
    , mLabelWidget(nullptr)
    , mState(WidgetState::NORMAL)
    , mSelected(false)
    , mPredefined(false)
    , mKeyboardEventHandler(nullptr)
    , mPressEventHandler(nullptr)
{
    COMMON_LT((" | normalImage = 0x%p, hoverImage = 0x%p, pressedImage = 0x%p, focusedImage = 0x%p, focusedHoverImage = 0x%p, selectedNormalImage = 0x%p, selectedHoverImage = 0x%p, selectedPressedImage = 0x%p, selectedFocusedImage = 0x%p, selectedFocusedHoverImage = 0x%p, contentImage = 0x%p, badgeImage = 0x%p, text = 0x%p, parent = 0x%p", normalImage, hoverImage, pressedImage, focusedImage, focusedHoverImage, selectedNormalImage, selectedHoverImage, selectedPressedImage, selectedFocusedImage, selectedFocusedHoverImage, contentImage, badgeImage, text, parent));

    COMMON_ASSERT(normalImage,               "normalImage is null");
    COMMON_ASSERT(hoverImage,                "hoverImage is null");
    COMMON_ASSERT(pressedImage,              "pressedImage is null");
    COMMON_ASSERT(focusedImage,              "focusedImage is null");
    COMMON_ASSERT(focusedHoverImage,         "focusedHoverImage is null");
    COMMON_ASSERT(selectedNormalImage,       "selectedNormalImage is null");
    COMMON_ASSERT(selectedHoverImage,        "selectedHoverImage is null");
    COMMON_ASSERT(selectedPressedImage,      "selectedPressedImage is null");
    COMMON_ASSERT(selectedFocusedImage,      "selectedFocusedImage is null");
    COMMON_ASSERT(selectedFocusedHoverImage, "selectedFocusedHoverImage is null");
    COMMON_ASSERT(contentImage,              "contentImage is null");
    COMMON_ASSERT(parent,                    "parent is null");



    if (badgeImage)
    {
        mBadgeWidget = new ImageWidget(badgeImage, this);
    }

    if (text && *text)
    {
        mLabelWidget = new LabelWidget(text, this);
    }
}

TabButton::TabButton(Image *normalImage, Image *hoverImage, Image *pressedImage, Image *focusedImage, Image *focusedHoverImage, Image *selectedNormalImage, Image *selectedHoverImage, Image *selectedPressedImage, Image *selectedFocusedImage, Image *selectedFocusedHoverImage, Image *normalResizedImage, Image *hoverResizedImage, Image *pressedResizedImage, Image *focusedResizedImage, Image *focusedHoverResizedImage, Image *selectedNormalResizedImage, Image *selectedHoverResizedImage, Image *selectedPressedResizedImage, Image *selectedFocusedResizedImage, Image *selectedFocusedHoverResizedImage, Image *contentImage, Image *badgeImage, const char8 *text, Widget *parent)
    : Widget(parent)
    , mNormalImage(normalImage)
    , mHoverImage(hoverImage)
    , mPressedImage(pressedImage)
    , mFocusedImage(focusedImage)
    , mFocusedHoverImage(focusedHoverImage)
    , mSelectedNormalImage(selectedNormalImage)
    , mSelectedHoverImage(selectedHoverImage)
    , mSelectedPressedImage(selectedPressedImage)
    , mSelectedFocusedImage(selectedFocusedImage)
    , mSelectedFocusedHoverImage(selectedFocusedHoverImage)
    , mNormalResizedImage(normalResizedImage)
    , mHoverResizedImage(hoverResizedImage)
    , mPressedResizedImage(pressedResizedImage)
    , mFocusedResizedImage(focusedResizedImage)
    , mFocusedHoverResizedImage(focusedHoverResizedImage)
    , mSelectedNormalResizedImage(selectedNormalResizedImage)
    , mSelectedHoverResizedImage(selectedHoverResizedImage)
    , mSelectedPressedResizedImage(selectedPressedResizedImage)
    , mSelectedFocusedResizedImage(selectedFocusedResizedImage)
    , mSelectedFocusedHoverResizedImage(selectedFocusedHoverResizedImage)
    , mImageWidget(new ImageWidget(contentImage, this))
    , mBadgeWidget(nullptr)
    , mLabelWidget(nullptr)
    , mState(WidgetState::NORMAL)
    , mSelected(false)
    , mPredefined(true)
    , mKeyboardEventHandler(nullptr)
    , mPressEventHandler(nullptr)
{
    COMMON_LT((" | normalImage = 0x%p, hoverImage = 0x%p, pressedImage = 0x%p, focusedImage = 0x%p, focusedHoverImage = 0x%p, selectedNormalImage = 0x%p, selectedHoverImage = 0x%p, selectedPressedImage = 0x%p, selectedFocusedImage = 0x%p, selectedFocusedHoverImage = 0x%p, normalResizedImage = 0x%p, hoverResizedImage = 0x%p, pressedResizedImage = 0x%p, focusedResizedImage = 0x%p, focusedHoverResizedImage = 0x%p, selectedNormalResizedImage = 0x%p, selectedHoverResizedImage = 0x%p, selectedPressedResizedImage = 0x%p, selectedFocusedResizedImage = 0x%p, selectedFocusedHoverResizedImage = 0x%p, contentImage = 0x%p, badgeImage = 0x%p, text = 0x%p, parent = 0x%p", normalImage, hoverImage, pressedImage, focusedImage, focusedHoverImage, selectedNormalImage, selectedHoverImage, selectedPressedImage, selectedFocusedImage, selectedFocusedHoverImage, normalResizedImage, hoverResizedImage, pressedResizedImage, focusedResizedImage, focusedHoverResizedImage, selectedNormalResizedImage, selectedHoverResizedImage, selectedPressedResizedImage, selectedFocusedResizedImage, selectedFocusedHoverResizedImage, contentImage, badgeImage, text, parent));

    COMMON_ASSERT(normalImage,                      "normalImage is null");
    COMMON_ASSERT(hoverImage,                       "hoverImage is null");
    COMMON_ASSERT(pressedImage,                     "pressedImage is null");
    COMMON_ASSERT(focusedImage,                     "focusedImage is null");
    COMMON_ASSERT(focusedHoverImage,                "focusedHoverImage is null");
    COMMON_ASSERT(selectedNormalImage,              "selectedNormalImage is null");
    COMMON_ASSERT(selectedHoverImage,               "selectedHoverImage is null");
    COMMON_ASSERT(selectedPressedImage,             "selectedPressedImage is null");
    COMMON_ASSERT(selectedFocusedImage,             "selectedFocusedImage is null");
    COMMON_ASSERT(selectedFocusedHoverImage,        "selectedFocusedHoverImage is null");
    COMMON_ASSERT(normalResizedImage,               "normalResizedImage is null");
    COMMON_ASSERT(hoverResizedImage,                "hoverResizedImage is null");
    COMMON_ASSERT(pressedResizedImage,              "pressedResizedImage is null");
    COMMON_ASSERT(focusedResizedImage,              "focusedResizedImage is null");
    COMMON_ASSERT(focusedHoverResizedImage,         "focusedHoverResizedImage is null");
    COMMON_ASSERT(selectedNormalResizedImage,       "selectedNormalResizedImage is null");
    COMMON_ASSERT(selectedHoverResizedImage,        "selectedHoverResizedImage is null");
    COMMON_ASSERT(selectedPressedResizedImage,      "selectedPressedResizedImage is null");
    COMMON_ASSERT(selectedFocusedResizedImage,      "selectedFocusedResizedImage is null");
    COMMON_ASSERT(selectedFocusedHoverResizedImage, "selectedFocusedHoverResizedImage is null");
    COMMON_ASSERT(contentImage,                     "contentImage is null");
    COMMON_ASSERT(parent,                           "parent is null");



    if (badgeImage)
    {
        mBadgeWidget = new ImageWidget(badgeImage, this);
    }

    if (text && *text)
    {
        mLabelWidget = new LabelWidget(text, this);
    }
}

TabButton::~TabButton()
{
    COMMON_LT((""));



    if (!mPredefined)
    {
        if (mNormalResizedImage)
        {
            delete mNormalResizedImage;
        }

        if (mHoverResizedImage)
        {
            delete mHoverResizedImage;
        }

        if (mPressedResizedImage)
        {
            delete mPressedResizedImage;
        }

        if (mFocusedResizedImage)
        {
            delete mFocusedResizedImage;
        }

        if (mFocusedHoverResizedImage)
        {
            delete mFocusedHoverResizedImage;
        }

        if (mSelectedNormalResizedImage)
        {
            delete mSelectedNormalResizedImage;
        }

        if (mSelectedHoverResizedImage)
        {
            delete mSelectedHoverResizedImage;
        }

        if (mSelectedPressedResizedImage)
        {
            delete mSelectedPressedResizedImage;
        }

        if (mSelectedFocusedResizedImage)
        {
            delete mSelectedFocusedResizedImage;
        }

        if (mSelectedFocusedHoverResizedImage)
        {
            delete mSelectedFocusedHoverResizedImage;
        }
    }



    if (mResultImage)
    {
        delete mResultImage;
    }
}

NgosStatus TabButton::invalidate()
{
    COMMON_LT((""));



    if (!mPredefined)
    {
        if (mNormalResizedImage)
        {
            delete mNormalResizedImage;
        }

        if (mHoverResizedImage)
        {
            delete mHoverResizedImage;
        }

        if (mPressedResizedImage)
        {
            delete mPressedResizedImage;
        }

        if (mFocusedResizedImage)
        {
            delete mFocusedResizedImage;
        }

        if (mFocusedHoverResizedImage)
        {
            delete mFocusedHoverResizedImage;
        }

        if (mSelectedNormalResizedImage)
        {
            delete mSelectedNormalResizedImage;
        }

        if (mSelectedHoverResizedImage)
        {
            delete mSelectedHoverResizedImage;
        }

        if (mSelectedPressedResizedImage)
        {
            delete mSelectedPressedResizedImage;
        }

        if (mSelectedFocusedResizedImage)
        {
            delete mSelectedFocusedResizedImage;
        }

        if (mSelectedFocusedHoverResizedImage)
        {
            delete mSelectedFocusedHoverResizedImage;
        }

        COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mNormalImage,               mWidth, mHeight, &mNormalResizedImage),               NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mHoverImage,                mWidth, mHeight, &mHoverResizedImage),                NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mPressedImage,              mWidth, mHeight, &mPressedResizedImage),              NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mFocusedImage,              mWidth, mHeight, &mFocusedResizedImage),              NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mFocusedHoverImage,         mWidth, mHeight, &mFocusedHoverResizedImage),         NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mSelectedNormalImage,       mWidth, mHeight, &mSelectedNormalResizedImage),       NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mSelectedHoverImage,        mWidth, mHeight, &mSelectedHoverResizedImage),        NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mSelectedPressedImage,      mWidth, mHeight, &mSelectedPressedResizedImage),      NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mSelectedFocusedImage,      mWidth, mHeight, &mSelectedFocusedResizedImage),      NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mSelectedFocusedHoverImage, mWidth, mHeight, &mSelectedFocusedHoverResizedImage), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus TabButton::repaint()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(mNormalResizedImage               != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mHoverResizedImage                != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mPressedResizedImage              != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mFocusedResizedImage              != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mFocusedHoverResizedImage         != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mSelectedNormalResizedImage       != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mSelectedHoverResizedImage        != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mSelectedPressedResizedImage      != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mSelectedFocusedResizedImage      != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mSelectedFocusedHoverResizedImage != nullptr, NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



    Image *image = nullptr;

    if (mSelected)
    {
        switch (mState)
        {
            case WidgetState::NORMAL:          mOwnResultImage = mSelectedNormalResizedImage;       image = mSelectedNormalImage;       break;
            case WidgetState::HOVERED:         mOwnResultImage = mSelectedHoverResizedImage;        image = mSelectedHoverImage;        break;
            case WidgetState::PRESSED:         mOwnResultImage = mSelectedPressedResizedImage;      image = mSelectedPressedImage;      break;
            case WidgetState::FOCUSED:         mOwnResultImage = mSelectedFocusedResizedImage;      image = mSelectedFocusedImage;      break;
            case WidgetState::FOCUSED_HOVERED: mOwnResultImage = mSelectedFocusedHoverResizedImage; image = mSelectedFocusedHoverImage; break;

            case WidgetState::NONE:
            case WidgetState::INACTIVE:
            case WidgetState::INACTIVE_HOVERED:
            {
                COMMON_LF(("Unexpected widget state: %u (%s)", mState, widgetStateToString(mState)));

                return NgosStatus::UNEXPECTED_BEHAVIOUR;
            }
            break;

            default:
            {
                COMMON_LF(("Unknown widget state: %u (%s)", mState, widgetStateToString(mState)));

                return NgosStatus::UNEXPECTED_BEHAVIOUR;
            }
            break;
        }
    }
    else
    {
        switch (mState)
        {
            case WidgetState::NORMAL:          mOwnResultImage = mNormalResizedImage;       image = mNormalImage;       break;
            case WidgetState::HOVERED:         mOwnResultImage = mHoverResizedImage;        image = mHoverImage;        break;
            case WidgetState::PRESSED:         mOwnResultImage = mPressedResizedImage;      image = mPressedImage;      break;
            case WidgetState::FOCUSED:         mOwnResultImage = mFocusedResizedImage;      image = mFocusedImage;      break;
            case WidgetState::FOCUSED_HOVERED: mOwnResultImage = mFocusedHoverResizedImage; image = mFocusedHoverImage; break;

            case WidgetState::NONE:
            case WidgetState::INACTIVE:
            case WidgetState::INACTIVE_HOVERED:
            {
                COMMON_LF(("Unexpected widget state: %u (%s)", mState, widgetStateToString(mState)));

                return NgosStatus::UNEXPECTED_BEHAVIOUR;
            }
            break;

            default:
            {
                COMMON_LF(("Unknown widget state: %u (%s)", mState, widgetStateToString(mState)));

                return NgosStatus::UNEXPECTED_BEHAVIOUR;
            }
            break;
        }
    }



    if (mResultImage)
    {
        delete mResultImage;
    }

    mResultImage = new Image(*mOwnResultImage);



    NinePatch *patch = image->getNinePatch();

    u16 paddingLeft;
    u16 paddingTop;
    u16 paddingRight;
    u16 paddingBottom;
    u64 allowedWidth;
    u64 allowedHeight;

    if (patch)
    {
        paddingLeft   = patch->getPaddingLeft();
        paddingTop    = patch->getPaddingTop();
        paddingRight  = patch->getPaddingRight();
        paddingBottom = patch->getPaddingBottom();

        allowedWidth  = mWidth  - paddingLeft - paddingRight;
        allowedHeight = mHeight - paddingTop  - paddingBottom;
    }
    else
    {
        paddingLeft   = 0;
        paddingTop    = 0;
        paddingRight  = 0;
        paddingBottom = 0;

        allowedWidth  = mWidth;
        allowedHeight = mHeight;
    }



    if (mLabelWidget)
    {
        allowedWidth >>= 2;
    }



    float scaleX = (float)allowedWidth  / mImageWidget->getImage()->getWidth();
    float scaleY = (float)allowedHeight / mImageWidget->getImage()->getHeight();

    float scale = MIN(scaleX, scaleY);

    u16 imageWidth  = mImageWidget->getImage()->getWidth()  * scale;
    u16 imageHeight = mImageWidget->getImage()->getHeight() * scale;

    COMMON_LVVV(("imageWidth = %u",  imageWidth));
    COMMON_LVVV(("imageHeight = %u", imageHeight));



    COMMON_ASSERT_EXECUTION(mImageWidget->lockUpdates(),                                                                                                    NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(mImageWidget->setPosition(paddingLeft + ((allowedWidth - imageWidth) >> 1), paddingTop + ((allowedHeight - imageHeight) >> 1)), NgosStatus::ASSERTION); // ">> 1" == "/ 2"
    COMMON_ASSERT_EXECUTION(mImageWidget->setSize(imageWidth, imageHeight),                                                                                 NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(mImageWidget->unlockUpdates(),                                                                                                  NgosStatus::ASSERTION);

    if (mBadgeWidget)
    {
        COMMON_ASSERT_EXECUTION(mBadgeWidget->lockUpdates(),                     NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(mBadgeWidget->setPosition(0, 0),                 NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(mBadgeWidget->setSize(mWidth >> 2, mWidth >> 2), NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(mBadgeWidget->unlockUpdates(),                   NgosStatus::ASSERTION);
    }

    if (mLabelWidget)
    {
        COMMON_ASSERT_EXECUTION(mLabelWidget->lockUpdates(),                                       NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(mLabelWidget->setPosition(paddingLeft + allowedWidth, paddingTop), NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(mLabelWidget->setSize(allowedWidth * 3, allowedHeight),            NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(mLabelWidget->unlockUpdates(),                                     NgosStatus::ASSERTION);
    }



    ListElement<Widget *> *element = mChildren.getHead();

    while (element)
    {
        Widget *widget = element->getData();

        COMMON_ASSERT_EXECUTION(drawWidget(widget, widget->getPositionX(), widget->getPositionY()), NgosStatus::ASSERTION);

        element = element->getNext();
    }



    COMMON_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus TabButton::onKeyboardEvent(const UefiInputKey &key)
{
    COMMON_LT((" | key = ..."));



    if (key.unicodeChar == KEY_ENTER)
    {
        if (mPressEventHandler)
        {
            return mPressEventHandler();
        }
    }



    return NgosStatus::NO_EFFECT;
}

bool TabButton::isAcceptMouseEvents()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return true;
}

NgosStatus TabButton::setState(WidgetState state)
{
    COMMON_LT((" | state = %u", state));



    if (mState != state)
    {
        mState = state;

        if (
            mWidth // mWidth > 0
            &&
            mHeight // mHeight > 0
           )
        {
            COMMON_ASSERT_EXECUTION(repaint(), NgosStatus::ASSERTION);

            if (isVisible())
            {
                COMMON_ASSERT_EXECUTION(update(), NgosStatus::ASSERTION);
            }
        }
    }



    return NgosStatus::OK;
}

WidgetState TabButton::getState() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mState;
}

NgosStatus TabButton::setSelected(bool selected)
{
    COMMON_LT((" | selected = %u", selected));



    if (mSelected != selected)
    {
        mSelected = selected;

        if (
            mWidth // mWidth > 0
            &&
            mHeight // mHeight > 0
           )
        {
            COMMON_ASSERT_EXECUTION(repaint(), NgosStatus::ASSERTION);

            if (isVisible())
            {
                COMMON_ASSERT_EXECUTION(update(), NgosStatus::ASSERTION);
            }
        }
    }



    return NgosStatus::OK;
}

bool TabButton::isSelected() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mSelected;
}

NgosStatus TabButton::setKeyboardEventHandler(keyboard_event_handler handler)
{
    COMMON_LT((" | handler = 0x%p", handler));



    mKeyboardEventHandler = handler;



    return NgosStatus::OK;
}

keyboard_event_handler TabButton::getKeyboardEventHandler() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mKeyboardEventHandler;
}

NgosStatus TabButton::setPressEventHandler(press_event_handler handler)
{
    COMMON_LT((" | handler = 0x%p", handler));



    mPressEventHandler = handler;



    return NgosStatus::OK;
}

press_event_handler TabButton::getPressEventHandler() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mPressEventHandler;
}
