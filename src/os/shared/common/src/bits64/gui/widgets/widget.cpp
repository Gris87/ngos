#include "widget.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



Widget::Widget(Widget *parent)
    : mParent(parent)
    , mChildren()
    , mPositionX(0)
    , mPositionY(0)
    , mWidth(0)
    , mHeight(0)
    , mResultImage(0)
{
    COMMON_LT((" | parent = 0x%p", parent));



    if (mParent)
    {
        mParent->mChildren.append(this);
    }
}

Widget::~Widget()
{
    COMMON_LT((""));



    ListElement<Widget *> *element = mChildren.getHead();

    while (element)
    {
        delete element->getData();

        element = element->getNext();
    }
}

NgosStatus Widget::update()
{
    COMMON_LT((""));



    return update(0, 0, mWidth, mHeight);
}

NgosStatus Widget::update(i64 positionX, i64 positionY, u64 width, u64 height)
{
    COMMON_LT((" | positionX = %d, positionY = %d, width = %u, height = %u", positionX, positionY, width, height));

    COMMON_ASSERT(width > 0,  "width is zero",  NgosStatus::ASSERTION);
    COMMON_ASSERT(height > 0, "height is zero", NgosStatus::ASSERTION);



    if (mParent)
    {
        return mParent->update(mPositionX + positionX, mPositionY + positionY, width, height);
    }



    return NgosStatus::OK;
}

NgosStatus Widget::invalidate()
{
    COMMON_LT((""));



    ListElement<Widget *> *element = mChildren.getHead();

    while (element)
    {
        COMMON_ASSERT_EXECUTION(element->getData()->invalidate(), NgosStatus::ASSERTION);

        element = element->getNext();
    }



    return NgosStatus::OK;
}

NgosStatus Widget::repaint()
{
    COMMON_LT((""));



    ListElement<Widget *> *element = mChildren.getHead();

    while (element)
    {
        COMMON_ASSERT_EXECUTION(element->getData()->repaint(), NgosStatus::ASSERTION);

        element = element->getNext();
    }



    return NgosStatus::OK;
}

bool Widget::hasIntersection(Widget *anotherWidget)
{
    COMMON_LT((" | anotherWidget = 0x%p", anotherWidget));

    COMMON_ASSERT(anotherWidget, "anotherWidget is null", false);



    return hasIntersection(anotherWidget->mPositionX, anotherWidget->mPositionY, anotherWidget->mWidth, anotherWidget->mHeight);
}

bool Widget::hasIntersection(i64 positionX, i64 positionY, u64 width, u64 height)
{
    COMMON_LT((" | positionX = %d, positionY = %d, width = %u, height = %u", positionX, positionY, width, height));

    COMMON_ASSERT(width > 0,  "width is zero",  false);
    COMMON_ASSERT(height > 0, "height is zero", false);



    return (i64)(positionX)           < (i64)(mPositionX + mWidth)
            &&
            (i64)(positionX + width)  > (i64)(mPositionX)
            &&
            (i64)(positionY)          < (i64)(mPositionY + mHeight)
            &&
            (i64)(positionY + height) > (i64)(mPositionY);
}

NgosStatus Widget::setPosition(i64 positionX, i64 positionY)
{
    COMMON_LT((" | positionX = %d, positionY = %d", positionX, positionY));



    mPositionX = positionX;
    mPositionY = positionY;



    return NgosStatus::OK;
}

NgosStatus Widget::setSize(u64 width, u64 height)
{
    COMMON_LT((" | width = %u, height = %u", width, height));



    mWidth  = width;
    mHeight = height;



    return NgosStatus::OK;
}

i64 Widget::getPositionX() const
{
    COMMON_LT((""));



    return mPositionX;
}

i64 Widget::getPositionY() const
{
    COMMON_LT((""));



    return mPositionY;
}

u64 Widget::getWidth() const
{
    COMMON_LT((""));



    return mWidth;
}

u64 Widget::getHeight() const
{
    COMMON_LT((""));



    return mHeight;
}
