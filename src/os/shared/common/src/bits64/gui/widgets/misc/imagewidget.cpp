#include "imagewidget.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



ImageWidget::ImageWidget(Image *image, Widget *parent)
    : Widget(parent)
    , mImage(image)
{
    COMMON_LT((" | image = 0x%p, parent = 0x%p", image, parent));

    COMMON_ASSERT(image, "image is null");
}

ImageWidget::~ImageWidget()
{
    COMMON_LT((""));
}
