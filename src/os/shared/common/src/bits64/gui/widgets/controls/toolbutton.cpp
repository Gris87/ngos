#include "toolbutton.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/gui/gui.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/utils.h>



ToolButton::ToolButton(Image *normalImage, Image *hoverImage, Image *pressedImage, Image *contentImage, Image *badgeImage, const char8 *text, Widget *parent)
    : Widget(parent)
    , mNormalImage(normalImage)
    , mHoverImage(hoverImage)
    , mPressedImage(pressedImage)
    , mNormalResizedImage(nullptr)
    , mHoverResizedImage(nullptr)
    , mPressedResizedImage(nullptr)
    , mImageWidget(new ImageWidget(contentImage, this))
    , mBadgeWidget(nullptr)
    , mLabelWidget(nullptr)
    , mState(WidgetState::NORMAL)
    , mPredefined(false)
    , mKeyboardEventHandler(nullptr)
    , mPressEventHandler(nullptr)
{
    COMMON_LT((" | normalImage = 0x%p, hoverImage = 0x%p, pressedImage = 0x%p, contentImage = 0x%p, badgeImage = 0x%p, text = 0x%p, parent = 0x%p", normalImage, hoverImage, pressedImage, contentImage, badgeImage, text, parent));

    COMMON_ASSERT(normalImage,  "normalImage is null");
    COMMON_ASSERT(hoverImage,   "hoverImage is null");
    COMMON_ASSERT(pressedImage, "pressedImage is null");
    COMMON_ASSERT(contentImage, "contentImage is null");
    COMMON_ASSERT(parent,       "parent is null");



    if (badgeImage)
    {
        mBadgeWidget = new ImageWidget(badgeImage, this);
    }

    if (text && *text)
    {
        mLabelWidget = new LabelWidget(text, this);
    }
}

ToolButton::ToolButton(Image *normalImage, Image *hoverImage, Image *pressedImage, Image *normalResizedImage, Image *hoverResizedImage, Image *pressedResizedImage, Image *contentImage, Image *badgeImage, const char8 *text, Widget *parent)
    : Widget(parent)
    , mNormalImage(normalImage)
    , mHoverImage(hoverImage)
    , mPressedImage(pressedImage)
    , mNormalResizedImage(normalResizedImage)
    , mHoverResizedImage(hoverResizedImage)
    , mPressedResizedImage(pressedResizedImage)
    , mImageWidget(new ImageWidget(contentImage, this))
    , mBadgeWidget(nullptr)
    , mLabelWidget(nullptr)
    , mState(WidgetState::NORMAL)
    , mPredefined(true)
    , mKeyboardEventHandler(nullptr)
    , mPressEventHandler(nullptr)
{
    COMMON_LT((" | normalImage = 0x%p, hoverImage = 0x%p, pressedImage = 0x%p, normalResizedImage = 0x%p, hoverResizedImage = 0x%p, pressedResizedImage = 0x%p, contentImage = 0x%p, badgeImage = 0x%p, text = 0x%p, parent = 0x%p", normalImage, hoverImage, pressedImage, normalResizedImage, hoverResizedImage, pressedResizedImage, contentImage, badgeImage, text, parent));

    COMMON_ASSERT(normalImage,         "normalImage is null");
    COMMON_ASSERT(hoverImage,          "hoverImage is null");
    COMMON_ASSERT(pressedImage,        "pressedImage is null");
    COMMON_ASSERT(normalResizedImage,  "normalResizedImage is null");
    COMMON_ASSERT(hoverResizedImage,   "hoverResizedImage is null");
    COMMON_ASSERT(pressedResizedImage, "pressedResizedImage is null");
    COMMON_ASSERT(contentImage,        "contentImage is null");
    COMMON_ASSERT(parent,              "parent is null");



    if (badgeImage)
    {
        mBadgeWidget = new ImageWidget(badgeImage, this);
    }

    if (text && *text)
    {
        mLabelWidget = new LabelWidget(text, this);
    }
}

ToolButton::~ToolButton()
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
    }



    if (mResultImage)
    {
        delete mResultImage;
    }
}

NgosStatus ToolButton::invalidate()
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

        COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mNormalImage,  mWidth, mHeight, &mNormalResizedImage),  NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mHoverImage,   mWidth, mHeight, &mHoverResizedImage),   NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mPressedImage, mWidth, mHeight, &mPressedResizedImage), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus ToolButton::repaint()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(mNormalResizedImage  != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mHoverResizedImage   != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mPressedResizedImage != nullptr, NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



    Image *image = nullptr;

    switch (mState)
    {
        case WidgetState::NORMAL:  mOwnResultImage = mNormalResizedImage;  image = mNormalImage;  break;
        case WidgetState::HOVERED: mOwnResultImage = mHoverResizedImage;   image = mHoverImage;   break;
        case WidgetState::PRESSED: mOwnResultImage = mPressedResizedImage; image = mPressedImage; break;

        case WidgetState::NONE:
        case WidgetState::FOCUSED:
        case WidgetState::FOCUSED_HOVERED:
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

NgosStatus ToolButton::onKeyboardEvent(const UefiInputKey &key)
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

bool ToolButton::isAcceptMouseEvents()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return true;
}

NgosStatus ToolButton::setContentImage(Image *contentImage)
{
    COMMON_LT((" | contentImage = %u", contentImage));

    COMMON_ASSERT(contentImage, "contentImage is null", NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(mImageWidget->setImage(contentImage), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus ToolButton::setText(const char8 *text)
{
    COMMON_LT((" | text = 0x%p", text));

    COMMON_ASSERT(text,  "text is null",  NgosStatus::ASSERTION);
    COMMON_ASSERT(*text, "text is empty", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mLabelWidget != nullptr, NgosStatus::ASSERTION);

    COMMON_ASSERT_EXECUTION(mLabelWidget->setText(text), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus ToolButton::setPredefined(bool predefined)
{
    COMMON_LT((" | predefined = %u", predefined));



    mPredefined = predefined;



    return NgosStatus::OK;
}

NgosStatus ToolButton::setState(WidgetState state)
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

WidgetState ToolButton::getState() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mState;
}

NgosStatus ToolButton::setKeyboardEventHandler(keyboard_event_handler handler)
{
    COMMON_LT((" | handler = 0x%p", handler));



    mKeyboardEventHandler = handler;



    return NgosStatus::OK;
}

keyboard_event_handler ToolButton::getKeyboardEventHandler() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mKeyboardEventHandler;
}

NgosStatus ToolButton::setPressEventHandler(press_event_handler handler)
{
    COMMON_LT((" | handler = 0x%p", handler));



    mPressEventHandler = handler;



    return NgosStatus::OK;
}

press_event_handler ToolButton::getPressEventHandler() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mPressEventHandler;
}
