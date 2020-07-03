#include "tabpagewidget.h"

#include <com/ngos/shared/common/graphics/graphics.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>



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
