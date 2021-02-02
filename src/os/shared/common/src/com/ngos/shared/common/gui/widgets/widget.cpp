#include "widget.h"

#include <com/ngos/shared/common/graphics/graphics.h>
#include <com/ngos/shared/common/gui/gui.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/utils.h>



Widget::Widget(Widget *parent)
    : mParent(parent)
    , mChildren()
    , mPositionX(0)
    , mPositionY(0)
    , mWidth(0)
    , mHeight(0)
    , mVisible(true)
    , mUpdatesLocks(0)
    , mOwnResultImage(nullptr)
    , mResultImage(nullptr)
{
    COMMON_LT((" | parent = 0x%p", parent));



    if (mParent)
    {
        COMMON_ASSERT_EXECUTION(mParent->mChildren.append(this));
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
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return update(0, 0, mWidth, mHeight);
}

NgosStatus Widget::update(bad_int64 positionX, bad_int64 positionY, bad_uint64 width, bad_uint64 height)
{
    // COMMON_LT((" | positionX = %d, positionY = %d, width = %u, height = %u", positionX, positionY, width, height)); // Commented to avoid too frequent logs

    COMMON_ASSERT(width > 0,  "width is zero",  NgosStatus::ASSERTION);
    COMMON_ASSERT(height > 0, "height is zero", NgosStatus::ASSERTION);



    if (mParent && isUpdatesEnabled())
    {
        positionX += mPositionX;
        positionY += mPositionY;

        Image *parentResultImage = mParent->mResultImage;

        if (parentResultImage)
        {
            Image *parentOwnResultImage = mParent->mOwnResultImage;

            COMMON_TEST_ASSERT(parentOwnResultImage, NgosStatus::ASSERTION);

            COMMON_ASSERT_EXECUTION(Graphics::insertImageRaw(
                                        parentOwnResultImage->getBuffer(),
                                        parentResultImage->getBuffer(),
                                        parentOwnResultImage->getWidth(),
                                        parentOwnResultImage->getHeight(),
                                        parentResultImage->getWidth(),
                                        parentResultImage->getHeight(),
                                        parentOwnResultImage->getBytesPerPixel(),
                                        parentResultImage->getBytesPerPixel(),
                                        true,
                                        0, 0,
                                        positionX,
                                        positionY,
                                        positionX + width,
                                        positionY + height),
                                    NgosStatus::ASSERTION);



            ListElement<Widget *> *element = mParent->mChildren.getHead();

            while (element)
            {
                Widget *widget = element->getData();

                if (widget->hasIntersection(positionX, positionY, width, height))
                {
                    bad_int64 left   = positionX - widget->getPositionX();
                    bad_int64 right  = left + (bad_int64)width;
                    bad_int64 top    = positionY - widget->getPositionY();
                    bad_int64 bottom = top + (bad_int64)height;

                    if (left < 0)
                    {
                        left = 0;
                    }

                    if (top < 0)
                    {
                        top = 0;
                    }

                    if (right > (bad_int64)widget->getResultImage()->getWidth())
                    {
                        right = widget->getResultImage()->getWidth();
                    }

                    if (bottom > (bad_int64)widget->getResultImage()->getHeight())
                    {
                        bottom = widget->getResultImage()->getHeight();
                    }



                    COMMON_ASSERT_EXECUTION(mParent->drawWidget(widget, widget->getPositionX(), widget->getPositionY(), left, top, right, bottom), NgosStatus::ASSERTION);
                }

                element = element->getNext();
            }
        }

        return mParent->update(positionX, positionY, width, height);
    }



    return NgosStatus::OK;
}

NgosStatus Widget::invalidate()
{
    COMMON_LT((""));



    return NgosStatus::OK;
}

NgosStatus Widget::repaint()
{
    COMMON_LT((""));



    return NgosStatus::OK;
}

NgosStatus Widget::onKeyboardEvent(const UefiInputKey &key)
{
    COMMON_LT((" | key = ..."));



    AVOID_UNUSED(key);



    return NgosStatus::NO_EFFECT;
}

NgosStatus Widget::onMouseScrollEvent(bad_int32 delta)
{
    COMMON_LT((" | delta = %d", delta));

    COMMON_ASSERT(delta != 0, "delta is zero", NgosStatus::ASSERTION);



    AVOID_UNUSED(delta);



    return NgosStatus::NO_EFFECT;
}

NgosStatus Widget::drawWidget(Widget *widget, bad_int64 positionX, bad_int64 positionY)
{
    // COMMON_LT((" | widget = 0x%p, positionX = %d, positionY = %d", widget, positionX, positionY)); // Commented to avoid too frequent logs

    COMMON_ASSERT(widget, "widget is null", NgosStatus::ASSERTION);



    return drawWidget(widget, positionX, positionY, 0, 0, widget->getResultImage()->getWidth(), widget->getResultImage()->getHeight());
}

NgosStatus Widget::drawWidget(Widget *widget, bad_int64 positionX, bad_int64 positionY, bad_int64 left, bad_int64 top, bad_int64 right, bad_int64 bottom)
{
    // COMMON_LT((" | widget = 0x%p, positionX = %d, positionY = %d, left = %d, top = %d, right = %d, bottom = %d", widget, positionX, positionY, left, top, right, bottom)); // Commented to avoid too frequent logs

    COMMON_ASSERT(widget,                                               "widget is null",                   NgosStatus::ASSERTION);
    COMMON_ASSERT(widget->getResultImage(),                             "widget->getResultImage() is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(left >= 0,                                            "left is invalid",                  NgosStatus::ASSERTION);
    COMMON_ASSERT(top >= 0,                                             "top is invalid",                   NgosStatus::ASSERTION);
    COMMON_ASSERT(right <= (bad_int64)widget->getResultImage()->getWidth(),   "right is invalid",                 NgosStatus::ASSERTION);
    COMMON_ASSERT(bottom <= (bad_int64)widget->getResultImage()->getHeight(), "bottom is invalid",                NgosStatus::ASSERTION);



    if (widget->isVisible())
    {
        Image *resultImage = widget->getResultImage();

        COMMON_ASSERT_EXECUTION(Graphics::insertImageRaw(
                                    resultImage->getBuffer(),
                                    mResultImage->getBuffer(),
                                    resultImage->getWidth(),
                                    resultImage->getHeight(),
                                    mResultImage->getWidth(),
                                    mResultImage->getHeight(),
                                    resultImage->getBytesPerPixel(),
                                    mResultImage->getBytesPerPixel(),
                                    resultImage->isOpaque() && mResultImage->isOpaque(),
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

Widget* Widget::detectHoveredWidget(bad_int64 positionX, bad_int64 positionY)
{
    COMMON_LT((" | positionX = %d, positionY = %d", positionX, positionY));



    if (
        positionX >= 0
        &&
        positionY >= 0
        &&
        positionX < (bad_int64)mWidth
        &&
        positionY < (bad_int64)mHeight
        &&
        isVisible()
       )
    {
        ListElement<Widget *> *element = mChildren.getTail();

        while (element)
        {
            Widget *widget = element->getData();

            Widget *res = widget->detectHoveredWidget(positionX - widget->getPositionX(), positionY - widget->getPositionY());

            if (res)
            {
                return res;
            }

            element = element->getPrevious();
        }



        if (isAcceptMouseEvents())
        {
            return this;
        }
    }



    return nullptr;
}

bool Widget::isAcceptMouseEvents()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return false;
}

bool Widget::hasIntersection(Widget *anotherWidget)
{
    // COMMON_LT((" | anotherWidget = 0x%p", anotherWidget)); // Commented to avoid too frequent logs

    COMMON_ASSERT(anotherWidget, "anotherWidget is null", false);



    return hasIntersection(anotherWidget->mPositionX, anotherWidget->mPositionY, anotherWidget->mWidth, anotherWidget->mHeight);
}

bool Widget::hasIntersection(bad_int64 positionX, bad_int64 positionY, bad_uint64 width, bad_uint64 height)
{
    // COMMON_LT((" | positionX = %d, positionY = %d, width = %u, height = %u", positionX, positionY, width, height)); // Commented to avoid too frequent logs

    COMMON_ASSERT(width > 0,  "width is zero",  false);
    COMMON_ASSERT(height > 0, "height is zero", false);



    return (bad_int64)(positionX)           < (bad_int64)(mPositionX + mWidth)
            &&
            (bad_int64)(positionX + width)  > (bad_int64)(mPositionX)
            &&
            (bad_int64)(positionY)          < (bad_int64)(mPositionY + mHeight)
            &&
            (bad_int64)(positionY + height) > (bad_int64)(mPositionY);
}

NgosStatus Widget::lockUpdates()
{
    COMMON_LT((""));



    ++mUpdatesLocks;

    COMMON_TEST_ASSERT(!isUpdatesEnabled(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus Widget::unlockUpdates()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(!isUpdatesEnabled(), NgosStatus::ASSERTION);

    --mUpdatesLocks;



    return NgosStatus::OK;
}

bool Widget::isUpdatesEnabled()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return !mUpdatesLocks; // sUpdatesLocks == 0
}

bool Widget::isFocused()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return GUI::getFocusedWidget() == this;
}

bool Widget::isFocusable()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return false;
}

Widget* Widget::getOwnerWidget()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return this;
}

NgosStatus Widget::setState(WidgetState state)
{
    COMMON_LT((" | state = %u", state));



    AVOID_UNUSED(state);



    return NgosStatus::OK;
}

WidgetState Widget::getState() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



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
    // COMMON_LT(("")); // Commented to avoid too frequent logs



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
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return nullptr;
}

NgosStatus Widget::setPressEventHandlerObject(PressEventHandler *handler)
{
    COMMON_LT((" | handler = 0x%p", handler));



    AVOID_UNUSED(handler);



    return NgosStatus::OK;
}

PressEventHandler* Widget::getPressEventHandlerObject() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return nullptr;
}

NgosStatus Widget::setParent(Widget *parent)
{
    COMMON_LT((" | parent = 0x%p", parent));

    COMMON_ASSERT(parent, "parent is null", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mParent, NgosStatus::ASSERTION);



    if (mParent != parent)
    {
        COMMON_ASSERT_EXECUTION(mParent->mChildren.remove(this), NgosStatus::ASSERTION);

        mParent = parent;

        COMMON_ASSERT_EXECUTION(mParent->mChildren.append(this), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

Widget* Widget::getParent() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mParent;
}

List<Widget *>& Widget::getChildren()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mChildren;
}

NgosStatus Widget::setPosition(bad_int64 positionX, bad_int64 positionY)
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
            isUpdatesEnabled()
            &&
            mWidth > 0
            &&
            mHeight > 0
           )
        {
            bad_int64 oldPositionX = mPositionX;
            bad_int64 oldPositionY = mPositionY;

            mPositionX = positionX;
            mPositionY = positionY;

            // Ignore CppAlignmentVerifier [BEGIN]
            COMMON_ASSERT_EXECUTION(GUI::lockUpdates(),                                                            NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(update(oldPositionX - mPositionX, oldPositionY - mPositionY, mWidth, mHeight), NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(update(),                                                                      NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(GUI::unlockUpdates(),                                                          NgosStatus::ASSERTION);
            // Ignore CppAlignmentVerifier [END]
        }
        else
        {
            mPositionX = positionX;
            mPositionY = positionY;
        }
    }



    return NgosStatus::OK;
}

bad_int64 Widget::getPositionX() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mPositionX;
}

bad_int64 Widget::getPositionY() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mPositionY;
}

