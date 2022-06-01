#include "screenwidget.h"

#include <com/ngos/shared/common/graphics/graphics.h>
#include <com/ngos/shared/common/graphics/rgbapixel.h>
#include <com/ngos/shared/common/graphics/rgbpixel.h>
#include <com/ngos/shared/common/gui/widgets/special/rootwidget.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/memory/memory.h>



ScreenWidget::ScreenWidget(Image *backgroundImage, UefiGraphicsOutputProtocol *screenGop, RootWidget *rootWidget)
    : Widget()
    , mBackgroundImage(backgroundImage)
    , mScreenGop(screenGop)
    , mRootWidget(rootWidget)
    , mUpdateLeft(-1)
    , mUpdateTop(-1)
    , mUpdateRight(-1)
    , mUpdateBottom(-1)
{
    COMMON_LT((" | backgroundImage = 0x%p, screenGop = 0x%p, rootWidget = 0x%p", backgroundImage, screenGop, rootWidget));

    COMMON_ASSERT(backgroundImage, "backgroundImage is null");
    COMMON_ASSERT(screenGop,       "screenGop is null");
    COMMON_ASSERT(rootWidget,      "rootWidget is null");



    mRootWidget->addScreen(this);
}

ScreenWidget::~ScreenWidget()
{
    COMMON_LT((""));



    if (mOwnResultImage)
    {
        delete mOwnResultImage;
    }

    if (mResultImage)
    {
        delete mResultImage;
    }
}

NgosStatus ScreenWidget::updateRegion(i64 positionX, i64 positionY, u64 width, u64 height)
{
    // COMMON_LT((" | positionX = %d, positionY = %d, width = %u, height = %u", positionX, positionY, width, height)); // Commented to avoid infinite loop

    COMMON_ASSERT(width > 0,  "width is invalid",  NgosStatus::ASSERTION);
    COMMON_ASSERT(height > 0, "height is invalid", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mOwnResultImage != nullptr, NgosStatus::ASSERTION);

    COMMON_ASSERT_EXECUTION(Graphics::insertImageRaw(
                                mOwnResultImage->getBuffer(),
                                mResultImage->getBuffer(),
                                mWidth,
                                mHeight,
                                mWidth,
                                mHeight,
                                sizeof(RgbaPixel),
                                sizeof(RgbaPixel),
                                true,
                                0, 0,
                                positionX,
                                positionY,
                                positionX + width,
                                positionY + height),
                            NgosStatus::ASSERTION);



    ListElement<Widget *> *element = mChildren.getHead();

    while (element)
    {
        Widget *widget = element->getData();

        if (widget->hasIntersection(positionX, positionY, width, height))
        {
            i64 left   = positionX - widget->getPositionX();
            i64 right  = left + (i64)width;
            i64 top    = positionY - widget->getPositionY();
            i64 bottom = top + (i64)height;

            if (left < 0)
            {
                left = 0;
            }

            if (top < 0)
            {
                top = 0;
            }

            if (right > (i64)widget->getResultImage()->getWidth())
            {
                right = widget->getResultImage()->getWidth();
            }

            if (bottom > (i64)widget->getResultImage()->getHeight())
            {
                bottom = widget->getResultImage()->getHeight();
            }



            COMMON_ASSERT_EXECUTION(drawWidget(widget, widget->getPositionX(), widget->getPositionY(), left, top, right, bottom), NgosStatus::ASSERTION);
        }

        element = element->getNext();
    }



    if (mUpdateLeft < 0)
    {
        mUpdateLeft   = positionX;
        mUpdateTop    = positionY;
        mUpdateRight  = positionX + width;
        mUpdateBottom = positionY + height;
    }
    else
    {
        if (positionX < mUpdateLeft)
        {
            mUpdateLeft = positionX;
        }

        if (positionY < mUpdateTop)
        {
            mUpdateTop = positionY;
        }



        if ((i64)(positionX + width) > mUpdateRight)
        {
            mUpdateRight = positionX + width;
        }

        if ((i64)(positionY + height) > mUpdateBottom)
        {
            mUpdateBottom = positionY + height;
        }
    }



    return NgosStatus::OK;
}

NgosStatus ScreenWidget::applyUpdates()
{
    // COMMON_LT(("")); // Commented to avoid infinite loop



    if (mUpdateLeft >= 0)
    {
        COMMON_ASSERT_EXECUTION(mScreenGop->blt(mScreenGop,
                                                (UefiGraphicsOutputBltPixel *)mResultImage->getBuffer(),
                                                UefiGraphicsOutputBltOperation::BLT_BUFFER_TO_VIDEO,
                                                mUpdateLeft, mUpdateTop,
                                                mUpdateLeft, mUpdateTop,
                                                mUpdateRight - mUpdateLeft,
                                                mUpdateBottom - mUpdateTop,
                                                mWidth * sizeof(RgbaPixel)),
                                UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);

        mUpdateLeft   = -1;
        mUpdateTop    = -1;
        mUpdateRight  = -1;
        mUpdateBottom = -1;
    }



    return NgosStatus::OK;
}

NgosStatus ScreenWidget::update(i64 positionX, i64 positionY, u64 width, u64 height)
{
    // COMMON_LT((" | positionX = %d, positionY = %d, width = %u, height = %u", positionX, positionY, width, height)); // Commented to avoid infinite loop

    COMMON_ASSERT(width > 0,  "width is invalid",  NgosStatus::ASSERTION);
    COMMON_ASSERT(height > 0, "height is invalid", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mRootWidget, NgosStatus::ASSERTION);



    return mRootWidget->update(mPositionX + positionX, mPositionY + positionY, width, height);
}

NgosStatus ScreenWidget::invalidate()
{
    COMMON_LT((""));



    if (mOwnResultImage)
    {
        delete mOwnResultImage;
    }



    COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mBackgroundImage, mWidth, mHeight, &mOwnResultImage), NgosStatus::ASSERTION);



    Image *opaqueImage;

    if (Graphics::makeOpaqueImage(mOwnResultImage, true, &opaqueImage) == NgosStatus::OK)
    {
        delete mOwnResultImage;
        mOwnResultImage = opaqueImage;
    }



    return NgosStatus::OK;
}

NgosStatus ScreenWidget::repaint()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(mOwnResultImage     != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mChildren.getHead() == nullptr, NgosStatus::ASSERTION);



    if (mResultImage)
    {
        delete mResultImage;
    }

    mResultImage = new Image(*mOwnResultImage);



    mUpdateLeft   = 0;
    mUpdateTop    = 0;
    mUpdateRight  = mWidth;
    mUpdateBottom = mHeight;



    return NgosStatus::OK;
}

UefiGraphicsOutputProtocol* ScreenWidget::getScreenGop() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mScreenGop;
}
