#ifndef GDB_DEBUG_SRC_THREADS_WAITFORBREAKTHREAD_H
#define GDB_DEBUG_SRC_THREADS_WAITFORBREAKTHREAD_H



#include <QThread>

#include "src/processes/gdbprocess.h"



class WaitForBreakThread: public QThread
{
public:
    WaitForBreakThread(GdbProcess *gdbProcess); // TEST: NO

    void stop(); // TEST: NO

protected:
    void run() override; // TEST: NO

private:
    bool        mIsRunning;
    GdbProcess *mGdbProcess;
};



#endif // GDB_DEBUG_SRC_THREADS_WAITFORBREAKTHREAD_H
