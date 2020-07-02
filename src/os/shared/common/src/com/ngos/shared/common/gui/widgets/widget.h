#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_WIDGET_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_WIDGET_H



#include <common/src/com/ngos/shared/common/containers/list.h>
#include <common/src/com/ngos/shared/common/graphics/image.h>
#include <common/src/com/ngos/shared/common/gui/other/presseventhandler.h>
#include <common/src/com/ngos/shared/common/gui/other/widgetstate.h>
#include <common/src/com/ngos/shared/common/uefi/uefiinputkey.h>



typedef NgosStatus (*keyboard_event_handler) (const UefiInputKey &key);
typedef NgosStatus (*press_event_handler) ();



class Widget
{
public:
    Widget(Widget *parent = 0); // TEST: NO
    virtual ~Widget(); // TEST: NO

    NgosStatus update(); // TEST: NO

    virtual NgosStatus update(i64 positionX, i64 positionY, u64 width, u64 height); // TEST: NO
    virtual NgosStatus invalidate(); // TEST: NO
    virtual NgosStatus repaint(); // TEST: NO
    virtual NgosStatus onKeyboardEvent(const UefiInputKey &key); // TEST: NO
    virtual NgosStatus onMouseScrollEvent(i32 delta); // TEST: NO

    NgosStatus drawWidget(Widget *widget, i64 positionX, i64 positionY); // TEST: NO
    NgosStatus drawWidget(Widget *widget, i64 positionX, i64 positionY, i64 left, i64 top, i64 right, i64 bottom); // TEST: NO

    Widget* detectHoveredWidget(i64 positionX, i64 positionY); // TEST: NO
    virtual bool isAcceptMouseEvents(); // TEST: NO

    bool hasIntersection(Widget *anotherWidget);
    bool hasIntersection(i64 positionX, i64 positionY, u64 width, u64 height);

    NgosStatus lockUpdates(); // TEST: NO
    NgosStatus unlockUpdates(); // TEST: NO

    bool isUpdatesEnabled(); // TEST: NO

    bool isFocused(); // TEST: NO
    virtual bool isFocusable(); // TEST: NO
    virtual Widget* getOwnerWidget(); // TEST: NO

    virtual NgosStatus setState(WidgetState state); // TEST: NO
    virtual WidgetState getState() const; // TEST: NO

    virtual NgosStatus setKeyboardEventHandler(keyboard_event_handler handler); // TEST: NO
    virtual keyboard_event_handler getKeyboardEventHandler() const; // TEST: NO

    virtual NgosStatus setPressEventHandler(press_event_handler handler); // TEST: NO
    virtual press_event_handler getPressEventHandler() const; // TEST: NO

    virtual NgosStatus setPressEventHandlerObject(PressEventHandler *handler); // TEST: NO
    virtual PressEventHandler* getPressEventHandlerObject() const; // TEST: NO

    NgosStatus setParent(Widget *parent); // TEST: NO
    Widget* getParent() const; // TEST: NO

    List<Widget *>& getChildren(); // TEST: NO

    NgosStatus setPosition(i64 positionX, i64 positionY);
    i64 getPositionX() const;
    i64 getPositionY() const;
    i64 getGlobalPositionX() const;
    i64 getGlobalPositionY() const;

    virtual NgosStatus setSize(u64 width, u64 height);
    u64 getWidth() const;
    u64 getHeight() const;

    NgosStatus setVisible(bool visible);
    bool isVisible() const;

    Image* getOwnResultImage() const; // TEST: NO
    Image* getResultImage() const; // TEST: NO

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
    bool            mVisible;
    u8              mUpdatesLocks;
    Image          *mOwnResultImage;
    Image          *mResultImage;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_WIDGET_H
