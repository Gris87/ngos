#include "button.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



Button::Button(Widget *parent)
    : Widget(parent)
{
    COMMON_LT((""));
}

Button::~Button()
{
    COMMON_LT((""));
}
