#include "trackinglineedit.h"



TrackingLineEdit::TrackingLineEdit(const QString &contents, QWidget *parent)
    : QLineEdit(contents, parent)
{
    setMouseTracking(true);
}

void TrackingLineEdit::focusInEvent(QFocusEvent *event)
{
    QLineEdit::focusInEvent(event);

    emit entered();
}

void TrackingLineEdit::focusOutEvent(QFocusEvent *event)
{
    QLineEdit::focusOutEvent(event);

    emit leaved();
}
