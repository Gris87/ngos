#include "treenodewidget.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/gui/gui.h>
#include <common/src/bits64/gui/widgets/controls/treewidget.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



TreeNodeWidget::TreeNodeWidget(Image *normalImage, Image *hoverImage, Image *pressedImage, Image *collapsedImage, Image *expandedImage, Image *image, const char8 *text, Widget *parent)
    : Widget(parent)
    , mCollapsedImage(collapsedImage)
    , mExpandedImage(expandedImage)
    , mImage(image)
    , mExpandToolButton(new ToolButton(normalImage, hoverImage, pressedImage, collapsedImage, nullptr, nullptr, this))
    , mImageWidget(nullptr)
    , mLabelWidget(nullptr)
    , mState(WidgetState::NORMAL)
    , mRowHeight(0)
{
    COMMON_LT((" | normalImage = 0x%p, hoverImage = 0x%p, pressedImage = 0x%p, collapsedImage = 0x%p, expandedImage = 0x%p, image = 0x%p, text = 0x%p, parent = 0x%p", normalImage, hoverImage, pressedImage, collapsedImage, expandedImage, image, text, parent));

    COMMON_ASSERT(normalImage,    "normalImage is null");
    COMMON_ASSERT(hoverImage,     "hoverImage is null");
    COMMON_ASSERT(pressedImage,   "pressedImage is null");
    COMMON_ASSERT(collapsedImage, "collapsedImage is null");
    COMMON_ASSERT(expandedImage,  "expandedImage is null");
    COMMON_ASSERT(parent,         "parent is null");



    if (image)
    {
        mImageWidget = new ImageWidget(image, this);
    }

    if (text && *text)
    {
        mLabelWidget = new LabelWidget(text, this);
    }
}

TreeNodeWidget::TreeNodeWidget(Image *normalImage, Image *hoverImage, Image *pressedImage, Image *normalResizedImage, Image *hoverResizedImage, Image *pressedResizedImage, Image *collapsedImage, Image *expandedImage, Image *image, const char8 *text, Widget *parent)
    : Widget(parent)
    , mCollapsedImage(collapsedImage)
    , mExpandedImage(expandedImage)
    , mImage(image)
    , mExpandToolButton(new ToolButton(normalImage, hoverImage, pressedImage, normalResizedImage, hoverResizedImage, pressedResizedImage, collapsedImage, nullptr, nullptr, this))
    , mImageWidget(nullptr)
    , mLabelWidget(nullptr)
    , mState(WidgetState::NORMAL)
    , mRowHeight(0)
{
    COMMON_LT((" | normalImage = 0x%p, hoverImage = 0x%p, pressedImage = 0x%p, normalResizedImage = 0x%p, hoverResizedImage = 0x%p, pressedResizedImage = 0x%p, collapsedImage = 0x%p, expandedImage = 0x%p, image = 0x%p, text = 0x%p, parent = 0x%p", normalImage, hoverImage, pressedImage, normalResizedImage, hoverResizedImage, pressedResizedImage, collapsedImage, expandedImage, image, text, parent));

    COMMON_ASSERT(normalImage,         "normalImage is null");
    COMMON_ASSERT(hoverImage,          "hoverImage is null");
    COMMON_ASSERT(pressedImage,        "pressedImage is null");
    COMMON_ASSERT(normalResizedImage,  "normalResizedImage is null");
    COMMON_ASSERT(hoverResizedImage,   "hoverResizedImage is null");
    COMMON_ASSERT(pressedResizedImage, "pressedResizedImage is null");
    COMMON_ASSERT(collapsedImage,      "collapsedImage is null");
    COMMON_ASSERT(expandedImage,       "expandedImage is null");
    COMMON_ASSERT(parent,              "parent is null");



    if (image)
    {
        mImageWidget = new ImageWidget(image, this);
    }

    if (text && *text)
    {
        mLabelWidget = new LabelWidget(text, this);
    }
}

TreeNodeWidget::~TreeNodeWidget()
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

