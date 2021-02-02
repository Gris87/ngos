#include "rootwidget.h"

#include <com/ngos/shared/common/graphics/graphics.h>
#include <com/ngos/shared/common/gui/gui.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>



RootWidget::RootWidget()
    : Widget()
{
    COMMON_LT((""));
}

RootWidget::~RootWidget()
{
    COMMON_LT((""));



    ListElement<ScreenWidget *> *element = mScreens.getHead();

    while (element)
    {
        delete element->getData();

        element = element->getNext();
    }
}

NgosStatus RootWidget::addScreen(ScreenWidget *screen)
{
    COMMON_LT((" | screen = 0x%p", screen));

    COMMON_ASSERT(screen, "screen is null", NgosStatus::ASSERTION);



    mScreens.append(screen);



    return NgosStatus::OK;
}

NgosStatus RootWidget::applyUpdates()
{
    // COMMON_LT(("")); // Commented to avoid infinite loop



    ListElement<ScreenWidget *> *screen = mScreens.getHead();

    while (screen)
    {
        COMMON_ASSERT_EXECUTION(screen->getData()->applyUpdates(), NgosStatus::ASSERTION);

        screen = screen->getNext();
    }



    return NgosStatus::OK;
}

NgosStatus RootWidget::update(bad_int64 positionX, bad_int64 positionY, bad_uint64 width, bad_uint64 height)
{
    // COMMON_LT((" | positionX = %d, positionY = %d, width = %u, height = %u", positionX, positionY, width, height)); // Commented to avoid infinite loop

    COMMON_ASSERT(width > 0,  "width is zero",  NgosStatus::ASSERTION);
    COMMON_ASSERT(height > 0, "height is zero", NgosStatus::ASSERTION);



    ListElement<ScreenWidget *> *screen = mScreens.getHead();

    while (screen)
    {
        ScreenWidget *screenWidget = screen->getData();

        if (screenWidget->hasIntersection(positionX, positionY, width, height))
        {
            bad_int64 left   = positionX - screenWidget->getPositionX();
            bad_int64 right  = left + (bad_int64)width;
            bad_int64 top    = positionY - screenWidget->getPositionY();
            bad_int64 bottom = top + (bad_int64)height;

            if (left < 0)
            {
                left = 0;
            }

            if (top < 0)
            {
                top = 0;
            }

            if (right > (bad_int64)screenWidget->getWidth())
            {
                right = screenWidget->getWidth();
            }

            if (bottom > (bad_int64)screenWidget->getHeight())
            {
                bottom = screenWidget->getHeight();
            }

            screenWidget->updateRegion(left, top, right - left, bottom - top);
        }

        screen = screen->getNext();
    }



    ListElement<Widget *> *element = mChildren.getHead();

    while (element)
    {
        Widget *widget = element->getData();

        if (widget->hasIntersection(positionX, positionY, width, height))
        {
            bad_int64 left   = positionX - widget->getPositionX();
            bad_int64 right  = left + (bad_int64)width;
            bad_int64 top    = positionY - widget->getPositionY();
            bad_int64 bottom = top + (bad_int64)height;

            if (left < 0)
            {
                left = 0;
            }

            if (top < 0)
            {
                top = 0;
            }

            if (right > (bad_int64)widget->getResultImage()->getWidth())
            {
                right = widget->getResultImage()->getWidth();
            }

            if (bottom > (bad_int64)widget->getResultImage()->getHeight())
            {
                bottom = widget->getResultImage()->getHeight();
            }



            ListElement<ScreenWidget *> *screen = mScreens.getHead();

            while (screen)
            {
                ScreenWidget *screenWidget = screen->getData();

                if (screenWidget->hasIntersection(widget))
                {
                    COMMON_ASSERT_EXECUTION(screenWidget->drawWidget(widget, widget->getPositionX() - screenWidget->getPositionX(), widget->getPositionY() - screenWidget->getPositionY(), left, top, right, bottom), NgosStatus::ASSERTION);
                }

                screen = screen->getNext();
            }
        }

        element = element->getNext();
    }



    if (GUI::isUpdatesEnabled())
    {
        COMMON_ASSERT_EXECUTION(applyUpdates(), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

const List<ScreenWidget *>& RootWidget::getScreens() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mScreens;
}
