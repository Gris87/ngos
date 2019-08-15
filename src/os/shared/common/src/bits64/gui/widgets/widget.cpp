#include "widget.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



Widget::Widget(Widget *parent)
    : mParent(parent)
    , mChildren()
    , mOwnImage(0)
    , mResultImage(0)
    , mPositionX(0)
    , mPositionY(0)
    , mWidth(0)
    , mHeight(0)
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
