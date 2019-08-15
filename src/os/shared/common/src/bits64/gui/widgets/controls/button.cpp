#include "button.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



Button::Button(Image *normalImage, Image *hoverImage, Image *pressedImage, Image *focusedImage, Image *contentImage, Widget *parent)
    : Widget(parent)
    , mNormalImage(normalImage)
    , mHoverImage(hoverImage)
    , mPressedImage(pressedImage)
    , mFocusedImage(focusedImage)
    , mContentImage(contentImage)
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
}
