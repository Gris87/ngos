#include "trackingcheckbox.h"



TrackingCheckBox::TrackingCheckBox(const QString &text, QWidget *parent)
    : QCheckBox(text, parent)
{
    setMouseTracking(true);
}

void TrackingCheckBox::focusInEvent(QFocusEvent *event)
{
    QCheckBox::focusInEvent(event);

    emit entered();
}

void TrackingCheckBox::focusOutEvent(QFocusEvent *event)
{
    QCheckBox::focusOutEvent(event);

    emit leaved();
}
