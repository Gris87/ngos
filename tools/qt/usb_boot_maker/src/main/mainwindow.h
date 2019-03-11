#ifndef GDB_DEBUG_SRC_MAIN_MAINWINDOW_H
#define GDB_DEBUG_SRC_MAIN_MAINWINDOW_H



#include <QMainWindow>

#include <QLabel>
#include <QTableWidget>
#include <QTimer>

#include "src/threads/addbreakpointthread.h"
#include "src/threads/deletebreakpointthread.h"
#include "src/threads/dumpmemorythread.h"
#include "src/threads/interpretthread.h"
#include "src/threads/qemureaderthread.h"
#include "src/threads/registersthread.h"
#include "src/threads/restartthread.h"
#include "src/threads/startthread.h"
#include "src/threads/stepthread.h"
#include "src/threads/stopthread.h"
#include "src/threads/waitforbreakthread.h"



namespace Ui
{
    class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0); // TEST: NO
    ~MainWindow(); // TEST: NO

public slots:
    void on_actionRestart_triggered(); // TEST: NO

private slots:
    void on_actionExit_triggered(); // TEST: NO
    void on_actionStop_triggered(); // TEST: NO
    void on_actionNext_step_triggered(); // TEST: NO
    void on_actionShow_memory_map_triggered(); // TEST: NO
    void on_actionAbout_triggered(); // TEST: NO
    void on_hexGraphicsView_byteHovered(qint64 position); // TEST: NO
    void on_hexGraphicsView_byteClicked(qint64 position); // TEST: NO
    void on_backToolButton_clicked(); // TEST: NO
    void on_assemblerTableWidget_cellDoubleClicked(qint32 row, qint32 column); // TEST: NO
    void on_assemblerTableWidget_currentCellChanged(qint32 currentRow, qint32 currentColumn, qint32 previousRow, qint32 previousColumn); // TEST: NO
    void on_registersTableWidget_cellDoubleClicked(qint32 row, qint32 column); // TEST: NO
    void on_dataInspectorAssemblerTableWidget_cellEntered(qint32 row, qint32 column); // TEST: NO
    void on_dataInspectorAssemblerTableWidget_cellClicked(qint32 row, qint32 column); // TEST: NO
    void on_dataInspectorAssemblerTableWidget_leaved(); // TEST: NO
    void on_dataInspectorTableWidget_cellEntered(qint32 row, qint32 column); // TEST: NO
    void on_dataInspectorTableWidget_cellClicked(qint32 row, qint32 column); // TEST: NO
    void on_dataInspectorTableWidget_leaved(); // TEST: NO

    void waitingProgressBarTimeout(); // TEST: NO
    void restartThreadFinished(); // TEST: NO
    void bootParamsAllocated(quint64 address, quint64 size); // TEST: NO
    void kernelAllocated(quint64 address, quint64 size); // TEST: NO
    void kernelRelocated(quint64 address); // TEST: NO
    void startThreadFinished(); // TEST: NO
    void stopThreadFinished(); // TEST: NO
    void stepThreadFinished(); // TEST: NO
    void interpretThreadFinished(); // TEST: NO
    void registersThreadFinished(); // TEST: NO
    void dumpMemoryThreadFinished(); // TEST: NO
    void addBreakpointThreadFinished(); // TEST: NO
    void deleteBreakpointThreadFinished(); // TEST: NO
    void waitForBreakThreadFinished(); // TEST: NO

private:
    Ui::MainWindow          *ui;
    bool                     mIsExecuting;
    QTimer                   mWaitingTimer;
    RestartThread           *mRestartThread;
    QemuProcess             *mQemuProcess;
    GdbProcess              *mGdbProcess;
    QemuReaderThread        *mQemuReaderThread;
    StartThread             *mStartThread;
    StopThread              *mStopThread;
    StepThread              *mStepThread;
    InterpretThread         *mInterpretThread;
    RegistersThread         *mRegistersThread;
    DumpMemoryThread        *mDumpMemoryThread;
    AddBreakpointThread     *mAddBreakpointThread;
    DeleteBreakpointThread  *mDeleteBreakpointThread;
    WaitForBreakThread      *mWaitForBreakThread;
    qint64                   mDataInspectorAssemblerPosition;
    qint64                   mDataInspectorPosition;
    qint64                   mDataInspectorScrollBarValue;
    QHash<QString, quint64>  mBreakpointsMap;

    void stopAllThreads(); // TEST: NO
    void stopRestartThread(); // TEST: NO
    void stopQemuReaderThread(); // TEST: NO
    void stopStartThread(); // TEST: NO
    void stopStopThread(); // TEST: NO
    void stopStepThread(); // TEST: NO
    void stopInterpretThread(); // TEST: NO
    void stopRegistersThread(); // TEST: NO
    void stopDumpMemoryThread(); // TEST: NO
    void stopAddBreakpointThread(); // TEST: NO
    void stopDeleteBreakpointThread(); // TEST: NO
    void stopWaitForBreakThread(); // TEST: NO
    void killAllProcesses(); // TEST: NO
    void updateCurrentPosition(); // TEST: NO
    void updateMemoryDump(); // TEST: NO
    void updateRegisters(); // TEST: NO
    void updateAssemblerAddresses(); // TEST: NO
    void hideAssemblerDataInspector(); // TEST: NO
    void updateDataInspector(qint64 position, QLabel *addressLabel, QLabel *sectionLabel, QTableWidget *tableWidget); // TEST: NO
    void dataInspectorCellEntered(QTableWidget *tableWidget, qint32 row, qint32 column, qint64 position); // TEST: NO
    void dataInspectorLeaved(); // TEST: NO
    void goToDisabledMode(); // TEST: NO
    void goToEnabledMode(); // TEST: NO

    void saveWindowState(); // TEST: NO
    void loadWindowState(); // TEST: NO
};



#endif // GDB_DEBUG_SRC_MAIN_MAINWINDOW_H
