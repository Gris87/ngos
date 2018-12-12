#ifndef GDB_DEBUG_SRC_WIDGETS_SCALEGRAPHICSVIEW_H
#define GDB_DEBUG_SRC_WIDGETS_SCALEGRAPHICSVIEW_H



#include <QGraphicsView>

#include <QWheelEvent>



class ScaleGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit ScaleGraphicsView(QWidget *parent = 0); // TEST: NO

protected:
    void wheelEvent(QWheelEvent *event) override; // TEST: NO
    void mousePressEvent(QMouseEvent *event) override; // TEST: NO
    void mouseMoveEvent(QMouseEvent *event) override; // TEST: NO
    void mouseReleaseEvent(QMouseEvent *event) override; // TEST: NO
    void mouseDoubleClickEvent(QMouseEvent *event) override; // TEST: NO

private:
    bool   mDragging;
    qint64 mDraggingPosX;
    qint64 mDraggingPosY;

signals:
    void doubleClicked(quint64 x, quint64 y); // TEST: NO
};



#endif // GDB_DEBUG_SRC_WIDGETS_SCALEGRAPHICSVIEW_H
