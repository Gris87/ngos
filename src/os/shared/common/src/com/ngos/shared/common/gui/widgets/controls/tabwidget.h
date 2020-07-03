#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GUI_WIDGETS_CONTROLS_TABWIDGET_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GUI_WIDGETS_CONTROLS_TABWIDGET_H



#include <common/src/com/ngos/shared/common/gui/widgets/widget.h>

#include <common/src/com/ngos/shared/common/containers/arraylist.h>
#include <common/src/com/ngos/shared/common/gui/widgets/controls/tabbutton.h>
#include <common/src/com/ngos/shared/common/gui/widgets/misc/tabpagewidget.h>



class TabWidget: public Widget
{
public:
    TabWidget(Image *panelImage, Widget *parent = 0); // TEST: NO
    ~TabWidget(); // TEST: NO

    NgosStatus addTabButton(TabButton *button); // TEST: NO
    NgosStatus addTabPage(TabPageWidget *page); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO

    NgosStatus setSize(u64 width, u64 height) override; // TEST: NO

    NgosStatus setCurrentPage(i64 page); // TEST: NO
    i64 getCurrentPage(); // TEST: NO

private:
    Image                      *mPanelImage;
    ArrayList<TabButton *>      mTabButtons;
    ArrayList<TabPageWidget *>  mTabPages;
    i64                         mCurrentPage;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GUI_WIDGETS_CONTROLS_TABWIDGET_H
