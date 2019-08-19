#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_WIDGET_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_WIDGET_H



#include <common/src/bits64/containers/list.h>
#include <common/src/bits64/graphics/image.h>



class Widget
{
public:
    Widget(Widget *parent = 0); // TEST: NO
    virtual ~Widget(); // TEST: NO

    virtual NgosStatus invalidate(); // TEST: NO
    virtual NgosStatus repaint(); // TEST: NO

    NgosStatus setPosition(i64 positionX, i64 positionY);
    NgosStatus setSize(u64 width, u64 height);

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
protected:
#endif
    Widget         *mParent;
    List<Widget *>  mChildren;
    i64             mPositionX;
    i64             mPositionY;
    u64             mWidth;
    u64             mHeight;
    Image          *mResultImage;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_WIDGET_H
