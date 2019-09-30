#include "imagewidget.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



ImageWidget::ImageWidget(Image *image, Widget *parent)
    : Widget(parent)
    , mImage(image)
    , mResizedImage(0)
{
    COMMON_LT((" | image = 0x%p, parent = 0x%p", image, parent));

    COMMON_ASSERT(image, "image is null");
}

ImageWidget::~ImageWidget()
{
    COMMON_LT((""));



    if (mResizedImage)
    {
        delete mResizedImage;
    }
}

NgosStatus ImageWidget::invalidate()
{
    COMMON_LT((""));



    if (mResizedImage)
    {
        delete mResizedImage;
    }

    COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mImage, mWidth, mHeight, &mResizedImage), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus ImageWidget::repaint()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(mResizedImage       != 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mChildren.getHead() == 0, NgosStatus::ASSERTION);



    mOwnResultImage = mResizedImage;
    mResultImage    = mOwnResultImage;



    return NgosStatus::OK;
}

Image* ImageWidget::getImage() const
{
    COMMON_LT((""));



    return mImage;
}
