#include "button.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



Button::Button(Image *normalImage, Image *hoverImage, Image *pressedImage, Image *focusedImage, Image *contentImage, Widget *parent)
    : Widget(parent)
    , mNormalImage(normalImage)
    , mHoverImage(hoverImage)
    , mPressedImage(pressedImage)
    , mFocusedImage(focusedImage)
    , mContentImage(contentImage)
    , mNormalResizedImage(0)
    , mHoverResizedImage(0)
    , mPressedResizedImage(0)
    , mFocusedResizedImage(0)
    , mState(WidgetState::NORMAL)
    , mKeyboardEventHandler(0)
    , mPressEventHandler(0)
{
    COMMON_LT((" | normalImage = 0x%p, hoverImage = 0x%p, pressedImage = 0x%p, focusedImage = 0x%p, contentImage = 0x%p, parent = 0x%p", normalImage, hoverImage, pressedImage, focusedImage, contentImage, parent));

    COMMON_ASSERT(normalImage,  "normalImage is null");
    COMMON_ASSERT(hoverImage,   "hoverImage is null");
    COMMON_ASSERT(pressedImage, "pressedImage is null");
    COMMON_ASSERT(focusedImage, "focusedImage is null");
    COMMON_ASSERT(contentImage, "contentImage is null");
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



    COMMON_ASSERT_EXECUTION(Widget::invalidate(), NgosStatus::ASSERTION);



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



    COMMON_ASSERT_EXECUTION(Widget::repaint(), NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mNormalResizedImage  != 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mHoverResizedImage   != 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mPressedResizedImage != 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mFocusedResizedImage != 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mChildren.getHead()  == 0, NgosStatus::ASSERTION);



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



    u16 paddingLeft   = 0;
    u16 paddingTop    = 0;
    u16 paddingRight  = 0;
    u16 paddingBottom = 0;



    NinePatch *patch = image->getNinePatch();

    if (patch)
    {
        paddingLeft   = patch->getPaddingLeft();
        paddingTop    = patch->getPaddingTop();
        paddingRight  = patch->getPaddingRight();
        paddingBottom = patch->getPaddingBottom();
    }



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



    return NgosStatus::OK;
}

NgosStatus Button::setState(WidgetState state)
{
    COMMON_LT((" | state = %u", state));



    if (mState != state)
    {
        mState = state;

        repaint();
        update();
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
