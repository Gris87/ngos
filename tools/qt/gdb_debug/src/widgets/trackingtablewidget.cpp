#include "trackingtablewidget.h"



TrackingTableWidget::TrackingTableWidget(QWidget *parent)
    : QTableWidget(parent)
{
    setMouseTracking(true);
}

void TrackingTableWidget::leaveEvent(QEvent *event)
{
    QTableWidget::leaveEvent(event);

    emit leaved();
}
