#include "consolewidget.h"

#include <common/src/com/ngos/shared/common/graphics/graphics.h>
#include <common/src/com/ngos/shared/common/log/assert.h>
#include <common/src/com/ngos/shared/common/log/log.h>



ConsoleWidget::ConsoleWidget(Image *panelImage, Widget *parent)
    : Widget(parent)
    , mPanelImage(panelImage)
{
    COMMON_LT((" | panelImage = 0x%p, parent = 0x%p", panelImage, parent));

    COMMON_ASSERT(panelImage, "panelImage is null");
    COMMON_ASSERT(parent,     "parent is null");
}

ConsoleWidget::~ConsoleWidget()
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

NgosStatus ConsoleWidget::update(i64 positionX, i64 positionY, u64 width, u64 height)
{
    // COMMON_LT((" | positionX = %d, positionY = %d, width = %u, height = %u", positionX, positionY, width, height)); // Commented to avoid infinite loop

    COMMON_ASSERT(width > 0,  "width is zero",  NgosStatus::ASSERTION);
    COMMON_ASSERT(height > 0, "height is zero", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(getParent(), NgosStatus::ASSERTION);



    return getParent()->update(mPositionX + positionX, mPositionY + positionY, width, height);
}

NgosStatus ConsoleWidget::invalidate()
{
    COMMON_LT((""));



    if (mOwnResultImage)
    {
        delete mOwnResultImage;
    }

    COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mPanelImage, mWidth, mHeight, &mOwnResultImage), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus ConsoleWidget::repaint()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(mOwnResultImage     != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mChildren.getHead() == nullptr, NgosStatus::ASSERTION);



    if (mResultImage)
    {
        delete mResultImage;
    }

    mResultImage = new Image(*mOwnResultImage);



    return NgosStatus::OK;
}

Image* ConsoleWidget::getPanelImage() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mPanelImage;
}
