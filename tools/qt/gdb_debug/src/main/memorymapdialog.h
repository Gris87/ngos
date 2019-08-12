#ifndef GDB_DEBUG_SRC_MAIN_MEMORYMAPDIALOG_H
#define GDB_DEBUG_SRC_MAIN_MEMORYMAPDIALOG_H



#include <QDialog>

#include "src/threads/memorymapthread.h"
#include "src/widgets/hexgraphicsview.h"



namespace Ui
{
    class MemoryMapDialog;
}



class MemoryMapDialog: public QDialog
{
    Q_OBJECT

public:
    explicit MemoryMapDialog(HexGraphicsView *hexgraphicsview, QWidget *parent = 0); // TEST: NO
    ~MemoryMapDialog(); // TEST: NO

private slots:
    void on_graphicsView_doubleClicked(quint64 x, quint64 y); // TEST: NO

    void workerFinished(); // TEST: NO

private:
    Ui::MemoryMapDialog      *ui;
    HexGraphicsView          *mHexgraphicsview;
    QList<MemoryMapThread *>  mWorkers;
    quint8                    mWorkersCompleted;
};



#endif // GDB_DEBUG_SRC_MAIN_MEMORYMAPDIALOG_H
