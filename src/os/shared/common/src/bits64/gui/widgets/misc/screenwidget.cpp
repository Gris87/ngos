#include "screenwidget.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/graphics/rgbapixel.h>
#include <common/src/bits64/graphics/rgbpixel.h>
#include <common/src/bits64/gui/widgets/misc/rootwidget.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/memory/memory.h>



ScreenWidget::ScreenWidget(Image *backgroundImage, UefiGraphicsOutputProtocol *screenGop, RootWidget *rootWidget)
    : Widget()
    , mBackgroundImage(backgroundImage)
    , mScreenGop(screenGop)
    , mRootWidget(rootWidget)
    , mBackgroundResizedImage(0)
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



    if (mBackgroundResizedImage)
    {
        delete mBackgroundResizedImage;
    }

    if (mResultImage)
    {
        delete mResultImage;
    }
}

NgosStatus ScreenWidget::updateRegion(i64 positionX, i64 positionY, u64 width, u64 height)
{
    COMMON_LT((" | positionX = %d, positionY = %d, width = %u, height = %u", positionX, positionY, width, height));

    COMMON_ASSERT(width > 0,  "width is zero",  NgosStatus::ASSERTION);
    COMMON_ASSERT(height > 0, "height is zero", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mOwnResultImage != 0, NgosStatus::ASSERTION);

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



    return NgosStatus::OK;
}

NgosStatus ScreenWidget::applyUpdates()
{
    COMMON_LT((""));



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
    COMMON_LT((" | positionX = %d, positionY = %d, width = %u, height = %u", positionX, positionY, width, height));

    COMMON_ASSERT(width > 0,  "width is zero",  NgosStatus::ASSERTION);
    COMMON_ASSERT(height > 0, "height is zero", NgosStatus::ASSERTION);



    return mRootWidget->update(mPositionX + positionX, mPositionY + positionY, width, height);
}

NgosStatus ScreenWidget::invalidate()
{
    COMMON_LT((""));



    if (mBackgroundResizedImage)
    {
        delete mBackgroundResizedImage;
    }

    COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mBackgroundImage, mWidth, mHeight, &mBackgroundResizedImage), NgosStatus::ASSERTION);

    if (
        !mBackgroundResizedImage->isRgba()
        ||
        !mBackgroundResizedImage->isOpaque()
       )
    {
        Image *newImage;

        COMMON_ASSERT_EXECUTION(Graphics::makeOpaqueImage(mBackgroundResizedImage, &newImage), NgosStatus::ASSERTION);

        delete mBackgroundResizedImage;
        mBackgroundResizedImage = newImage;
    }



    return NgosStatus::OK;
}

NgosStatus ScreenWidget::repaint()
{
    COMMON_LT((""));



    if (mResultImage)
    {
        delete mResultImage;
    }

    mOwnResultImage = mBackgroundResizedImage;
    mResultImage    = new Image(*mOwnResultImage);



    mUpdateLeft   = 0;
    mUpdateTop    = 0;
    mUpdateRight  = mWidth;
    mUpdateBottom = mHeight;



    return NgosStatus::OK;
}

NgosStatus ScreenWidget::drawWidget(Widget *widget, i64 positionX, i64 positionY)
{
    COMMON_LT((" | widget = 0x%p, positionX = %d, positionY = %d", widget, positionX, positionY));

    COMMON_ASSERT(widget, "widget is null", NgosStatus::ASSERTION);



    return drawWidget(widget, positionX, positionY, 0, 0, widget->getResultImage()->getWidth(), widget->getResultImage()->getHeight());
}

NgosStatus ScreenWidget::drawWidget(Widget *widget, i64 positionX, i64 positionY, i64 left, i64 top, i64 right, i64 bottom)
{
    COMMON_LT((" | widget = 0x%p, positionX = %d, positionY = %d, left = %d, top = %d, right = %d, bottom = %d", widget, positionX, positionY, left, top, right, bottom));

    COMMON_ASSERT(widget,                                               "widget is null",    NgosStatus::ASSERTION);
    COMMON_ASSERT(left >= 0,                                            "left is invalid",   NgosStatus::ASSERTION);
    COMMON_ASSERT(top >= 0,                                             "top is invalid",    NgosStatus::ASSERTION);
    COMMON_ASSERT(right <= (i64)widget->getResultImage()->getWidth(),   "right is invalid",  NgosStatus::ASSERTION);
    COMMON_ASSERT(bottom <= (i64)widget->getResultImage()->getHeight(), "bottom is invalid", NgosStatus::ASSERTION);



    if (widget->isVisible())
    {
        Image *resultImage = widget->getResultImage();

        COMMON_ASSERT_EXECUTION(Graphics::insertImageRaw(
                                    resultImage->getBuffer(),
                                    mResultImage->getBuffer(),
                                    resultImage->getWidth(),
                                    resultImage->getHeight(),
                                    mWidth,
                                    mHeight,
                                    resultImage->getBytesPerPixel(),
                                    sizeof(RgbaPixel),
                                    resultImage->isOpaque(),
                                    positionX,
                                    positionY,
                                    left,
                                    top,
                                    right,
                                    bottom),
                                NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}
