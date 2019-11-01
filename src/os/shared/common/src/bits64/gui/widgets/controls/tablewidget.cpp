#include "tablewidget.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



TableWidget::TableWidget(Image *backgroundImage, Image *headerImage, Widget *parent)
    : Widget(parent)
    , mBackgroundImage(backgroundImage)
    , mHeaderImage(headerImage)
    , mRowHeight(0)
    , mColumnWidth()
    , mHeaders()
{
    COMMON_LT((" | backgroundImage = 0x%p, headerImage = 0x%p, parent = 0x%p", backgroundImage, headerImage, parent));

    COMMON_ASSERT(backgroundImage, "backgroundImage is null");
    COMMON_ASSERT(headerImage,     "headerImage is null");
    COMMON_ASSERT(parent,          "parent is null");
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

    COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mBackgroundImage, mWidth, mHeight, &mOwnResultImage), NgosStatus::ASSERTION);



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
        mHeaders.append(nullptr);
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

NgosStatus TableWidget::setHeaderText(u64 column, const char8 *text)
{
    COMMON_LT((" | column = %u, text = 0x%p", column, text));

    COMMON_ASSERT(text, "text is null", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mHeaders.at(column)     == nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mColumnWidth.at(column) > 0,        NgosStatus::ASSERTION);



    u64 positionX = 0;

    for (i64 i = 0; i < (i64)column; ++i)
    {
        COMMON_TEST_ASSERT(mColumnWidth.at(i) > 0, NgosStatus::ASSERTION);

        positionX += mColumnWidth.at(i);
    }



    TableHeaderWidget *header = new TableHeaderWidget(mHeaderImage, text, this);

    COMMON_ASSERT_EXECUTION(header->setPosition(positionX, 0),                    NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(header->setSize(mColumnWidth.at(column), mRowHeight), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
