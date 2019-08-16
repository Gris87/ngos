#include "cursorwidget.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



CursorWidget::CursorWidget(Image *cursorImage, Image *pointerImage, Widget *parent)
    : Widget(parent)
    , mCursorImage(cursorImage)
    , mPointerImage(pointerImage)
    , mCursorResizedImage(0)
    , mPointerResizedImage(0)
{
    COMMON_LT((" | cursorImage = 0x%p, pointerImage = 0x%p, parent = 0x%p", cursorImage, pointerImage, parent));

    COMMON_ASSERT(cursorImage,  "cursorImage is null");
    COMMON_ASSERT(pointerImage, "pointerImage is null");
}

CursorWidget::~CursorWidget()
{
    COMMON_LT((""));



    if (mCursorResizedImage)
    {
        COMMON_ASSERT_EXECUTION(free(mCursorResizedImage));
    }

    if (mPointerResizedImage)
    {
        COMMON_ASSERT_EXECUTION(free(mPointerResizedImage));
    }
}

NgosStatus CursorWidget::invalidate()
{
    COMMON_LT((""));



    COMMON_ASSERT_EXECUTION(Widget::invalidate(), NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mCursorResizedImage  == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mPointerResizedImage == 0, NgosStatus::ASSERTION);

    COMMON_ASSERT_EXECUTION(Graphics::resizeImageProportional(mCursorImage,  mWidth, mHeight, &mCursorResizedImage),  NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(Graphics::resizeImageProportional(mPointerImage, mWidth, mHeight, &mPointerResizedImage), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
