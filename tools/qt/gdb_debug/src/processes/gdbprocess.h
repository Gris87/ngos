#ifndef GDB_DEBUG_SRC_PROCESSES_GDBPROCESS_H
#define GDB_DEBUG_SRC_PROCESSES_GDBPROCESS_H



#include <QMutex>
#include <QProcess>
#include <elf/elfobject.h>



class GdbProcess
{
public:
    GdbProcess(const QStringList &qemuOutput); // TEST: NO
    ~GdbProcess(); // TEST: NO

    void start(bool *isRunning = 0); // TEST: NO

    void lock(); // TEST: NO
    void unlock(); // TEST: NO

    QString executeCommand(const QString &command, bool *isRunning = 0); // TEST: NO
    QString readOutput(bool *isRunning = 0); // TEST: NO
    void updateCurrentPositionFromOutput(const QString &output); // TEST: NO

    void terminateExecution(bool *isRunning = 0); // TEST: NO
    void continueExecution(bool *isRunning = 0); // TEST: NO

    void setMemoryDump(const QByteArray &memoryDump); // TEST: NO
    void setKernelLocation(quint64 address); // TEST: NO

    const ElfObject& getElfObject() const; // TEST: NO
    const QByteArray& getMemoryDump() const; // TEST: NO
    quint64 getKernelLocation() const; // TEST: NO
    quint64 getCurrentPosition() const; // TEST: NO

private:
    QStringList mQemuOutput;
    QMutex      mMutex;
    QProcess    mProcess;
    ElfObject   mElfObject;
    QByteArray  mMemoryDump;
    quint64     mKernelLocation;
    quint64     mCurrentPosition;
};



#endif // GDB_DEBUG_SRC_PROCESSES_GDBPROCESS_H
