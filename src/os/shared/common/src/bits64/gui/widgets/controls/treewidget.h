#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_CONTROLS_TREEWIDGET_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_CONTROLS_TREEWIDGET_H



#include <common/src/bits64/gui/widgets/widget.h>

#include <common/src/bits64/gui/widgets/misc/wrapperwidget.h>
#include <common/src/bits64/gui/widgets/misc/treenodewidget.h>



class TreeWidget: public Widget
{
public:
    TreeWidget(Image *backgroundImage, Widget *parent = 0); // TEST: NO
    ~TreeWidget(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO

    bool isFocusable() override; // TEST: NO

    NgosStatus setState(WidgetState state) override; // TEST: NO
    WidgetState getState() const override; // TEST: NO

    NgosStatus setRowHeight(u64 height); // TEST: NO
    u64 getRowHeight() const; // TEST: NO

    NgosStatus setRootNodeWidget(TreeNodeWidget *node); // TEST: NO

    NgosStatus setSelectedTreeNodeWidget(TreeNodeWidget *node); // TEST: NO
    TreeNodeWidget* getSelectedTreeNodeWidget() const; // TEST: NO

    NgosStatus setHighlightedTreeNodeWidget(TreeNodeWidget *node); // TEST: NO
    TreeNodeWidget* getHighlightedTreeNodeWidget() const; // TEST: NO

    NgosStatus setKeyboardEventHandler(keyboard_event_handler handler) override; // TEST: NO
    keyboard_event_handler getKeyboardEventHandler() const override; // TEST: NO

private:
    Image                  *mBackgroundImage;
    WidgetState             mState;
    u64                     mRowHeight;
    WrapperWidget          *mWrapperWidget;
    TreeNodeWidget         *mSelectedTreeNodeWidget;
    TreeNodeWidget         *mHighlightedTreeNodeWidget;
    keyboard_event_handler  mKeyboardEventHandler;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_CONTROLS_TREEWIDGET_H
