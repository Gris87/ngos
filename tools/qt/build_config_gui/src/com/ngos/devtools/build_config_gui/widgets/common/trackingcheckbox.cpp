#include "trackingcheckbox.h"



TrackingCheckBox::TrackingCheckBox(const QString &text, QWidget *parent)
    : QCheckBox(text, parent)
{
    setMouseTracking(true);
}

void TrackingCheckBox::enterEvent(QEvent *event)
{
    QCheckBox::enterEvent(event);

    emit entered();
}

void TrackingCheckBox::leaveEvent(QEvent *event)
{
    QCheckBox::leaveEvent(event);

    emit leaved();
}
