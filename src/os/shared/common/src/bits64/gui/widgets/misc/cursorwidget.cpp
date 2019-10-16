#include "cursorwidget.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



CursorWidget::CursorWidget(Image *cursorImage, Widget *parent)
    : Widget(parent)
    , mCursorImage(cursorImage)
    , mCursorResizedImage(nullptr)
{
    COMMON_LT((" | cursorImage = 0x%p, parent = 0x%p", cursorImage, parent));

    COMMON_ASSERT(cursorImage, "cursorImage is null");
    COMMON_ASSERT(parent,      "parent is null");
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



    if (mCursorResizedImage)
    {
        delete mCursorResizedImage;
    }

    COMMON_ASSERT_EXECUTION(Graphics::resizeImageProportional(mCursorImage, mWidth, mHeight, &mCursorResizedImage), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus CursorWidget::repaint()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(mCursorResizedImage != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mChildren.getHead() == nullptr, NgosStatus::ASSERTION);



    mOwnResultImage = mCursorResizedImage;
    mResultImage    = mOwnResultImage;



    return NgosStatus::OK;
}
