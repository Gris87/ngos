#include "widget.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/gui/gui.h>
#include <ngos/linkage.h>



Widget::Widget(Widget *parent)
    : mParent(parent)
    , mChildren()
    , mPositionX(0)
    , mPositionY(0)
    , mWidth(0)
    , mHeight(0)
    , mVisible(true)
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

NgosStatus Widget::setState(WidgetState state)
{
    COMMON_LT((" | state = %u", state));



    AVOID_UNUSED(state);



    return NgosStatus::OK;
}

WidgetState Widget::getState() const
{
    COMMON_LT((""));



    return WidgetState::NONE;
}

NgosStatus Widget::setKeyboardEventHandler(keyboard_event_handler handler)
{
    COMMON_LT((" | handler = 0x%p", handler));



    AVOID_UNUSED(handler);



    return NgosStatus::OK;
}

keyboard_event_handler Widget::getKeyboardEventHandler() const
{
    COMMON_LT((""));



    return nullptr;
}

NgosStatus Widget::setPressEventHandler(press_event_handler handler)
{
    COMMON_LT((" | handler = 0x%p", handler));



    AVOID_UNUSED(handler);



    return NgosStatus::OK;
}

press_event_handler Widget::getPressEventHandler() const
{
    COMMON_LT((""));



    return nullptr;
}

NgosStatus Widget::setPosition(i64 positionX, i64 positionY)
{
    COMMON_LT((" | positionX = %d, positionY = %d", positionX, positionY));



    if (
        mPositionX != positionX
        ||
        mPositionY != positionY
       )
    {
        if (
            mParent
            &&
            isVisible()
            &&
            mWidth // mWidth > 0
            &&
            mHeight // mHeight > 0
           )
        {
            i64 oldPositionX = mPositionX;
            i64 oldPositionY = mPositionY;

            mPositionX = positionX;
            mPositionY = positionY;

            COMMON_ASSERT_EXECUTION(GUI::lockUpdates(),                                           NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(mParent->update(oldPositionX, oldPositionY, mWidth, mHeight), NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(mParent->update(mPositionX,   mPositionY,   mWidth, mHeight), NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(GUI::unlockUpdates(),                                         NgosStatus::ASSERTION);
        }
        else
        {
            mPositionX = positionX;
            mPositionY = positionY;
        }
    }



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

NgosStatus Widget::setSize(u64 width, u64 height)
{
    COMMON_LT((" | width = %u, height = %u", width, height));



    mWidth  = width;
    mHeight = height;



    return NgosStatus::OK;
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

NgosStatus Widget::setVisible(bool visible)
{
    COMMON_LT((" | visible = %u", visible));



    if (mVisible != visible)
    {
        mVisible = visible;

        if (
            mWidth // mWidth > 0
            &&
            mHeight // mHeight > 0
           )
        {
            COMMON_ASSERT_EXECUTION(update(), NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

bool Widget::isVisible() const
{
    COMMON_LT((""));



    return mVisible;
}

Image* Widget::getResultImage() const
{
    COMMON_LT((""));



    return mResultImage;
}
