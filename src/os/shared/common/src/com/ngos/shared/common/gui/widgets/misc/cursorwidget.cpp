#include "cursorwidget.h"

#include <com/ngos/shared/common/graphics/graphics.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>



CursorWidget::CursorWidget(Image *cursorImage, Widget *parent)
    : Widget(parent)
    , mCursorImage(cursorImage)
{
    COMMON_LT((" | cursorImage = 0x%p, parent = 0x%p", cursorImage, parent));

    COMMON_ASSERT(cursorImage, "cursorImage is null");
    COMMON_ASSERT(parent,      "parent is null");
}

CursorWidget::~CursorWidget()
{
    COMMON_LT((""));



    if (mResultImage)
    {
        delete mResultImage;
    }
}

NgosStatus CursorWidget::invalidate()
{
    COMMON_LT((""));



    if (mOwnResultImage)
    {
        delete mOwnResultImage;
    }

    COMMON_ASSERT_EXECUTION(Graphics::resizeImageProportional(mCursorImage, mWidth, mHeight, &mOwnResultImage), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus CursorWidget::repaint()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(mOwnResultImage     != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mChildren.getHead() == nullptr, NgosStatus::ASSERTION);



    mResultImage = mOwnResultImage;



    return NgosStatus::OK;
}
