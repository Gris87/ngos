#ifndef GDB_DEBUG_SRC_THREADS_ADDBREAKPOINTTHREAD_H
#define GDB_DEBUG_SRC_THREADS_ADDBREAKPOINTTHREAD_H



#include <QThread>

#include "src/processes/gdbprocess.h"



class AddBreakpointThread: public QThread
{
public:
    AddBreakpointThread(GdbProcess *gdbProcess, QString address); // TEST: NO

    void stop(); // TEST: NO

    const QString& getAddress() const; // TEST: NO
    quint64 getBreakpointId() const; // TEST: NO

protected:
    void run() override; // TEST: NO

private:
    bool        mIsRunning;
    GdbProcess *mGdbProcess;
    QString     mAddress;
    quint64     mBreakpointId;
};



#endif // GDB_DEBUG_SRC_THREADS_ADDBREAKPOINTTHREAD_H
