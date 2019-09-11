#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_WIDGET_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_WIDGET_H



#include <common/src/bits64/containers/list.h>
#include <common/src/bits64/graphics/image.h>



class Widget
{
public:
    Widget(Widget *parent = 0); // TEST: NO
    virtual ~Widget(); // TEST: NO

    NgosStatus update(); // TEST: NO

    virtual NgosStatus update(i64 positionX, i64 positionY, u64 width, u64 height); // TEST: NO
    virtual NgosStatus invalidate(); // TEST: NO
    virtual NgosStatus repaint(); // TEST: NO

    bool hasIntersection(Widget *anotherWidget);
    bool hasIntersection(i64 positionX, i64 positionY, u64 width, u64 height);

    NgosStatus setPosition(i64 positionX, i64 positionY);
    NgosStatus setSize(u64 width, u64 height);
    NgosStatus setVisible(bool visible);

    i64 getPositionX() const;
    i64 getPositionY() const;
    u64 getWidth() const;
    u64 getHeight() const;
    Image* getResultImage() const; // TEST: NO
    bool isVisible() const;

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
    bool            mVisible;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_WIDGET_H
