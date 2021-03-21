#ifndef COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_TREENODEWIDGET_H
#define COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_TREENODEWIDGET_H



#include <com/ngos/shared/common/gui/other/presseventhandler.h>
#include <com/ngos/shared/common/gui/widgets/widget.h>

#include <com/ngos/shared/common/containers/arraylist.h>
#include <com/ngos/shared/common/gui/widgets/controls/toolbutton.h>
#include <com/ngos/shared/common/gui/widgets/misc/imagewidget.h>
#include <com/ngos/shared/common/gui/widgets/misc/labelwidget.h>



class TreeNodeWidget: public Widget, public PressEventHandler
{
public:
    TreeNodeWidget(Image *normalImage, Image *hoverImage, Image *pressedImage, Image *collapsedImage, Image *expandedImage, Image *image, const char8* text, Widget *parent = nullptr); // TEST: NO
    TreeNodeWidget(Image *normalImage, Image *hoverImage, Image *pressedImage, Image *normalResizedImage, Image *hoverResizedImage, Image *pressedResizedImage, Image *collapsedImage, Image *expandedImage, Image *image, const char8* text, Widget *parent = nullptr); // TEST: NO
    ~TreeNodeWidget(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO

    bool isAcceptMouseEvents() override; // TEST: NO
    NgosStatus onWidgetPressed(Widget *sender) override; // TEST: NO

    Widget* getOwnerWidget() override; // TEST: NO

    LabelWidget* getLabelWidget() const; // TEST: NO

    NgosStatus setState(WidgetState state) override; // TEST: NO
    WidgetState getState() const override; // TEST: NO

    NgosStatus setRowHeight(u64 height); // TEST: NO
    u64 getRowHeight() const; // TEST: NO

    NgosStatus setExpanded(bool expanded); // TEST: NO
    bool isExpanded() const; // TEST: NO

    NgosStatus setParentNode(TreeNodeWidget *node); // TEST: NO
    TreeNodeWidget* getParentNode() const; // TEST: NO

    i64 getNodeIndexInParent() const; // TEST: NO

    NgosStatus addChildNode(TreeNodeWidget *node); // TEST: NO

    const ArrayList<TreeNodeWidget *>& getChildrenNodes() const; // TEST: NO

    NgosStatus setUserData(void *data); // TEST: NO
    void* getUserData() const; // TEST: NO

private:
    NgosStatus doExpand(); // TEST: NO
    NgosStatus doCollapse(); // TEST: NO
    NgosStatus invalidatePositionY(i64 &positionY); // TEST: NO

    Image                       *mCollapsedImage;
    Image                       *mExpandedImage;
    Image                       *mImage;
    ToolButton                  *mExpandToolButton;
    ImageWidget                 *mImageWidget;
    LabelWidget                 *mLabelWidget;
    WidgetState                  mState;
    u64                          mRowHeight;
    bool                         mExpanded;
    TreeNodeWidget              *mParentNode;
    i64                          mNodeIndexInParent;
    ArrayList<TreeNodeWidget *>  mChildrenNodes;
    void                        *mUserData;
};



#endif // COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_TREENODEWIDGET_H
