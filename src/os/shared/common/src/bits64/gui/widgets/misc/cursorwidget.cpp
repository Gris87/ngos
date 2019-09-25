#include "cursorwidget.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



CursorWidget::CursorWidget(Image *cursorImage, Widget *parent)
    : Widget(parent)
    , mCursorImage(cursorImage)
    , mCursorResizedImage(0)
{
    COMMON_LT((" | cursorImage = 0x%p, parent = 0x%p", cursorImage, parent));

    COMMON_ASSERT(cursorImage, "cursorImage is null");
}

CursorWidget::~CursorWidget()
{
    COMMON_LT((""));



    if (mCursorResizedImage)
    {
        delete mCursorResizedImage;
    }
}

NgosStatus CursorWidget::invalidate()
{
    COMMON_LT((""));



    COMMON_ASSERT_EXECUTION(Widget::invalidate(), NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mCursorResizedImage  == 0, NgosStatus::ASSERTION);

    COMMON_ASSERT_EXECUTION(Graphics::resizeImageProportional(mCursorImage, mWidth, mHeight, &mCursorResizedImage), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus CursorWidget::repaint()
{
    COMMON_LT((""));



    COMMON_ASSERT_EXECUTION(Widget::repaint(), NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mCursorResizedImage != 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mChildren.getHead() == 0, NgosStatus::ASSERTION);



    mResultImage = mCursorResizedImage;



    return NgosStatus::OK;
}
