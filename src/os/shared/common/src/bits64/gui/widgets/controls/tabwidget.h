#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_CONTROLS_TABWIDGET_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_CONTROLS_TABWIDGET_H



#include <common/src/bits64/gui/widgets/widget.h>

#include <common/src/bits64/containers/arraylist.h>
#include <common/src/bits64/gui/widgets/controls/button.h>
#include <common/src/bits64/gui/widgets/misc/tabpagewidget.h>



class TabWidget: public Widget
{
public:
    TabWidget(Image *panelImage, Widget *parent = 0); // TEST: NO
    ~TabWidget(); // TEST: NO

    NgosStatus addTabButton(Button *button); // TEST: NO
    NgosStatus addTabPage(TabPageWidget *page); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO

    NgosStatus setSize(u64 width, u64 height) override; // TEST: NO

    NgosStatus setCurrentPage(i64 page); // TEST: NO
    i64 getCurrentPage(); // TEST: NO

private:
    Image                      *mPanelImage;
    Image                      *mPanelResizedImage;
    ArrayList<Button *>         mTabButtons;
    ArrayList<TabPageWidget *>  mTabPages;
    i64                         mCurrentPage;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_CONTROLS_TABWIDGET_H
