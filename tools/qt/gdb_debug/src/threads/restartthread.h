#ifndef GDB_DEBUG_SRC_THREADS_RESTARTTHREAD_H
#define GDB_DEBUG_SRC_THREADS_RESTARTTHREAD_H



#include <QThread>

#include "src/processes/gdbprocess.h"
#include "src/processes/qemuprocess.h"



class RestartThread: public QThread
{
public:
    RestartThread(); // TEST: NO
    ~RestartThread(); // TEST: NO

    void stop(); // TEST: NO

    QemuProcess* takeQemuProcess(); // TEST: NO
    GdbProcess* takeGdbProcess(); // TEST: NO

protected:
    void run() override; // TEST: NO

private:
    bool         mIsRunning;
    QemuProcess *mQemuProcess;
    GdbProcess  *mGdbProcess;
};



#endif // GDB_DEBUG_SRC_THREADS_RESTARTTHREAD_H
