#include "trackinglineedit.h"



TrackingLineEdit::TrackingLineEdit(const QString &contents, QWidget *parent)
    : QLineEdit(contents, parent)
{
    setMouseTracking(true);
}

void TrackingLineEdit::enterEvent(QEvent *event)
{
    QLineEdit::enterEvent(event);

    emit entered();
}

void TrackingLineEdit::leaveEvent(QEvent *event)
{
    QLineEdit::leaveEvent(event);

    emit leaved();
}
