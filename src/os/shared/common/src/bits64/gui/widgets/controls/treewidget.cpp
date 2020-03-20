#include "treewidget.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/gui/gui.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



TreeWidget::TreeWidget(Image *backgroundImage, Widget *parent)
    : Widget(parent)
    , mBackgroundImage(backgroundImage)
    , mState(WidgetState::NORMAL)
    , mRowHeight(0)
    , mContentWrapperWidget(new WrapperWidget(this))
    , mScrollWrapperWidget(nullptr)
    , mRootNodeWidget(nullptr)
    , mSelectedTreeNodeWidget(nullptr)
    , mHighlightedTreeNodeWidget(nullptr)
    , mKeyboardEventHandler(nullptr)
{
    COMMON_LT((" | backgroundImage = 0x%p, parent = 0x%p", backgroundImage, parent));

    COMMON_ASSERT(backgroundImage, "backgroundImage is null");
    COMMON_ASSERT(parent,          "parent is null");
}

TreeWidget::~TreeWidget()
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

NgosStatus TreeWidget::invalidate()
{
    COMMON_LT((""));



    if (mOwnResultImage)
    {
        delete mOwnResultImage;
    }

    COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mBackgroundImage, mWidth, mHeight, &mOwnResultImage), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus TreeWidget::repaint()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(mOwnResultImage != nullptr, NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);



    if (mResultImage)
    {
        delete mResultImage;
    }

    mResultImage = new Image(*mOwnResultImage);



    NinePatch *patch = mBackgroundImage->getNinePatch();

    u16 paddingLeft;
    u16 paddingTop;
    u64 allowedWidth;
    u64 allowedHeight;

    if (patch)
    {
        paddingLeft = patch->getPaddingLeft();
        paddingTop  = patch->getPaddingTop();

        allowedWidth  = mWidth  - paddingLeft - patch->getPaddingRight();
        allowedHeight = mHeight - paddingTop  - patch->getPaddingBottom();
    }
    else
    {
        paddingLeft = 0;
        paddingTop  = 0;

        allowedWidth  = mWidth;
        allowedHeight = mHeight;
    }



    COMMON_ASSERT_EXECUTION(mContentWrapperWidget->lockUpdates(),                        NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(mContentWrapperWidget->setPosition(paddingLeft, paddingTop), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(mContentWrapperWidget->setSize(allowedWidth, allowedHeight), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(mContentWrapperWidget->unlockUpdates(),                      NgosStatus::ASSERTION);



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

NgosStatus TreeWidget::onKeyboardEvent(const UefiInputKey &key)
{
    COMMON_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::LEFT:
        {
            if (mSelectedTreeNodeWidget)
            {
                if (mSelectedTreeNodeWidget->isExpanded())
                {
                    COMMON_ASSERT_EXECUTION(mSelectedTreeNodeWidget->setExpanded(false), NgosStatus::ASSERTION);
                }
                else
                {
                    TreeNodeWidget *parentNode = mSelectedTreeNodeWidget->getParentNode();

                    if (parentNode)
                    {
                        COMMON_ASSERT_EXECUTION(GUI::lockUpdates(),                    NgosStatus::ASSERTION);
                        COMMON_ASSERT_EXECUTION(setSelectedTreeNodeWidget(parentNode), NgosStatus::ASSERTION);
                        COMMON_ASSERT_EXECUTION(GUI::unlockUpdates(),                  NgosStatus::ASSERTION);
                    }
                }
            }



            return NgosStatus::OK;
        }
        break;

        case UefiInputKeyScanCode::RIGHT:
        {
            if (mSelectedTreeNodeWidget)
            {
                if (!mSelectedTreeNodeWidget->isExpanded())
                {
                    if (!mSelectedTreeNodeWidget->getChildrenNodes().isEmpty())
                    {
                        COMMON_ASSERT_EXECUTION(mSelectedTreeNodeWidget->setExpanded(true), NgosStatus::ASSERTION);
                    }
                }
                else
                {
                    COMMON_ASSERT_EXECUTION(GUI::lockUpdates(),                                                           NgosStatus::ASSERTION);
                    COMMON_ASSERT_EXECUTION(setSelectedTreeNodeWidget(mSelectedTreeNodeWidget->getChildrenNodes().at(0)), NgosStatus::ASSERTION);
                    COMMON_ASSERT_EXECUTION(GUI::unlockUpdates(),                                                         NgosStatus::ASSERTION);
                }
            }



            return NgosStatus::OK;
        }
        break;

        case UefiInputKeyScanCode::UP:
        {
            if (mSelectedTreeNodeWidget)
            {
                TreeNodeWidget *parentNode = mSelectedTreeNodeWidget->getParentNode();

                if (parentNode)
                {
                    i64 nodeIndex = mSelectedTreeNodeWidget->getNodeIndexInParent();

                    if (nodeIndex > 0)
                    {
                        COMMON_ASSERT_EXECUTION(GUI::lockUpdates(),                                                          NgosStatus::ASSERTION);
                        COMMON_ASSERT_EXECUTION(setSelectedTreeNodeWidget(parentNode->getChildrenNodes().at(nodeIndex - 1)), NgosStatus::ASSERTION);
                        COMMON_ASSERT_EXECUTION(GUI::unlockUpdates(),                                                        NgosStatus::ASSERTION);
                    }
                    else
                    {
                        COMMON_ASSERT_EXECUTION(GUI::lockUpdates(),                    NgosStatus::ASSERTION);
                        COMMON_ASSERT_EXECUTION(setSelectedTreeNodeWidget(parentNode), NgosStatus::ASSERTION);
                        COMMON_ASSERT_EXECUTION(GUI::unlockUpdates(),                  NgosStatus::ASSERTION);
                    }
                }
            }



            return NgosStatus::OK;
        }
        break;

        case UefiInputKeyScanCode::DOWN:
        {
            if (mSelectedTreeNodeWidget)
            {
                if (mSelectedTreeNodeWidget->isExpanded())
                {
                    COMMON_ASSERT_EXECUTION(GUI::lockUpdates(),                                                           NgosStatus::ASSERTION);
                    COMMON_ASSERT_EXECUTION(setSelectedTreeNodeWidget(mSelectedTreeNodeWidget->getChildrenNodes().at(0)), NgosStatus::ASSERTION);
                    COMMON_ASSERT_EXECUTION(GUI::unlockUpdates(),                                                         NgosStatus::ASSERTION);
                }
                else
                {
                    TreeNodeWidget *parentNode = mSelectedTreeNodeWidget->getParentNode();

                    if (parentNode)
                    {
                        i64 nodeIndex = mSelectedTreeNodeWidget->getNodeIndexInParent();

                        if (nodeIndex < (i64)parentNode->getChildrenNodes().getSize() - 1)
                        {
                            COMMON_ASSERT_EXECUTION(GUI::lockUpdates(),                                                          NgosStatus::ASSERTION);
                            COMMON_ASSERT_EXECUTION(setSelectedTreeNodeWidget(parentNode->getChildrenNodes().at(nodeIndex + 1)), NgosStatus::ASSERTION);
                            COMMON_ASSERT_EXECUTION(GUI::unlockUpdates(),                                                        NgosStatus::ASSERTION);
                        }
                    }
                }
            }



            return NgosStatus::OK;
        }
        break;

        case UefiInputKeyScanCode::HOME:
        {
            COMMON_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);

            COMMON_ASSERT_EXECUTION(setSelectedTreeNodeWidget(mRootNodeWidget), NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(scrollToSelectedNode(),                     NgosStatus::ASSERTION);

            COMMON_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);



            return NgosStatus::OK;
        }
        break;

        case UefiInputKeyScanCode::END:
        {
            TreeNodeWidget *node = mRootNodeWidget;

            while (node->isExpanded())
            {
                const ArrayList<TreeNodeWidget *> &childrenNodes = node->getChildrenNodes();

                node = childrenNodes.at(childrenNodes.getSize() - 1);
            }



            COMMON_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);

            COMMON_ASSERT_EXECUTION(setSelectedTreeNodeWidget(node), NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(scrollToSelectedNode(),          NgosStatus::ASSERTION);

            COMMON_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);



            return NgosStatus::OK;
        }
        break;

        case UefiInputKeyScanCode::PAGE_UP:   return pageUp();
        case UefiInputKeyScanCode::PAGE_DOWN: return pageDown();

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus TreeWidget::onMouseScrollEvent(i32 delta)
{
    COMMON_LT((" | delta = %d", delta));

    COMMON_ASSERT(delta != 0, "delta is zero", NgosStatus::ASSERTION);



    i64 positionY = mScrollWrapperWidget->getPositionY() - mRowHeight * delta;

    if (positionY < (i64)(mContentWrapperWidget->getHeight() - mScrollWrapperWidget->getHeight()))
    {
        positionY = mContentWrapperWidget->getHeight() - mScrollWrapperWidget->getHeight();
    }

    if (positionY > 0)
    {
        positionY = 0;
    }

    COMMON_ASSERT_EXECUTION(mScrollWrapperWidget->setPosition(0, positionY), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus TreeWidget::scrollToSelectedNode()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(mSelectedTreeNodeWidget != nullptr, NgosStatus::ASSERTION);



    i64 localPositionY  = mSelectedTreeNodeWidget->getPositionY();
    i64 globalPositionY = localPositionY + mScrollWrapperWidget->getPositionY();

    if (globalPositionY < 0)
    {
        COMMON_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);

        COMMON_ASSERT_EXECUTION(mScrollWrapperWidget->setPosition(0, -localPositionY), NgosStatus::ASSERTION);

        if (!GUI::getPressedWidget())
        {
            COMMON_ASSERT_EXECUTION(GUI::detectHoveredWidget(), NgosStatus::ASSERTION);
        }

        COMMON_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);
    }
    else
    if (globalPositionY + (i64)mRowHeight > (i64)mContentWrapperWidget->getHeight())
    {
        COMMON_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);

        COMMON_ASSERT_EXECUTION(mScrollWrapperWidget->setPosition(0, (i64)mContentWrapperWidget->getHeight() - localPositionY - mRowHeight), NgosStatus::ASSERTION);

        if (!GUI::getPressedWidget())
        {
            COMMON_ASSERT_EXECUTION(GUI::detectHoveredWidget(), NgosStatus::ASSERTION);
        }

        COMMON_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus TreeWidget::pageUp()
{
    COMMON_LT((""));

    // TODO: Implement

    return NgosStatus::OK;
}

NgosStatus TreeWidget::pageDown()
{
    COMMON_LT((""));

    // TODO: Implement

    return NgosStatus::OK;
}

NgosStatus TreeWidget::invalidateScrollWrapperWidget()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(mRootNodeWidget != nullptr, NgosStatus::ASSERTION);



    TreeNodeWidget *node = mRootNodeWidget;

    while (node->isExpanded())
    {
        const ArrayList<TreeNodeWidget *> &childrenNodes = node->getChildrenNodes();

        node = childrenNodes.at(childrenNodes.getSize() - 1);
    }

    COMMON_ASSERT_EXECUTION(mScrollWrapperWidget->setSize(mContentWrapperWidget->getWidth(), node->getPositionY() + mRowHeight), NgosStatus::ASSERTION);



    if (mScrollWrapperWidget->getPositionY() < (i64)(mContentWrapperWidget->getHeight() - mScrollWrapperWidget->getHeight()))
    {
        i64 positionY = mContentWrapperWidget->getHeight() - mScrollWrapperWidget->getHeight();

        if (positionY > 0)
        {
            positionY = 0;
        }

        COMMON_ASSERT_EXECUTION(mScrollWrapperWidget->setPosition(0, positionY), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

bool TreeWidget::isFocusable()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return true;
}

NgosStatus TreeWidget::setState(WidgetState state)
{
    COMMON_LT((" | state = %u", state));



    if (
        mState != state
        ||
        (
         (
          mState == WidgetState::FOCUSED
          ||
          mState == WidgetState::FOCUSED_HOVERED
         )
         &&
         mHighlightedTreeNodeWidget
        )
       )
    {
        if (mState != state)
        {
            mState = state;
        }
        else
        {
            COMMON_ASSERT_EXECUTION(setSelectedTreeNodeWidget(mHighlightedTreeNodeWidget), NgosStatus::ASSERTION);
        }



        switch (mState)
        {
            case WidgetState::NORMAL:
            {
                COMMON_ASSERT_EXECUTION(setHighlightedTreeNodeWidget(nullptr), NgosStatus::ASSERTION);

                switch (mSelectedTreeNodeWidget->getState())
                {
                    case WidgetState::FOCUSED: COMMON_ASSERT_EXECUTION(mSelectedTreeNodeWidget->setState(WidgetState::INACTIVE), NgosStatus::ASSERTION); break;

                    case WidgetState::INACTIVE:
                    {
                        // Nothing
                    }
                    break;

                    case WidgetState::NONE:
                    case WidgetState::NORMAL:
                    case WidgetState::HOVERED:
                    case WidgetState::PRESSED:
                    case WidgetState::FOCUSED_HOVERED:
                    case WidgetState::INACTIVE_HOVERED:
                    {
                        COMMON_LF(("Unexpected widget state: %s, %s:%u", enumToFullString(mSelectedTreeNodeWidget->getState()), __FILE__, __LINE__));

                        return NgosStatus::UNEXPECTED_BEHAVIOUR;
                    }
                    break;

                    default:
                    {
                        COMMON_LF(("Unknown widget state: %s, %s:%u", enumToFullString(mSelectedTreeNodeWidget->getState()), __FILE__, __LINE__));

                        return NgosStatus::UNEXPECTED_BEHAVIOUR;
                    }
                    break;
                }
            }
            break;

            case WidgetState::FOCUSED:
            {
                COMMON_ASSERT_EXECUTION(setHighlightedTreeNodeWidget(nullptr), NgosStatus::ASSERTION);

                switch (mSelectedTreeNodeWidget->getState())
                {
                    case WidgetState::INACTIVE: COMMON_ASSERT_EXECUTION(mSelectedTreeNodeWidget->setState(WidgetState::FOCUSED), NgosStatus::ASSERTION); break;

                    case WidgetState::FOCUSED:
                    {
                        // Nothing
                    }
                    break;

                    case WidgetState::NONE:
                    case WidgetState::NORMAL:
                    case WidgetState::HOVERED:
                    case WidgetState::PRESSED:
                    case WidgetState::FOCUSED_HOVERED:
                    case WidgetState::INACTIVE_HOVERED:
                    {
                        COMMON_LF(("Unexpected widget state: %s, %s:%u", enumToFullString(mSelectedTreeNodeWidget->getState()), __FILE__, __LINE__));

                        return NgosStatus::UNEXPECTED_BEHAVIOUR;
                    }
                    break;

                    default:
                    {
                        COMMON_LF(("Unknown widget state: %s, %s:%u", enumToFullString(mSelectedTreeNodeWidget->getState()), __FILE__, __LINE__));

                        return NgosStatus::UNEXPECTED_BEHAVIOUR;
                    }
                    break;
                }
            }
            break;

            case WidgetState::FOCUSED_HOVERED:
            {
                switch (mSelectedTreeNodeWidget->getState())
                {
                    case WidgetState::INACTIVE:         COMMON_ASSERT_EXECUTION(mSelectedTreeNodeWidget->setState(WidgetState::FOCUSED),         NgosStatus::ASSERTION); break;
                    case WidgetState::INACTIVE_HOVERED: COMMON_ASSERT_EXECUTION(mSelectedTreeNodeWidget->setState(WidgetState::FOCUSED_HOVERED), NgosStatus::ASSERTION); break;

                    case WidgetState::FOCUSED:
                    case WidgetState::FOCUSED_HOVERED:
                    {
                        // Nothing
                    }
                    break;

                    case WidgetState::NONE:
                    case WidgetState::NORMAL:
                    case WidgetState::HOVERED:
                    case WidgetState::PRESSED:
                    {
                        COMMON_LF(("Unexpected widget state: %s, %s:%u", enumToFullString(mSelectedTreeNodeWidget->getState()), __FILE__, __LINE__));

                        return NgosStatus::UNEXPECTED_BEHAVIOUR;
                    }
                    break;

                    default:
                    {
                        COMMON_LF(("Unknown widget state: %s, %s:%u", enumToFullString(mSelectedTreeNodeWidget->getState()), __FILE__, __LINE__));

                        return NgosStatus::UNEXPECTED_BEHAVIOUR;
                    }
                    break;
                }
            }
            break;

            case WidgetState::PRESSED:
            {
                if (mHighlightedTreeNodeWidget)
                {
                    COMMON_ASSERT_EXECUTION(setSelectedTreeNodeWidget(mHighlightedTreeNodeWidget), NgosStatus::ASSERTION);
                }
            }
            break;

            case WidgetState::HOVERED:
            {
                switch (mSelectedTreeNodeWidget->getState())
                {
                    case WidgetState::FOCUSED:         COMMON_ASSERT_EXECUTION(mSelectedTreeNodeWidget->setState(WidgetState::INACTIVE),         NgosStatus::ASSERTION); break;
                    case WidgetState::FOCUSED_HOVERED: COMMON_ASSERT_EXECUTION(mSelectedTreeNodeWidget->setState(WidgetState::INACTIVE_HOVERED), NgosStatus::ASSERTION); break;

                    case WidgetState::INACTIVE:
                    case WidgetState::INACTIVE_HOVERED:
                    {
                        // Nothing
                    }
                    break;

                    case WidgetState::NONE:
                    case WidgetState::NORMAL:
                    case WidgetState::HOVERED:
                    case WidgetState::PRESSED:
                    {
                        COMMON_LF(("Unexpected widget state: %s, %s:%u", enumToFullString(mSelectedTreeNodeWidget->getState()), __FILE__, __LINE__));

                        return NgosStatus::UNEXPECTED_BEHAVIOUR;
                    }
                    break;

                    default:
                    {
                        COMMON_LF(("Unknown widget state: %s, %s:%u", enumToFullString(mSelectedTreeNodeWidget->getState()), __FILE__, __LINE__));

                        return NgosStatus::UNEXPECTED_BEHAVIOUR;
                    }
                    break;
                }
            }
            break;

            case WidgetState::NONE:
            case WidgetState::INACTIVE:
            case WidgetState::INACTIVE_HOVERED:
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
    }



    return NgosStatus::OK;
}

WidgetState TreeWidget::getState() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mState;
}

NgosStatus TreeWidget::setRowHeight(u64 height)
{
    COMMON_LT((" | height = %u", height));

    COMMON_ASSERT(height > 0, "height is zero", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mRowHeight == 0, NgosStatus::ASSERTION);



    mRowHeight = height;



    return NgosStatus::OK;
}

u64 TreeWidget::getRowHeight() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mRowHeight;
}

NgosStatus TreeWidget::setRootNodeWidget(TreeNodeWidget *node)
{
    COMMON_LT((" | node = 0x%p", node));

    COMMON_ASSERT(node, "node is null", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mRowHeight           != 0,       NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mScrollWrapperWidget == nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mRootNodeWidget      == nullptr, NgosStatus::ASSERTION);



    mScrollWrapperWidget = new WrapperWidget(mContentWrapperWidget);


    mRootNodeWidget = node;

    COMMON_ASSERT_EXECUTION(mRootNodeWidget->setParent(mScrollWrapperWidget),                        NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(mRootNodeWidget->setRowHeight(mRowHeight),                               NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(mRootNodeWidget->setSize(mContentWrapperWidget->getWidth(), mRowHeight), NgosStatus::ASSERTION);

    COMMON_ASSERT_EXECUTION(setSelectedTreeNodeWidget(mRootNodeWidget), NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(mScrollWrapperWidget->setSize(mContentWrapperWidget->getWidth(), mRowHeight), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus TreeWidget::setSelectedTreeNodeWidget(TreeNodeWidget *node)
{
    COMMON_LT((" | node = 0x%p", node));



    if (mSelectedTreeNodeWidget != node)
    {
        TreeNodeWidget *previousNode = mSelectedTreeNodeWidget;

        mSelectedTreeNodeWidget = node;



        if (previousNode)
        {
            switch (previousNode->getState())
            {
                case WidgetState::FOCUSED:          COMMON_ASSERT_EXECUTION(previousNode->setState(WidgetState::NORMAL),  NgosStatus::ASSERTION); break;
                case WidgetState::FOCUSED_HOVERED:  COMMON_ASSERT_EXECUTION(previousNode->setState(WidgetState::HOVERED), NgosStatus::ASSERTION); break;
                case WidgetState::INACTIVE:         COMMON_ASSERT_EXECUTION(previousNode->setState(WidgetState::NORMAL),  NgosStatus::ASSERTION); break;
                case WidgetState::INACTIVE_HOVERED: COMMON_ASSERT_EXECUTION(previousNode->setState(WidgetState::HOVERED), NgosStatus::ASSERTION); break;

                case WidgetState::NONE:
                case WidgetState::NORMAL:
                case WidgetState::HOVERED:
                case WidgetState::PRESSED:
                {
                    COMMON_LF(("Unexpected widget state: %s, %s:%u", enumToFullString(previousNode->getState()), __FILE__, __LINE__));

                    return NgosStatus::UNEXPECTED_BEHAVIOUR;
                }
                break;

                default:
                {
                    COMMON_LF(("Unknown widget state: %s, %s:%u", enumToFullString(previousNode->getState()), __FILE__, __LINE__));

                    return NgosStatus::UNEXPECTED_BEHAVIOUR;
                }
                break;
            }
        }



        if (mSelectedTreeNodeWidget)
        {
            switch (mSelectedTreeNodeWidget->getState())
            {
                case WidgetState::NORMAL:  COMMON_ASSERT_EXECUTION(mSelectedTreeNodeWidget->setState(isFocused() ? WidgetState::FOCUSED         : WidgetState::INACTIVE),         NgosStatus::ASSERTION); break;
                case WidgetState::HOVERED: COMMON_ASSERT_EXECUTION(mSelectedTreeNodeWidget->setState(isFocused() ? WidgetState::FOCUSED_HOVERED : WidgetState::INACTIVE_HOVERED), NgosStatus::ASSERTION); break;

                case WidgetState::NONE:
                case WidgetState::PRESSED:
                case WidgetState::FOCUSED:
                case WidgetState::FOCUSED_HOVERED:
                case WidgetState::INACTIVE:
                case WidgetState::INACTIVE_HOVERED:
                {
                    COMMON_LF(("Unexpected widget state: %s, %s:%u", enumToFullString(mSelectedTreeNodeWidget->getState()), __FILE__, __LINE__));

                    return NgosStatus::UNEXPECTED_BEHAVIOUR;
                }
                break;

                default:
                {
                    COMMON_LF(("Unknown widget state: %s, %s:%u", enumToFullString(mSelectedTreeNodeWidget->getState()), __FILE__, __LINE__));

                    return NgosStatus::UNEXPECTED_BEHAVIOUR;
                }
                break;
            }
        }
    }



    return NgosStatus::OK;
}

TreeNodeWidget* TreeWidget::getSelectedTreeNodeWidget() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mSelectedTreeNodeWidget;
}

NgosStatus TreeWidget::setHighlightedTreeNodeWidget(TreeNodeWidget *node)
{
    COMMON_LT((" | node = 0x%p", node));



    if (mHighlightedTreeNodeWidget != node)
    {
        TreeNodeWidget *previousNode = mHighlightedTreeNodeWidget;

        mHighlightedTreeNodeWidget = node;



        if (previousNode)
        {
            switch (previousNode->getState())
            {
                case WidgetState::HOVERED:          COMMON_ASSERT_EXECUTION(previousNode->setState(WidgetState::NORMAL),   NgosStatus::ASSERTION); break;
                case WidgetState::FOCUSED_HOVERED:  COMMON_ASSERT_EXECUTION(previousNode->setState(WidgetState::FOCUSED),  NgosStatus::ASSERTION); break;
                case WidgetState::INACTIVE_HOVERED: COMMON_ASSERT_EXECUTION(previousNode->setState(WidgetState::INACTIVE), NgosStatus::ASSERTION); break;

                case WidgetState::NONE:
                case WidgetState::NORMAL:
                case WidgetState::PRESSED:
                case WidgetState::FOCUSED:
                case WidgetState::INACTIVE:
                {
                    COMMON_LF(("Unexpected widget state: %s, %s:%u", enumToFullString(previousNode->getState()), __FILE__, __LINE__));

                    return NgosStatus::UNEXPECTED_BEHAVIOUR;
                }
                break;

                default:
                {
                    COMMON_LF(("Unknown widget state: %s, %s:%u", enumToFullString(previousNode->getState()), __FILE__, __LINE__));

                    return NgosStatus::UNEXPECTED_BEHAVIOUR;
                }
                break;
            }
        }



        if (mHighlightedTreeNodeWidget)
        {
            switch (mHighlightedTreeNodeWidget->getState())
            {
                case WidgetState::NORMAL:   COMMON_ASSERT_EXECUTION(mHighlightedTreeNodeWidget->setState(WidgetState::HOVERED),          NgosStatus::ASSERTION); break;
                case WidgetState::FOCUSED:  COMMON_ASSERT_EXECUTION(mHighlightedTreeNodeWidget->setState(WidgetState::FOCUSED_HOVERED),  NgosStatus::ASSERTION); break;
                case WidgetState::INACTIVE: COMMON_ASSERT_EXECUTION(mHighlightedTreeNodeWidget->setState(WidgetState::INACTIVE_HOVERED), NgosStatus::ASSERTION); break;

                case WidgetState::NONE:
                case WidgetState::HOVERED:
                case WidgetState::PRESSED:
                case WidgetState::FOCUSED_HOVERED:
                case WidgetState::INACTIVE_HOVERED:
                {
                    COMMON_LF(("Unexpected widget state: %s, %s:%u", enumToFullString(mHighlightedTreeNodeWidget->getState()), __FILE__, __LINE__));

                    return NgosStatus::UNEXPECTED_BEHAVIOUR;
                }
                break;

                default:
                {
                    COMMON_LF(("Unknown widget state: %s, %s:%u", enumToFullString(mHighlightedTreeNodeWidget->getState()), __FILE__, __LINE__));

                    return NgosStatus::UNEXPECTED_BEHAVIOUR;
                }
                break;
            }
        }
    }



    return NgosStatus::OK;
}

TreeNodeWidget* TreeWidget::getHighlightedTreeNodeWidget() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mHighlightedTreeNodeWidget;
}

NgosStatus TreeWidget::setKeyboardEventHandler(keyboard_event_handler handler)
{
    COMMON_LT((" | handler = 0x%p", handler));



    mKeyboardEventHandler = handler;



    return NgosStatus::OK;
}

keyboard_event_handler TreeWidget::getKeyboardEventHandler() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mKeyboardEventHandler;
}