NgosStatus TreeNodeWidget::invalidate()
{
    COMMON_LT((""));



    if (mOwnResultImage)
    {
        delete mOwnResultImage;
    }

    mOwnResultImage = new Image(mWidth, mHeight, true, false);



    if (mState == WidgetState::NORMAL)
    {
        COMMON_ASSERT_EXECUTION(mOwnResultImage->clearBuffer(), NgosStatus::ASSERTION);
    }
    else
    {
        RgbaPixel color;

        switch (mState)
        {
            case WidgetState::HOVERED:          color.red = 0x90; color.green = 0x90; color.blue = 0x90; color.alpha = 0xDD; break;
            case WidgetState::PRESSED:          color.red = 0x60; color.green = 0x60; color.blue = 0x60; color.alpha = 0xDD; break;
            case WidgetState::FOCUSED:          color.red = 0x40; color.green = 0x60; color.blue = 0x90; color.alpha = 0xDD; break;
            case WidgetState::FOCUSED_HOVERED:  color.red = 0x30; color.green = 0x40; color.blue = 0x60; color.alpha = 0xDD; break;
            case WidgetState::INACTIVE:         color.red = 0xC0; color.green = 0xC0; color.blue = 0xC0; color.alpha = 0xDD; break;
            case WidgetState::INACTIVE_HOVERED: color.red = 0xE0; color.green = 0xE0; color.blue = 0xE0; color.alpha = 0xDD; break;

            case WidgetState::NONE:
            case WidgetState::NORMAL:
            {
                COMMON_LF(("Unexpected widget state: %s", enumToFullString(mState)));

                return NgosStatus::UNEXPECTED_BEHAVIOUR;
            }
            break;

            default:
            {
                COMMON_LF(("Unknown widget state: %s", enumToFullString(mState)));

                return NgosStatus::UNEXPECTED_BEHAVIOUR;
            }
            break;
        }

        COMMON_ASSERT_EXECUTION(mOwnResultImage->fill(color), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus TreeNodeWidget::repaint()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(mOwnResultImage != nullptr, NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



    if (mResultImage)
    {
        delete mResultImage;
    }

    mResultImage = new Image(*mOwnResultImage);



    COMMON_ASSERT_EXECUTION(mExpandToolButton->lockUpdates(),                   NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(mExpandToolButton->setPosition(0, 0),               NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(mExpandToolButton->setSize(mRowHeight, mRowHeight), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(mExpandToolButton->unlockUpdates(),                 NgosStatus::ASSERTION);



    if (mImageWidget)
    {
        COMMON_ASSERT_EXECUTION(mImageWidget->lockUpdates(),                   NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(mImageWidget->setPosition(mRowHeight, 0),      NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(mImageWidget->setSize(mRowHeight, mRowHeight), NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(mImageWidget->unlockUpdates(),                 NgosStatus::ASSERTION);
    }



    if (mLabelWidget)
    {
        COMMON_ASSERT_EXECUTION(mLabelWidget->lockUpdates(),                             NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(mLabelWidget->setPosition(mRowHeight * 2, 0),            NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(mLabelWidget->setSize(mWidth - mRowHeight * 2, mHeight), NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(mLabelWidget->unlockUpdates(),                           NgosStatus::ASSERTION);
    }



    ListElement<Widget *> *element = mChildren.getHead();

    while (element)
    {
        Widget *widget = element->getData();

        COMMON_ASSERT_EXECUTION(drawWidget(widget, widget->getPositionX(), widget->getPositionY()), NgosStatus::ASSERTION);

        element = element->getNext();
    }



    COMMON_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

bool TreeNodeWidget::isAcceptMouseEvents()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return true;
}

Widget* TreeNodeWidget::getOwnerWidget()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    Widget *widget = getParent();

    do
    {
        COMMON_TEST_ASSERT(widget, nullptr);

        if (widget->isFocusable())
        {
            break;
        }

        widget = widget->getParent();
    } while(true);

    TreeWidget *treeWidget = (TreeWidget *)widget;



    return treeWidget;
}

NgosStatus TreeNodeWidget::setState(WidgetState state)
{
    COMMON_LT((" | state = %u", state));



    if (mState != state)
    {
        mState = state;

        if (
            mWidth // mWidth > 0
            &&
            mHeight // mHeight > 0
           )
        {
            COMMON_ASSERT_EXECUTION(invalidate(), NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(repaint(),    NgosStatus::ASSERTION);

            if (isVisible())
            {
                COMMON_ASSERT_EXECUTION(update(), NgosStatus::ASSERTION);
            }
        }
    }



    return NgosStatus::OK;
}

WidgetState TreeNodeWidget::getState() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mState;
}

NgosStatus TreeNodeWidget::setRowHeight(u64 height)
{
    COMMON_LT((" | height = %u", height));

    COMMON_ASSERT(height > 0, "height is zero", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mRowHeight == 0, NgosStatus::ASSERTION);



    mRowHeight = height;



    return NgosStatus::OK;
}

u64 TreeNodeWidget::getRowHeight() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mRowHeight;
}