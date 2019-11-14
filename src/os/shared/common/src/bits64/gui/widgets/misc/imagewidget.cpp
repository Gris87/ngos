#include "imagewidget.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



ImageWidget::ImageWidget(Image *image, Widget *parent)
    : Widget(parent)
    , mImage(image)
{
    COMMON_LT((" | image = 0x%p, parent = 0x%p", image, parent));

    COMMON_ASSERT(image,  "image is null");
    COMMON_ASSERT(parent, "parent is null");
}

ImageWidget::~ImageWidget()
{
    COMMON_LT((""));



    if (mResultImage)
    {
        delete mResultImage;
    }
}

NgosStatus ImageWidget::invalidate()
{
    COMMON_LT((""));



    if (mOwnResultImage)
    {
        delete mOwnResultImage;
    }

    COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mImage, mWidth, mHeight, &mOwnResultImage), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus ImageWidget::repaint()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(mOwnResultImage     != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mChildren.getHead() == nullptr, NgosStatus::ASSERTION);



    mResultImage = mOwnResultImage;



    return NgosStatus::OK;
}

NgosStatus ImageWidget::setImage(Image *image)
{
    COMMON_LT((" | image = %u", image));

    COMMON_ASSERT(image, "image is null", NgosStatus::ASSERTION);



    mImage = image;

    if (
        mWidth // mWidth > 0
        &&
        mHeight // mHeight > 0
       )
    {
        COMMON_ASSERT_EXECUTION(invalidate(), NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(repaint(),    NgosStatus::ASSERTION);

        if (isVisible())
        {
            COMMON_ASSERT_EXECUTION(update(), NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

Image* ImageWidget::getImage() const
{
    COMMON_LT((""));



    return mImage;
}
