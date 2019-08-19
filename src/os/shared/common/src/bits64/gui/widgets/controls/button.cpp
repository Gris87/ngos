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
        COMMON_ASSERT_EXECUTION(free(mNormalResizedImage));
    }

    if (mHoverResizedImage)
    {
        COMMON_ASSERT_EXECUTION(free(mHoverResizedImage));
    }

    if (mPressedResizedImage)
    {
        COMMON_ASSERT_EXECUTION(free(mPressedResizedImage));
    }

    if (mFocusedResizedImage)
    {
        COMMON_ASSERT_EXECUTION(free(mFocusedResizedImage));
    }

    if (mResultImage)
    {
        COMMON_ASSERT_EXECUTION(free(mResultImage));
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



    if (mResultImage)
    {
        COMMON_ASSERT_EXECUTION(free(mResultImage), NgosStatus::ASSERTION);
    }



    COMMON_ASSERT_EXECUTION(Graphics::cloneImage(mNormalResizedImage, &mResultImage),                              NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(Graphics::insertImage(mContentImage, mResultImage, 10, 10, mWidth - 10, mHeight - 10), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
