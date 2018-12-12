#ifndef GDB_DEBUG_SRC_WIDGETS_TRACKINGTABLEWIDGET_H
#define GDB_DEBUG_SRC_WIDGETS_TRACKINGTABLEWIDGET_H



#include <QTableWidget>



class TrackingTableWidget : public QTableWidget
{
    Q_OBJECT

public:
    explicit TrackingTableWidget(QWidget *parent = 0); // TEST: NO

protected:
    void leaveEvent(QEvent *event) override; // TEST: NO

signals:
    void leaved(); // TEST: NO
};



#endif // GDB_DEBUG_SRC_WIDGETS_TRACKINGTABLEWIDGET_H
