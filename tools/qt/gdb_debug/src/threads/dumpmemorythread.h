#ifndef GDB_DEBUG_SRC_THREADS_DUMPMEMORYTHREAD_H
#define GDB_DEBUG_SRC_THREADS_DUMPMEMORYTHREAD_H



#include <QThread>

#include "src/processes/gdbprocess.h"



class DumpMemoryThread: public QThread
{
public:
    DumpMemoryThread(GdbProcess *gdbProcess); // TEST: NO

    void stop(); // TEST: NO

    QByteArray getResult() const; // TEST: NO

protected:
    void run() override; // TEST: NO

private:
    bool        mIsRunning;
    GdbProcess *mGdbProcess;
    QByteArray  mResult;
};



#endif // GDB_DEBUG_SRC_THREADS_DUMPMEMORYTHREAD_H
