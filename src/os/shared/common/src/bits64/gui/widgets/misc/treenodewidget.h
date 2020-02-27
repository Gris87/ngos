#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_TREENODEWIDGET_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_TREENODEWIDGET_H



#include <common/src/bits64/gui/widgets/widget.h>

#include <common/src/bits64/gui/widgets/controls/button.h>
#include <common/src/bits64/gui/widgets/misc/imagewidget.h>
#include <common/src/bits64/gui/widgets/misc/labelwidget.h>



class TreeNodeWidget: public Widget
{
public:
    TreeNodeWidget(Image *normalImage, Image *hoverImage, Image *pressedImage, Image *focusedImage, Image *focusedHoverImage, Image *collapsedImage, Image *expandedImage, Image *image, const char8* text, Widget *parent = 0); // TEST: NO
    TreeNodeWidget(Image *normalImage, Image *hoverImage, Image *pressedImage, Image *focusedImage, Image *focusedHoverImage, Image *normalResizedImage, Image *hoverResizedImage, Image *pressedResizedImage, Image *focusedResizedImage, Image *focusedHoverResizedImage, Image *collapsedImage, Image *expandedImage, Image *image, const char8* text, Widget *parent = 0); // TEST: NO
    ~TreeNodeWidget(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO

    NgosStatus setRowHeight(u64 height); // TEST: NO
    u64 getRowHeight() const; // TEST: NO

private:
    Image       *mCollapsedImage;
    Image       *mExpandedImage;
    Image       *mImage;
    Button      *mExpandButton;
    ImageWidget *mImageWidget;
    LabelWidget *mLabelWidget;
    u64          mRowHeight;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_TREENODEWIDGET_H
