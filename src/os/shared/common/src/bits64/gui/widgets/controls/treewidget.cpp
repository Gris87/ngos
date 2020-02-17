#include "treewidget.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



TreeWidget::TreeWidget(Widget *parent)
    : Widget(parent)
{
    COMMON_LT((" | parent = 0x%p", parent));

    COMMON_ASSERT(parent, "parent is null");
}

TreeWidget::~TreeWidget()
{
    COMMON_LT((""));



    if (mResultImage)
    {
        delete mResultImage;
    }
}

NgosStatus TreeWidget::invalidate()
{
    COMMON_LT((""));



    if (mOwnResultImage)
    {
        delete mOwnResultImage;
    }

    RgbaPixel pixel;

    pixel.red   = 0;
    pixel.green = 0;
    pixel.blue  = 255;
    pixel.alpha = 255;

    mOwnResultImage = new Image(mWidth, mHeight, false, true);
    mOwnResultImage->fill(pixel);



    return NgosStatus::OK;
}

NgosStatus TreeWidget::repaint()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(mOwnResultImage     != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mChildren.getHead() == nullptr, NgosStatus::ASSERTION);



    mResultImage = mOwnResultImage;




    return NgosStatus::OK;
}
