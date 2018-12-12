#ifndef GDB_DEBUG_SRC_THREADS_STARTTHREAD_H
#define GDB_DEBUG_SRC_THREADS_STARTTHREAD_H



#include <QThread>

#include "src/processes/gdbprocess.h"



class StartThread: public QThread
{
public:
    StartThread(GdbProcess *gdbProcess); // TEST: NO

    void stop(); // TEST: NO

protected:
    void run() override; // TEST: NO

private:
    bool        mIsRunning;
    GdbProcess *mGdbProcess;
};



#endif // GDB_DEBUG_SRC_THREADS_STARTTHREAD_H
