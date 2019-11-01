#include "tabpagewidget.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



TabPageWidget::TabPageWidget(Widget *parent)
    : WrapperWidget(parent)
{
    COMMON_LT((" | parent = 0x%p", parent));

    COMMON_ASSERT(parent, "parent is null");



    COMMON_ASSERT_EXECUTION(setVisible(false));
}

TabPageWidget::~TabPageWidget()
{
    COMMON_LT((""));
}
