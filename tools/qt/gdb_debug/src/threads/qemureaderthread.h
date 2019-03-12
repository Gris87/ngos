#ifndef GDB_DEBUG_SRC_THREADS_QEMUREADERTHREAD_H
#define GDB_DEBUG_SRC_THREADS_QEMUREADERTHREAD_H



#include <QThread>

#include "src/processes/qemuprocess.h"



class QemuReaderThread: public QThread
{
    Q_OBJECT

public:
    QemuReaderThread(QemuProcess *qemuProcess); // TEST: NO

    void stop(); // TEST: NO

protected:
    void run() override; // TEST: NO

private:
    void parseBootParamsAllocated(const QString &line); // TEST: NO
    void parseKernelAllocated(const QString &line); // TEST: NO
    void parseKernelRelocated(const QString &line); // TEST: NO

    bool         mIsRunning;
    QemuProcess *mQemuProcess;

signals:
    void bootParamsAllocated(quint64 address, quint64 size); // TEST: NO
    void kernelAllocated(quint64 address, quint64 size); // TEST: NO
    void kernelRelocated(quint64 address); // TEST: NO
};



#endif // GDB_DEBUG_SRC_THREADS_QEMUREADERTHREAD_H
