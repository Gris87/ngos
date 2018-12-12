#ifndef GDB_DEBUG_SRC_THREADS_REGISTERSTHREAD_H
#define GDB_DEBUG_SRC_THREADS_REGISTERSTHREAD_H



#include <QThread>

#include "src/processes/gdbprocess.h"



class RegistersThread: public QThread
{
public:
    RegistersThread(GdbProcess *gdbProcess); // TEST: NO

    void stop(); // TEST: NO

    QList<QStringList> getResult() const; // TEST: NO

protected:
    void run() override; // TEST: NO

private:
    bool                mIsRunning;
    GdbProcess         *mGdbProcess;
    QList<QStringList>  mResult;
};



#endif // GDB_DEBUG_SRC_THREADS_REGISTERSTHREAD_H
