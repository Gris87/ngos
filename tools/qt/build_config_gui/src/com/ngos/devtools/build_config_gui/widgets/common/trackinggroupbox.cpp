#include "trackinggroupbox.h"



TrackingGroupBox::TrackingGroupBox(const QString &title, QWidget *parent)
    : QGroupBox(title, parent)
{
    setMouseTracking(true);
}

void TrackingGroupBox::focusInEvent(QFocusEvent *event)
{
    QGroupBox::focusInEvent(event);

    emit entered();
}

void TrackingGroupBox::focusOutEvent(QFocusEvent *event)
{
    QGroupBox::focusOutEvent(event);

    emit leaved();
}
