#include "treenodewidget.h"

#include <com/ngos/shared/common/graphics/graphics.h>
#include <com/ngos/shared/common/gui/gui.h>
#include <com/ngos/shared/common/gui/other/defines.h>
#include <com/ngos/shared/common/gui/widgets/controls/treewidget.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>



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
    , mExpanded(false)
    , mParentNode(nullptr)
    , mNodeIndexInParent(-1)
    , mChildrenNodes()
    , mUserData(nullptr)
{
    COMMON_LT((" | normalImage = 0x%p, hoverImage = 0x%p, pressedImage = 0x%p, collapsedImage = 0x%p, expandedImage = 0x%p, image = 0x%p, text = 0x%p, parent = 0x%p", normalImage, hoverImage, pressedImage, collapsedImage, expandedImage, image, text, parent));

    COMMON_ASSERT(normalImage,    "normalImage is null");
    COMMON_ASSERT(hoverImage,     "hoverImage is null");
    COMMON_ASSERT(pressedImage,   "pressedImage is null");
    COMMON_ASSERT(collapsedImage, "collapsedImage is null");
    COMMON_ASSERT(expandedImage,  "expandedImage is null");
    COMMON_ASSERT(parent,         "parent is null");



    COMMON_ASSERT_EXECUTION(mExpandToolButton->setVisible(false));
    COMMON_ASSERT_EXECUTION(mExpandToolButton->setPressEventHandlerObject(this));



    if (image)
    {
        mImageWidget = new ImageWidget(image, this);
    }

    if (text != nullptr && text[0] != 0)
    {
        mLabelWidget = new LabelWidget(text, this);

        COMMON_ASSERT_EXECUTION(mLabelWidget->setHorizontalAlignment(HorizontalAlignment::LEFT_JUSTIFIED));
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
    , mExpanded(false)
    , mParentNode(nullptr)
    , mNodeIndexInParent(-1)
    , mChildrenNodes()
    , mUserData(nullptr)
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



    COMMON_ASSERT_EXECUTION(mExpandToolButton->setVisible(false));
    COMMON_ASSERT_EXECUTION(mExpandToolButton->setPressEventHandlerObject(this));



    if (image)
    {
        mImageWidget = new ImageWidget(image, this);
    }

    if (text != nullptr && text[0] != 0)
    {
        mLabelWidget = new LabelWidget(text, this);

        COMMON_ASSERT_EXECUTION(mLabelWidget->setHorizontalAlignment(HorizontalAlignment::LEFT_JUSTIFIED));
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
            case WidgetState::HOVERED:          color.value32 = HOVERED_COLOR;          break;
            case WidgetState::PRESSED:          color.value32 = PRESSED_COLOR;          break;
            case WidgetState::FOCUSED:          color.value32 = FOCUSED_COLOR;          break;
            case WidgetState::FOCUSED_HOVERED:  color.value32 = FOCUSED_HOVERED_COLOR;  break;
            case WidgetState::INACTIVE:         color.value32 = INACTIVE_COLOR;         break;
            case WidgetState::INACTIVE_HOVERED: color.value32 = INACTIVE_HOVERED_COLOR; break;

            case WidgetState::NONE:
            case WidgetState::NORMAL:
            {
                COMMON_LF(("Unexpected widget state: %s, %s:%u", enumToFullString(mState), __FILE__, __LINE__));

                return NgosStatus::UNEXPECTED_BEHAVIOUR;
            }
            break;

            default:
            {
                COMMON_LF(("Unknown widget state: %s, %s:%u", enumToFullString(mState), __FILE__, __LINE__));

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

NgosStatus TreeNodeWidget::onWidgetPressed(Widget *sender)
{
    COMMON_LT((" | sender = 0x%p", sender));

    COMMON_ASSERT(sender,                      "sender is null",    NgosStatus::ASSERTION);
    COMMON_ASSERT(sender == mExpandToolButton, "sender is unknown", NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(setExpanded(!mExpanded), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

Widget* TreeNodeWidget::getOwnerWidget()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    COMMON_TEST_ASSERT(getParent(),              nullptr);
    COMMON_TEST_ASSERT(getParent()->getParent(), nullptr);

    Widget *widget = getParent()->getParent();

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



    COMMON_ASSERT_EXECUTION(treeWidget->setHighlightedTreeNodeWidget(this), nullptr);



    return treeWidget;
}

LabelWidget* TreeNodeWidget::getLabelWidget() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mLabelWidget;
}

NgosStatus TreeNodeWidget::setState(WidgetState state)
{
    COMMON_LT((" | state = %u", state));



    if (mState != state)
    {
        mState = state;

        if (
            mWidth > 0
            &&
            mHeight > 0
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

NgosStatus TreeNodeWidget::setExpanded(bool expanded)
{
    COMMON_LT((" | expanded = %u", expanded));



    if (mExpanded != expanded)
    {
        mExpanded = expanded;



        COMMON_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



        if (mExpanded)
        {
            COMMON_ASSERT_EXECUTION(mExpandToolButton->setContentImage(mExpandedImage), NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(doExpand(),                                         NgosStatus::ASSERTION);
        }
        else
        {
            COMMON_ASSERT_EXECUTION(mExpandToolButton->setContentImage(mCollapsedImage), NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(doCollapse(),                                        NgosStatus::ASSERTION);
        }



        i64 positionY = mPositionY + mRowHeight;

        if (isExpanded())
        {
            for (i64 i = 0; i < (i64)mChildrenNodes.getSize(); ++i)
            {
                COMMON_ASSERT_EXECUTION(mChildrenNodes.at(i)->invalidatePositionY(positionY), NgosStatus::ASSERTION);
            }
        }



        TreeNodeWidget *parentNode = mParentNode;
        TreeNodeWidget *curNode    = this;

        while (parentNode)
        {
            for (i64 i = curNode->mNodeIndexInParent + 1; i < (i64)parentNode->mChildrenNodes.getSize(); ++i)
            {
                COMMON_ASSERT_EXECUTION(parentNode->mChildrenNodes.at(i)->invalidatePositionY(positionY), NgosStatus::ASSERTION);
            }

            curNode    = parentNode;
            parentNode = parentNode->getParentNode();
        }



        COMMON_TEST_ASSERT(getParent(),              NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(getParent()->getParent(), NgosStatus::ASSERTION);

        Widget *widget = getParent()->getParent();

        do
        {
            COMMON_TEST_ASSERT(widget, NgosStatus::ASSERTION);

            if (widget->isFocusable())
            {
                break;
            }

            widget = widget->getParent();
        } while(true);

        TreeWidget *treeWidget = (TreeWidget *)widget;



        COMMON_ASSERT_EXECUTION(treeWidget->invalidateScrollWrapperWidget(), NgosStatus::ASSERTION);



        if (
            GUI::getRootWidget()
            &&
            !GUI::getPressedWidget()
           )
        {
            COMMON_ASSERT_EXECUTION(GUI::detectHoveredWidget(), NgosStatus::ASSERTION);
        }



        COMMON_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

bool TreeNodeWidget::isExpanded() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mExpanded;
}

NgosStatus TreeNodeWidget::setParentNode(TreeNodeWidget *node)
{
    COMMON_LT((" | node = 0x%p", node));

    COMMON_ASSERT(node, "node is null", NgosStatus::ASSERTION);



    mParentNode = node;



    return NgosStatus::OK;
}

TreeNodeWidget* TreeNodeWidget::getParentNode() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mParentNode;
}

i64 TreeNodeWidget::getNodeIndexInParent() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mNodeIndexInParent;
}

NgosStatus TreeNodeWidget::addChildNode(TreeNodeWidget *node)
{
    COMMON_LT((" | node = 0x%p", node));

    COMMON_ASSERT(node, "node is null", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mRowHeight != 0, NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(mExpandToolButton->setVisible(true), NgosStatus::ASSERTION);

    COMMON_ASSERT_EXECUTION(node->setParent(getParent()),   NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(node->setRowHeight(mRowHeight), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(node->setVisible(false),        NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(node->setSize(mWidth, mHeight), NgosStatus::ASSERTION);

    node->mNodeIndexInParent = mChildrenNodes.getSize();

    COMMON_ASSERT_EXECUTION(node->setParentNode(this),   NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(mChildrenNodes.append(node), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

const ArrayList<TreeNodeWidget *>& TreeNodeWidget::getChildrenNodes() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mChildrenNodes;
}

NgosStatus TreeNodeWidget::doExpand()
{
    COMMON_LT((""));



    for (i64 i = 0; i < (i64)mChildrenNodes.getSize(); ++i)
    {
        TreeNodeWidget *node = mChildrenNodes.at(i);

        COMMON_ASSERT_EXECUTION(node->setVisible(true), NgosStatus::ASSERTION);

        if (node->isExpanded())
        {
            COMMON_ASSERT_EXECUTION(node->doExpand(), NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus TreeNodeWidget::doCollapse()
{
    COMMON_LT((""));



    for (i64 i = 0; i < (i64)mChildrenNodes.getSize(); ++i)
    {
        TreeNodeWidget *node = mChildrenNodes.at(i);

        COMMON_ASSERT_EXECUTION(node->setVisible(false), NgosStatus::ASSERTION);

        if (node->isExpanded())
        {
            COMMON_ASSERT_EXECUTION(node->doCollapse(), NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus TreeNodeWidget::invalidatePositionY(i64 &positionY)
{
    COMMON_LT((" | positionY = %d", positionY));



    if (mParentNode)
    {
        COMMON_ASSERT_EXECUTION(setPosition(mParentNode->getPositionX() + mRowHeight, positionY), NgosStatus::ASSERTION);
    }
    else
    {
        COMMON_ASSERT_EXECUTION(setPosition(0, positionY), NgosStatus::ASSERTION);
    }

    positionY += mRowHeight;



    if (isExpanded())
    {
        for (i64 i = 0; i < (i64)mChildrenNodes.getSize(); ++i)
        {
            COMMON_ASSERT_EXECUTION(mChildrenNodes.at(i)->invalidatePositionY(positionY), NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus TreeNodeWidget::setUserData(void *data)
{
    COMMON_LT((" | data = 0x%p", data));

    COMMON_ASSERT(data, "data is null", NgosStatus::ASSERTION);



    mUserData = data;



    return NgosStatus::OK;
}

void* TreeNodeWidget::getUserData() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mUserData;
}
