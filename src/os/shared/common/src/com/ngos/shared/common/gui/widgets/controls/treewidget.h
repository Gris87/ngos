#ifndef COM_NGOS_SHARED_COMMON_GUI_WIDGETS_CONTROLS_TREEWIDGET_H
#define COM_NGOS_SHARED_COMMON_GUI_WIDGETS_CONTROLS_TREEWIDGET_H



#include <com/ngos/shared/common/gui/widgets/widget.h>

#include <com/ngos/shared/common/gui/widgets/misc/treenodewidget.h>
#include <com/ngos/shared/common/gui/widgets/misc/wrapperwidget.h>



typedef NgosStatus (*tree_widget_node_select_event_handler) (TreeNodeWidget *node);



class TreeWidget: public Widget
{
public:
    TreeWidget(Image *backgroundImage, Widget *parent = nullptr); // TEST: NO
    ~TreeWidget(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO
    NgosStatus onKeyboardEvent(const UefiInputKey &key) override; // TEST: NO
    NgosStatus onMouseScrollEvent(i32 delta) override; // TEST: NO

    NgosStatus scrollToSelectedNode(); // TEST: NO
    NgosStatus pageUp(); // TEST: NO
    NgosStatus pageDown(); // TEST: NO

    NgosStatus invalidateScrollWrapperWidget(); // TEST: NO

    bool isFocusable() override; // TEST: NO

    NgosStatus setState(WidgetState state) override; // TEST: NO
    WidgetState getState() const override; // TEST: NO

    NgosStatus setRowHeight(u64 height); // TEST: NO
    u64 getRowHeight() const; // TEST: NO

    NgosStatus setRootNodeWidget(TreeNodeWidget *node); // TEST: NO
    TreeNodeWidget* getRootNodeWidget() const; // TEST: NO

    NgosStatus setSelectedTreeNodeWidget(TreeNodeWidget *node); // TEST: NO
    TreeNodeWidget* getSelectedTreeNodeWidget() const; // TEST: NO

    NgosStatus setHighlightedTreeNodeWidget(TreeNodeWidget *node); // TEST: NO
    TreeNodeWidget* getHighlightedTreeNodeWidget() const; // TEST: NO

    NgosStatus setKeyboardEventHandler(keyboard_event_handler handler) override; // TEST: NO
    keyboard_event_handler getKeyboardEventHandler() const override; // TEST: NO

    NgosStatus setNodeSelectEventHandler(tree_widget_node_select_event_handler handler); // TEST: NO
    tree_widget_node_select_event_handler getNodeSelectEventHandler() const; // TEST: NO

private:
    Image                                 *mBackgroundImage;
    WidgetState                            mState;
    u64                                    mRowHeight;
    WrapperWidget                         *mContentWrapperWidget;
    WrapperWidget                         *mScrollWrapperWidget;
    TreeNodeWidget                        *mRootNodeWidget;
    TreeNodeWidget                        *mSelectedTreeNodeWidget;
    TreeNodeWidget                        *mHighlightedTreeNodeWidget;
    keyboard_event_handler                 mKeyboardEventHandler;
    tree_widget_node_select_event_handler  mNodeSelectEventHandler;
    i64                                    mLastTimePressed;
};



#endif // COM_NGOS_SHARED_COMMON_GUI_WIDGETS_CONTROLS_TREEWIDGET_H
