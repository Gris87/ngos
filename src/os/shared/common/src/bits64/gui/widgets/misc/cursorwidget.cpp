#include "cursorwidget.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



CursorWidget::CursorWidget(Image *cursorImage, Image *pointerImage, Widget *parent)
    : Widget(parent)
    , mCursorImage(cursorImage)
    , mPointerImage(pointerImage)
{
    COMMON_LT((" | cursorImage = 0x%p, pointerImage = 0x%p, parent = 0x%p", cursorImage, pointerImage, parent));

    COMMON_ASSERT(cursorImage,  "cursorImage is null");
    COMMON_ASSERT(pointerImage, "pointerImage is null");
}

CursorWidget::~CursorWidget()
{
    COMMON_LT((""));
}
