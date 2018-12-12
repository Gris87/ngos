#include "scalegraphicsview.h"

#include <QScrollBar>



ScaleGraphicsView::ScaleGraphicsView(QWidget *parent)
    : QGraphicsView(parent)
    , mDragging(false)
    , mDraggingPosX(0)
    , mDraggingPosY(0)
{
    viewport()->setCursor(Qt::OpenHandCursor);
}

void ScaleGraphicsView::wheelEvent(QWheelEvent *event)
{
    if (event->angleDelta().y() > 0)
    {
        scale(1.1, 1.1);
    }
    else
    {
        scale(0.9, 0.9);
    }
}

void ScaleGraphicsView::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);

    if (event->button() == Qt::LeftButton)
    {
        mDragging     = true;
        mDraggingPosX = event->pos().x();
        mDraggingPosY = event->pos().y();

        viewport()->setCursor(Qt::ClosedHandCursor);
    }
}

void ScaleGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);

    if (mDragging)
    {
        qint64 mouseX = event->pos().x();
        qint64 mouseY = event->pos().y();

        horizontalScrollBar()->setValue(horizontalScrollBar()->value() + mDraggingPosX - mouseX);
        verticalScrollBar()->setValue(verticalScrollBar()->value()     + mDraggingPosY - mouseY);

        mDraggingPosX = mouseX;
        mDraggingPosY = mouseY;
    }
}

void ScaleGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::mouseReleaseEvent(event);

    if (mDragging)
    {
        mDragging = false;

        viewport()->setCursor(Qt::OpenHandCursor);
    }
}

void ScaleGraphicsView::mouseDoubleClickEvent(QMouseEvent *event)
{
    emit doubleClicked(event->pos().x(), event->pos().y());
}
