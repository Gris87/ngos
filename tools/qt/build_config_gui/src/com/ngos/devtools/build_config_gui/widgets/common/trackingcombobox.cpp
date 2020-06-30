#include "trackingcombobox.h"



TrackingComboBox::TrackingComboBox(QWidget *parent)
    : QComboBox(parent)
{
    setMouseTracking(true);
}

void TrackingComboBox::enterEvent(QEvent *event)
{
    QComboBox::enterEvent(event);

    emit entered();
}

void TrackingComboBox::leaveEvent(QEvent *event)
{
    QComboBox::leaveEvent(event);

    emit leaved();
}
