#include "button.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/gui/gui.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/utils.h>



Button::Button(Image *normalImage, Image *hoverImage, Image *pressedImage, Image *focusedImage, Image *contentImage, const char8 *text, Widget *parent)
    : Widget(parent)
    , mNormalImage(normalImage)
    , mHoverImage(hoverImage)
    , mPressedImage(pressedImage)
    , mFocusedImage(focusedImage)
    , mNormalResizedImage(0)
    , mHoverResizedImage(0)
    , mPressedResizedImage(0)
    , mFocusedResizedImage(0)
    , mImageWidget(new ImageWidget(contentImage, this))
    , mLabelWidget(0)
    , mState(WidgetState::NORMAL)
    , mKeyboardEventHandler(0)
    , mPressEventHandler(0)
{
    COMMON_LT((" | normalImage = 0x%p, hoverImage = 0x%p, pressedImage = 0x%p, focusedImage = 0x%p, contentImage = 0x%p, text = 0x%p, parent = 0x%p", normalImage, hoverImage, pressedImage, focusedImage, contentImage, text, parent));

    COMMON_ASSERT(normalImage,  "normalImage is null");
    COMMON_ASSERT(hoverImage,   "hoverImage is null");
    COMMON_ASSERT(pressedImage, "pressedImage is null");
    COMMON_ASSERT(focusedImage, "focusedImage is null");
    COMMON_ASSERT(contentImage, "contentImage is null");



    if (text && *text)
    {
        mLabelWidget = new LabelWidget(text, this);
    }
}

Button::~Button()
{
    COMMON_LT((""));



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

    if (mResultImage)
    {
        delete mResultImage;
    }
}

NgosStatus Button::invalidate()
{
    COMMON_LT((""));



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

    COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mNormalImage,  mWidth, mHeight, &mNormalResizedImage),  NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mHoverImage,   mWidth, mHeight, &mHoverResizedImage),   NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mPressedImage, mWidth, mHeight, &mPressedResizedImage), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mFocusedImage, mWidth, mHeight, &mFocusedResizedImage), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus Button::repaint()
{
    COMMON_LT((""));



    COMMON_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mNormalResizedImage  != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mHoverResizedImage   != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mPressedResizedImage != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mFocusedResizedImage != nullptr, NgosStatus::ASSERTION);



    Image *image = nullptr;

    switch (mState)
    {
        case WidgetState::NORMAL:  mOwnResultImage = mNormalResizedImage;  image = mNormalImage;  break;
        case WidgetState::HOVERED: mOwnResultImage = mHoverResizedImage;   image = mHoverImage;   break;
        case WidgetState::PRESSED: mOwnResultImage = mPressedResizedImage; image = mPressedImage; break;
        case WidgetState::FOCUSED: mOwnResultImage = mFocusedResizedImage; image = mFocusedImage; break;

        case WidgetState::NONE:
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
        allowedWidth /= 5;
    }



    float scaleX = (float)allowedWidth  / mImageWidget->getImage()->getWidth();
    float scaleY = (float)allowedHeight / mImageWidget->getImage()->getHeight();

    float scale = MIN(scaleX, scaleY);

    u16 imageWidth  = mImageWidget->getImage()->getWidth()  * scale;
    u16 imageHeight = mImageWidget->getImage()->getHeight() * scale;



    COMMON_ASSERT_EXECUTION(mImageWidget->setPosition(paddingLeft + ((allowedWidth - imageWidth) >> 1), paddingTop + ((allowedWidth - imageWidth) >> 1)), NgosStatus::ASSERTION); // ">> 1" == "/ 2"
    COMMON_ASSERT_EXECUTION(mImageWidget->setSize(imageWidth, imageHeight),                                                                               NgosStatus::ASSERTION);

    if (mLabelWidget)
    {
        COMMON_ASSERT_EXECUTION(mLabelWidget->setPosition(paddingLeft + allowedWidth, paddingTop), NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(mLabelWidget->setSize(allowedWidth << 2, allowedHeight),           NgosStatus::ASSERTION); // "<< 2" == "* 4"
    }



    Image *imageResult = mImageWidget->getResultImage();

    COMMON_ASSERT_EXECUTION(Graphics::insertImageRaw(
                                imageResult->getBuffer(),
                                mResultImage->getBuffer(),
                                imageResult->getWidth(),
                                imageResult->getHeight(),
                                mResultImage->getWidth(),
                                mResultImage->getHeight(),
                                imageResult->getBytesPerPixel(),
                                mResultImage->getBytesPerPixel(),
                                imageResult->isOpaque() && mResultImage->isOpaque(),
                                mImageWidget->getPositionX(),
                                mImageWidget->getPositionY()),
                            NgosStatus::ASSERTION);

    if (mLabelWidget)
    {
        imageResult = mLabelWidget->getResultImage();

        COMMON_ASSERT_EXECUTION(Graphics::insertImageRaw(
                                    imageResult->getBuffer(),
                                    mResultImage->getBuffer(),
                                    imageResult->getWidth(),
                                    imageResult->getHeight(),
                                    mResultImage->getWidth(),
                                    mResultImage->getHeight(),
                                    imageResult->getBytesPerPixel(),
                                    mResultImage->getBytesPerPixel(),
                                    imageResult->isOpaque() && mResultImage->isOpaque(),
                                    mLabelWidget->getPositionX(),
                                    mLabelWidget->getPositionY()),
                                NgosStatus::ASSERTION);
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
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus Button::setState(WidgetState state)
{
    COMMON_LT((" | state = %u", state));



    if (mState != state)
    {
        mState = state;

        COMMON_ASSERT_EXECUTION(repaint(), NgosStatus::ASSERTION);

        if (isVisible())
        {
            COMMON_ASSERT_EXECUTION(update(),  NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

WidgetState Button::getState() const
{
    COMMON_LT((""));



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
    COMMON_LT((""));



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
    COMMON_LT((""));



    return mPressEventHandler;
}
