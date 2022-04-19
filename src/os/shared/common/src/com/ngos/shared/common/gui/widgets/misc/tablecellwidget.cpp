#include "tablecellwidget.h"

#include <com/ngos/shared/common/graphics/graphics.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>



TableCellWidget::TableCellWidget(Widget *parent)
    : Widget(parent)
{
    COMMON_LT((" | parent = 0x%p", parent));

    COMMON_ASSERT(parent, "parent is null");
}

TableCellWidget::~TableCellWidget()
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

NgosStatus TableCellWidget::invalidate()
{
    COMMON_LT((""));



    if (mOwnResultImage)
    {
        delete mOwnResultImage;
    }

    mOwnResultImage = new Image(mWidth, mHeight, true, false);
    COMMON_ASSERT_EXECUTION(mOwnResultImage->clearBuffer(), NgosStatus::ASSERTION);



    for (good_i64 i = 0; i < (i64)mHeight; ++i)
    {
        RgbaPixel *pixel1 = &mOwnResultImage->getRgbaBuffer()[i * mWidth + 0];
        RgbaPixel *pixel2 = &mOwnResultImage->getRgbaBuffer()[i * mWidth + mWidth - 1];

        pixel1->alpha = 0xFF;
        pixel2->alpha = 0xFF;
    }

    for (good_i64 i = 1; i < (i64)mWidth - 1; ++i)
    {
        RgbaPixel *pixel1 = &mOwnResultImage->getRgbaBuffer()[i];
        RgbaPixel *pixel2 = &mOwnResultImage->getRgbaBuffer()[(mHeight - 1) * mWidth + i];

        pixel1->alpha = 0xFF;
        pixel2->alpha = 0xFF;
    }



    return NgosStatus::OK;
}

NgosStatus TableCellWidget::repaint()
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
