#include "widget.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



Widget::Widget(Widget *parent)
    : mParent(parent)
    , mChildren()
{
    COMMON_LT((""));



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
