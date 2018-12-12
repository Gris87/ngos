#include "trackinggroupbox.h"



TrackingGroupBox::TrackingGroupBox(const QString &title, QWidget *parent)
    : QGroupBox(title, parent)
{
    setMouseTracking(true);
}

void TrackingGroupBox::enterEvent(QEvent *event)
{
    QGroupBox::enterEvent(event);

    emit entered();
}

void TrackingGroupBox::leaveEvent(QEvent *event)
{
    QGroupBox::leaveEvent(event);

    emit leaved();
}
