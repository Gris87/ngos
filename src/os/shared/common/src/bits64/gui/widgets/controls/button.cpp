#include "button.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/gui/gui.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/utils.h>



Button::Button(Image *normalImage, Image *hoverImage, Image *pressedImage, Image *focusedImage, Image *focusedHoverImage, Image *contentImage, Image *badgeImage, const char8 *text, Widget *parent)
    : Widget(parent)
    , mNormalImage(normalImage)
    , mHoverImage(hoverImage)
    , mPressedImage(pressedImage)
    , mFocusedImage(focusedImage)
    , mFocusedHoverImage(focusedHoverImage)
    , mNormalResizedImage(nullptr)
    , mHoverResizedImage(nullptr)
    , mPressedResizedImage(nullptr)
    , mFocusedResizedImage(nullptr)
    , mFocusedHoverResizedImage(nullptr)
    , mImageWidget(new ImageWidget(contentImage, this))
    , mBadgeWidget(nullptr)
    , mLabelWidget(nullptr)
    , mState(WidgetState::NORMAL)
    , mPredefined(false)
    , mKeyboardEventHandler(nullptr)
    , mPressEventHandler(nullptr)
    , mPressEventHandlerObject(nullptr)
{
    COMMON_LT((" | normalImage = 0x%p, hoverImage = 0x%p, pressedImage = 0x%p, focusedImage = 0x%p, focusedHoverImage = 0x%p, contentImage = 0x%p, badgeImage = 0x%p, text = 0x%p, parent = 0x%p", normalImage, hoverImage, pressedImage, focusedImage, focusedHoverImage, contentImage, badgeImage, text, parent));

    COMMON_ASSERT(normalImage,       "normalImage is null");
    COMMON_ASSERT(hoverImage,        "hoverImage is null");
    COMMON_ASSERT(pressedImage,      "pressedImage is null");
    COMMON_ASSERT(focusedImage,      "focusedImage is null");
    COMMON_ASSERT(focusedHoverImage, "focusedHoverImage is null");
    COMMON_ASSERT(contentImage,      "contentImage is null");
    COMMON_ASSERT(parent,            "parent is null");



    if (badgeImage)
    {
        mBadgeWidget = new ImageWidget(badgeImage, this);
    }

    if (text && *text)
    {
        mLabelWidget = new LabelWidget(text, this);
    }
}

Button::Button(Image *normalImage, Image *hoverImage, Image *pressedImage, Image *focusedImage, Image *focusedHoverImage, Image *normalResizedImage, Image *hoverResizedImage, Image *pressedResizedImage, Image *focusedResizedImage, Image *focusedHoverResizedImage, Image *contentImage, Image *badgeImage, const char8 *text, Widget *parent)
    : Widget(parent)
    , mNormalImage(normalImage)
    , mHoverImage(hoverImage)
    , mPressedImage(pressedImage)
    , mFocusedImage(focusedImage)
    , mFocusedHoverImage(focusedHoverImage)
    , mNormalResizedImage(normalResizedImage)
    , mHoverResizedImage(hoverResizedImage)
    , mPressedResizedImage(pressedResizedImage)
    , mFocusedResizedImage(focusedResizedImage)
    , mFocusedHoverResizedImage(focusedHoverResizedImage)
    , mImageWidget(new ImageWidget(contentImage, this))
    , mBadgeWidget(nullptr)
    , mLabelWidget(nullptr)
    , mState(WidgetState::NORMAL)
    , mPredefined(true)
    , mKeyboardEventHandler(nullptr)
    , mPressEventHandler(nullptr)
    , mPressEventHandlerObject(nullptr)
{
    COMMON_LT((" | normalImage = 0x%p, hoverImage = 0x%p, pressedImage = 0x%p, focusedImage = 0x%p, focusedHoverImage = 0x%p, normalResizedImage = 0x%p, hoverResizedImage = 0x%p, pressedResizedImage = 0x%p, focusedResizedImage = 0x%p, focusedHoverResizedImage = 0x%p, contentImage = 0x%p, badgeImage = 0x%p, text = 0x%p, parent = 0x%p", normalImage, hoverImage, pressedImage, focusedImage, focusedHoverImage, normalResizedImage, hoverResizedImage, pressedResizedImage, focusedResizedImage, focusedHoverResizedImage, contentImage, badgeImage, text, parent));

    COMMON_ASSERT(normalImage,              "normalImage is null");
    COMMON_ASSERT(hoverImage,               "hoverImage is null");
    COMMON_ASSERT(pressedImage,             "pressedImage is null");
    COMMON_ASSERT(focusedImage,             "focusedImage is null");
    COMMON_ASSERT(focusedHoverImage,        "focusedHoverImage is null");
    COMMON_ASSERT(normalResizedImage,       "normalResizedImage is null");
    COMMON_ASSERT(hoverResizedImage,        "hoverResizedImage is null");
    COMMON_ASSERT(pressedResizedImage,      "pressedResizedImage is null");
    COMMON_ASSERT(focusedResizedImage,      "focusedResizedImage is null");
    COMMON_ASSERT(focusedHoverResizedImage, "focusedHoverResizedImage is null");
    COMMON_ASSERT(contentImage,             "contentImage is null");
    COMMON_ASSERT(parent,                   "parent is null");



    if (badgeImage)
    {
        mBadgeWidget = new ImageWidget(badgeImage, this);
    }

    if (text && *text)
    {
        mLabelWidget = new LabelWidget(text, this);
    }
}

