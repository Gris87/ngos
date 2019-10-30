#include "tablewidget.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



TableWidget::TableWidget(Image *headerImage, Image *cellNormalImage, Image *cellHoverImage, Image *cellInactiveImage, Image *cellFocusedImage, Image *cellFocusedHoverImage, Widget *parent)
    : Widget(parent)
    , mHeaderImage(headerImage)
    , mCellNormalImage(cellNormalImage)
    , mCellHoverImage(cellHoverImage)
    , mCellInactiveImage(cellInactiveImage)
    , mCellFocusedImage(cellFocusedImage)
    , mCellFocusedHoverImage(cellFocusedHoverImage)
{
    COMMON_LT((" | headerImage = 0x%p, cellNormalImage = 0x%p, cellHoverImage = 0x%p, cellInactiveImage = 0x%p, cellFocusedImage = 0x%p, cellFocusedHoverImage = 0x%p, parent = 0x%p", headerImage, cellNormalImage, cellHoverImage, cellInactiveImage, cellFocusedImage, cellFocusedHoverImage, parent));

    COMMON_ASSERT(headerImage,           "headerImage is null");
    COMMON_ASSERT(cellNormalImage,       "cellNormalImage is null");
    COMMON_ASSERT(cellHoverImage,        "cellHoverImage is null");
    COMMON_ASSERT(cellInactiveImage,     "cellInactiveImage is null");
    COMMON_ASSERT(cellFocusedImage,      "cellFocusedImage is null");
    COMMON_ASSERT(cellFocusedHoverImage, "cellFocusedHoverImage is null");
    COMMON_ASSERT(parent,                "parent is null");
}

TableWidget::~TableWidget()
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

NgosStatus TableWidget::invalidate()
{
    COMMON_LT((""));



    if (mOwnResultImage)
    {
        delete mOwnResultImage;
    }

    mOwnResultImage = new Image(mWidth, mHeight, true, false);
    COMMON_ASSERT_EXECUTION(mOwnResultImage->clearBuffer(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus TableWidget::repaint()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(mOwnResultImage != nullptr, NgosStatus::ASSERTION);



    if (mResultImage)
    {
        delete mResultImage;
    }

    mResultImage = new Image(*mOwnResultImage);



    ListElement<Widget *> *element = mChildren.getHead();

    while (element)
    {
        Widget *widget = element->getData();

        COMMON_ASSERT_EXECUTION(drawWidget(widget, widget->getPositionX(), widget->getPositionY()), NgosStatus::ASSERTION);

        element = element->getNext();
    }



    return NgosStatus::OK;
}
