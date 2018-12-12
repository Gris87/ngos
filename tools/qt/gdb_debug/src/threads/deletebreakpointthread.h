#ifndef GDB_DEBUG_SRC_THREADS_DELETEBREAKPOINTTHREAD_H
#define GDB_DEBUG_SRC_THREADS_DELETEBREAKPOINTTHREAD_H



#include <QThread>

#include "src/processes/gdbprocess.h"



class DeleteBreakpointThread: public QThread
{
public:
    DeleteBreakpointThread(GdbProcess *gdbProcess, QString address, quint64 breakpointId); // TEST: NO

    void stop(); // TEST: NO

    const QString& getAddress() const; // TEST: NO

protected:
    void run() override; // TEST: NO

private:
    bool        mIsRunning;
    GdbProcess *mGdbProcess;
    QString     mAddress;
    quint64     mBreakpointId;
};



#endif // GDB_DEBUG_SRC_THREADS_DELETEBREAKPOINTTHREAD_H
