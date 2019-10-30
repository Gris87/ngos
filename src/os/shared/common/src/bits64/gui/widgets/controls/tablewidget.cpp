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
    , mRowHeight(0)
    , mColumnWidth()
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


NgosStatus TableWidget::setRowHeight(u64 height)
{
    COMMON_LT((" | height = %u", height));

    COMMON_ASSERT(height > 0, "height is zero", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mRowHeight == 0, NgosStatus::ASSERTION);
    mRowHeight = height;



    return NgosStatus::OK;
}

u64 TableWidget::getRowHeight() const
{
    COMMON_LT((""));



    return mRowHeight;
}

NgosStatus TableWidget::setColumnCount(u64 columns)
{
    COMMON_LT((" | columns = %u", columns));

    COMMON_ASSERT(columns > 0, "columns is zero", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mColumnWidth.getSize() == 0, NgosStatus::ASSERTION);



    for (i64 i = 0; i < (i64)columns; ++i)
    {
        mColumnWidth.append(0);
    }



    return NgosStatus::OK;
}

u64 TableWidget::getColumnCount() const
{
    COMMON_LT((""));



    return mColumnWidth.getSize();
}

NgosStatus TableWidget::setColumnWidth(u64 column, u64 width)
{
    COMMON_LT((" | column = %u, width = %u", column, width));

    COMMON_ASSERT(width > 0, "width is zero", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mColumnWidth.at(column) == 0, NgosStatus::ASSERTION);
    mColumnWidth[column] = width;



    return NgosStatus::OK;
}

u64 TableWidget::getColumnWidth(u64 column) const
{
    COMMON_LT((" | column = %u", column));



    return mColumnWidth.at(column);
}
