#include "panelwidget.h"

#include <com/ngos/shared/common/graphics/graphics.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>



PanelWidget::PanelWidget(Image *panelImage, Widget *parent)
    : Widget(parent)
    , mPanelImage(panelImage)
    , mPredefined(false)
{
    COMMON_LT((" | panelImage = 0x%p, parent = 0x%p", panelImage, parent));

    COMMON_ASSERT(panelImage, "panelImage is null");
    COMMON_ASSERT(parent,     "parent is null");
}

PanelWidget::PanelWidget(Image *panelImage, Image *panelResizedImage, Widget *parent)
    : Widget(parent)
    , mPanelImage(panelImage)
    , mPredefined(true)
{
    COMMON_LT((" | panelImage = 0x%p, panelResizedImage = 0x%p, parent = 0x%p", panelImage, panelResizedImage, parent));

    COMMON_ASSERT(panelImage,        "panelImage is null");
    COMMON_ASSERT(panelResizedImage, "panelResizedImage is null");
    COMMON_ASSERT(parent,            "parent is null");



    mOwnResultImage = panelResizedImage;
}

PanelWidget::~PanelWidget()
{
    COMMON_LT((""));



    if (!mPredefined)
    {
        if (mOwnResultImage)
        {
            delete mOwnResultImage;
        }
    }

    if (mResultImage)
    {
        delete mResultImage;
    }
}

NgosStatus PanelWidget::invalidate()
{
    COMMON_LT((""));



    if (!mPredefined)
    {
        if (mOwnResultImage)
        {
            delete mOwnResultImage;
        }

        COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mPanelImage, mWidth, mHeight, &mOwnResultImage), NgosStatus::ASSERTION);
    }
    else
    {
        COMMON_TEST_ASSERT(mOwnResultImage->getWidth()  == mWidth,  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(mOwnResultImage->getHeight() == mHeight, NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus PanelWidget::repaint()
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

Image* PanelWidget::getPanelImage() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mPanelImage;
}
