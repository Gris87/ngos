#ifndef COM_NGOS_SHARED_COMMON_GUI_WIDGETS_WIDGET_H
#define COM_NGOS_SHARED_COMMON_GUI_WIDGETS_WIDGET_H



#include <com/ngos/shared/common/containers/list.h>
#include <com/ngos/shared/common/graphics/image.h>
#include <com/ngos/shared/common/gui/other/presseventhandler.h>
#include <com/ngos/shared/common/gui/other/widgetstate.h>
#include <com/ngos/shared/common/uefi/uefiinputkey.h>



typedef NgosStatus (*keyboard_event_handler) (const UefiInputKey &key);
typedef NgosStatus (*press_event_handler) ();



class Widget
{
public:
    Widget(Widget *parent = 0); // TEST: NO
    virtual ~Widget(); // TEST: NO

    NgosStatus update(); // TEST: NO

    virtual NgosStatus update(bad_int64 positionX, bad_int64 positionY, bad_uint64 width, bad_uint64 height); // TEST: NO
    virtual NgosStatus invalidate(); // TEST: NO
    virtual NgosStatus repaint(); // TEST: NO
    virtual NgosStatus onKeyboardEvent(const UefiInputKey &key); // TEST: NO
    virtual NgosStatus onMouseScrollEvent(bad_int32 delta); // TEST: NO

    NgosStatus drawWidget(Widget *widget, bad_int64 positionX, bad_int64 positionY); // TEST: NO
    NgosStatus drawWidget(Widget *widget, bad_int64 positionX, bad_int64 positionY, bad_int64 left, bad_int64 top, bad_int64 right, bad_int64 bottom); // TEST: NO

    Widget* detectHoveredWidget(bad_int64 positionX, bad_int64 positionY); // TEST: NO
    virtual bool isAcceptMouseEvents(); // TEST: NO

    bool hasIntersection(Widget *anotherWidget);
    bool hasIntersection(bad_int64 positionX, bad_int64 positionY, bad_uint64 width, bad_uint64 height);

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

    NgosStatus setPosition(bad_int64 positionX, bad_int64 positionY);
    bad_int64 getPositionX() const;
    bad_int64 getPositionY() const;
    bad_int64 getGlobalPositionX() const;
    bad_int64 getGlobalPositionY() const;

    virtual NgosStatus setSize(bad_uint64 width, bad_uint64 height);
    bad_uint64 getWidth() const;
    bad_uint64 getHeight() const;

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
    bad_int64             mPositionX;
    bad_int64             mPositionY;
    bad_uint64             mWidth;
    bad_uint64             mHeight;
    bool            mVisible;
    bad_uint8              mUpdatesLocks;
    Image          *mOwnResultImage;
    Image          *mResultImage;
};



#endif // COM_NGOS_SHARED_COMMON_GUI_WIDGETS_WIDGET_H
