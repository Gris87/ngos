#include "trackingcombobox.h"



TrackingComboBox::TrackingComboBox(QWidget *parent)
    : QComboBox(parent)
{
    setMouseTracking(true);
}

void TrackingComboBox::focusInEvent(QFocusEvent *event)
{
    QComboBox::focusInEvent(event);

    emit entered();
}

void TrackingComboBox::focusOutEvent(QFocusEvent *event)
{
    QComboBox::focusOutEvent(event);

    emit leaved();
}