bad_int64 Widget::getGlobalPositionX() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    if (mParent)
    {
        return mParent->getGlobalPositionX() + mPositionX;
    }
    else
    {
        return mPositionX;
    }
}

bad_int64 Widget::getGlobalPositionY() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    if (mParent)
    {
        return mParent->getGlobalPositionY() + mPositionY;
    }
    else
    {
        return mPositionY;
    }
}

NgosStatus Widget::setSize(bad_uint64 width, bad_uint64 height)
{
    COMMON_LT((" | width = %u, height = %u", width, height));

    COMMON_ASSERT(width  > 0, "width is zero",  NgosStatus::ASSERTION);
    COMMON_ASSERT(height > 0, "height is zero", NgosStatus::ASSERTION);



    if (
        mWidth != width
        ||
        mHeight != height
       )
    {
        bad_uint64 oldWidth  = mWidth;
        bad_uint64 oldHeight = mHeight;

        mWidth  = width;
        mHeight = height;

        COMMON_ASSERT_EXECUTION(invalidate(), NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(repaint(),    NgosStatus::ASSERTION);



        if (isVisible())
        {
            COMMON_ASSERT_EXECUTION(update(0, 0, MAX(mWidth, oldWidth), MAX(mHeight, oldHeight)), NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

bad_uint64 Widget::getWidth() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mWidth;
}

bad_uint64 Widget::getHeight() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mHeight;
}

NgosStatus Widget::setVisible(bool visible)
{
    COMMON_LT((" | visible = %u", visible));



    if (mVisible != visible)
    {
        mVisible = visible;

        if (
            mWidth > 0
            &&
            mHeight > 0
           )
        {
            COMMON_ASSERT_EXECUTION(update(), NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

bool Widget::isVisible() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mVisible;
}

Image* Widget::getOwnResultImage() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mOwnResultImage;
}

Image* Widget::getResultImage() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mResultImage;
}