Button::~Button()
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
    }



    if (mResultImage)
    {
        delete mResultImage;
    }
}

NgosStatus Button::invalidate()
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

        COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mNormalImage,       mWidth, mHeight, &mNormalResizedImage),       NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mHoverImage,        mWidth, mHeight, &mHoverResizedImage),        NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mPressedImage,      mWidth, mHeight, &mPressedResizedImage),      NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mFocusedImage,      mWidth, mHeight, &mFocusedResizedImage),      NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mFocusedHoverImage, mWidth, mHeight, &mFocusedHoverResizedImage), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus Button::repaint()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(mNormalResizedImage       != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mHoverResizedImage        != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mPressedResizedImage      != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mFocusedResizedImage      != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mFocusedHoverResizedImage != nullptr, NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



    Image *image = nullptr;

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
            COMMON_LF(("Unexpected widget state: %s, %s:%u", enumToFullString(mState), __FILE__, __LINE__));

            return NgosStatus::UNEXPECTED_BEHAVIOUR;
        }
        break;

        default:
        {
            COMMON_LF(("Unknown widget state: %s, %s:%u", enumToFullString(mState), __FILE__, __LINE__));

            return NgosStatus::UNEXPECTED_BEHAVIOUR;
        }
        break;
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

    COMMON_LVVV(("imageWidth  = %u", imageWidth));
    COMMON_LVVV(("imageHeight = %u", imageHeight));



    COMMON_ASSERT_EXECUTION(mImageWidget->lockUpdates(),                                                                                              NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(mImageWidget->setPosition(paddingLeft + (allowedWidth - imageWidth) / 2, paddingTop + (allowedHeight - imageHeight) / 2), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(mImageWidget->setSize(imageWidth, imageHeight),                                                                           NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(mImageWidget->unlockUpdates(),                                                                                            NgosStatus::ASSERTION);

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

NgosStatus Button::onKeyboardEvent(const UefiInputKey &key)
{
    COMMON_LT((" | key = ..."));



    if (key.unicodeChar == KEY_ENTER)
    {
        if (mPressEventHandler)
        {
            return mPressEventHandler();
        }
        else
        if (mPressEventHandlerObject)
        {
            return mPressEventHandlerObject->onWidgetPressed(this);
        }
    }



    return NgosStatus::NO_EFFECT;
}

bool Button::isAcceptMouseEvents()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return true;
}

bool Button::isFocusable()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return true;
}

NgosStatus Button::setContentImage(Image *contentImage)
{
    COMMON_LT((" | contentImage = %u", contentImage));

    COMMON_ASSERT(contentImage, "contentImage is null", NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(mImageWidget->setImage(contentImage), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus Button::setText(const char8 *text)
{
    COMMON_LT((" | text = 0x%p", text));

    COMMON_ASSERT(text,  "text is null",  NgosStatus::ASSERTION);
    COMMON_ASSERT(*text, "text is empty", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mLabelWidget != nullptr, NgosStatus::ASSERTION);

    COMMON_ASSERT_EXECUTION(mLabelWidget->setText(text), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus Button::setPredefined(bool predefined)
{
    COMMON_LT((" | predefined = %u", predefined));



    mPredefined = predefined;



    return NgosStatus::OK;
}

NgosStatus Button::setState(WidgetState state)
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

WidgetState Button::getState() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mState;
}

NgosStatus Button::setKeyboardEventHandler(keyboard_event_handler handler)
{
    COMMON_LT((" | handler = 0x%p", handler));



    mKeyboardEventHandler = handler;



    return NgosStatus::OK;
}

keyboard_event_handler Button::getKeyboardEventHandler() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mKeyboardEventHandler;
}

NgosStatus Button::setPressEventHandler(press_event_handler handler)
{
    COMMON_LT((" | handler = 0x%p", handler));



    mPressEventHandler = handler;



    return NgosStatus::OK;
}

press_event_handler Button::getPressEventHandler() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mPressEventHandler;
}

NgosStatus Button::setPressEventHandlerObject(PressEventHandler *handler)
{
    COMMON_LT((" | handler = 0x%p", handler));



    mPressEventHandlerObject = handler;



    return NgosStatus::OK;
}

PressEventHandler* Button::getPressEventHandlerObject() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mPressEventHandlerObject;
}
