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



    COMMON_TEST_ASSERT(mNormalResizedImage  == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mHoverResizedImage   == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mPressedResizedImage == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mFocusedResizedImage == 0, NgosStatus::ASSERTION);

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



    COMMON_TEST_ASSERT(mNormalResizedImage  != 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mHoverResizedImage   != 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mPressedResizedImage != 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mFocusedResizedImage != 0, NgosStatus::ASSERTION);



    Image *image = 0;

    if (mResultImage)
    {
        delete mResultImage;
    }

    switch (mState)
    {
        case WidgetState::NORMAL:  mResultImage = new Image(*mNormalResizedImage);  image = mNormalImage;  break;
        case WidgetState::HOVERED: mResultImage = new Image(*mHoverResizedImage);   image = mHoverImage;   break;
        case WidgetState::PRESSED: mResultImage = new Image(*mPressedResizedImage); image = mPressedImage; break;
        case WidgetState::FOCUSED: mResultImage = new Image(*mFocusedResizedImage); image = mFocusedImage; break;

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



    mImageWidget->setPosition(paddingLeft + ((allowedWidth - imageWidth) >> 1), paddingTop + ((allowedWidth - imageWidth) >> 1)); // ">> 1" == "/ 2"
    mImageWidget->setSize(imageWidth, imageHeight);

    if (mLabelWidget)
    {
        mLabelWidget->setPosition(paddingLeft + allowedWidth, paddingTop);
        mLabelWidget->setSize(allowedWidth << 2, allowedHeight); // "<< 2" == "* 4"
    }

/*

    Image *contentResizedImage;

    COMMON_ASSERT_EXECUTION(Graphics::resizeImageProportional(
                                mContentImage,
                                mWidth - paddingLeft - paddingRight,
                                mHeight - paddingTop - paddingBottom,
                                &contentResizedImage),
                            NgosStatus::ASSERTION);

    COMMON_ASSERT_EXECUTION(Graphics::insertImageRaw(
                                contentResizedImage->getBuffer(),
                                mResultImage->getBuffer(),
                                contentResizedImage->getWidth(),
                                contentResizedImage->getHeight(),
                                mResultImage->getWidth(),
                                mResultImage->getHeight(),
                                contentResizedImage->getBytesPerPixel(),
                                mResultImage->getBytesPerPixel(),
                                contentResizedImage->isOpaque() && mResultImage->isOpaque(),
                                (mResultImage->getWidth() - contentResizedImage->getWidth()) >> 1,
                                (mResultImage->getHeight() - contentResizedImage->getHeight()) >> 1),
                            NgosStatus::ASSERTION);

    delete contentResizedImage;
    */



    COMMON_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
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
