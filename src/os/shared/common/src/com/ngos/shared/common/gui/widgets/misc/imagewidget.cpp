#include "imagewidget.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



ImageWidget::ImageWidget(Image *image, Widget *parent)
    : Widget(parent)
    , mImage(image)
    , mPredefined(false)
{
    COMMON_LT((" | image = 0x%p, parent = 0x%p", image, parent));

    COMMON_ASSERT(image,  "image is null");
    COMMON_ASSERT(parent, "parent is null");
}

ImageWidget::ImageWidget(Image *image, Image *resizedImage, Widget *parent)
    : Widget(parent)
    , mImage(image)
    , mPredefined(true)
{
    COMMON_LT((" | image = 0x%p, resizedImage = 0x%p, parent = 0x%p", image, resizedImage, parent));

    COMMON_ASSERT(image,        "image is null");
    COMMON_ASSERT(resizedImage, "resizedImage is null");
    COMMON_ASSERT(parent,       "parent is null");



    mOwnResultImage = resizedImage;
}

ImageWidget::~ImageWidget()
{
    COMMON_LT((""));



    if (!mPredefined)
    {
        if (mOwnResultImage)
        {
            delete mOwnResultImage;
        }
    }
}

NgosStatus ImageWidget::invalidate()
{
    COMMON_LT((""));



    if (!mPredefined)
    {
        if (mOwnResultImage)
        {
            delete mOwnResultImage;
        }

        COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mImage, mWidth, mHeight, &mOwnResultImage), NgosStatus::ASSERTION);
    }
    else
    {
        COMMON_TEST_ASSERT(mOwnResultImage->getWidth()  == mWidth,  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(mOwnResultImage->getHeight() == mHeight, NgosStatus::ASSERTION);
    }



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



    COMMON_TEST_ASSERT(!mPredefined, NgosStatus::ASSERTION);



    if (mImage != image)
    {
        mImage = image;

        if (
            mWidth > 0
            &&
            mHeight > 0
           )
        {
            COMMON_ASSERT_EXECUTION(invalidate(), NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(repaint(),    NgosStatus::ASSERTION);

            if (isVisible())
            {
                COMMON_ASSERT_EXECUTION(update(), NgosStatus::ASSERTION);
            }
        }
    }



    return NgosStatus::OK;
}

Image* ImageWidget::getImage() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mImage;
}

NgosStatus ImageWidget::setResizedImage(Image *image)
{
    COMMON_LT((" | image = %u", image));

    COMMON_ASSERT(image, "image is null", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mPredefined, NgosStatus::ASSERTION);



    if (mOwnResultImage != image)
    {
        mOwnResultImage = image;

        if (
            mWidth > 0
            &&
            mHeight > 0
           )
        {
            COMMON_ASSERT_EXECUTION(invalidate(), NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(repaint(),    NgosStatus::ASSERTION);

            if (isVisible())
            {
                COMMON_ASSERT_EXECUTION(update(), NgosStatus::ASSERTION);
            }
        }
    }



    return NgosStatus::OK;
}
