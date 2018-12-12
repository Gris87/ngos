#ifndef GDB_DEBUG_SRC_THREADS_INTERPRETTHREAD_H
#define GDB_DEBUG_SRC_THREADS_INTERPRETTHREAD_H



#include <QThread>

#include "src/processes/gdbprocess.h"



class InterpretThread: public QThread
{
public:
    InterpretThread(GdbProcess *gdbProcess, quint64 position); // TEST: NO

    void stop(); // TEST: NO

    quint64 getPosition() const; // TEST: NO
    QList<QStringList> getResult() const; // TEST: NO

protected:
    void run() override; // TEST: NO

private:
    bool                mIsRunning;
    GdbProcess         *mGdbProcess;
    quint64             mPosition;
    QList<QStringList>  mResult;
};



#endif // GDB_DEBUG_SRC_THREADS_INTERPRETTHREAD_H
